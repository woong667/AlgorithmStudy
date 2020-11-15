#include <string>
#include <vector>
#include <algorithm>

using namespace std;



long long solution(int a, int b) {
    long long answer = 0;
    int MIN,MAX;
    MIN=min(a,b);
    MAX=max(a,b);
    for(int i=MIN;i<=MAX;i++)
    {
        answer+=i;
     }
    return answer;
}