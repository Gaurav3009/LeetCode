class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<double, pair<int, int>>> f;
        double d;
        for(int i = 0 ; i < points.size(); i++){
            d = sqrt(pow(points[i][0], 2) + pow(points[i][1], 2));
            f.push_back({d, {points[i][0], points[i][1]}});
        }
        sort(f.begin(), f.end(), [](pair<double, pair<int, int>> &a, pair<double, pair<int, int>> &b)->bool{
          return a.first < b.first;  
        });
        vector<vector<int>> res;
        for(int i = 0; i < k; i++){
            vector<int> a;
            a.push_back(f[i].second.first);
            a.push_back(f[i].second.second);
            res.push_back(a);
        }
        return res;
    }
};