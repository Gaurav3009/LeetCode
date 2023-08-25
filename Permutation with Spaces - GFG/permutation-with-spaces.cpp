//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void solve(string s, string op, int i, vector<string> &arr) {
        if(i == s.length() - 1) {
            // if(op[op.length() - 1] == ' ') {
            //     op = op.substr(0, op.length() - 1);
            // }
            op.push_back(s[i]);
            arr.push_back(op);
            return ;
        }
        string a, b;
        a = b = op;
        a.push_back(s[i]);
        b.push_back(s[i]);
        b += " ";
        solve(s, b, i + 1, arr);
        solve(s, a, i + 1, arr);
    }
    vector<string> permutation(string S){
       vector<string> arr;
       solve(S, "", 0, arr);
       return arr;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends