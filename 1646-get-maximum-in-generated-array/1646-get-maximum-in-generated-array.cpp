class Solution {
public:
    int dp[101];
    Solution(){
        memset(dp, -1, sizeof(dp));
    }
    int solve(int n){
        if(n <= 1){
            return n;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        if(n % 2 == 0){
            return dp[n] =  solve(n / 2);
        }else{
            return dp[n] =  (solve(n / 2) + solve(n / 2 + 1));
        }
    }
    int getMaximumGenerated(int n) {
        int m = 0;
        for(int i = 0; i < n + 1; i++){
            m = max(solve(i), m);
        }
        return m;
    }
};