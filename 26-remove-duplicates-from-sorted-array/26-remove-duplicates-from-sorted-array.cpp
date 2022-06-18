class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        if(nums.size() == 0)
        {
            return 0;
        }
        int a = nums[0];
        int count = 1;
        for(int i=1;i<nums.size();)
        {
            if(a != nums[i])
            {
                count++;
                a = nums[i];
                i++;
            }
            else
            {
                nums.erase(nums.begin() + i);
            }
        }
        for(int i = 0; i < nums.size(); i++){
            cout<<nums[i]<<" ";
        }
        return count;
    }
};