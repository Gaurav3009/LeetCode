//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> topK(vector<int>& nums, int k) {
        auto cmp = [](pair<int, int> a,pair<int, int> b) {
            if(a.first > b.first) {
                return true;
            } else if(a.first < b.first){
                return false;
            } else {
                if(a.second > b.second) {
                    return true;
                } else {
                    return false;
                }
            }
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> minHeap(cmp);
        map<int, int>hashMap;
        for(int i = 0; i < nums.size(); i++) {
            hashMap[nums[i]]++;
        }
        for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
            minHeap.push({it->second, it->first});
            if(minHeap.size() > k) {
                minHeap.pop();
            }
        }
        vector<int> ans;
        while(!minHeap.empty()) {
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (auto &i : nums) cin >> i;
        int k;
        cin >> k;
        Solution obj;
        vector<int> ans = obj.topK(nums, k);
        for (auto i : ans) cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends