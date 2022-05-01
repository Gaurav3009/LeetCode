class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int len1 = s.length(), len2 = t.length();
        string a = "", b = "";
        for(int i = 0; i < len1; i++){
            if(s[i] != '#'){
                a.push_back(s[i]);
            }else{
                if(a.length() != 0){
                    a.pop_back();
                }
            }
        }
        for(int i = 0; i < len2; i++){
            if(t[i] != '#'){
                b.push_back(t[i]);
            }else{
                if(b.length() != 0){
                    b.pop_back();
                }
            }
        }
        cout<<a<<" "<<b<<endl;
        if(a.compare(b) == 0){
            return true;
        }
        return false;
    }
};