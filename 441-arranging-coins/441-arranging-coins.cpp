class Solution {
public:
    int arrangeCoins(int n) {
        long a = 0, b = 1;
        int count = 0;
        while(a < n){
            a += b;
            b++;
            count++;
        }
        if(a - n > 0){
            return count - 1;
        }
        return count;
        
    //     long arr[n];
    //     arr[0] = 1;
    //     for(int i = 1; i < n; i++){
    //         arr[i] += arr[i - 1] + (i + 1); 
    //     }
    //     int start = 0, mid, end = n - 1, res;
    //     while(start < end){
    //         mid = start + (end - start) / 2;
    //         if(arr[mid] == n){
    //             return mid;
    //         }else if(arr[mid] < n){
    //             start = mid + 1;
    //         }else if(arr[mid] > n){
    //             res = mid;
    //             end = mid - 1;
    //         }
    //     }
    //     return res;
    }
};