class Solution {
public:
    int a[31] = {}; 
    int fib(int n) {
        if(n == 0){
            return 0;
        }
        if(n == 1){
            return 1;
        }
        if(a[n] != 0){
            return a[n];
        }
        return a[n] = (fib(n - 1) + fib(n - 2));
    }
};