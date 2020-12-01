#include <vector>

using namespace std;
vector<vector<bool> > arr;
int number_of_area;
int sum;
int max_size_of_one_area;
int row,col;
int mx[4]={0,-1,0,1};
int my[4]={-1,0,1,0};


void dfs(int i,int j,int now,vector<vector<int> > picture)
{
     if(arr[i][j]==true||picture[i][j]==0||picture[i][j]!=now)
     {
         return;
     }//해당되지 않는다면.
    sum++;
    if(sum>max_size_of_one_area)
        max_size_of_one_area=sum;
    
    arr[i][j]=true;
    for(int k=0;k<4;k++)
    {
        int nx,ny;
        nx=i+mx[k];ny=j+my[k];
        if(nx<0||nx>=row||ny<0||ny>=col)
            continue;
        dfs(nx,ny,now,picture);
    }
   
}


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    number_of_area = 0;
    row=m;col=n;
    max_size_of_one_area = 0;
    arr.assign(m, vector<bool>(n, false)); //false로 다 들어있다.
    for(int i=0;i<m;i++)
    {
       for(int j=0;j<n;j++)
       {
           if(arr[i][j]==false&&picture[i][j]>0) //아직 들르지 않은곳이여야지
           {
               dfs(i,j,picture[i][j],picture);
               number_of_area++;
               sum=0;
           }
       }
    }
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}