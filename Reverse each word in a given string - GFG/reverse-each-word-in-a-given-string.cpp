//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s) {
        stack<char> st;
        int x = 0;
        s.push_back('.');
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '.') {
                while(!st.empty()) {
                    s[x] = st.top();
                    st.pop();
                    x++;
                }
                x = i + 1;
            } else {
                st.push(s[i]);
            }
        }
        s.erase(s.end() - 1);
        return s;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends