class Solution {
public:   
    int helper(vector<int>& a, int n, int d, int sum) {
        int m=0, cp = 0;
        for(int i=0;i<n;i++) {
            if(cp+a[i]<=sum) { cp+=a[i]; }
            else { m++; cp = a[i]; }
        }
        return m+1;
    }
  
    int shipWithinDays(vector<int>& a, int d) {
        // code here
        int n = a.size();
        int mx = a[0], sum=a[0];
        for(int i=0;i<n;i++) {
            mx = max(mx,a[i]);
            sum+=a[i];
        }
        int l = mx, r = sum;
        while(l<r) {
            int mid = (l+r)/2;
            if(helper(a,n,d,mid)<=d) { r = mid; }
            else { l = mid+1; }
        }
        return r;
    }
};