class Solution {
public:
    bool isvowel(char ch){
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;
        while(start <= end){
            bool l = isvowel(s[start]);
            bool r = isvowel(s[end]);
            if(l && r){
                char ch = s[start];
                s[start] = s[end];
                s[end] = ch;
                start++;
                end--;
            }else if(!l && r){
                start++;
            }else if(l && !r){
                end--;
            }else{
                start++;
                end--;
            }
        }
        return s;
    }
};