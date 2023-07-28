//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        int i = 0, maxLength = 0, sum = 0;
        map<int, int> hashMap;
        for(int i = 0; i < N; i++) {
            sum += A[i];
            if(sum == K) {
                maxLength = i + 1;
            }
            if(hashMap.find(sum) == hashMap.end()) {
                hashMap[sum] = i;
            }
            if(hashMap.find(sum - K) != hashMap.end()) {
                if(maxLength < (i - hashMap[sum - K])) {
                    maxLength = i - hashMap[sum - K];
                }
            }
        }
        // Only work for positive numbers
        // while(j < N) {
        //     sum += A[j];
        //     if(sum < K) {
        //         j++;
        //     } else if(sum == K) {
        //         maxLength = max(maxLength, (j - i + 1));
        //         j++;
        //     } else {
        //         while(sum > K) {
        //             sum -= A[i];
        //             i++;
        //         }
        //         j++;
        //     }
        // }
        return maxLength;
    } 

};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends