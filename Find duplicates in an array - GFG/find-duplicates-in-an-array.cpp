//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int arr[], int n) {
        // map<int, int>m;
        // for(int i = 0; i < n; i++) {
        //     m[arr[i]]++;
        // }
        // // map<int, int>::iterator it;
        vector<int> ans;
        // for(auto it : m) {
        //     if(it.second > 1) {
        //         ans.push_back(it.first);
        //     }
        // }
        sort(arr, arr + n);
        int count = 1;
        for(int i = 1; i < n; i++) {
            while(arr[i] == arr[i - 1]) {
                i++;
                count++;
            }
            if(count > 1) {
                ans.push_back(arr[i - 1]);
            }
            count = 1;
        }
        if(ans.size() == 0) {
            ans.push_back(-1);
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends