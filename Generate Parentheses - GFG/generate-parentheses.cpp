//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


// } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    void solve(int n, int o, int c, string op, vector<string> &arr) {
        if((o + c) == (2 * n)) {
            arr.push_back(op);
            return ;
        }
        if(o == c) {
            op += "(";
            solve(n, o + 1, c, op, arr);
            return ;
        }
        if(o == n) {
            op += ")";
            solve(n, o, c + 1, op, arr);
            return ;
        }
        string a, b;
        a = b = op;
        a += "(";
        b += ")";
        solve(n, o + 1, c, a, arr);
        solve(n, o, c + 1, b, arr);
    }
    vector<string> AllParenthesis(int n) {
        vector<string> arr;
        solve(n, 0, 0, "", arr);
        return arr;
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
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 

// } Driver Code Ends