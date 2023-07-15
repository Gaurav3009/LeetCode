//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
#include <iostream>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int merge(vector<int> &arr, int start, int mid, int end) {
        int j = mid + 1, count = 0;
        for(int i = start; i <= mid; i++) {
            while(j <= end && arr[i] > (2LL * arr[j])) {
                j++;
            }
            count += j - (mid + 1);
        }
        vector<int> temp;
        int i = start, k = mid + 1;
        while(i <= mid && k <= end) {
            if(arr[i] <=  arr[k]) {
                temp.push_back(arr[i]);
                i++;
            } else {
                temp.push_back(arr[k]);
                k++;
            }
        }
        while(i <= mid) {
            temp.push_back(arr[i]);
            i++;
        }
        while(k <= end) {
            temp.push_back(arr[k]);
            k++;
        }
        for(int i = start; i <= end; i++) {
            arr[i] = temp[i - start];
        }
        return count;
    }
    int mergeSort(vector<int> &arr, int start, int end) {
        int count = 0;
        if(start >= end) return 0;
        int mid = start + (end - start) / 2;
        count += mergeSort(arr, start, mid);
        count += mergeSort(arr, mid + 1, end);
        count += merge(arr, start, mid, end);
        return count;
    }
    int countRevPairs(int n, vector<int> arr) {
        return mergeSort(arr, 0, n - 1);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countRevPairs(n, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends