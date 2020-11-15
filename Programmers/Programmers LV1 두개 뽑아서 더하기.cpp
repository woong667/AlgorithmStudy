#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool arr[201];

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    int sum;
    //먼저 sort를 시키자.
    sort(numbers.begin(),numbers.end());
    for(int i=0;i<numbers.size()-1;i++)
    {
        for(int j=i+1;j<numbers.size();j++){
            sum=numbers[i]+numbers[j];
            if(arr[sum]==false) //아직 들어있지 않은 수라면
            {  
                arr[sum]=true; //true로 바꿔준다.
                answer.push_back(sum);
            }
            sum=0;
        }
    }
    sort(answer.begin(),answer.end());
    
    return answer;
}