#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int m) {
    vector<int> answer;
    int nn=n,mm=m,sub;
    int MIN=n>=m?m:n;
    int MAX=n>=m?n:m;
    while(1)
    {
        sub=MAX%MIN;
        if(sub==0)
            break;
        MAX=MIN;MIN=sub;
    } //이때 m이 최대공약수
    answer.push_back(MIN);
    answer.push_back(nn*mm/MIN);
    return answer;
}