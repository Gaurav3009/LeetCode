//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) {
        string o = "", word = "";
        s += ".";
        for(int i = 0; i < s.length(); i++) {
            if(s[i] != '.') {
                word.push_back(s[i]);
            } else {
                o = word + "." + o;
                word = "";
            }
        }
        o = o.substr(0, o.length() - 1);
        return o;
    }
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends