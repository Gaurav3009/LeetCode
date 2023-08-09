//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) {
        map<int, int> hashMap;
        for(int i = 0; i < n; i++) {
            if(arr[i] > 0) {
                hashMap[arr[i]] = 1;
            } 
        }
        if(hashMap.size() == 0) {
            return 1;
        }
        int x = 1;
        for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
            if(x != it->first) {
                break;
            }
            x++;
        }
        return x;
    }
};

//{ Driver Code Starts.

int missingNumber(int arr[], int n);

int main() { 
    
    //taking testcases
    int t;
    cin>>t;
    while(t--){
        
        //input number n
        int n;
        cin>>n;
        int arr[n];
        
        //adding elements to the array
        for(int i=0; i<n; i++)cin>>arr[i];
        
        Solution ob;
        //calling missingNumber()
        cout<<ob.missingNumber(arr, n)<<endl;
    }
    return 0; 
} 
// } Driver Code Ends