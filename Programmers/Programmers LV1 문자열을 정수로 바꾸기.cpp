#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    if(s[0]=='-')
    {
      for(int i=1;i<s.length();i++)
      {
         answer=(answer*10)+(s[i]-'0');
      }
        answer=-answer;
    }
    else if(s[0]=='+'){
        for(int i=1;i<s.length();i++)
      {
         answer=(answer*10)+(s[i]-'0');
      }
    }
    else
    {
        for(int i=0;i<s.length();i++)
      {
         answer=(answer*10)+(s[i]-'0');
      }
    }
    return answer;
}