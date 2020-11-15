#include <string>
#include <vector>
#include <stack>
using namespace std;

stack <int> s;
int cnt=0;

void cnt_doll(){
    
  int T,ST;
  if(s.size()>1) //스택에 인형이 한개이상있으면
  {
      T=s.top();
      s.pop();
      ST=s.top();
      s.pop();
      if(T==ST)//둘이 같으면
      {
        cnt+=2; 
      }
      else
      {
          s.push(ST);
          s.push(T); // 둘 다 다시 집어넣음
      }
  }
}

int solution(vector<vector<int>> board, vector<int> moves) {
    int i=0,now;
    int answer;
    while(i<moves.size())
    {
        now=moves[i]-1; //몇번째 칸에 있는것을 가져올것인지.
        for(int j=0;j<board.size();j++)
        {
            if(board[j][now]>0)  //인형이 있으면
            {
                s.push(board[j][now]); //스택에 넣고
                cnt_doll(); //현재 한번 체크.
                board[j][now]=0;
                break;
            } //인형이 없으면 그냥 지나감
        }
        i++;
        
    }
    answer=cnt;
    return answer;
}