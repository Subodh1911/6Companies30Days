// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
    
    int solve(vector<int>& a,vector<vector<int>>dp, int i, int j) {
        if(i==j) { return dp[i][j]=a[i]; }
        if(i>j) { return dp[i][j]=0; }
        if(dp[i][j]!=-1) { return dp[i][j]; }
        int l = a[i] + min(solve(a,dp,i+2,j),solve(a,dp,i+1,j-1));
        int r = a[j] + min(solve(a,dp,i+1,j-1),solve(a,dp,i,j-2));
        return dp[i][j]=max(l,r);
    }
    
public:
    

    int maxCoins(vector<int>&a,int n)
    {
	    //Write your code here
	    vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solve(a,dp,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends