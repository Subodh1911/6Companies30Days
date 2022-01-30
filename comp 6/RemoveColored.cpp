class Solution {
public:
    bool winnerOfGame(string colors) {
        int n=colors.size();
        if(n<3) { return 0; }
        int bob =0, alice=0;
        for(int i=2;i<n;i++) {
            if(colors[i]==colors[i-1] && colors[i]==colors[i-2]) {
                if(colors[i]=='A') { alice++; }
                else { bob++; }
            }
        }
        if(alice>bob) { return 1; }
        else { return 0; }
    }
};