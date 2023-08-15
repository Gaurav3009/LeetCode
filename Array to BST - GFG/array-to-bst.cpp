//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    // We will solve this using divide and conquer
    void getPreorder(vector<int> nums,int low, int high, vector<int> &pre) {
        if(low <= high) {
            int mid = (low + high) / 2;
            pre.push_back(nums[mid]);
            getPreorder(nums, low, mid - 1, pre);
            getPreorder(nums, mid + 1, high, pre);
        }
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        vector<int> pre;
        getPreorder(nums, 0, nums.size() - 1, pre);
        return pre; 
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends