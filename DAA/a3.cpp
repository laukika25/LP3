#include<bits/stdc++.h>
using namespace std;

int f(int n, int wt, vector<int>& w, vector<int>& v, vector<vector<int>>& dp){
    // base case
    if(n==0){
        if(wt >= w[0])
            return v[0];
        else
            return 0;
    }

    if(dp[n][wt] != -1)
        return dp[n][wt];

    int notpick = 0 + f(n - 1, wt, w, v, dp);
    int pick = INT32_MIN;
    if(wt >= w[n]){
        pick = v[n] + f(n - 1, wt - w[n], w, v, dp);
    }
    return dp[n][wt] = max(pick, notpick);
}

int main(){
    int n = 4;
    int wt = 8;
    vector<int> w = {2, 3, 4,5};
    vector<int> v = {1,2,5,6};
    vector<vector<int>> dp(n, vector<int>(wt + 1, -1));
    cout << f(n-1, wt, w, v, dp);
}