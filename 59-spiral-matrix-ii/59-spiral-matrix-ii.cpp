class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        int arr[n][n];
        int num = 1;
        while(num <= (n * n)){
            int l = left;
            while(l <= right){
                arr[top][l++] = num;
                num++;
            }
            top++;
            int t = top;
            while(t <= bottom){
                arr[t++][right] = num;
                num++;
            }
            right--;
            int r = right;
            while(r >= left){
                arr[bottom][r--] = num;
                num++;
            }
            bottom--;
            int b = bottom;
            while(b >= top){
                arr[b--][left] = num;
                num++;
            }
            left++;
        }
        vector<vector<int>>res;
        for(int i = 0;i<n;i++){
            vector<int> a;
            for(int j = 0;j<n;j++){
                a.push_back(arr[i][j]);
            }
            res.push_back(a);
        }
        return res;
        }
};