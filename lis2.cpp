#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;

int n;
vector<int> a;
int dp[10010];

int lis2(int level){// gives the best max length sequence ending at  this level

    //pruning 
    //basecase
    //cache 
    if(dp[level]!=-1){
        return dp[level];
    }
    //compute(choices, check)
    int ans = 1;
    for(int i=0;i<level;i++){
        if(a[i]<a[level])
        {
            ans = max(ans, 1+lis2(i));
        }
    }
    //save and return
    return dp[level]=ans;

}

int main(){
    cin>>n;
    a.resize(n);
    for (int i=0;i<n;i++){
        cin>>a[i];
    }
    memset(dp,-1, sizeof(dp));
    
    int best = 0;
    for(int i=0;i<n;i++){
        best = max(best, lis2(i));

    }

    cout<<best;


    return 0;
}