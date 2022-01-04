class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int a = str1.length();
        int b = str2.length();
        int c = max(a,b);
        string ans;
        if(a>b) ans = str2; else ans = str1;
        while(1) {
        string t1="", t2 = "";
        int f1 = 0, f2 = 0;
        while(a>=t1.size() && str1!=t1) {
            t1+=ans;
            if(str1==t1) f1 = 1;
        }
        while(b>=t2.size() && str2!=t2) {
            t2+=ans;
            if(t2==str2) f2 = 1;
        }
        if(f1==1 && f2 == 1) { return ans; }
        else { ans=ans.substr(0, ans.size()-1); }
        if(ans=="") { return ans; }
    } }
};