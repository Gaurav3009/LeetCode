class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0, n = arr.size() - 1, end = n, mid;
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
};