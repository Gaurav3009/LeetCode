//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    void getNSL(vector<int> arr, vector<int> &NSL) {
        stack<int> st;
        int n = arr.size();
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                NSL.push_back(-1);
            } else if(!st.empty() && arr[st.top()] < arr[i]) {
                NSL.push_back(st.top());
            } else if(!st.empty() && arr[st.top()] >= arr[i]) {
                while(!st.empty()) {
                    if(arr[st.top()] < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSL.push_back((st.empty())?-1:st.top());
            }
            st.push(i);
        }
    }
    void getNSR(vector<int> arr, vector<int> &NSR) {
        stack<int> st;
        int n = arr.size();
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                NSR.push_back(n);
            } else if(!st.empty() && arr[st.top()] < arr[i]) {
                NSR.push_back(st.top());
            } else if(!st.empty() && arr[st.top()] >= arr[i]) {
                while(!st.empty()) {
                    if(arr[st.top()] < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSR.push_back((st.empty())?n:st.top());
            }
            st.push(i);
        }
        reverse(NSR.begin(), NSR.end());
    }
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // NSR && NSL
        vector<int> NSL;
        vector<int> NSR;
        getNSL(arr, NSL);
        getNSR(arr, NSR);
        vector<int> ans;
        for(int i = 0; i < arr.size(); i++) {
            if(NSL[i] == -1 && NSR[i] == arr.size()) {
                ans.push_back(-1);
            } else if(NSL[i] == -1 && NSR[i] != arr.size()) {
                ans.push_back(NSR[i]);
            } else if(NSL[i] != -1 && NSR[i] == arr.size()) {
                ans.push_back(NSL[i]);
            } else {
                if((i - NSL[i]) == (NSR[i] - i)) {
                    if(arr[NSL[i]] <= arr[NSR[i]]) {
                        ans.push_back(NSL[i]);
                    } else {
                        ans.push_back(NSR[i]);
                    }
                } else if((i - NSL[i]) < (NSR[i] - i)){
                    ans.push_back(NSL[i]);
                } else {
                    ans.push_back(NSR[i]);
                }
            }
        }
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
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends