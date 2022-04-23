class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0, mid, n, end;
        n = nums.size() - 1;
        end = n;
        while(start < end - 1){
            mid = start + (end - start) / 2;
            if(nums[start] == nums[end]){
                end--;
            }else if(nums[mid] <= nums[end]){
                end = mid;
            }else{
                start = mid;
            }
        }
        return min(nums[start], nums[end]);
    }
};