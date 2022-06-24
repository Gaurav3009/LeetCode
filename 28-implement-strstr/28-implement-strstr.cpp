class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1, l2, count = 0;
        l1 = haystack.length();
        l2 = needle.length();
        if((l2 > l1) || ((l1 == l2) && (haystack.compare(needle)<0))){
            return -1;
        }else if(haystack.compare(needle) == 0){
            return 0;
        }else{
            for(int i = 0; i <= l1 - l2; i++){
                if(haystack[i] == needle[0]){
                    for(int j = 0; j < l2; j++){
                        if(haystack[i + j] == needle[j]){
                            count++;
                        }else{
                            break;
                        }
                    }
                    if(count == l2){
                        return i;
                    }
                    count = 0;
                }
            }
        }
        return -1;
    }
};