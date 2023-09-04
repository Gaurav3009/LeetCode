//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution{   
public:
    int numbersInRange(int L, int R){
        int cnt = 0;
        for(int i = L; i <= R; i++) {
            int last = i % 10;
            int first = i;
            while(first > 9) {
                first /= 10;
            }
            if(first == last) {
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int L, R;
        cin >> L >> R;
        Solution ob;
        cout << ob.numbersInRange(L, R) << endl;
    }
    return 0; 
} 

// } Driver Code Ends