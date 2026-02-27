#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cstring>

using namespace std;
int row, col;
vector<vector<int>> grid;
int dp[10010][10010];
int visited[10010][10010];

int pathmaxsum(int row_level, int col_level){// best max length ending at this level(r,c)
    //pruning (invalid cases)
    if(row_level<0 || col_level < 0 ) return INT_MIN;
    //base case
    if(row_level == 0 && col_level == 0) return grid[0][0];
    //cache
    if(visited[row_level][col_level]==0) return dp[row_level][col_level];
    //mark visited
    visited[row_level][col_level]=0;
    
    //compute(choices,check, move)
    int up = pathmaxsum(row_level-1, col_level);
    int left = pathmaxsum(row_level, col_level-1);

    return dp[row_level][col_level]=grid[row_level][col_level]+max(up,left);
}

int main(){
    cin>>row>>col;
    grid.assign(row, vector<int>(col,0));
    memset(dp,-1,sizeof(dp));
    memset(visited, -1, sizeof(visited));
    for(auto &r:grid)
    {
        for(auto &x:r){
            cin>>x;
        }
    }
    cout<<pathmaxsum(row-1,col-1);



    return 0;
}