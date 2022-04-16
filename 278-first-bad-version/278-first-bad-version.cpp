// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int start = 1, end = n, mid;
        int ans = 1;
        while(start <= end){
            mid = start + (end - start) / 2;
            if(!isBadVersion(mid)){
                start = mid + 1;
            }else{
                ans = mid;
                end = mid - 1;
            }
        }
        return ans;
    }
};