#include <iostream>
#include <string>
#include <cctype>


using namespace std;

int countLine(const string &str)
{
    int cnt = 0;
    bool isLetter = false;
    for(int i = 0 ; i < str.size() ; ++i)
    {
        if(isalpha(str[i]) && !isLetter)
        {
            isLetter = true;
            cnt++;
        }
        else if(isLetter && !isalpha(str[i]))
            isLetter = false;
    }
    return cnt;
}


int main()
{
    string str;
    while(getline(cin, str))
    {
        int cnt = 0;
        cnt = countLine(str);
        cout << cnt << endl;
    }
}