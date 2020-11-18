#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


bool compare(pair<double,int> a,pair<double,int> b)
{
    if(a.first==b.first)
        return a.second<b.second;
    else
        return a.first>b.first;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    double MAX;
    int idx;
    vector < pair<double,int> > a;
    int l=stages.size();
    double challenge=0;
    double failer=0;
    double avg;
    for(int i=1;i<=N;i++)  //각 스테이지 for문
    {
        for(int j=0;j<l;j++)    //각각의 challenge와 success의 수를 찾는과정
        {
            if(stages[j]>=i) //도전자를 찾는 if문
            {
                challenge++;
            }
            
            if(stages[j]==i) //success를 찾는 if문
            {
                failer++;
            }
    
        }
        if(failer==0&&challenge==0) a.push_back(make_pair(0,i));
        else a.push_back(make_pair(failer/challenge,i));
        challenge=0;
        failer=0;
    } //각 스테이지 for문 밖
    sort(a.begin(),a.end(),compare);
    for(int i=0;i<N;i++)
    {
       answer.push_back(a[i].second);
    }
    return answer;
}