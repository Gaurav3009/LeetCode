class Solution {
public:
    bool isPerfectSquare(int num) {
        double val = sqrt(num);
        int _val = val;
        if(_val == val){
            return true;
        }
        return false;
    }
};