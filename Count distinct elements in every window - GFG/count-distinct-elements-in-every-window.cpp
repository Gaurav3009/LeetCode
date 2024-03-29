//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution{
  public:
    vector <int> countDistinct (int arr[], int n, int k)
    {
        map<int, int> hashMap;
        int i = 0, j = 0;
        vector<int> ans;
        while(j < n) {
            hashMap[arr[j]]++;
            if((j - i + 1) < k) {
                j++;
            } else {
                ans.push_back(hashMap.size());
                hashMap[arr[i]]--;
                if(hashMap[arr[i]] == 0) {
                    hashMap.erase(arr[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++) 
        	cin >> a[i];
        Solution obj;
        vector <int> result = obj.countDistinct(a, n, k);
        for (int i : result) 
        	cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends