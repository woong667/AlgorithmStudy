#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
     if(s.length()%2==1) //홀수라면
    {
        int l=s.length()/2;
         answer+=s[l];
    }
    else{              //짝수라면        
        int l=s.length()/2;
        answer+=s[l-1];
        answer+=s[l];
    }
    return answer;
}