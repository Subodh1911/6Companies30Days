// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 


 // } Driver Code Ends
//User function Template for C++

class Solution
{
  public:
    int kvowelwords(int n, int k) {
        // Write Your Code here
        // if(k==0) { return pow(21,n); }
        // int sum=0;
        // for(int i=0;i<=k;i++) {
        //     sum+=pow(21,n-i)*pow(5,i)*(n-i);
        // }
        // return sum;
        
        vector<vector<long long>>dp(n+1,vector<long long>(k+1));
        int m = 1e9+7;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=k;j++) {
                if(i==0) { dp[i][j]=1; }
                else{
                    dp[i][j]=dp[i-1][k]*21%m;
                    if(j>0){ dp[i][j]=(dp[i][j]+dp[i-1][j-1]*5%m)%m; }
                }
            }
        }
        return dp[n][k];
    }
};


// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;int K;
        cin >>N>>K;
        
        Solution ob;
        int ans = ob.kvowelwords(N,K);
        cout << ans << endl;
    }
    return 0;
}  // } Driver Code Ends