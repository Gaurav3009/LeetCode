//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        long long arr[n];
        arr[0] = a[0];
        for(int i = 1; i < n; i++) {
            arr[i] = arr[i - 1] + a[i];
        }
        int right_sum = arr[n - 1], left_sum = 0;
        int f = 0, ind = -1;
        for(int i = 0; i < n; i++) {
            left_sum = arr[i] - a[i];
            right_sum = arr[n - 1] - arr[i];
            if(left_sum == right_sum) {
                f = 1;
                ind = i;
                break;
            }
        }
        if(f == 1) {
            return ind + 1;
        }
        return ind;
    }

};

//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends