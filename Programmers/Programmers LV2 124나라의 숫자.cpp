#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    int next;
    while(1)
    {
        next=n%3;
        if(next==0) 
              answer='4'+answer;
        else if(next==2)
                answer='2'+answer;
         else if(next==1)
                answer='1'+answer;
        if(n/4==0)
            break;
        else
        {
            if(n%3==0) //자리가 넘어가는 거기 때문에 -1을 해줘야함.... 이거 생각한다고 오래걸렷음
                n=n/3-1;
            else  //나머지가 0이 아니면 그냥 나눠주고
                n=n/3;
        }
    }
    return answer;
}