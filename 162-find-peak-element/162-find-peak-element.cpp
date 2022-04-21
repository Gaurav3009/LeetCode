class Solution {
public:
    int find_Peak(vector<int> arr, int start, int end){
        int mid, n = end, res;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(mid > 0 && mid < n){
                if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]){
                    return mid;
                }else if(arr[mid - 1] > arr[mid + 1]){
                    end = mid - 1;
                }else if(arr[mid + 1] >= arr[mid - 1]){
                    start = mid + 1;
                }
            }else{
                if(mid == 0){
                    if(arr[mid] > arr[mid + 1]){
                        return mid;
                    }else if(arr[mid + 1] > arr[mid]){
                        return mid + 1;
                    }
                }
                if(mid == n){
                    if(arr[mid] > arr[mid - 1]){
                        return mid;
                    }else if(arr[mid - 1] > arr[mid]){
                        return mid - 1;
                    }
                }
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1){
            return 0;
        }
        return find_Peak(nums, 0, nums.size() - 1);
    }
};