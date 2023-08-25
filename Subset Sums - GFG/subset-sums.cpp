//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    void solve(vector<int> arr, int i, vector<int> &ans, vector<int> op) {
        if(i == arr.size()) {
            int sum = 0;
            for(int i = 0; i < op.size(); i++) {
                sum += op[i];
            }
            ans.push_back(sum);
            return;
        }
        vector<int> a = op;
        vector<int> b = op;
        b.push_back(arr[i]);
        solve(arr, i + 1, ans, a);
        solve(arr, i + 1, ans, b);
    }
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        vector<int> a;
        solve(arr, 0, ans, a);
        return ans;
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
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends