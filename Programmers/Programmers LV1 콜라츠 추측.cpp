#include string
#include vector

using namespace std;

int solution(int num) {
    int answer = 0;
    long long int num2=num;
    while(num2!=1)
    {
        if(num2%2==0) 짝수이면
            num2=2;
        else
            num2=(num23)+1;
        
        answer++;
        if(answer==500)
        {
            answer=-1;
                break;
        }
        
    }
    return answer;
}