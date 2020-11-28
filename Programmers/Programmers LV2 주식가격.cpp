#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    for(int i=0;i<prices.size()-1;i++)
    {
        int now=prices[i];
        int sum=0;
        for(int j=i+1;j<prices.size();j++)
        {
            sum++; //일단 1을 올리고
            if(now>prices[j])
                break;
        }
        answer.push_back(sum);
    }
    answer.push_back(0);
    return answer;
}