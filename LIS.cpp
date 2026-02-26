#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;



int n;
vector<int> a;
int dp[10010][10010];

int lis(int level, int prev_elt){ // gives max length from level to n-1
    // pruning
    //basecase
    if(level == n){
        return 0;
    }
    if(dp[level][prev_elt + 1]!=-1)  // offset by 1: -1 -> 0, 0 -> 1, etc.
    {
        return dp[level][prev_elt + 1];
    }
    //compute(choices, check)
    // here i have choices take / not take
    //not take
    int ans1=0;
    ans1 = lis(level+1, prev_elt);

    // taking
    //check whether i can take it 
    int ans2=0;
    if(prev_elt==-1||a[level]>a[prev_elt]){ // increasing so i can take
         ans2 = 1+lis(level+1, level);
    }

    //save and return 
    return dp[level][prev_elt + 1]=max(ans1,ans2);  // offset by 1

}


int main(){
    cin>>n;
    int value;
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;++i){
        cin>>value;
        a.push_back(value);
    }
    cout<<lis(0,-1);
    return 0;

}