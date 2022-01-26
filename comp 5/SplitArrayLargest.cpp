class Solution {
public:
    int helper(vector<int>& a, int n, int part) {
        int m=0;
        int sum=0;
        for(int i=0;i<n;i++) {
            if(sum+a[i]<=part) { sum+=a[i]; }
            else { m++; sum = a[i]; }
        }
        return m+1;
    } 
    
    int splitArray(vector<int>& a, int m) {
        int sum=a[0], mx = a[0], n=a.size();
        for(int i=1;i<n;i++) {
            sum+=a[i];
            mx = max(mx,a[i]);
        }
        int l = mx, r = sum;
        int mn = 0;
        while(l<=r) {
            int mid = (l+r)/2;
            if(helper(a,n,mid)<=m) { r=mid-1; mn = mid; }
            else { l = mid+1; }
        }
        return mn;
    }
};