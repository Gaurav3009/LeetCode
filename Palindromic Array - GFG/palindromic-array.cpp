// { Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


 // } Driver Code Ends
/*Complete the function below*/
bool isPallindrome(int n){
    int s = 0;
    int num = n;
    while(num > 0){
        s = (s * 10) + (num % 10);
        num = num / 10;
    }
    if(n == s){
        return true;
    }
    return false;
}
class Solution {
public:
    int PalinArray(int arr[], int n){
        for(int i = 0;i < n; i++){
            if(!isPallindrome(arr[i])){
                return 0;
            }
        }
        return 1;
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}  // } Driver Code Ends