#include <iostream>
#include <string.h>
#include <iterator>
using namespace std;

struct CStudent
{
   int id = 0,
       score = 0;
   char name[30] = {};
};

ostream & operator << (ostream &os, const CStudent &stu)
{
    os << stu.id << ' ' << stu.name << ' ' << stu.score;
    return os;
}

void sort(CStudent data[], int n, int (*cmp)(const CStudent &lhs, const CStudent &rhs))
{
    // Call cmp(data[i], data[j]) when you need to compare two CStudent objects
    for(int i = 0 ; i < n ; ++i)
    {
        for(int j = i + 1 ; j < n ; ++j)
        {
            if(cmp(data[i], data[j]) > 0)
            {
                CStudent temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

int CompareId(const CStudent &lhs, const CStudent &rhs)
{
    return lhs.id > rhs.id;
}

int CompareName(const CStudent &lhs, const CStudent &rhs)
{
    return strcmp(lhs.name, rhs.name);
}

int CompareScore(const CStudent &lhs, const CStudent &rhs)
{
    return lhs.score > rhs.score;
}



int main()
{
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};

    sort(data, size(data), CompareId);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareName);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareScore);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
}






