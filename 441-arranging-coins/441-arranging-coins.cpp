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
    }
};