class Solution {
public:
    bool detectCapitalUse(string word) {
        int count = 0;
        int ind = -1;
        int i = 0;
        int n = word.length();
        while(i < n){
            if(word[i] >= 'A' && word[i] <= 'Z'){
                count++;
                ind = i;
            }
            i++;
        }
        if(count == 0 || count == n || (count == 1 && ind == 0)){
            return true;
        }
        return false;
    }
};