//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the minimum element in sorted and rotated array.
    int minNumber(int arr[], int low, int high) {
        int mid, next, prev, n = high + 1;
        while(low <= high) {
            mid = low + (high - low) / 2;
            next = (mid + 1) % n;
            prev = (mid - 1 + n) % n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return arr[mid];
            } else if(arr[mid] >= arr[low]) {
                if(arr[high] < arr[low]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            } else {
                high = mid - 1;
            }
        }
        return arr[0];
    }
};

//{ Driver Code Starts.


int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;++i)
			cin>>a[i];	
		Solution obj;
		cout << obj.minNumber(a,0,n-1) << endl;
	}
	return 0;
}
// } Driver Code Ends