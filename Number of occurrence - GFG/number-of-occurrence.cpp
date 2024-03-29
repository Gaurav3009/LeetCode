//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int firstOccurance(int arr[], int start, int end, int target) {
	    int ans = -1, mid;
	    while(start <= end) {
	        mid = start + (end - start) / 2;
	        if(arr[mid] == target) {
	            ans = mid;
	            end = mid - 1;
	        } else if(arr[mid] > target) {
	            end = mid - 1;
	        } else {
	            start = mid + 1;
	        }
 	    }
 	    return ans;
	}
	int lastOccurance(int arr[], int start, int end, int target) {
	    int ans = -1, mid;
	    while(start <= end) {
	        mid = start + (end - start) / 2;
	        if(arr[mid] == target) {
	            ans = mid;
	            start = mid + 1;
	        } else if(arr[mid] > target) {
	            end = mid - 1;
	        } else {
	            start = mid + 1;
	        }
 	    }
 	    return ans;
	}
	int count(int arr[], int n, int x) {
	    int start = firstOccurance(arr, 0, n - 1, x);
	    int end = lastOccurance(arr, 0, n - 1, x);
	    if(start == -1) {
	        return 0;
	    }
	    return end - start + 1;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends