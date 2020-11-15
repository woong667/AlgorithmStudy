#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(long long n) {
    long long answer = 0;
    string s=to_string(n);
    vector <int> v;
    for(int i=0;i<s.length();i++)
    {
     int num=s[i]-'0';
     v.push_back(num);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        answer=(answer*10)+v[i];
    }
    return answer;
}