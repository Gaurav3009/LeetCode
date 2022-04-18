class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();
        int dp[n + 1][m + 1];
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i < m + 1; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i < n + 1; i++){
            for(int j = 1; j < m + 1; j++){
                if(str1[i - 1] == str2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        string res = "";
        while(m > 0 && n > 0){
            if(str1[n - 1] == str2[m - 1]){
                res.insert(res.begin(), str1[n - 1]);
                n--;
                m--;
            }else{
                if(dp[n - 1][m] > dp[n][m - 1]){
                    res.insert(res.begin(), str1[n - 1]);
                    n--;
                }else{
                    res.insert(res.begin(), str2[m - 1]);
                    m--;
                }
            }
        }
        while(n > 0){
            res.insert(res.begin(), str1[n - 1]);
            n--;
        }
        while(m > 0){
            res.insert(res.begin(), str2[m - 1]);
            m--;
        }
        return res;
    }
};