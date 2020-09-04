
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    int temp = arr[0];

    answer.push_back(temp);

    for (int i = 1; i < arr.size(); i++)
    {
        if (arr[i] != temp)
        {
            answer.push_back(arr[i]);
            temp = arr[i];
        }
    }
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;

    return answer;
}