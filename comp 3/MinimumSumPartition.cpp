//Recursive Method : include element or not, TC : O(2^n)
/* 
    public:
    int findMin(int a[], int n, int tsum, int cal) {
        if(n==0) { return abs((tsum-cal)-cal); }
        return min(findMin(a,n-1,tsum,cal+a[n-1]), findMin(a,n-1,tsum,cal));
    }
  
    int minDifference(int a[], int n)  { 
	 // Your code goes here
	 int sum = 0;
	 for(int i=0;i<n;i++) { sum+=a[i]; }
	 int ans = findMin(a,n,sum,0);
	 return ans; 
    }
*/ 

//DP Method : TC = O(n*sum) 

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int a[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    for(int i=0;i<n;i++) { sum+=a[i]; }
	    bool dp[n+1][sum+1];
	    for(int i=0;i<=n;i++) { dp[i][0] = true; }
	    for(int i=1;i<=sum;i++) { dp[0][i] = false; }
	    for(int i=1;i<=n;i++) {
	        for(int j=1;j<=sum;j++) { 
	            dp[i][j] = dp[i-1][j];
	            if(a[i-1]<=j) { dp[i][j] = dp[i][j]|dp[i-1][j-a[i-1]]; }
	    } }
	    int diff = INT_MAX;
	    for(int j=sum/2;j>=0;j--) {
	        if(dp[n][j]==true) { diff = min(diff,sum-2*j); }
	    }
	    return diff;
} };


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends