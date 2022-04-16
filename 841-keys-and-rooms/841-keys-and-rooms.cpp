class Solution {
public:
    void depth_first_search(int vis[], int i, vector<vector<int>> rooms){
        vis[i] = 1;
        for(int j = 0; j < rooms[i].size(); j++){
            if(vis[rooms[i][j]] != 1){
                depth_first_search(vis, rooms[i][j], rooms);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        if(n == 0){
            return false;
        }
        int vis[n];
        memset(vis, 0, sizeof(vis));
        depth_first_search(vis, 0, rooms);
        for(int i = 0; i < n; i++){
            cout<<i<<" "<<vis[i]<<endl;
            if(vis[i] == 0){
                return false;
            }
        }
        return true;
    }
};