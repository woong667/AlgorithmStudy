#include <string>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector <int> clsVec;
    for(int i=0;i<commands.size();i++)
    {
        // 배열에서 지정된 영역을 복사한다.
       clsVec.assign( array.begin() + (commands[i][0]-1), array.begin() + commands[i][1] );

        // 정렬한다.
        sort( clsVec.begin(), clsVec.end() );

        // 지정된 위치의 값을 저장한다.
        answer.push_back( clsVec[commands[i][2]-1] );

    }
    return answer;
    
}