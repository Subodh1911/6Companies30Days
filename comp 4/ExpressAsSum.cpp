// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    int numOfWays(int n, int k)
    {
        // code here
        // vector<int> a;int i=1;
        // while(pow(i,k)<=n) { a.push_back(pow(i,k)); i++; }
        // int sz = a.size(), sum=0;
        // int dp[sz+1][n+1] = {0};
        // for(i=0;i<=n;i++) { dp[0][i] = 0; }
        // for(i=0;i<=sz;i++) { dp[i][0] = 1; }
        // for(i=1;i<=sz;i++) {
        //     for(int j=1;j<=n;j++) {
        //         dp[i][j] = dp[i-1][j];
        //         if(a[i-1]<=j) { dp[i][j]|=dp[i-1][j-a[i-1]]; }
        //     }
        // }
        // long long cn = 0;
        // int mod = 1e9 + 7;
        // for(i=0;i<=sz;i++) { if(dp[i][n]) { cn++; cn = cn%mod; } }
        // return cn;
        
        long long dp[n+1] = {0};
        dp[0] = dp[1] = 1;
        int mod = 1e9+7;
        int maxLimit = pow(n, 1.0/k);
        for(int i=2;i<= maxLimit;i++){
            int curr = pow(i, k);
            for(int j = n; j >= curr; j--){
                dp[j] = (dp[j]+dp[j-curr])%mod;
            }
        }
        return dp[n];
        
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends