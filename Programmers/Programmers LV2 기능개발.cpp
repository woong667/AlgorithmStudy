#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> sol;
     vector<int> answer;
    int cnt=1; //숫자를 세줄 cnt.
    for(int i=0;i<speeds.size();i++)
    {
        if((100-progresses[i])%speeds[i]==0)
        sol.push_back((100-progresses[i])/speeds[i]); //각 작업들마다 남은 시간을 구해주는 벡터.
        else
            sol.push_back(((100-progresses[i])/speeds[i])+1);
    }
    for(int i=0;i<speeds.size();i++)
    {
        if(sol[i]!=-1)
        {
           for(int j=i+1;j<speeds.size();j++)
            {
              if(sol[i]>=sol[j]) //작거나 같으면
              {
                  cnt++;
                  sol[j]=-1;
              }
               else
               {
                   break;
                   
               }
            }
            answer.push_back(cnt);
            cnt=1;
                   
        }
    }
    return answer;
}