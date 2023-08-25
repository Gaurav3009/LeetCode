//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    void solve(int from, int to, int aux, int N, long long &ans) {
        if(N == 1) {
            ans++;
            cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
            return ;
        }
        solve(from, aux, to, N - 1, ans);
        ans++;
        cout<<"move disk "<<N<<" from rod "<<from<<" to rod "<<to<<endl;
        solve(aux, to, from, N - 1, ans);
        
    }
    long long toh(int N, int from, int to, int aux) {
        long long ans = 0;
        solve(from, to, aux, N, ans);
        return ans;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends