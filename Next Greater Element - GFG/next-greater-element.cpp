//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template for C++ solution

class Solution {
  public:
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        vector<long long> vec;
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                vec.push_back(-1);
            } else if(!st.empty() && st.top() > arr[i]) {
                vec.push_back(st.top());
            } else if(!st.empty() && st.top() <= arr[i]) {
                while(!st.empty()) {
                    if(st.top() > arr[i]) {
                        break;
                    }
                    st.pop();
                }
                vec.push_back((st.empty())?-1:st.top());
            }
            st.push(arr[i]);
        }
        reverse(vec.begin(), vec.end());
        return vec;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        
        int n;
        cin>>n;
        vector<long long> arr(n);
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        Solution ob;
        
        vector <long long> res = ob.nextLargerElement(arr, n);
        for (long long i : res) cout << i << " ";
        cout<<endl;
    }
	return 0;
}

// } Driver Code Ends