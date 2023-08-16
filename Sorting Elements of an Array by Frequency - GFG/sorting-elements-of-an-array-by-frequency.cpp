//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(int arr[],int n) {
        auto cmp = [](pair<int, int> a, pair<int, int> b) {
            if(a.first > b.first) {
                return false;
            } else if(a.first < b.first) {
                return true;
            } else {
                if(a.second < b.second) {
                    return false;
                } else {
                    return true;
                }
            }
        };
        priority_queue<pair<int,int>, vector<pair<int, int>>, decltype(cmp)> maxHeap(cmp);
        map<int,int> hashMap;
        for(int i = 0; i < n; i++) {
            hashMap[arr[i]]++;
        }
        for(auto it = hashMap.begin(); it != hashMap.end(); it++) {
            maxHeap.push({it->second, it->first});
        }
        vector<int> ans;
        while(!maxHeap.empty()) {
            for(int i = 1; i <= maxHeap.top().first; i++) {
                ans.push_back(maxHeap.top().second);
            }
            maxHeap.pop();
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	
	
	int t;
	cin >> t;
	
	
	while(t--){
	    
	    
	    int n;
	    cin >> n;
	    
	    int a[n+1];
	    
	    for(int i = 0;i<n;i++){
	        cin >> a[i];
	    }
	    Solution obj;
	    vector<int> v;
	    v = obj.sortByFreq(a,n);
	    for(int i:v)
	        cout<<i<<" ";
	    cout << endl;
	}
	
	return 0;
}


// } Driver Code Ends