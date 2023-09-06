//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2) {
        int i = 0, j = 0, n1 = array1.size(), n2 = array2.size();
        vector<int> arr;
        while(i < n1 && j < n2) {
            if(array1[i] <= array2[j]) {
                arr.push_back(array1[i]);
                i++;
            } else {
                arr.push_back(array2[j]);
                j++;
            }
        }
        while(i < n1) {
            arr.push_back(array1[i]);
            i++;
        }
        while(j < n2) {
            arr.push_back(array2[j]);
            j++;
        }
        int n = n1 + n2;
        double med = 0;
        if(n & 1) {
            med = arr[n / 2];
        } else {
            med = (double)(arr[n / 2] + arr[(n / 2) - 1]) / 2.0;
        }
        return med;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends