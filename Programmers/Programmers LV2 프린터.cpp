#include <string>
#include <vector>
#include <queue>

using namespace std;


int solution(vector<int> priorities, int location) {
    int answer = 0;
    while(1)
    {
        bool flag=false;
        int now=priorities[0]; //현재 맨앞꺼 가져오고.
        for(int i=1;i<priorities.size();i++) //우선순위 높은것이 있나 탐색을 해보자.
        {
           if(now<priorities[i]) //하나라도 크것이 존재를 한다면.
           {
               flag=true; //flag가 true인게 하나라도 존재를 한다는 의미이다.
               break;
           }
        }
        
        if(flag==true)
        {
             if(location==0) //now가 target이라면
                {
                    priorities.erase(priorities.begin());
                    priorities.push_back(now);
                    location=priorities.size()-1; //location은 맨마지막으로 이동.
                }
                else
                {
                    priorities.erase(priorities.begin());
                    priorities.push_back(now);
                    location--;
                }
        }
        else //우선순위가 후달리지 않기 때문에 이제 나가도됨.
        {
                location--;
                priorities.erase(priorities.begin()); //큐에서도 빼고
                answer++;
                if(location==-1) //목표한 친구가 나온거라면.
                    return answer; //answer return.
        }
    }
    return answer;
}