#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int Distance(pair<int, int> const a, pair<int, int> const b)
{
    int x = a.first - b.first;
    int y = a.second - b.second;
    return int(sqrt(pow(x, 2) + pow(y, 2)));
}

class Base{
public:
    void SetCoor(const int &x, const int &y)
    {
        
        myBaseCoor_ = make_pair(x, y);
        if(x == 0) oppBaseCoor_ = make_pair(17630, 9000);
        else       oppBaseCoor_ = make_pair(0, 0);
        return;
    }

    void Update(const int &myHealth, const int &myMana, const int &oppHealth, const int &oppMana)
    {
        myHealth_ = myHealth;
        myMana_ = myMana;
        oppHealth_ = oppHealth;
        oppMana_ = oppMana;
        return;
    }

    pair<int, int> MyBaseCoor() const
    {
        return myBaseCoor_;
    }

    pair<int, int> OppBaseCoor() const
    {
        return oppBaseCoor_;
    }

private:
    pair<int, int> myBaseCoor_;
    pair<int, int> oppBaseCoor_;
    int myHealth_, myMana_;
    int oppHealth_, oppMana_;
};

class Monster{
public:
    void Build(const int id, const pair<int, int> pos, const pair<int, int> trajectory, const int shieldLife,
               const int health, const int threatFor, const bool isControlled, const bool nearBase, const int willGoBase)
    {
        id_ = id;
        pos_ = pos;
        trajectory_ = trajectory;
        shieldLife_ = shieldLife;
        health_ = health;
        threatFor_ = threatFor;
        isControlled_ = isControlled;
        nearBase_ = nearBase;
        willGoBase_ = willGoBase;
        return;
    }

    int WillGoBase() const
    {
        return willGoBase_;
    }

    pair<int, int> Pos() const
    {
        return pos_;
    }

private:
    int id_;
    pair<int, int> pos_;
    pair<int, int> trajectory_;
    int shieldLife_;
    int health_;
    int threatFor_;
    bool isControlled_;
    bool nearBase_;
    int willGoBase_;
};

class Hero{
public:
    void Init(int id)
    {
        id_ = id;
    }

    void Update(pair<int, int> pos)
    {
        pos_ = pos;
    }

    bool IsId(int id)
    {
        return id == id_;
    }

    pair<int, int> Pos() const
    {
        return pos_;
    }

private:
    int id_;
    int targetId_;
    pair<int, int> pos_;
};

int CheckWillGoBase(pair<int, int> const pos, pair<int, int> const trajectory, int const threatFor, Base const base)
{
    pair<int, int> temp = pos;

    if(threatFor == 1)
        return Distance(temp, base.MyBaseCoor()) / 400;

    int cnt = 0;
    pair<int, int> change;
    double ration = sqrt(pow(trajectory.first, 2) + pow(trajectory.second, 2)) / 200.0;
    change.first = int(double(trajectory.first) / ration);
    change.second = int(double(trajectory.second) / ration);
    while((temp.first >= 0 && temp.first <= 17630) && (temp.second >= 0 && temp.second <= 9000))
    {
        cnt++;
        int dis = Distance(temp, base.MyBaseCoor());
        if(dis <= 5000)
        {
            return cnt + 12;
        }
        temp.first += change.first;
        temp.second += change.second;
    }
    return 0;
}

int main()
{
    int base_x; // The corner of the map representing your base
    int base_y;
    cin >> base_x >> base_y; cin.ignore();
    int heroes_per_player; // Always 3
    cin >> heroes_per_player; cin.ignore();

    Base base;
    base.SetCoor(base_x, base_y);

    // game loop
    while (1)
    {
        int myHealth, myMana;
        int oppHealth, oppMana;
        cin >> myHealth >> myMana >> oppHealth >> oppMana; cin.ignore();
        base.Update(myHealth, myMana, oppHealth, oppMana);

        vector<Monster> allMonster;
        Hero myHero[3];

        for(int i = 0 ; i < 3 ; ++i)
            myHero[i].Init(i);

        int entity_count;
        cin >> entity_count; cin.ignore();
        for (int i = 0; i < entity_count; i++) {
            int id; // Unique identifier
            int type; // 0=monster, 1=your hero, 2=opponent hero
            int x; // Position of this entity
            int y;
            int shieldLife; // Ignore for this league; Count down until shield spell fades
            int isControlled; // Ignore for this league; Equals 1 when this entity is under a control spell
            int health; // Remaining health of this monster
            int vx; // Trajectory of this monster
            int vy;
            int nearBase; // 0=monster with no target yet, 1=monster targeting a base
            int threatFor; // Given this monster's trajectory, is it a threat to 1=your base, 2=your opponent's base, 0=neither
            cin >> id >> type >> x >> y >> shieldLife >> isControlled >> health >> vx >> vy >> nearBase >> threatFor; cin.ignore();
            
            pair<int, int> pos = make_pair(x, y);
            if(type == 0)
            {                
                pair<int, int> trajectory = make_pair(vx, vy);
                int willGoBase = CheckWillGoBase(pos, trajectory, threatFor, base);
                Monster newMonster;
                newMonster.Build(id, pos, trajectory, shieldLife, health, threatFor, isControlled, nearBase, willGoBase);
                allMonster.push_back(newMonster);
            } 
            else if(type == 1)
            {
                myHero[id % 3].Update(pos);
            }
        }

        pair<int, int> target[3];
        for(int i = 0 ; i < 3 ; ++i)
            target[i] = base.MyBaseCoor();

        for(int i = 0 ; i < 3 ; ++i)
        {
            int minDis = 30;
            for(int j = 0 ; j < allMonster.size() ; ++j)
            {
                int willGoBase = allMonster[j].WillGoBase();
                if(willGoBase)
                {
                    if(willGoBase < minDis)
                    {
                        minDis = willGoBase;
                        target[i] = allMonster[j].Pos();
                    }
                }
            }
        }

        cout << "MOVE "<< target[0].first << " " << target[0].second << endl;
        cout << "MOVE "<< target[1].first << " " << target[1].second << endl;
        cout << "MOVE "<< target[2].first << " " << target[2].second << endl;
    }
}