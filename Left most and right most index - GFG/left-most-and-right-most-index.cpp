//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    long firstOccurence(vector<long long> arr, long start, long end, long target) {
        long mid, ans = -1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(arr[mid] == target) {
                ans = mid;
                end = mid - 1;
            } else if(arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    long lastOccurence(vector<long long> arr, long start, long end, long target) {
        long mid, ans = -1;
        while(start <= end) {
            mid = start + (end - start) / 2;
            if(arr[mid] == target) {
                ans = mid;
                start = mid + 1;
            } else if(arr[mid] > target) {
                end = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return ans;
    }
    pair<long,long> indexes(vector<long long> v, long long x) {
        return {firstOccurence(v, 0, v.size() - 1, x), lastOccurence(v, 0, v.size() - 1, x)};
    }
};

//{ Driver Code Starts.

int main()
 {
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        vector<long long>v;
        cin>>n;
        for(long long i=0;i<n;i++)
        {
            cin>>k;
            v.push_back(k);
        }
        long long x;
        cin>>x;
        Solution obj;
        pair<long,long> pair = obj.indexes(v, x);
        
        if(pair.first==pair.second and pair.first==-1)
        cout<< -1 <<endl;
        else
        cout<<pair.first<<" "<<pair.second<<endl;

    }
	return 0;
}

// } Driver Code Ends