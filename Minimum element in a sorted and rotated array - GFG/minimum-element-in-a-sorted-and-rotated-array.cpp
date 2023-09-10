//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int start = 0, end = n - 1, mid, next, prev;
        while(start <= end) {
            mid = start + (end - start) / 2;
            next = (mid + 1) % n;
            prev = (mid - 1 + n) % n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return arr[mid];
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
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}
// } Driver Code Ends