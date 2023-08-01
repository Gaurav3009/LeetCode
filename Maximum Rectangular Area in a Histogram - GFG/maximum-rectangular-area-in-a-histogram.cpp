//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find largest rectangular area possible in a given histogram.
    void getNSL(long long arr[], int n, vector<int> &NSL) {
        stack<int> st;
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
    void getNSR(long long arr[], int n, vector<int> &NSR) {
        stack<int> st;
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
    long long getMaxArea(long long arr[], int n)
    {
        // Get NSL and NSR for every index in array and use the below formulae to find the maximum possible are 
        // for every index and return the maximum among them. 
        // area[i] = (NSR[i] - NSL[i] - 1) * arr[i]
        vector<int> NSL;
        vector<int> NSR;
        getNSL(arr, n, NSL);
        getNSR(arr, n, NSR);
        long long area = 0, maxArea = 0;
        for(int i = 0; i < n; i++) {
            area = (NSR[i] - NSL[i] - 1) * arr[i];
            maxArea = max(area, maxArea);
        }
        return maxArea;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends