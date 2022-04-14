class Solution {
public:
    void breadth_first_search(int i, int vis[], vector<int> e[], int n){
        vis[i] = 1;
        int count = 1;
        queue<int> q;
        q.push(i);
        int k;
        while(!q.empty()){
            k = q.front();
            q.pop();
            for(int j = 0; j < e[k].size(); j++){
                if(vis[e[k][j]] != 1){
                    q.push(e[k][j]);
                    vis[e[k][j]] = 1;
                    count++;
                }
            }
        }
    }
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // vector<int> e[n];
        // for(int i = 0; i < edges.size(); i++){
        //     e[edges[i][0]].push_back(edges[i][1]);
        // }
        // int vis[n];
        // vector<int> res;
        // for(int i = 0; i < n; i++){
        //     if(vis[i] != 1){
        //         breadth_first_search(i, vis, e, n);                                                       res.push_back(i);
        //     }
        // }
        // return res;
         vector<int> inDegree(n,0);
        vector<int> ans;
        for(int i=0;i<edges.size();i++)
            inDegree[edges[i][1]]++;
        for(int i=0;i<n;i++)
            if(inDegree[i]==0)
                ans.push_back(i);
        return ans;
    }
};