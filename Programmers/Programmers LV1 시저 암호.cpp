#include <string>
#include <vector>
using namespace std;
char sm[26]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v'
              ,'w','x','y','z'};
char bg[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V'
              ,'W','X','Y','Z'};

string solution(string s, int n) {
    string answer = "";
    int idx;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') //공백이면.
        {
          answer+=" ";
        } 
        else{ //공백이 아니면..
            if(s[i]<97) //대문자이면
            {
                for(int j=0;j<26;j++)
                {
                    if(bg[j]==s[i]) //같으면
                    {
                        idx=j; //인덱스를 받고
                        idx=idx+n ;//숫자만큼 밀어주고
                        idx=idx%26; //26만큼 나머지.
                        answer+=bg[idx]; //이것만큼 answer에 더해줌
                        break;
                    }
                }
            }
            else //소문자이면.
            {
                for(int j=0;j<26;j++)
                {
                    if(sm[j]==s[i]) //같으면
                    {
                        idx=j; //인덱스를 받고
                        idx=idx+n ;//숫자만큼 밀어주고
                        idx=idx%26; //26만큼 나머지.
                        answer+=sm[idx]; //이것만큼 answer에 더해줌
                        break;
                    }
                }
            }
        }
    }
    return answer;
}