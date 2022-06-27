class Solution {
public:
    string count(string s){
        if(s.length() == 1){
            return "11";
        }
        string ss = "";
        int c = 1;
        char ch = s[0];
        for(int i = 1; i < s.length(); i++){
            if(ch == s[i]){
                c++;
            }
            if((i == s.length() - 1) || (ch != s[i])){
                ss = ss + to_string(c);
                ss.push_back(ch);
                ch = s[i];
                c = 1;
            }
        }
        if(s[s.length() - 1] != s[s.length() - 2]){
            ss.push_back('1');
            ss.push_back(s[s.length() - 1]);
        }
        return ss;
    }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string x = "1";
        for(int i = 2; i <= n; i++){
            x = count(x);
            cout<<x<<" ";
        }
        return x;
    }
};