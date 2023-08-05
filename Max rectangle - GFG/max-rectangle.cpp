//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    void getNSL(int arr[], int n, int NSL[]) {
        stack<int> st;
        for(int i = 0 ; i < n; i++) {
            if(st.empty()) {
                NSL[i] = -1;
            } else if(!st.empty() && arr[st.top()] < arr[i]) {
                NSL[i] = st.top();
            } else if(!st.empty() && arr[st.top()] >= arr[i]) {
                while(!st.empty()) {
                    if(arr[st.top()] < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSL[i] = (st.empty())?-1:st.top();
            }
            st.push(i);
        }
    }
    void getNSR(int arr[], int n, int NSR[]) {
        stack<int> st;
        for(int i = n - 1 ; i >= 0; i--) {
            if(st.empty()) {
                NSR[i] = n;
            } else if(!st.empty() && arr[st.top()] < arr[i]) {
                NSR[i] = st.top();
            } else if(!st.empty() && arr[st.top()] >= arr[i]) {
                while(!st.empty()) {
                    if(arr[st.top()] < arr[i]) {
                        break;
                    }
                    st.pop();
                }
                NSR[i] = (st.empty())?n:st.top();
            }
            st.push(i);
        }
    }
    int getMAH(int arr[], int n) {
        int NSL[n] = {};
        int NSR[n] = {};
        getNSL(arr, n, NSL);
        getNSR(arr, n, NSR);
        int maxArea = 0;
        for(int i = 0; i < n; i++) {
            maxArea = max(maxArea, (NSR[i] - NSL[i] - 1) * arr[i]);
        }
        return maxArea;
    }
    int maxArea(int M[MAX][MAX], int n, int m) {
        int maxAr = 0;
        int arr[m] = {};
        for(int i = 0; i < m; i++) {
            arr[i] = M[0][i];
        }
        maxAr = getMAH(arr, m);
        for(int i = 1; i < n; i++) {
            for(int j = 0; j < m; j++) {
                arr[j] = (arr[j] * M[i][j]) + M[i][j];
            }
            maxAr = max(maxAr, getMAH(arr, m));
        }
        return maxAr;
    }
};


//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}

// } Driver Code Ends