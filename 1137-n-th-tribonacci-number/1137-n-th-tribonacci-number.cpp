class Solution {
public:
    int arr[38];
    int solve(int n){
        if(n <= 2){
            return arr[n];
        }
        if(arr[n] != -1){
            return arr[n];
        }
        return arr[n] = solve(n - 1) + solve(n - 2) + solve(n - 3);
    }
    int tribonacci(int n) {
        memset(arr, -1, sizeof(arr));
        arr[0] = 0;
        arr[1] = 1;
        arr[2] = 1;
        return solve(n);
    }
};