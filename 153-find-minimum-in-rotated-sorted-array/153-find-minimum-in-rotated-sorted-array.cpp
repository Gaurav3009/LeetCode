class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        if(n == 1 || arr[0] < arr[n - 1]){
            return arr[0];
        }
        int start = 0, end = n - 1, mid;
        while(start < end){
            mid = start + (end - start) / 2;
            if(arr[mid] >= arr[0]){
                start = mid + 1;
            }else{
                end = mid;
            }
        }
        return arr[start];
    }
};