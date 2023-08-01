//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    /*You are required to complete this method */
    void getNSL(int arr[], int n, vector<int> &NSL) {
        stack<int> st;
        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                NSL.push_back(0);
            } else if(!st.empty() && st.top() < arr[i]) {
                NSL.push_back(st.top());
            } else if(!st.empty() && st.top() >= arr[i]) {
                while(!st.empty()) {
                    if(st.top() < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSL.push_back((st.empty())?0:st.top());
            }
            st.push(arr[i]);
        }
    }
    void getNSR(int arr[], int n, vector<int> &NSR) {
        stack<int> st;
        for(int i = n - 1; i >= 0; i--) {
            if(st.empty()) {
                NSR.push_back(0);
            } else if(!st.empty() && st.top() < arr[i]) {
                NSR.push_back(st.top());
            } else if(!st.empty() && st.top() >= arr[i]) {
                while(!st.empty()) {
                    if(st.top() < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSR.push_back((st.empty())?0:st.top());
            }
            st.push(arr[i]);
        }
        reverse(NSR.begin(), NSR.end());
    }
    int findMaxDiff(int A[], int n)
    {
      vector<int> NSL;
      vector<int> NSR;
      getNSL(A, n, NSL);
      getNSR(A, n , NSR);
      int maxDiff = -1;
      for(int i = 0; i < n; i++) {
          maxDiff = max(maxDiff, abs(NSL[i] - NSR[i]));
      }
      return maxDiff;
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
   	int a[n];
   	for(int i=0;i<n;i++)
   	cin>>a[i];
   	Solution ob;
   	cout<<ob.findMaxDiff(a,n)<<endl;
   }
    return 0;
}



// } Driver Code Ends