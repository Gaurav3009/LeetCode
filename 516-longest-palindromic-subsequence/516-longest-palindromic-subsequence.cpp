class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string a = s, b = s;
        reverse(b.begin(), b.end());
        int n = s.length();
        int dp[n + 1][n + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = dp[0][i] = 0;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < n + 1; j++){
                if(a[i - 1] == b[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j -1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[n][n];
    }
};