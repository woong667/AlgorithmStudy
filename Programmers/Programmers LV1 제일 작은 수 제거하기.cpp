#include <string>
#include <vector>

using namespace std;
int MIN;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    MIN=arr[0];
    int idx;
    if(arr.size()==1) //한개밖에 없는 배열이 들어온다면
    {
        answer.push_back(-1);
        return answer;
    }
    else{
       for(int i=1;i<arr.size();i++)
         {
            if(MIN>arr[i]) 
            {
                MIN=arr[i];
                idx=i; //인덱스번호까지 받아옴.
            }
         }
        arr.erase(arr.begin()+idx);
        return arr;
    }
}