//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    string isPowerof3(int N){
        if(N == 1) {
            return "Yes";
        }
        int f = 0;
        while(N != 1) {
            if(N % 3 != 0) {
                f = 1;
                break;
            }
            N /= 3;
        }
        if(f == 1) {
            return "No";
        }
        return "Yes";
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.isPowerof3(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends