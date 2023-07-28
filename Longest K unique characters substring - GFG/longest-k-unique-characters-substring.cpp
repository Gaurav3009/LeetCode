//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        int n = s.length();
        int i = 0, j = 0, maxLength = -1;
        map<char, int> hashMap;
        while(j < n) {
            hashMap[s[j]]++;
            if(hashMap.size() < k) {
                j++;
            } else if(hashMap.size() == k) {
                maxLength = max(maxLength, (j - i + 1));
                j++;
            } else {
                while(hashMap.size() > k) {
                    hashMap[s[i]]--;
                    if(hashMap[s[i]] == 0) {
                        hashMap.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return maxLength;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends