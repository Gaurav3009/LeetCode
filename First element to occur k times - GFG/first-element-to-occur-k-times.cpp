//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int firstElementKTime(int a[], int n, int k)
    {
        map<int, pair<int, int>> m;
        for(int i = 0; i < n; i++) {
            if(m.find(a[i]) == m.end()) {
                m[a[i]] = {i, 1};
            }else {
                m[a[i]] = {i, m[a[i]].second+1};
                // cout<<a[i]<<" "<<m[a[i]].first<<" "<<m[a[i]].second<<endl;
            }
            if(m[a[i]].second == k) {
                    return a[i];
                }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n, k;
	    cin >> n >> k;
	    int a[n];
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution ob;
	    cout<<ob.firstElementKTime(a, n, k)<<endl;
	}
	
	return 0;
}
// } Driver Code Ends