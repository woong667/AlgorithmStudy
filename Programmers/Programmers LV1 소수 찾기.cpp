#include <string>
#include <vector>

using namespace std;

void eratostenes(int n)
{
    vector <bool> arr(n+1,true);
    arr[0]=false;
    arr[1]=false;
    for(int i=2;i*i<=n;i++)
    {
       if(arr[i])
       {
           for(int l=i*i;l<=n;l+=i)
           {
               arr[l]=false;
           }
       }
     }
}

int solution(int n) {
    int answer = 0;
    eratosthenes(n);
    for(int i=0;i<=n;i++)
    {
      if(arr[i]==true)
          answer++;
     }
    return answer;
}