//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    void getSubsets(vector<int> A, int i, vector<vector<int>> &arr, vector<int> a) {
        if(i == A.size()) {
            arr.push_back(a);
            return ;
        }
        vector<int> x;
        vector<int> y;
        x = y = a;
        y.push_back(A[i]);
        getSubsets(A, i + 1, arr, x);
        getSubsets(A, i + 1, arr, y);
    }
    vector<vector<int> > subsets(vector<int>& A) {
        vector<vector<int>> arr;
        getSubsets(A, 0, arr, vector<int>());
        sort(arr.begin(), arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n, x;
		cin >> n;

		vector<int> array;
		for (int i = 0; i < n; i++)
		{
			cin >> x;
			array.push_back(x);
		}
        
        
        Solution ob;
		vector<vector<int> > res = ob.subsets(array);

		// Print result
		for (int i = 0; i < res.size(); i++) {
			for (int j = 0; j < res[i].size(); j++)
				cout << res[i][j] << " ";
			cout << endl;
		}

		
	}

	return 0;
}
// } Driver Code Ends