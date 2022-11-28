#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>

// #define debug(format, ...) fprintf (stderr, format, ##__VA_ARGS__)

const std::string DISH = "DISH";
const std::string ICE_CREAM = "ICE_CREAM";
const std::string BLUEBERRIES = "BLUEBERRIES";
const std::string WINDOW = "WINDOW";
const std::string STRAWBERRIES = "STRAWBERRIES";
const std::string CHOPPED_STRAWBERRIES = "CHOPPED_STRAWBERRIES";
const std::string CHOPBOARD = "CHOPBOARD";
const std::string DOUGH = "DOUGH";
const std::string CHOPPED_DOUGH = "CHOPPED_DOUGH";
const std::string CROISSANT = "CROISSANT";
const std::string OVEN = "OVEN";
const std::string TART = "TART";
const std::string RAW_TART = "RAW_TART";
constexpr int REMAKE = 20;

const std::vector<std::string> split(const std::string &str, const char delimiter = '-') {
    std::vector<std::string> result;
    std::stringstream ss(str);
    std::string tok;

    while (std::getline(ss, tok, delimiter)) {
        result.push_back(tok);
    }
    return result;
}

bool isneighbor(std::pair<int, int> l, std::pair<int, int> r) {
    return std::abs(r.first - l.first) <= 1 && std::abs(r.second - l.second) <= 1;
}

int distance(std::pair<int, int> l, std::pair<int, int> r) {
    return std::max(std::abs(r.first - l.first), std::abs(r.second - l.second));
}

class Kitchen {
    public:
        void Build(const std::vector<std::string> &m) {
            m_ = m;
            for(int i = 0; i < m.size(); ++i) {
                for(int j = 0; j < m[i].size(); ++j) {
                    if (m[i][j] == 'D') {
                        item_coordinate_[DISH] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'I') {
                        item_coordinate_[ICE_CREAM] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'B') {
                        item_coordinate_[BLUEBERRIES] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'W') {
                        item_coordinate_[WINDOW] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'S') {
                        item_coordinate_[STRAWBERRIES] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'C') {
                        item_coordinate_[CHOPBOARD] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'O') {
                        item_coordinate_[OVEN] = std::make_pair(j, i);
                    }
                    else if (m[i][j] == 'H') {
                        item_coordinate_[DOUGH] = std::make_pair(j, i);
                    }
                }
            }
        }
        std::pair<int, int> GetCoordinate(const std::string &item) const {
            if (item_coordinate_.count(item)) {
                return item_coordinate_.at(item);
            }
            else {
                return std::make_pair(-1, -1);
            }
        }
        bool IsTable(int x, int y) const {
            return m_[y][x] == '#';
        }
    private:
        std::vector<std::string> m_;
        static constexpr int width_ = 11;
        static constexpr int height_ = 7;
        std::unordered_map<std::string, std::pair<int, int>> item_coordinate_;
};


struct ItemOnTable {
    void Build(int x, int y, const std::string &i) {
        contain_item = split(i);
        x_ = x;
        y_ = y;
    }
    int x_, y_;
    std::vector<std::string> contain_item;
};

class Table {
    public:
        void Add(ItemOnTable item) {
            items.push_back(item);
        }
        bool OnTable(const std::string &item) const{
            for(int i = 0; i < items.size(); ++i) {
                for(int j = 0; j < items[i].contain_item.size(); ++j) {
                    if (items[i].contain_item[j] == item) {
                        return true;
                    }
                }
            }
            return false;
        }
        bool FindItem(const std::string &item, std::pair<int, int> &item_position) const {
            for(int i = 0; i < items.size(); ++i) {
                for(int j = 0; j < items[i].contain_item.size(); ++j) {
                    if (items[i].contain_item[j] == item) {
                        item_position.first = items[i].x_;
                        item_position.second = items[i].y_;
                        return true;
                    }
                }
            }
            return false;
        }
        bool IsEmpty(int x, int y) const {
            for(int i = 0; i < items.size(); ++i) {
                if (items[i].x_ == x && items[i].y_ == y) {
                    return false;
                }
            }
            return true;
        }
        bool HaveItem(int x, int y, const std::string &item) const {
            for(int i = 0; i < items.size(); ++i) {
                if (items[i].x_ == x && items[i].y_ == y) {
                    for(int j = 0; j < items[i].contain_item.size(); ++j) {
                        if (item == items[i].contain_item[j]) {
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        std::pair<int,int> ItemOnDish(std::vector<std::string> target, std::vector<std::string> carrying){
            for(auto item:items){
                bool find=true;
                if(std::find(item.contain_item.begin(), item.contain_item.end(), DISH) == item.contain_item.end())
                    continue;
                for(auto i:item.contain_item){
                    if(std::find(target.begin(), target.end(), i) == target.end()||std::find(carrying.begin(), carrying.end(), i) != carrying.end()){
                        find=false;
                        break;
                    }
                }
                if(find)
                    return std::make_pair(item.x_,item.y_);
            }
            return std::make_pair(-1,-1);
        }
    private:
        std::vector<ItemOnTable> items;
};

class Oven {
    public:
        void Update(std::string ovenitem, int oven_time) {
            if (ovenitem != "NONE") {
                baking_ = true;
                item_ = ovenitem;
            }
            else{
                FinishBaking();
            }
            baking_time_ = oven_time;
        }
        bool GetBaking() const {
            return baking_;
        }
        bool BakingTimeUp() const {
            return (item_ == "TART" || item_ == "CROISSANT");
        }
        std::string BakingItem() const {
            return item_;
        }
        void FinishBaking() {
            baking_ = false;
            item_ = "NONE";
        }
    private:
        bool baking_ = false;
        int baking_time_;
        std::string item_;
};

struct Customer {
    void Build(const std::string &item, int award) {
        item_ = split(item);
        award_ = award;
    }
    const std::vector<std::string> & GetNeedItem() const {
        return item_;
    }
    std::vector<std::string> item_;
    int award_;
};

class CustomerList {
    public:
        void Add(const Customer &customer) {
            customers_.push_back(customer);
        }
        bool IsServed(std::vector<std::string> target)
        {
            for(auto c:customers_)
            {
                std::sort(target.begin(), target.end());
                std::sort(c.item_.begin(), c.item_.end());
                if(target == c.item_){
                    return false;
                }
            }
            return true;
        }
        Customer GetCustomer(int choice){
            std::sort(customers_.begin(), customers_.end(), cmp);
            if (choice < 0){
                choice = 0;
            }
            else if(choice > 2){
                choice = 2;
            }
            return customers_[choice];
        }
    private:
        static bool cmp(const Customer &a, const Customer &b)
        {
            return a.award_ < b.award_;
        }
        std::vector<Customer> customers_;
};

struct Record {
    std::vector<std::string> items;
    int round;
};

class Chef {
    public:
        void Build(Kitchen kitchen) {
            kitchen_ = kitchen;
        }
        void Update(int x, int y, const std::string &player_item, const Table &table) {
            x_ = x;
            y_ = y;
            if (player_item != "NONE")
                carrying_ = split(player_item);
            else
                carrying_ = std::vector<std::string>();
            table_ = table;
            round_ += 1;
        }
        int Distance(int x, int y) const {
            return distance(std::make_pair(x, y), std::make_pair(x_, y_));
        }
        int Distance(std::pair<int, int> p) const {
            return Distance(p.first, p.second);
        }
        int Distance(const std::string &item) const {
            return Distance(kitchen_.GetCoordinate(item));
        }
        void Use(int x, int y) const {
            std::cout << "USE " << x << " " << y << std::endl;
        }
        void Use(const std::pair<int, int> &p) const {
            Use(p.first, p.second);
        }
        void Use(const std::string &item) const {
            Use(kitchen_.GetCoordinate(item));
        }
        void Move(int x, int y) const {
            std::cout << "MOVE " << x << " " << y << std::endl;
        }
        void Move(const std::pair<int, int> &p) const {
            Move(p.first, p.second);
        }
        void Move(const std::string &item) const {
            Move(kitchen_.GetCoordinate(item));
        }
        void Wait() const {
            std::cout << "WAIT" << std::endl;
        }
        bool IsCarrying(const std::string &item) const {
            for(int i = 0; i < carrying_.size(); ++i) {
                if (carrying_[i] == item) {
                    return true;
                }
            }
            return false;
        }
        bool HaveTarget() const {
            return !target_.empty();
        }
        void SetTarget(const std::vector<std::string> &new_target) {
            target_ = new_target;
        }
        const std::vector<std::string> & GetTarget() const {
            return target_;
        }
        const std::vector<std::string> & GetCarrying() const {
            return carrying_;
        }
        std::pair<int, int> GetPosition() const {
            return std::make_pair(x_, y_);
        }
        void ClearTarget() {
            target_.clear(); 
        }
        bool HaveCarry() const {
            return !carrying_.empty();
        }
        bool IsTargetContained(const std::string &item) const {
            for(int i = 0; i < target_.size(); ++i) {
                if (target_[i] == item) {
                    return true;
                }
            }
            return false;
        }
        bool IsFinish() const {
            if (carrying_.empty() && target_.empty()) {
                return false;
            }
            std::unordered_set<std::string> hash_target(target_.begin(), target_.end());
            std::unordered_set<std::string> hash_carrying(carrying_.begin(), carrying_.end());
            return hash_target == hash_carrying;
        }
        void GetDish() const {
            auto dish_pos = kitchen_.GetCoordinate(DISH);
            std::pair<int, int> p;
            if (table_.FindItem(DISH, p)) {
                if (Distance(p) < Distance(dish_pos)) {
                    dish_pos = p;
                }
            }
            Use(dish_pos);
        }
        void PutOnTable() const {
            int dir[8][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
            for(int d = 0; d < 8; ++d) {
                int new_x = x_ + dir[d][0], new_y = y_ + dir[d][1];
                if (kitchen_.IsTable(new_x, new_y) && table_.IsEmpty(new_x, new_y)) {
                    Use(new_x, new_y);
                    return;
                }
            }
        }
        bool FindTable() const {
            for(int i = 0; i < target_.size(); ++i) {
                std::pair<int, int> p;
                if (table_.FindItem(target_[i], p) && !IsCarrying(target_[i])) {
                    auto save = p;
                    if (IsCarrying(DISH) && !table_.HaveItem(p.first, p.second, DISH)) {
                        Use(save);
                        return true;
                    }
                }
            }
            return false;
        }
        void MakeItem(const std::string &item) {
            if (item == CHOPPED_STRAWBERRIES) {
                MakeStrawberry();
            }
            else if (item == DISH){
                GetDish();
            }
            else if (item == CROISSANT) {
                MakeDoughToOven();
            }
            else if (item == TART){
                MakeTart();
            }
            else {
                MakeGeneral(item);
            }
        }
        void MakeStrawberry() const {
            if (HaveCarry() && !IsCarrying(STRAWBERRIES)) {
                if (Distance(GetIngredients(STRAWBERRIES)) >= 3) {
                    Move(GetIngredients(STRAWBERRIES));
                }
                else {
                    PutOnTable();
                    records.push_back({carrying_, round_});
                }
            }
            else if (IsCarrying(STRAWBERRIES)) {
                Use(kitchen_.GetCoordinate(CHOPBOARD));
            }
            else {
                Use(GetIngredients(STRAWBERRIES));
            }
        }
        std::pair<int, int> GetIngredients(std::string ingredient) const {
            auto pos = kitchen_.GetCoordinate(ingredient);
            std::pair<int, int> p;
            if (table_.FindItem(ingredient, p)) {
                if (Distance(p) < Distance(pos)) {
                    pos = p;
                }
            }
            return pos;
        }
        void MakeDoughToOven() {
            if (IsCarrying(DOUGH)) {
                Use(OVEN);
                SetMine();
                // std::cerr << "is my bake: " << MyBake() << std::endl;
            }
            else if (HaveCarry() && Distance(GetIngredients(DOUGH)) >= 3) {
                Move(GetIngredients(DOUGH));
            }
            else if (HaveCarry()) {
                PutOnTable();
                records.push_back({carrying_, round_});
            }
            else {
                Use(GetIngredients(DOUGH));
            }
        }
        void MakeTart() {
            if (IsCarrying(RAW_TART)) {
                Use(OVEN);
                SetMine();
                // std::cerr << "is my bake: " << MyBake() << std::endl;
            }
            else if (table_.OnTable(RAW_TART)){
                if (Distance(GetIngredients(RAW_TART)) >= 3) {
                    Move(GetIngredients(RAW_TART));
                }
                else if (HaveCarry()) {
                    PutOnTable();
                    records.push_back({carrying_, round_});
                }
                else {
                    Use(GetIngredients(RAW_TART));
                }
            }
            else if (table_.OnTable(CHOPPED_DOUGH)){
                if (Distance(GetIngredients(CHOPPED_DOUGH)) >= 3) {
                    Move(GetIngredients(CHOPPED_DOUGH));
                }
                else if (HaveCarry()) {
                    PutOnTable();
                    records.push_back({carrying_, round_});
                }
                else {
                    Use(GetIngredients(CHOPPED_DOUGH));
                }
            }
            else if (!IsCarrying(BLUEBERRIES) && IsCarrying(CHOPPED_DOUGH)){
                Use(GetIngredients(BLUEBERRIES));
            }
            else if (IsCarrying(DOUGH)) {
                Use(kitchen_.GetCoordinate(CHOPBOARD));
            }
            else if (Distance(GetIngredients(DOUGH)) >= 3) {
                Move(GetIngredients(DOUGH));
            }
            else if (HaveCarry()) {
                PutOnTable();
                records.push_back({carrying_, round_});
            }
            else {
                Use(GetIngredients(DOUGH));
            }
        }
        bool MyBake() const {
            return my_bake_;
        }
        void SetMine() {
            my_bake_ = true;
        }
        void EndMine() {
            my_bake_ = false;
        }
        void MakeGeneral(const std::string &item) const {
            Use(item);
        }
        int ScoreFunction(const std::string &item) {
            if (item == TART){
                return 101;
            }
            else if (item == CROISSANT) {
                return 100;
            }
            else if (item == CHOPPED_STRAWBERRIES) {
                return 99;
            }
            else if (item == DISH) {
                return 98;
            }
            else {
                return -Distance(kitchen_.GetCoordinate(item));
            }
        }
        void Schedule() {
            // define you target priority algorithm
            for(int i = 0; i < target_.size(); ++i) {
                for(int j = i + 1; j < target_.size(); ++j) {
                    if (ScoreFunction(target_[i]) < ScoreFunction(target_[j])) {
                        std::swap(target_[i], target_[j]);
                    }
                }
            }
        }
        bool InRecord(const std::string &item) const {
            for(int i = 0; i < records.size(); ++i) {
                for(int j = 0; j < records[i].items.size(); ++j) {
                    if (records[i].items[j] == item && table_.OnTable(item)) {
                        return true;
                    }
                }
            }
            return false;
        }
        int GetRound() const {
            return round_;
        }

    private:
        int x_, y_;
        std::vector<std::string> carrying_;
        Kitchen kitchen_;
        std::vector<std::string> target_;
        Table table_;
        mutable std::vector<Record> records;
        int round_ = 0;
        bool my_bake_ = false;
};

int main()
{
    int num_all_customers;
    std::cin >> num_all_customers; std::cin.ignore();
    for (int i = 0; i < num_all_customers; i++) {
        std::string customer_item;
        int customer_award;
        std::cin >> customer_item >> customer_award; std::cin.ignore();
    }
    std::vector<std::string> k;
    for (int i = 0; i < 7; i++) {
        std::string kitchen_line;
        std::getline(std::cin, kitchen_line);
        k.push_back(kitchen_line);
    }
    Kitchen kitchen;
    kitchen.Build(k);
    Chef my_chef, partner_chef;
    my_chef.Build(kitchen);
    Oven oven;

    Customer nowTodoCustomer;
    nowTodoCustomer.Build(DISH, -1);

    while (1) {
        int turns_remaining;
        std::cin >> turns_remaining; std::cin.ignore();
        int player_x;
        int player_y;
        std::string player_item;
        std::cin >> player_x >> player_y >> player_item; std::cin.ignore();
        int partner_x;
        int partner_y;
        std::string partner_item;
        std::cin >> partner_x >> partner_y >> partner_item; std::cin.ignore();
        
        int num_tables_with_items;
        std::cin >> num_tables_with_items; std::cin.ignore();
        Table table;
        for (int i = 0; i < num_tables_with_items; i++) {
            ItemOnTable item_on_table;
            int table_x;
            int table_y;
            std::string item;
            std::cin >> table_x >> table_y >> item; std::cin.ignore();
            item_on_table.Build(table_x, table_y, item);
            table.Add(item_on_table);
        }
        
        std::string oven_contents;
        int oven_timer;
        std::cin >> oven_contents >> oven_timer; std::cin.ignore();
        
        oven.Update(oven_contents, oven_timer);
        int num_customers;
        std::cin >> num_customers; std::cin.ignore();
        CustomerList customer_list;
        for (int i = 0; i < num_customers; i++) {
            std::string customer_item;
            int customer_award;
            std::cin >> customer_item >> customer_award; std::cin.ignore();
            Customer customer;
            customer.Build(customer_item, customer_award);
            customer_list.Add(customer);
        }
        
        my_chef.Update(player_x, player_y, player_item, table);
        partner_chef.Update(partner_x, partner_y, partner_item, table);
    }
}