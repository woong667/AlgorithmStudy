#include <string>
#include <vector>
#include <string.h>
#include <algorithm>
#include <functional>

using namespace std;
int gn;

bool compare(string a,string b)
{
    if(a[gn]<b[gn])
        return true;
    else if(a[gn]>b[gn])
        return false;
    else{    
        return a<b;
    }
}

vector<string> solution(vector<string> strings, int n) {
    gn=n;
    sort(strings.begin(),strings.end(),compare);
    return strings;
}