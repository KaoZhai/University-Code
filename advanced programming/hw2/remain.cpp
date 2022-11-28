#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

enum Item
{
    DISH,
    DOUGH,
    ICE_CREAM,
    BLUEBERRIES,
    STRAWBERRIES,
    CHOPPED_STRAWBERRIES,
    CHOPPED_DOUGH,
    RAW_TART,
    TART,
    CROISSANT,
    BLUEBERRY_TART,
    NONE
};

class MyFunction
{
public:
    // return if player is at something's arround
    static bool isArround(pair<int, int> thing, pair<int, int> player)
    {
        return ((abs(player.first - thing.first) <= 1) && (abs(player.second - thing.second) <= 1));
    }

    // split string into item
    static vector<Item> split(const string& str, const string& pattern)
    {
        vector<Item> result;
        string::size_type begin, end;

        end = str.find(pattern);
        begin = 0;

        while (end != string::npos)
        {
            if (end - begin != 0)
            {
                string t = str.substr(begin, end-begin);

                if(t.compare("DISH") == 0)
                    result.push_back(DISH);
                else if(t.compare("BLUEBERRIES") == 0) 
                    result.push_back(BLUEBERRIES);
                else if(t.compare("ICE_CREAM") == 0)
                    result.push_back(ICE_CREAM);
                else if(t.compare("STRAWBERRIES") == 0)
                    result.push_back(STRAWBERRIES);
                else if(t.compare("CHOPPED_STRAWBERRIES") == 0)
                    result.push_back(CHOPPED_STRAWBERRIES);
                else if(t.compare("DOUGH") == 0)
                    result.push_back(DOUGH);
                else if(t.compare("CROISSANT") == 0)
                    result.push_back(CROISSANT);
                else if(t.compare("CHOPPED_DOUGH") == 0)
                    result.push_back(CHOPPED_DOUGH);
                else if(t.compare("RAW_TART") == 0)
                    result.push_back(RAW_TART);
                else if(t.compare("TART") == 0)
                    result.push_back(TART);
                else
                    cerr << "unknown item type: " << t << endl;
            }    
            begin = end + pattern.size();
            end = str.find(pattern, begin);
        }

        if (begin != str.length())
        {
            string t = str.substr(begin);

            if(t.compare("DISH") == 0)
                result.push_back(DISH);
            else if(t.compare("BLUEBERRIES") == 0) 
                result.push_back(BLUEBERRIES);
            else if(t.compare("ICE_CREAM") == 0)
                result.push_back(ICE_CREAM);
            else if(t.compare("STRAWBERRIES") == 0)
                result.push_back(STRAWBERRIES);
            else if(t.compare("CHOPPED_STRAWBERRIES") == 0)
                result.push_back(CHOPPED_STRAWBERRIES);
            else if(t.compare("DOUGH") == 0)
                result.push_back(DOUGH);
            else if(t.compare("CROISSANT") == 0)
                result.push_back(CROISSANT);
            else if(t.compare("CHOPPED_DOUGH") == 0)
                result.push_back(CHOPPED_DOUGH);
            else if(t.compare("RAW_TART") == 0)
                result.push_back(RAW_TART);
            else if(t.compare("TART") == 0)
                result.push_back(TART);
            else if(t.compare("NONE") == 0)
                return result;
            else
                cerr << "unknown item type: " << t << endl;
        }
        return result; 
    }

private:
};

class Kitchen
{
public:
    pair<int, int> blueberry() const
    {
        return blueberry_;
    }

    pair<int, int> dish() const
    {
        return dish_;
    }

    pair<int, int> window() const
    {
        return window_;
    }

    pair<int, int> choppingBoard() const
    {
        return choppingBoard_;
    }

    pair<int, int> iceCream() const
    {
        return iceCream_;
    }

    pair<int, int> strawberry() const
    {
        return strawberry_;
    }

    pair<int, int> oven() const
    {
        return oven_;
    }

    pair<int, int> dough() const
    {
        return dough_;
    }

    // return if the coordinate is empty table or not
    bool tableIsEmpty(const int x, const int y) const
    {
        return tableMap_[y][x];
    }

    void init()
    {
        string s;
        for (int i = 0; i < 7 ; ++i)
        {
            cin >> s;
            for(int j = 0 ; j < 11 ; ++j)
            {   
                // init empty table
                if(s[j] == '#')
                    tableMap_[i][j] = true;
                else
                    tableMap_[i][j] = false;

                // init walkable place
                if(s[j] == '0' || s[j] == '1' || s[j] == '.')
                    walkMap_[i][j] = true;
                else
                    walkMap_[i][j] = false;

                // init workbench
                if(s[j] == 'D')
                    dish_ = make_pair(j, i);
                else if(s[j] == 'W')
                    window_ = make_pair(j, i);
                else if(s[j] == 'B')
                    blueberry_ = make_pair(j, i);
                else if(s[j] == 'I')
                    iceCream_ = make_pair(j, i);
                else if(s[j] == 'S')
                    strawberry_ = make_pair(j, i);
                else if(s[j] == 'C')
                    choppingBoard_ = make_pair(j, i);
                else if(s[j] == 'H')
                    dough_ = make_pair(j, i);
                else if(s[j] == 'O')
                    oven_ = make_pair(j, i);
            }
        }
    }

private:
    pair<int, int> dish_;
    pair<int, int> window_;
    pair<int, int> iceCream_;
    pair<int, int> strawberry_;
    pair<int, int> blueberry_;
    pair<int, int> oven_;
    pair<int, int> choppingBoard_;
    pair<int, int> dough_;
    bool walkMap_[7][11];
    bool tableMap_[7][11];
};

class GameState
{
public:
    // return if player has the item on hand
    bool playerHave(const Item item) const
    {
        for(int i = 0 ; i < playerItem_.size() ; ++i)
        {
            if(playerItem_[i] == item)
                return true;
        }
        return false;
    }

    bool partnerHave(const Item item) const
    {
        for(int i = 0 ; i < partnerItem_.size() ; ++i)
        {
            if(partnerItem_[i] == item)
                return true;
        }
        return false;
    }

    // return remainTime
    int remainTime() const
    {
        return turnsRemaining_;
    }

    // return player's position
    pair<int, int> getPlayerPos() const
    {
        return playerPos_;
    }

    bool playerEmpty() const
    {
        return playerItem_.empty();
    }

    void getState()
    {
        string s;
        int X, Y;

        cin >> turnsRemaining_; cin.ignore();

        cin >> X >> Y >> s; cin.ignore();
        playerPos_ = make_pair(X, Y);
        playerItem_ = MyFunction::split(s, "-");

        cin >> X >> Y >> s; cin.ignore();
        partnerPos_ = make_pair(X, Y);
        partnerItem_ = MyFunction::split(s, "-");
    }

private:
    // how many turns remain
    int turnsRemaining_;
    // player's coordinate
    pair<int, int> playerPos_;
    // player's item
    vector<Item> playerItem_;
    // partner's coordinate
    pair<int, int> partnerPos_;
    // partner's item
    vector<Item> partnerItem_;
};

class Customers
{
public:
    // return this customer's award
    int getReward() const
    {
        return award_;
    }

    //return this customer's order
    vector<Item> getOrder() const
    {
        return order_;
    }

    // get customers informations
    void makeCustomers()
    {
        string s;
        cin >> s >> award_ ; cin.ignore();
        order_ = MyFunction::split(s, "-");
    }

    bool orderHave(Item item) const
    {
        for(int i = 0 ; i < order_.size() ; ++i)
        {
            if(order_[i] == item)
                return true;
        }
        return false;
    }

private:
    // list of all item in the order
    vector<Item> order_;
    int award_;
};

class Table
{
public:
    // return how many croissant on table
    int croissantNum() const
    {
        int cnt = 0;
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].second[0] == CROISSANT)
                ++cnt;
        }
        return cnt;
    }

    // return how many raw tart on table
    int rawTartNum() const
    {
        int cnt = 0;
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].second[0] == RAW_TART)
                ++cnt;
        }
        return cnt;
    }

    // return how many tart on table
    int tartNum() const
    {
        int cnt = 0;
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].second[0] == TART)
                ++cnt;
        }
        return cnt;
    }

    int allDishNum(const GameState gameState) const
    {
        int cnt = 0;
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].second[0] == DISH)
                ++cnt;
        }
        if(gameState.partnerHave(DISH))
            ++cnt;

        return cnt;
    }

    // return how many chpped strawberries on table
    int choppedStrawberriesNum() const
    {
        int cnt = 0;
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].second[0] == CHOPPED_STRAWBERRIES)
                ++cnt;
        }
        return cnt;
    }

    bool isEmpty(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y)
                return false;
        }

        return isEmpty_[y][x];
    }

    // return nearest empty table from player
    pair<int, int> getNearestEmpty(const pair<int, int> player) const
    {
        int min = 20;
        pair<int, int> minPos;
        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isEmpty(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    bool isCroissant(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == CROISSANT)
                return true;
        }
        return false;
    }

    bool isTart(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == TART)
                return true;
        }
        return false;
    }

    bool isRawTart(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == RAW_TART)
                return true;
        }
        return false;
    }

    bool isChoppedStrawberries(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == CHOPPED_STRAWBERRIES)
                return true;
        }
        return false;
    }

    bool isStrawberries(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == STRAWBERRIES)
                return true;
        }
        return false;
    }

    bool isDough(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == DOUGH)
                return true;
        }
        return false;
    }

    bool isDish(const int x, const int y) const
    {
        for(int i = 0 ; i < items_.size() ; ++i)
        {
            if(items_[i].first.first == x && items_[i].first.second == y && items_[i].second[0] == DISH && items_[i].second.size() == 1)
                return true;
        }
        return false;
    }

    pair<int, int> getNearestCroissant(const pair<int, int> player) const
    {
        int min = 20;
        pair<int, int> minPos;
        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isCroissant(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestRawTart(const pair<int, int> player) const
    {
        int min = 20;
        pair<int, int> minPos;
        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isRawTart(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestTart(const pair<int, int> player) const
    {
        int min = 20;
        pair<int, int> minPos;
        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isTart(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestChoppedStrawberries(const pair<int, int> player) const
    {
        int min = 20;
        pair<int, int> minPos;
        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isChoppedStrawberries(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestStrawberry(const pair<int, int> player, const Kitchen kitchen) const
    {
        int min = abs(player.first - kitchen.strawberry().first) + abs(player.second - kitchen.strawberry().second);
        pair<int, int> minPos = kitchen.strawberry();

        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isStrawberries(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestDough(const pair<int, int> player, const Kitchen kitchen) const
    {
        int min = abs(player.first - kitchen.dough().first) + abs(player.second - kitchen.dough().second);
        pair<int, int> minPos = kitchen.dough();

        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isDough(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                    }
                }
            }
        }
        return minPos;
    }

    pair<int, int> getNearestDish(const GameState gameState, const Kitchen kitchen) const
    {   
        pair<int, int> player = gameState.getPlayerPos();
        bool modFlag = false;
        int min;
        pair<int, int> minPos;
        if(allDishNum(gameState) == 3)
        {
            min = 20;
        }
        else
        {
            min = abs(player.first - kitchen.dish().first) + abs(player.second - kitchen.dish().second);
            minPos = kitchen.dish();
            modFlag = true;
        }

        for(int i = 0 ; i < 7 ; ++i)
        {
            for(int j = 0 ; j < 11 ; ++j)
            {
                if(isDish(j, i))
                {
                    int dis = abs(player.first - j) + abs(player.second - i);
                    if(dis < min)
                    {
                        min = dis;
                        minPos = make_pair(j, i);
                        modFlag = true;
                    }
                }
            }
        }
        if(modFlag)
            return minPos;
        else
            return make_pair(-1, -1);
    }

    // init empty table by kitchen
    void init(const Kitchen kitchen)
    {
        for(int i = 0; i < 7 ; ++i)
            for(int j = 0 ; j < 11 ; ++j)
                isEmpty_[i][j] = kitchen.tableIsEmpty(j, i);
        items_.clear();
    }

    // get all table's items
    void getItems()
    {
        cin >> itemNum_; cin.ignore();

        items_.clear();

        for (int i = 0 ; i < itemNum_ ; ++i)
        {
            int x, y;
            string s;
            cin >> x >> y >> s; cin.ignore();

            items_.push_back(make_pair(make_pair(x, y), MyFunction::split(s, "-")));
        }
    }

private:
    bool isEmpty_[7][11];
    int itemNum_;
    vector<pair<pair<int, int>, vector<Item>>> items_;
};

class Oven
{
public:
    // return oven inside object
    Item inside() const
    {
        return item_;
    }

    void getOven()
    {
        string s;
        cin >> s >> remainTime_ ; cin.ignore();
        if(s.compare("CROISSANT") == 0)
            item_ = CROISSANT;
        else if(s.compare("DOUGH") == 0)
            item_ = DOUGH;
        else if(s.compare("TART") == 0)
            item_ = TART;
        else if(s.compare("RAW_TART") == 0)
            item_ = RAW_TART;
        else if(s.compare("NONE") == 0)
            item_ = NONE;
    }
private:
    int remainTime_;
    Item item_;
};

class Command
{
public:
    bool isCommand() const
    {
        return isCommand_;
    }

    // erase certain item in order
    void eraseOrder(Item item)
    {
        for (int i = 0 ; i < itemList_.size() ; ++i)
        {
            cerr << itemList_[i] << endl;
        }

        int eraseIndex = 0;
        for (int i = 0 ; i < itemList_.size() ; ++i)
        {
            if(itemList_[i] == item)
            {
                eraseIndex = i;
            }
        }
        itemList_.erase(itemList_.begin() + eraseIndex);

        for (int i = 0 ; i < itemList_.size() ; ++i)
        {
            cerr << itemList_[i] << endl;
        }
    }

    // return if the order has a certain item
    bool orderHave(Item item) const
    {
        for(int i = 0 ; i < itemList_.size() ; ++i)
        {
            if(itemList_[i] == item)
                return true;
        }
        return false;
    }

    void getDish(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = table.getNearestDish(gameState, kitchen);
        if(target.first == -1)
        {
            cout << "WAIT" << endl;
        }
        else
        {
            if(MyFunction::isArround(target, gameState.getPlayerPos()))
            {
                itemList_.erase(itemList_.begin());
                pfunc_ = nullptr;
            }
            cout << "USE " << target.first << " " << target.second << " get dish" << endl;
        }
    }

    void getIceCream(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = kitchen.iceCream();
        if(MyFunction::isArround(target, gameState.getPlayerPos()))
        {
            itemList_.erase(itemList_.begin());
            pfunc_ = nullptr;
        }
        cout << "USE " << target.first << " " << target.second << " get ice cream" << endl;
    }

    void getBlueberries(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = kitchen.blueberry();
        if(MyFunction::isArround(target, gameState.getPlayerPos()))
        {
            itemList_.erase(itemList_.begin());
            pfunc_ = nullptr;
        }
        cout << "USE " << target.first << " " << target.second << " get blueberry" << endl;
    }

    void putEmptyTable(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = table.getNearestEmpty(gameState.getPlayerPos());
        if(MyFunction::isArround(target, gameState.getPlayerPos()))
        {
            pfunc_ = nullptr;
            isCommand_ = false;
        }
        cout << "USE " << target.first << " " << target.second << " put on empty table" << endl;
    }

    void getChoppedStrawberry(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(oven.inside() == TART || oven.inside() == CROISSANT)
        {
            if(!gameState.playerEmpty())
            {
                pfunc_ = &Command::putEmptyTable;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pfunc_ = &Command::useOven;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
        }
        else if(gameState.playerHave(STRAWBERRIES))
        {
            pair<int, int> target = kitchen.choppingBoard();
            cout << "USE " << target.first << " " << target.second << " chopping" << endl;
        }
        else if(gameState.playerHave(CHOPPED_STRAWBERRIES))
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = table.getNearestStrawberry(gameState.getPlayerPos(), kitchen);
            cout << "USE " << target.first << " " << target.second << " get strawberry" << endl;
        }
    }

    void useOven(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(oven.inside() != NONE && (!gameState.playerEmpty()))
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = kitchen.oven();
            if(MyFunction::isArround(target, gameState.getPlayerPos()))
            {
                pfunc_ = nullptr;
                isCommand_ = false;
            }
            cout << "USE " << target.first << " " << target.second << " use oven" << endl;
        }
    }

    void getDough(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = table.getNearestDough(gameState.getPlayerPos(), kitchen);
        if(MyFunction::isArround(target, gameState.getPlayerPos()))
        {
            pfunc_ = nullptr;
        }
        cout << "USE " << target.first << " " << target.second << " get dough" << endl;
    }

    void getCroissant(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(oven.inside() == CROISSANT)
        {
            if(!gameState.playerEmpty())
            {
                pfunc_ = &Command::putEmptyTable;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pfunc_ = &Command::useOven;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
        }
        else if(gameState.playerHave(DOUGH))
        {
            pfunc_ = &Command::useOven;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else if(gameState.playerHave(CROISSANT))
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = table.getNearestDough(gameState.getPlayerPos(), kitchen);
            cout << "USE " << target.first << " " << target.second << " take dough" << endl;
        }
    }

    void takeCroissant(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(table.croissantNum() == 0)
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = table.getNearestCroissant(gameState.getPlayerPos());
            if(MyFunction::isArround(target, gameState.getPlayerPos()))
            {
                eraseOrder(CROISSANT);
                pfunc_ = nullptr;
            }
            cout << "USE " << target.first << " " << target.second << " take croissant" << endl;
        }
    }

    void takeChoppedStrawberries(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(table.choppedStrawberriesNum() == 0)
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = table.getNearestChoppedStrawberries(gameState.getPlayerPos());
            if(MyFunction::isArround(target, gameState.getPlayerPos()))
            {
                eraseOrder(CHOPPED_STRAWBERRIES);
                pfunc_ = nullptr;
            }
            cout << "USE " << target.first << " " << target.second << " take chopped strawberries" << endl;
        }
    }

    void takeTart(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(table.tartNum() == 0)
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            pair<int, int> target = table.getNearestTart(gameState.getPlayerPos());
            if(MyFunction::isArround(target, gameState.getPlayerPos()))
            {
                eraseOrder(TART);
                pfunc_ = nullptr;
            }
            cout << "USE " << target.first << " " << target.second << " take tart" << endl;
        }
    }

    void getRawTart(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(oven.inside() == TART || oven.inside() == CROISSANT)
        {
            if(!gameState.playerEmpty())
            {
                pfunc_ = &Command::putEmptyTable;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pfunc_ = &Command::useOven;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
        }
        else if(gameState.playerHave(DOUGH))
        {
            pair<int, int> target = kitchen.choppingBoard();
            cout << "USE " << target.first << " " << target.second << " chopping" << endl;
        }
        else if(gameState.playerHave(CHOPPED_DOUGH))
        {
            pair<int, int> target = kitchen.blueberry();
            cout << "USE " << target.first << " " << target.second << " put blueberry on dough" << endl;
        }
        else if(gameState.playerHave(RAW_TART))
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else if(gameState.playerEmpty())
        {
            pair<int, int> target = table.getNearestDough(gameState.getPlayerPos(), kitchen);
            cout << "USE " << target.first << " " << target.second << " get dough" << endl;
        }
    }

    void getTart(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        if(oven.inside() == TART || oven.inside() == CROISSANT)
        {
            if(!gameState.playerEmpty())
            {
                pfunc_ = &Command::putEmptyTable;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pfunc_ = &Command::useOven;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
        }
        else if(gameState.playerHave(RAW_TART))
        {
            pfunc_ = &Command::useOven;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else if(gameState.playerHave(TART))
        {
            pfunc_ = &Command::putEmptyTable;
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        }
        else
        {
            if(table.rawTartNum() == 0)
            {
                pfunc_ = &Command::getRawTart;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pair<int, int> target = table.getNearestRawTart(gameState.getPlayerPos());
                cout << "USE " << target.first << " " << target.second << " take raw tart" << endl;
            }
        }
    }

    void deliver(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        pair<int, int> target = kitchen.window();
        if(MyFunction::isArround(target, gameState.getPlayerPos()))
        {
            pfunc_ = nullptr;
            isCommand_ = false;
        }
        cout << "USE " << target.first << " " << target.second << " deliver" << endl;
    }

    void finish(const Kitchen kitchen, const GameState gameState, const Table table, const Oven oven)
    {
        cerr << "now list to do: ";
        for(int i = 0 ; i < itemList_.size() ; ++i)
        {
            if(itemList_[i] == TART)
                cerr << "TART ";
            else if(itemList_[i] == CHOPPED_STRAWBERRIES)
                cerr << "CHOPPED_STRAWBERRIES ";
            else if(itemList_[i] == CROISSANT)
                cerr << "CROISSANT ";
            else if(itemList_[i] == BLUEBERRIES)
                cerr << "BLUEBERRIES ";
            else if(itemList_[i] == ICE_CREAM)
                cerr << "ICE_CREAM ";
            else if(itemList_[i] == DISH)
                cerr << "DISH ";
        }
        cerr << endl;


        if(pfunc_)
            (*this.*pfunc_)(kitchen, gameState, table, oven);
        else
        {
            if(itemList_.empty())
            {
                pfunc_ = &Command::deliver;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else if(oven.inside() == TART || oven.inside() == CROISSANT)
            {
                if(!gameState.playerEmpty())
                {
                    pfunc_ = &Command::putEmptyTable;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
                else
                {
                    pfunc_ = &Command::useOven;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
            }
            else if(!gameState.playerEmpty() && (!gameState.playerHave(DISH)))
            {
                pfunc_ = &Command::putEmptyTable;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else if(gameState.playerHave(DISH))
            {
                if(itemList_.empty())
                {
                    pfunc_ = &Command::deliver;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
                else if(itemList_.front() == DISH)
                {
                    pfunc_ = &Command::putEmptyTable;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
                else if(itemList_.front() == TART)
                {
                    if(table.tartNum() == 0)
                    {
                        pfunc_ = &Command::putEmptyTable;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                    else
                    {
                        pfunc_ = &Command::takeTart;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                }
                else if(itemList_.front() == CROISSANT)
                {
                    if(table.croissantNum() == 0)
                    {
                        pfunc_ = &Command::putEmptyTable;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                    else
                    {
                        pfunc_ = &Command::takeCroissant;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                }
                else if(itemList_.front() == CHOPPED_STRAWBERRIES)
                {
                    if(table.choppedStrawberriesNum() == 0)
                    {
                        pfunc_ = &Command::putEmptyTable;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                    else
                    {
                        pfunc_ = &Command::takeChoppedStrawberries;
                        (*this.*pfunc_)(kitchen, gameState, table, oven);
                    }
                }
                else if(itemList_.front() == ICE_CREAM)
                {
                    pfunc_ = &Command::getIceCream;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
                else if(itemList_.front() == BLUEBERRIES)
                {
                    pfunc_ = &Command::getBlueberries;
                    (*this.*pfunc_)(kitchen, gameState, table, oven);
                }
            }
            else if(orderHave(TART) && ( (table.tartNum() <= 1 && (!gameState.partnerHave(TART))) || (table.tartNum() < 1 && (gameState.partnerHave(TART)))) )
            {
                pfunc_ = &Command::getTart;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else if(orderHave(CROISSANT) && ( (table.croissantNum() <= 1 && (!gameState.partnerHave(CROISSANT))) || (table.croissantNum() < 1 && (gameState.partnerHave(CROISSANT)))) )
            {
                pfunc_ = &Command::getCroissant;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else if(orderHave(CHOPPED_STRAWBERRIES) && table.choppedStrawberriesNum() == 0)
            {
                pfunc_ = &Command::getChoppedStrawberry;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
            else
            {
                pfunc_ = &Command::getDish;
                (*this.*pfunc_)(kitchen, gameState, table, oven);
            }
        }

        if(gameState.remainTime() <= 1)
        {
            pfunc_ = nullptr;
            isCommand_ = false;
        }
    }

    // check if order exit
    bool checkOrder(const vector<Customers> customers)
    {
        for(int i = 0 ; i < customers.size() ; ++i)
        {
            vector<Item> customersOrder = customers[i].getOrder();
            vector<Item> temp = order_;
            for(int j = temp.size() ; j >= 0 ; --j)
            {
                for(int k = 0 ; k < customersOrder.size() ; ++k)
                {
                    if(temp[j] == customersOrder[k])
                    {
                        temp.pop_back();
                        customersOrder.erase(customersOrder.begin() + k);
                        break;
                    }
                }
            }
            if(temp.empty() && customersOrder.empty())
                return true;
        }
        pfunc_ = nullptr;
        isCommand_ = false;
        return false;
    }

    // init now making target
    void make(const Customers customer)
    {
        itemList_ = customer.getOrder();
        order_ = itemList_;
        isCommand_ = true;
    }

private:
    bool isCommand_ = false;
    void (Command::*pfunc_)(Kitchen, GameState, Table, Oven) = nullptr;
    vector<Item> itemList_;
    vector<Item> order_;    
};


Customers maxCustomer(const vector<Customers> allCustomers)
{
    int max = 0, maxIndex = 2;
    for(int i = 0 ; i < allCustomers.size() ; ++i)
    {
        int nowReward = allCustomers[i].getReward();
        if((!allCustomers[i].orderHave(TART)) && (!allCustomers[i].orderHave(CROISSANT)) && nowReward + 99999 > max)
        {
            max = 99999 + nowReward;
            maxIndex = i;
        }
        else if(allCustomers[i].orderHave(TART) && (!allCustomers[i].orderHave(CROISSANT)) && nowReward + 77777 > max)
        {
            max = 55555 + nowReward;
            maxIndex = i;
        }
        else if((!allCustomers[i].orderHave(TART)) && allCustomers[i].orderHave(CROISSANT) && nowReward + 55555 > max)
        {
            max = 33333 + nowReward;
            maxIndex = i;
        }
        else if(nowReward > max)
        {
            max = nowReward;
            maxIndex = i;
        }
    }

    return allCustomers[maxIndex];
}

int main()
{    
    Kitchen kitchen;
    int numAllCustomers;
    Customers allCustomers;
    GameState gameState;
    Command command;
    Table table;
    Oven oven;
    vector<Customers> customers;

    cin >> numAllCustomers; cin.ignore();

    for(int i = 0 ; i <numAllCustomers ; ++i)
        allCustomers.makeCustomers();

    kitchen.init();
    table.init(kitchen);

    // game loop
    while (1)
    {
        gameState.getState();

        table.getItems();

        oven.getOven();

        int customersNum;
        cin >> customersNum; cin.ignore();
        customers.clear(); 
        for (int i = 0 ; i < customersNum; ++i)
        {
            Customers temp;
            temp.makeCustomers();
            customers.push_back(temp);
        }

        cerr << "croissantNum: " << table.croissantNum() << endl;
        cerr << "choppedStrawberriesNum: " << table.choppedStrawberriesNum() << endl;
        cerr << "rawTartNum: " << table.rawTartNum() << endl;
        cerr << "tartNum: " << table.tartNum() << endl;
        cerr << "allDishNum" << table.allDishNum(gameState) << endl;

        if(command.isCommand() && command.checkOrder(customers))
        {
            command.finish(kitchen, gameState, table, oven);
        }
        else
        {
            Customers nowCustomers = maxCustomer(customers);
            command.make(nowCustomers);
            // command.makeWithoutTart(customers);
            command.finish(kitchen, gameState, table, oven);
        }

    }
}
