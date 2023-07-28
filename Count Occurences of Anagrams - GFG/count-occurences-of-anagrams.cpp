//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    map<char, int> hashMap;
	    int n, m;
	    n = txt.length();
	    m = pat.length();
	    for(int i = 0; i < m; i++) {
	        hashMap[pat[i]]++;
	    }
	    int count = hashMap.size();
	    int res = 0, i = 0, j = 0;
	    while(j < n) {
	        if(hashMap.find(txt[j]) != hashMap.end()) {
	            hashMap[txt[j]]--;
	            if(hashMap[txt[j]] == 0) {
	                count--;
	            }
	        }
	        if((j - i + 1) < m) {
	            j++;
	        } else {
	            if(count == 0) {
	                res++;
	            }
	            j++;
	            if(hashMap.find(txt[i]) != hashMap.end()) {
	                hashMap[txt[i]]++;
	                if(hashMap[txt[i]] == 1) {
	                    count++;
	                }
	            }
	            i++;
	        }
	    }
	    return res;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends