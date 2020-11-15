#include <string>
#include <vector>

using namespace std;
long long int set_check(long long n)
{ 
    long long int a;
    for(long long int i=1;i<=10000000;i++)
    {
        a=i*i;
        if(a==n) //같으면
        {
           return ((i+1)*(i+1));
           
          }
        else if(a>n) //넘어가면
        {
           return -1;
        }
    }
    return -1;
}

long long solution(long long n) {
    long long answer=set_check(n);
    return answer;
}