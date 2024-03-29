//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
   	int corner_digitSum(int n){
   	    int last = n % 10;
   	    int f = 0;
   	    while(n > 9) {
   	        n /= 10;
   	        f = 1;
   	    }
   	    if(f == 0) {
   	        return n;
   	    }
   	    return n + last;
   	}    
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.corner_digitSum(n);
		cout << ans <<"\n";
	}  
	return 0;
}
// } Driver Code Ends