class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 0, mx = piles[0];
        for(int i=1;i<piles.size();i++) { mx = max(mx,piles[i]); }
        while(l<mx) {
            int mid = (l+mx)/2;
            int hs = 0;
            for(int i=0;i<piles.size();i++) {
               if(mid>0) hs+= piles[i]/mid + (piles[i]%mid!=0);
            }
            if(hs<=h) { mx=mid; } else { l = mid+1; }
        }
        if(mx==0) return 1;
        return mx;
    }
};