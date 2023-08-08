//{ Driver Code Starts
#include<bits/stdc++.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

// } Driver Code Ends
/* You are required to complete the function below
*  arr[]: input array
*  n: size of array
*/
class Solution{
  public:
    //Function to find triplets with zero sum.
    bool findTriplets(int arr[], int n)
    { 
        sort(arr, arr + n);
        int count = 0;
        for(int i = 0; i <= (n - 3); i++) {
            int t = -(arr[i]);
            int start = i + 1, end = n - 1;
            while(start < end) {
                if((arr[start] + arr[end]) == t) {
                    count = 1;
                    break;
                } else if((arr[start] + arr[end]) < t) {
                    start++;
                } else {
                    end--;
                }
            }
            if(count == 1) {
                break;
            }
            while(i <= (n - 3)) {
                if(arr[i] != arr[i + 1]) {
                    break;
                }
                i++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
	cin>>t;
	while(t--){
    	int n;
    	cin>>n;
    	int arr[n]={0};
    	for(int i=0;i<n;i++)
    		cin>>arr[i];
    	Solution obj;
        if(obj.findTriplets(arr, n))
            cout<<"1"<<endl;
        else 
            cout<<"0"<<endl;
	}
    return 0;
}
// } Driver Code Ends