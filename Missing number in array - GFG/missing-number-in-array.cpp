//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;




// } Driver Code Ends
// User function template for C++
#include<bits/stdc++.h>
class Solution{
  public:
    int MissingNumber(vector<int>& array, int n) {
        // Your code goes here
        int array_sum = 0;
        for(int i = 0; i < array.size(); i++) {
            array_sum += array[i];
        }
        int linear_sum = (n * (n + 1)) / 2;
        return linear_sum - array_sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> array(n - 1);
        for (int i = 0; i < n - 1; ++i) cin >> array[i];
        Solution obj;
        cout << obj.MissingNumber(array, n) << "\n";
    }
    return 0;
}
// } Driver Code Ends