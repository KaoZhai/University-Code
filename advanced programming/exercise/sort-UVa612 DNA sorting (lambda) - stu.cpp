#include <iostream>
#include <cstddef>
#include <cstring>
#include <algorithm>
using namespace std;

constexpr size_t MaxStringLen = 50;

class String
{
friend ostream & operator << (ostream &os, const String &rhs);
public:
    void Set(const char s[]);
    const char & operator[](size_t i) const { return str_[i]; }
    size_t size() const { return strlen(str_); }
    size_t Unsortedness() const { return unsortedness_; }
private:
    static constexpr size_t MaxLen = MaxStringLen;
    char str_[MaxLen+1]={};
    size_t unsortedness_ = 0;
};
// ------------------------------------------------------------------
void String::Set(const char s[])
{
    char tmp[MaxLen + 1] = {};
    strcpy(tmp, s);
    strcpy(str_, s);
    for(int i = 0 ; i < strlen(tmp) ; ++i)
    {
        for(int j = i + 1 ; j < strlen(tmp) ; ++j)
        {
            if(tmp[j] < tmp[i])
            {
                swap(tmp[j], tmp[i]);
                unsortedness_+= j - i;
            }
        }
    }
}
// ------------------------------------------------------------------
ostream & operator << (ostream &os, const String &rhs)
{
    os << rhs.str_;
    return os;
}
// ------------------------------------------------------------------
int main()
{
    int T=0;
    cin >> T;

    while (T--)
    {
        int L=0, N=0;
        cin >> L >> N;
        String data[100];

        for (int i=0; i<N; i+=1)
        {
            char str[MaxStringLen+1]={};
            cin >> str;
            data[i].Set(str);
        }

        stable_sort(data, data+N, 
            [](const String &l, const String &r){return l.Unsortedness() < r.Unsortedness();});
        for (int i=0; i<N; i+=1)
        {
            cout << data[i] << endl;
        }

        if (T) cout << endl;
    }
}
/*
2

10 6
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
CCCGGGGGGA
ATCGATGCAT

10 6
CCCGGGGGGA
AACATGAAGG
TTTTGGCCAA
TTTGGCCAAA
GATCAGATTT
ATCGATGCAT

*/
