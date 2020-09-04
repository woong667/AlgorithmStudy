#include <string>
#include <vector>

using namespace std;

string carender[12][31];
string day[7]={"FRI","SAT","SUN","MON","TUE","WED","THU"};
int cnt[12]={31,29,31,30,31,30,31,31,30,31,30,31};

void set_day(){
    int k=0;
    for(int i=0;i<12;i++)
    {
        for(int j=0;j<cnt[i];j++)
        {
          carender[i][j]=day[k%7];
          k++;
        }
    }
}

string solution(int a, int b) {
    set_day();
    string answer = "";
    answer=carender[a-1][b-1];
    return answer;
}