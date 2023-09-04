//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int getSum(int N) {
        int sum = 0;
        while(N) {
            sum += N % 10;
            N /= 10;
        }
        return sum;
    }
    int repeatedSumOfDigits(int N){
        while(N > 9) {
            N = getSum(N);
        }
        return N;
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
        cout << ob.repeatedSumOfDigits(N) << endl;
    }
    return 0; 
} 
// } Driver Code Ends