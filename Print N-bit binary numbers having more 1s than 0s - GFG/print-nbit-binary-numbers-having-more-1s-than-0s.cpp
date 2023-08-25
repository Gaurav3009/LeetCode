//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(int N, string num, int o, int z, vector<string> &arr) {
        if(o + z == N) {
            arr.push_back(num);
            return;
        }
        if(o == z) {
            num += "1";
            solve(N, num, o + 1, z, arr);
            return ;
        }
        string a, b;
        a = b = num;
        a += "0";
        b += "1";
        solve(N, b, o + 1, z, arr);
        solve(N, a, o, z + 1, arr);
    }
	vector<string> NBitBinary(int N) {
	    vector<string> arr;
	    solve(N, "", 0, 0, arr);
	    return arr;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends