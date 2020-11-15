#include <iostream>
#include <string>

using namespace std;
int solution(int n)
{
    int answer = 0;
    string s=to_string(n);
    char c;
    for(int i=0;i<s.length();i++)
    {
        c=s[i];
        answer+=(c-'0');
    }
    return answer;
}