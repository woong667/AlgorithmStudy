#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string memo="수박";
    string answer = "";
    while(n>0)
    {
        if(n>1) //두자리이상일경우
        {
            answer+=memo;
            n=n-2;
        }
        else{ //이제 한개남았을때
            answer+="수";
            n=n-1;
        }
    }
    return answer;
}