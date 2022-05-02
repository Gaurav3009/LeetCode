class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size() - 1;
        while(start <= end){
            if(nums[start] % 2 == 0 && nums[end] %2 != 0){
                start++;
                end--;
            }else if(nums[start] % 2 == 0 && nums[end] % 2 == 0){
                start++;
            }else if(nums[start] % 2 != 0 && nums[end] % 2 != 0){
                end--;
            }else if(nums[start]% 2 != 0 && nums[end] % 2 == 0){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
            }
        }
        return nums;
    }
};