//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string removePair(string s) {
        // Stack problem
        stack<char> st;
        for(int i = 0; i < s.length(); i++) {
            if(st.empty() || st.top() != s[i]) {
                st.push(s[i]);
            } else if(!st.empty() && st.top() == s[i]) {
                st.pop();
            }
        }
        if(st.empty()) {
            return "-1";
        }
        string str = "";
        while(!st.empty()) {
            str.insert(str.begin(), st.top());
            st.pop();
        }
        return str;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s; 
        cin>>s;
        
        Solution obj;
        string res = obj.removePair(s);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends