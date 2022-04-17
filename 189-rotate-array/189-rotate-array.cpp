class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if(k >= nums.size()){
            k = k % nums.size();
        }
        vector<int> a;
        int n = nums.size();
        for(int i = n - k; i < n; i++){
            a.push_back(nums[i]);
        }
        int ind = n - 1;
        for(int i = n - k - 1; i >=0 ; i--){
            nums[ind] = nums[i];
            ind--;
        }
        for(int i = k - 1; i >= 0; i--){
            nums[ind] = a[i];
            ind--;
        }
    }
};