#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>

using namespace std;

int row, col;
vector<vector<int>> grid;
vector<vector<int>> dp;
vector<vector<bool>> visited;

int pathmaxsum(int r, int c){
    // pruning
    if(r >= row || c >= col) return INT_MIN;
    // basecase
    if(r == row-1 && c == col-1) return grid[r][c];
    // cache check
    if(visited[r][c]) return dp[r][c];

    // mark visited
    visited[r][c] = true;
    
    // compute
    int right = pathmaxsum(r, c+1);
    int down = pathmaxsum(r+1, c);
   
    // save and return
    dp[r][c] = grid[r][c] + max(right, down);
    return dp[r][c];
}

int main(){
    cin >> row >> col;
    grid.assign(row, vector<int>(col));
    dp.assign(row, vector<int>(col, 0));
    visited.assign(row, vector<bool>(col, false));
    
    for(auto &r : grid){
        for(auto &x : r){
            cin >> x;
        }
    }
    
    cout << pathmaxsum(0, 0) << endl;
    
    return 0;
}