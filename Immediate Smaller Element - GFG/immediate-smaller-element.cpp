//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	void immediateSmaller(vector<int>&arr, int n) {
	    int prev = arr[n - 1];
	    arr[n - 1] = -1;
	    for(int i = n - 2; i >= 0; i--) {
	        int temp = arr[i];
	        if(prev < arr[i]) {
	            arr[i] = prev;
	        } else {
	            arr[i] = -1;
	        }
	        prev = temp;
	    }
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >> n;
        vector<int>arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.immediateSmaller(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends