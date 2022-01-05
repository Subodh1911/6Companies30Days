// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        int n= nums.size();
        if(n%2==1) { return false; }
        int h[k+1]={0};
        for(int i=0;i<n;i++) { h[nums[i]%k]++; }
        if(h[0]%2==1 && h[0]!=0) { return false; }
        for(int i=1;i<=k/2;i++) {
            if(h[i]!=h[k-i]) { return false; }
        }
        if(k%2==0 && h[k/2]%2!=0 && h[k/2]!=0) { return false; }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends