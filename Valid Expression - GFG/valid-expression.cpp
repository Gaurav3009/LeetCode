//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
bool valid(string str);
int main()
{
    int t;
    cin>>t;
    cin.ignore();
    while(t--)
    {
        string str;
        getline(cin,str);
        cout<<valid(str)<<endl;
    }
    return 0;
}
// } Driver Code Ends


bool valid(string s)
{
    stack<char> st;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '{' || s[i] == '(' || s[i] == '[') {
            st.push(s[i]);
        } else {
            if(st.empty()) {
                return false;
            }
            if((st.top() == '(' && s[i] == ')') || (st.top() == '{' && s[i] == '}') || (st.top() == '[' && s[i] == ']')) {
                st.pop();
            } else {
                return false;
            }
        }
    }
    if(st.empty()) {
        return true;
    }
    return false;
}