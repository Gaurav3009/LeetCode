class Solution {
public:
    int BinarySearch(vector<int> arr, int start, int end, int target){
        int mid;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(arr[mid] == target){
                return mid;
            }else if(arr[mid] > target){
                end = mid - 1;
            }else if(arr[mid] < target){
                start = mid + 1;
            }
        }
        return -1;
    }
    vector<int> twoSum(vector<int>& numbers, int target) {
        int second;
        vector<int> res(2, -1);
        for(int i = 0; i < numbers.size(); i++){
            second = target - numbers[i];
            if(second >= numbers[i + 1] && second <= numbers[numbers.size() - 1]){
                int ind = BinarySearch(numbers, i + 1, numbers.size() - 1, second);
                if(ind != -1){
                res[0] = i + 1;
                res[1] = ind + 1;
                break;
            }
            }
        }
        return res;
    }
};