#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
string s;
int dp[100001][3];  // [level][prev_choice: 0, 1, or 2 for none]

int inefficiency(int level, int prev_choice) {  // min inefficeincy from [level...n-1], this what recursion at a level tells, before that level everything fixed
    // base case
    if (level == n) { // there is no elemenet to put, when there is no element no efficiency is gained or reduced 
        return 0;
    }

    if (dp[level][prev_choice] != -1) {
        return dp[level][prev_choice];
    }

    int ans = INT_MAX;

    // if current position is '?'
    if (s[level] == '?') {
        // now we have two choices 0/1, find for all choices 
        for (int curr_choice = 0; curr_choice <= 1; curr_choice++) {
            int cost = (prev_choice != 2 && prev_choice != curr_choice) ? 1 : 0;
            ans = min(ans, cost + inefficiency(level + 1, curr_choice));
        }
    }
    else { //already fixed value given to us so no choice just compare with previous
        int curr_choice = s[level] - '0';  // convert '0'/'1' to 0/1
        int cost = 0;
        if (prev_choice != 2 && prev_choice != curr_choice) {
            cost = 1;
        }
        ans = cost + inefficiency(level + 1, curr_choice);
    }

    return dp[level][prev_choice] = ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cin >> n;
        cin >> s;
        memset(dp, -1, sizeof(dp));

        // starting recursion with prev_choice = 2 (meaning no previous)
        cout << inefficiency(0, 2) << endl;
    }

    return 0;
}