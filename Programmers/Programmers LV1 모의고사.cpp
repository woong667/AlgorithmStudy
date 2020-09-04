#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int num1[5]={1,2,3,4,5};
int num2[8]={2,1,2,3,2,4,2,5};
int num3[10]={3,3,1,1,2,2,4,4,5,5};

vector<int> solution(vector<int> answers) {
    
    vector <int> dap;
    int MAX;
   int limit1=5,limit2=8,limit3=10;
   int cnt1=0,cnt2=0,cnt3=0;
   for(int i=0;i<(int)answers.size();i++)
   {
       if(answers[i]==num1[i%5])
           cnt1++;
       if(answers[i]==num2[i%8])
           cnt2++;
       if(answers[i]==num3[i%10])
           cnt3++;
   }
   MAX=max(cnt1,max(cnt2,cnt3));
    if(cnt1==MAX)
        dap.push_back(1);
    if(cnt2==MAX)
        dap.push_back(2);
    if(cnt3==MAX)
        dap.push_back(3);
    sort(dap.begin(),dap.end());
    return dap;

}