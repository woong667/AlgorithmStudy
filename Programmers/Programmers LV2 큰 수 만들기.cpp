#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
stack <char> s;

string solution(string number, int k) {
    string answer = "";
    vector <char> v;
    int cnt=0;
    s.push(number[0]);
    int number_length=number.length();
    for(int i=1;i<number_length;i++)
    {
        while(1){
            
            if(s.empty()||cnt==k)
            {
                s.push(number[i]);
                break;
            }
             if((s.top()-'0')>=(number[i]-'0'))
                {   
                    s.push(number[i]);
                    break;
                }
             else
                    s.pop();
                    cnt++;
           }
    }
    
    if(cnt!=k)  //같지않은상태에서 끝나버리면
    {
        int remain=k-cnt;
        while(remain--)
        {
          s.pop();
        }
    }
    while(!s.empty())
    {
        v.push_back(s.top());
        s.pop();
    }
    reverse(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
       answer+=v[i];                
    }
    return answer;
}