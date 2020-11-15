#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector <int> digit;
int solution(int n) {
    int answer = 0;
    int s=1;
    while(n>=3)
    {
        digit.push_back(n%3);
        n=n/3;
    }
    digit.push_back(n);
    for(int i=digit.size()-1;i>=0;i--)
    {
        answer=answer+(digit[i]*s);
        s=s*3;
    }
    cout<<"hello"<<endl;
    return answer;
}