#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int cnt=0;
    char check_space;
    string word="";
    for(int i=0;i<s.length();i++)
    {
        check_space=s[i];
        if(check_space==' ') //공백이면
        {
            answer+=word;
            answer+=" "; //공백한칸 넣어주고
            word="";
            cnt=0;
            continue;
        }
        else     //공백칸이 아니면
        {
            if(cnt%2==0) //짝수번째 인덱스이면 대문자로 바꿔야함.
            {
              word+=toupper(s[i]);
              cnt++;
              if(i==s.length()-1)
              {
                answer+=word;
                 break;
              }
            }
            else{
                word+=tolower(s[i]);
                cnt++;
                if(i==s.length()-1)
              {
                answer+=word;
                 break;
              }
            }
        }
    }
    return answer;
}