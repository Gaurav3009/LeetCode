//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    bool check(vector<vector<int>> arr, int i, int j) {
        if(i < 0 || j < 0 || i >= arr.size() || j >= arr[0].size()) {
            return 0;
        }
        if(arr[i][j] == 0) {
            return 1;
        }
        return 0;
        
    }
    // int count = 0;
    // int Count1(vector<vector<int>> matrix, int i, int j) {
    //     if(matrix.size() == 0) {
    //         return 0;
    //     }
    //     if(i < 0 || j < 0 || i >= matrix.size() || j >= matrix[i].size()) {
    //         return 0;
    //     }
    //     int ans = ((Count1(matrix, i - 1, j - 1)) + (Count1(matrix, i - 1, j)) + (Count1(matrix, i - 1, j + 1)) + (Count1(matrix, i, j - 1)) + (Count1(matrix, i, j + 1)) + (Count1(matrix, i + 1, j - 1)) + (Count1(matrix, i + 1, j)) + (Count1(matrix, i + 1, j + 1)));
    //     count = ((ans != 0 &&  ans % 2 == 0)) ? count + 1 : count;
    //     return ((matrix[i][j] % 2 == 0)?1:0);
    // }
    bool isValid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int Count(vector<vector<int> >& matrix) {
        // int count = 0;
        // for(int i = 0; i < matrix.size(); i++) {
        //     for(int j = 0; j < matrix[i].size(); j++) {
        //         if(matrix[i][j] == 1) {
        //             int ans = 0;
        //             if(i - 1 >= 0) {
        //                 ans += check(matrix, i - 1, j);
        //                 if(j - 1 >= 0) {
        //                     ans += check(matrix, i - 1, j - 1);
        //                 }
        //                 if(j + 1 < matrix[i].size()) {
        //                     ans += check(matrix, i - 1, j + 1);
        //                 }
        //             }
        //             if(i + 1 < matrix.size()) {
        //                 ans += check(matrix, i + 1, j);
        //                 if(j - 1 >= 0) {
        //                     ans += check(matrix, i + 1, j - 1);
        //                 }
        //                 if(j + 1 < matrix[i].size()) {
        //                     ans += check(matrix, i + 1, j + 1);
        //                 }
        //             } 
        //             if(j - 1 >= 0) {
        //                 ans += check(matrix, i, j - 1);
        //             }
        //             if(j + 1 < matrix[i].size()) {
        //                 ans += check(matrix, i, j + 1);
        //             }
        //             count = ((ans % 2 == 0 && ans != 0) ? count + 1 : count);
        //         }
        //     }
        // }
        // return count;
        // int c = Count1(matrix, 0, 0);
        // return count;
        int dx[] = { -1 , 1 ,  0  , 0 , -1  , -1  ,  1  , 1  };
        int dy[] = { 0  , 0 , -1  , 1 , -1  ,  1  , -1  , 1  };
        
        int ans = 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        auto valid = [&](int x, int y) -> bool {
            if(x < 0 or x >= n or y < 0 or y >= m)
                return 0;
                
            return matrix[x][y] == 0;
        };
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(matrix[i][j]){
                    int cur = 0;
                    for(int k = 0; k < 8; k++){
                        int x = i + dx[k];
                        int y = j + dy[k];
                        
                        cur += valid(x, y);
                    }
                    
                    if(cur)
                        ans += !(cur & 1);
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends