class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string str, res = "";
        while(ss.rdbuf()->in_avail() != 0){
            getline(ss, str, ' ');
            reverse(str.begin(), str.end());
            res.append(str + " ");
        }
        res.pop_back();
        return res;
    }
};