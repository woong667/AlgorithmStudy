#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

string solution(string s) {
    char tmp;
    for(int i=0;i<s.length();i++)
    {
      for(int j=i+1;j<s.length();j++)
      {
          if(s[i]<s[j])
          {
              tmp=s[i];
              s[i]=s[j];
              s[j]=tmp;
          }
      }
    }
    return s;
}