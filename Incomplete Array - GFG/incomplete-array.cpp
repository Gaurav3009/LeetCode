//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int countElements(int n, int A[]) {
        if(n == 0 || n == 1) {
            return 0;
        } 
        map<int, int> hashMap;
        int max = INT_MIN, min = INT_MAX;
        for(int i = 0; i < n; i++) {
            max = (max < A[i])?A[i]:max;
            min = (min > A[i])?A[i]:min;
            hashMap[A[i]]++;
        }
        return (max - min - 1) - (hashMap.size() - 2);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        Solution ob;
        cout << ob.countElements(N, A) << "\n";
    }
}
// } Driver Code Ends