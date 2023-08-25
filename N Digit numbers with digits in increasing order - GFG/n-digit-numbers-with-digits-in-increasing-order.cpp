//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    void solve(int N, int i, int num, vector<int> &arr) {
        if(i == N + 1) {
            arr.push_back(num);
            return;
        }
        int x;
        for(int j = 0; j < 10; j++) {
            if(N == 1 && j == 0) {
                solve(N, i + 1, 0, arr);
                continue;
            }
            x = num;
           if(x % 10 < j) {
                x = (x * 10) + j;
                solve(N , i + 1, x, arr);
           }
        }
        
    }
    vector<int> increasingNumbers(int N) {
        vector<int> arr;
        solve(N, 1, 0, arr);
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
        int N;
        cin>>N;
        Solution ob;
        vector<int> ans = ob.increasingNumbers(N);
        for(auto num : ans){
            cout<< num <<" ";
        }
        cout<<endl;
        
    }
    return 0;
}
// } Driver Code Ends