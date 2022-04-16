class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0, end = n - 1, mid;
        string s = " ";
        bool f = false;
        while(start <= end){
            mid = start + (end - start)/2;
            if(nums[mid] == target){
                f = true;
                break;
            }else if(nums[mid] > target){
                end = mid - 1;
                s = "end";
            }else if(nums[mid] < target){
                start = mid  +1;
                s = "start";
            }
        }
        if(f){
            return mid;
        }else{
            if(s == "start"){
                return start;
            }else if(s == "end"){
                return end + 1;
            }
        }
        return 0;
    }
};