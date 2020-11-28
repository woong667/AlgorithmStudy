#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    int len=skill.length(); //스킬트리의 전체길이.
    for(int i=0;i<skill_trees.size();i++)
    {
        int idx=-1;
        bool flag=true;
        string s=skill_trees[i]; //하나하나씩 스트링을 가져온다.
        for(int j=0;j<s.length();j++) //하나의 스킬트리씩의 한자한자 비교해볼예정
        {
            char c=s[j]; //한글자씩 가져옴
            for(int k=0;k<len;k++)
            {
                if(c==skill[k]) //글자가 같은것이 있으면
                {
                    //여기서부터 idx비교를 해야함.
                    if(k==idx+1) //한칸올린 인덱스번호랑 같다면
                    {
                        idx++;
                    }
                    else //같지않다면
                    {
                        flag=false; //플래그를 false로 바꾸고.
                        break;
                    }
                }
            }
            if(flag==false)
                break; 
                
        }
        if(flag==true)
            answer++;
     }
    return answer;
}