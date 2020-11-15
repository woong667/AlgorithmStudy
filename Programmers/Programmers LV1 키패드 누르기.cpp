#include <string>
#include <vector>
//#include <cstdlib>

using namespace std;
bool phone[4][3];
int Lh=10,Rh=12;

char a(int target,string hand){ //
    if(target==0)
        target=11;
    int Lx,Ly,Rx,Ry,Tx,Ty,Lcnt,Rcnt;
    Lx=(Lh-1)/3;Ly=(Lh-1)%3;
    Rx=(Rh-1)/3;Ry=(Rh-1)%3; //각각의 위치를 가져왔음.
    Tx=(target-1)/3;Ty=(target-1)%3;
    Lcnt=abs(Lx-Tx)+abs(Ly-Ty);
    Rcnt=abs(Rx-Tx)+abs(Ry-Ty);
    if(Lcnt>Rcnt)
    {
        Rh=target;
        return 'R';
        
    }
    else if(Lcnt==Rcnt)
    {
        if(hand=="right")
        {
            Rh=target;
             return 'R';
        }
        else
        { 
            Lh=target;
            return 'L';
        }
    }
    else
    {
        Lh=target;
        return 'L';
    }
    
    
}

string solution(vector<int> numbers, string hand) {
    string answer = "";
    for(int i=0;i<numbers.size();i++)
    {
       if(numbers[i]==1||numbers[i]==4||numbers[i]==7)
       {
           answer+="L";
           Lh=numbers[i];
       }
        else if(numbers[i]==3||numbers[i]==6||numbers[i]==9)
        {
            answer+="R";
            Rh=numbers[i];
        }
        else     //여기가 이제 진짜다.
        {
             char c=a(numbers[i],hand);
             answer+=c;
        }
        
    }
    return answer;
}