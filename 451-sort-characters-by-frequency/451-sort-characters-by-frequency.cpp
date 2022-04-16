class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        // cout<<s<<endl;
        vector<pair<char, int>> hash;
        int count = 0;
        char prev = s[0];
        for(int i = 0; i < s.length(); i++){
            if(s[i] == prev){
                count++;
            }
            if(s[i] != prev){
                hash.push_back({prev, count});
                count = 1;
                prev = s[i];
            }
        }
        hash.push_back({prev, count});
        sort(hash.begin(), hash.end(), [](pair<char, int> &a, pair<char, int> &b)->bool{
            return a.second > b.second;
        });
        // cout<<hash.size()<<endl;
        string res = "";
        for(int i = 0; i < hash.size(); i++){
            for(int j = 1; j <= hash[i].second; j++){
                res.push_back(hash[i].first);
            }
        }
        return res;
    }
};