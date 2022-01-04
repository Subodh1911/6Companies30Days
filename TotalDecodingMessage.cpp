// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    if(str.size()==0 || str[0]=='0') return 0;
		    if(str.size()==1) { return 1; }
		    int n = str.size();
		    int mod = 1e9 + 7;
		    int a[n+1]; a[0] = 1; a[1] = 1;
		    for(int i=2;i<=str.size();i++) {
		        a[i] = 0;
		        int val = (str[i-2]-'0')*10 + (str[i-1]-'0');
		        if(str[i-1]>'0') { a[i] = a[i-1]; }
		        if(val>9 && val<27) { a[i] = (a[i] + a[i-2])%mod; }
		    }
		    return a[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends