#include <iostream>
using namespace std;

int gcd(int a,int b)
{
  while(b!=0){
   int n=a%b;
   a=b;
   b=n;
  }
  return a;
}
int main()
{
  int test,i,j;
  cin>>test;
  while(test--)
  {
   cin>>i>>j;
   cout<<(i*j)/gcd(i,j)<<endl;
  }
  return 0;
}