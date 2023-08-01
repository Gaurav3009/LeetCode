//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    deque<char> dq;
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] == '{') {
            if(!dq.empty() && dq.back() == '}') {
                count++;
                dq.pop_back();
                dq.push_back('{');
            }
            dq.push_back(s[i]);
        } else {
            if(!dq.empty() && dq.back() == '{' && s[i] == '}') {
                dq.pop_back();
            } else if(!dq.empty() && dq.back() == '}' && s[i] == '}') {
                dq.pop_back();
                count++;
            } else {
                dq.push_back(s[i]);
            }
        }
    }
    if(dq.empty()) {
        return count;
    }
    if(dq.size() % 2 != 0) {
        return -1;
    }
    return count + dq.size() / 2;
    // int count = 0;
    // while(!dq.empty()) {
    //     if(dq.front() == '}') {
    //         count++;
    //     }
    //     if(dq.back() == '{') {
    //         count++;
    //     }
    //     dq.pop_front();
    //     dq.pop_back();
    // }
    return count;
}