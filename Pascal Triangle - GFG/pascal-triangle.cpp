//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod = 1000000007;
    ll dp[1002][1002];
    ll solve(int n,int k) {
        if(k < 1 || k > n) {
            return 0;
        }
        if(n == 1 && k == 1) {
            dp[1][1] = 1;
            return 1;
        }
        ll lv, rv;
        if(dp[n - 1][k - 1] != 0) {
            lv = dp[n - 1][k - 1];
        } else {
            lv = dp[n - 1][k - 1] = solve(n - 1, k - 1);
        }
        if(dp[n - 1][k] != 0) {
            rv = dp[n - 1][k];
        } else {
            rv = dp[n - 1][k] = solve(n - 1, k) % mod;
        }
        return (lv + rv) % mod;
    }
    vector<ll> nthRowOfPascalTriangle(int n) {
        memset(dp,0, sizeof(dp));
        vector<ll> arr;
        for(int i = 1; i <= n; i++) {
            ll x = solve(n, i);
            arr.push_back(x);
        }
        return arr;
    }
};


//{ Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends