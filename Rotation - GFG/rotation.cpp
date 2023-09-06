//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    int start = 0, end = n - 1, next, prev, mid;
	    while(start <= end) {
	        mid = start + (end - start) / 2;
	        next = (mid + n) % n;
	        prev = (mid - 1 + n) % n;
	        if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
	            return mid;
	        } else if(arr[mid] >= arr[start]) {
	            if(arr[end] < arr[start]) {
	                start = mid + 1;
	            } else {
	                end = mid - 1;
	            }
	        } else {
	            end = mid - 1;
	        }
	    }
	    return 0;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends