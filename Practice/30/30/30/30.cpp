#include <iostream>
#include <vector>
#include <map>
#include <ctime>
using namespace std;
struct Weapon
{
    uint damage;
    uint critical;
    uint durability;
};
struct Armor
{
    uint guard;
    uint durability;
};
struct Coin
{
    uint count;
};
struct Rune
{
    uint level;
    enum class Element { FIRE, WATER, EARTH, AIR } element;
};
struct Item;
Item generate();
struct Item
{
    enum class ItemType { COIN, RUNE, WEAPON, ARMOR } type;
    union Value { Coin coin; Rune rune; Weapon weapon; Armor armor; } value;
    Item& operator++ () {
        *this = generate();
        return *this;
    }
};
Item GetCoin(uint count) {
    return { Item{Item::ItemType::COIN,Item::Value{.coin = Coin{count}}} };
}
Item GetRune(Rune::Element element, uint level) {
    return { Item{Item::ItemType::RUNE,Item::Value{.rune = Rune{level, element}}} };
}
Item GetRunefire(uint level) {
    return GetRune(Rune::Element::FIRE, level);
}
Item GetRunewater(uint level) {
    return GetRune(Rune::Element::WATER, level);
}
Item GetRuneearth(uint level) {
    return GetRune(Rune::Element::EARTH, level);
}
Item GetRuneair(uint level) {
    return GetRune(Rune::Element::AIR, level);
}
Item GetWeapon(uint damage, uint critical, uint durability) {
    return { Item{Item::ItemType::WEAPON, Item::Value{.weapon = Weapon{damage, critical, durability}}} };
}
Item GetArmor(uint guard, uint durability) {
    return { Item{Item::ItemType::ARMOR, Item::Value{.armor = Armor{guard,durability}}} };
}

template<class T, class S>
struct Pair {
    T first;
    S second;
};
vector<Pair<Item, double>> chance = {
    {GetCoin(1000), 50},
    {GetRunefire(1), 6}, //56
    {GetRunewater(1), 13}, //69
    {GetRuneearth(1), 7}, // 76
    {GetRuneair(1), 14},// 90
    {GetRunefire(5), 0.6}, // 90.6
    {GetRunewater(5), 1.3}, // 91.9
    {GetRuneearth(5), 0.7}, // 92.6
    {GetRuneair(5), 1.4}, // 94
    {GetRunefire(10), 0.06}, //94.06
    {GetRunewater(10), 0.13}, //94.19
    {GetRuneearth(10), 0.07},//94.26
    {GetRuneair(10), 0.14},//94.4
    {GetWeapon(100,0,100),1.4}, // 95.8
    {GetWeapon(75,50,100),1.4}, //97.2
    {GetArmor(50,100), 2.8}, //100
};
double counter() {
    double sum = 0;
    for (auto& i : chance)
        sum += i.second;
    return sum;
}
ostream& operator<<(ostream& out, Pair<Item, double>& chances) {
    out << chances.second << endl;
    return out;
}
Item generate() {
    double random = double(rand() % int(counter()));
    double cursum = 0;
    for (auto& elem : chance) {
        if (cursum > random or random < cursum + elem.second) {
            return elem.first;
        }
        cursum += elem.second;
    }
    return chance[0].first;
};
string s_ting(Rune::Element& element) {
    switch (element) {
    case Rune::Element::FIRE:
        return "fire";
    case Rune::Element::EARTH:
        return "earth";
    case Rune::Element::WATER:
        return "water";
    case Rune::Element::AIR:
        return "air";
    }
    return "rune";
}

ostream& operator<< (ostream& out, Item& item) {
    Item::ItemType& type = item.type;
    switch (type) {
    case Item::ItemType::COIN:
        out << item.value.coin.count << "Gold";
        break;
    case Item::ItemType::RUNE:
        out << "Rune of " << s_ting(item.value.rune.element) << " " << item.value.rune.level << " lvl";
        break;

    case Item::ItemType::WEAPON:
        if (item.value.weapon.damage == 100) out << "God killer. ";
        if (item.value.weapon.damage == 75) out << "Demon Slayer. ";
        out << "Damage: " << item.value.weapon.damage << ", crit: " << item.value.weapon.critical;  out << ", durability: " << item.value.weapon.durability;
        break;

    case Item::ItemType::ARMOR:
        out << "Bronezhiletka. Guard: " << item.value.armor.guard << ", durability: " << item.value.armor.durability;
        break;
    }
    out << endl;
    return out;
}
using LootBox = vector<Item>;
LootBox generate_lootbox();
LootBox& operator<<(LootBox& box, Item item) {
    box.push_back(item);
    return box;
}
LootBox generate_lootbox() {
    LootBox box;
    srand(time(0));
    for (int i; i < 3; i++) box << generate();
    return box;
}
ostream& operator<<(ostream& out, LootBox& lootbox) {
    for (auto& elem : lootbox) {
        out << elem << "\n";
    }
    return out;
}
int main() {
    while (true) {
        cout << "Open LootBox? Yes/No" << endl;
        string line;
        cin >> line;
        if (line == "y" or line == "Y" or line == "Ye" or line == "ye" or line == "yE" or line == "Yes" or line == "yes") {
            cout << "\n";
            auto box = generate_lootbox();
            cout << box;
        }
        else if (line == "n" or line == "N" or line == "No" or line == "no" or line == "nO" or line == "NO" or line == "on") break;
    }
}