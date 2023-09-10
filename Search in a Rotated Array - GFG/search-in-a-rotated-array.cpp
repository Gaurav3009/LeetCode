//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int getPivot(int arr[], int start, int end) {
        int mid, prev, next, n = (end - start + 1);
        while(start <= end) {
            mid = start + (end - start) / 2;
            next = (mid + 1) % n;
            prev = (mid - 1 + n) % n;
            if(arr[mid] <= arr[prev] && arr[mid] <= arr[next]) {
                return mid;
            } else if(arr[mid] >= arr[start]) {
                if(arr[end] < arr[start]) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            } else {
                end = mid - 1;
            }
        }
        return 0;
    }
    int binarySearch(int arr[], int start, int end, int target) {
        int mid;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(arr[mid] == target) {
                return mid;
            } else if(arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return -1;
    }
    int search(int arr[], int l, int h, int key){
        int pivot = getPivot(arr, l, h);
        if(arr[pivot] == key) {
            return pivot;
        }
        int a = binarySearch(arr, l, pivot - 1, key);
        if(a != -1) {
            return a;
        }
        int b = binarySearch(arr, pivot + 1, h, key);
        return b;
    }
};

//{ Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}
// } Driver Code Ends