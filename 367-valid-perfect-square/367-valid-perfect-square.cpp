class Solution {
public:
    bool isPerfectSquare(int num) {
        double val = sqrt(num);
        return (val == (int)val)?true:false;
    }
};