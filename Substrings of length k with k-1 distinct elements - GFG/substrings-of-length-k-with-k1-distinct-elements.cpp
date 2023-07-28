//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string S, int K) {
        int n = S.length();
        map<char, int> hashMap;
        int i = 0, j = 0, ans = 0;
        while(j < n) {
            hashMap[S[j]]++;
            if((j - i + 1) < K) {
                j++;
            } else {
                if(hashMap.size() == K - 1) {
                    ans++;
                }
                j++;
                hashMap[S[i]]--;
                if(hashMap[S[i]] == 0) {
                    hashMap.erase(S[i]);
                }
                i++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends