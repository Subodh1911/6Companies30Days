#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,n) for(int i=0;i<n;i++)

//Quick Select algo
ll selectKth(ll a[], ll n, ll k) {
    if(n<=k) { return 0; }
    ll from = 0, to = n-1;
    while(from<to) {
        ll r = from , w = to;
        ll mid = a[(r+w)/2];
        while(r<w) {
            if(a[r] > mid) {
                ll t=a[r]; a[r]=a[w]; a[w] = t; w--;
            } else { r++; }
        }
        if(a[r]>mid) { r--; }
        if(k<=r) { to = r; } else { from = r+1; }
    }
    return a[k];
}

int main() {
    ll n,k; cin>>n>>k;
    ll a[n]; 
    f(i,n) {
        cin>>a[i];
    }
    cout<<selectKth(a,n,k)<<endl;

    return 0;
}