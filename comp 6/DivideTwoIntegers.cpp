class Solution {
public:
    // int divide(int dividend, int divisor) {
    //     if(divisor==1) { return dividend; }
    //     if(divisor==-1) { return dividend == INT_MIN ? INT_MAX : 0-dividend; }
    //     if(divisor==dividend) { return 1; }
    //     int a = abs(dividend), b = abs(divisor);
    //     if(a==b && (dividend==-divisor)) { return -1; }
    //     if(a<b) { return 0; }
    //     long long dp[32][2]={0}; int cn=0;
    //     long long sum=b; int quo = 1;
    //     while(sum<a) {
    //         dp[cn][0] = sum;
    //         dp[cn][1] = quo;
    //         sum+=sum; quo+=quo;
    //         cn++;
    //     }
    //     while(dp[cn-1][0]<a) {
    //         dp[cn-1][0]+=dp[0][0];
    //         dp[cn-1][1]++;
    //     }
    //     int ans = dp[cn-1][1]-1;
    //     if((divisor>0 && dividend>0) ||(divisor<0 && dividend<0)) { return ans; }
    //     if((divisor>0 && dividend<0) ||(divisor<0 && dividend>0)) { return -ans; }
    //     return ans;
    // }
    
    int divide(int dividend, int divisor) {
        if(dividend == 0) return 0;
        if(divisor == 1) return dividend;
        if(divisor == -1) return dividend == INT_MIN ? INT_MAX : 0 - dividend;
        bool neg = (dividend < 0) ^ (divisor < 0);
        int count = 0;
        long long a = abs(dividend);
        long long b = abs(divisor);
        int ct = 1;
        
        while(b <= a){
            count += ct;
            a = a-b;
            b = b<<1;
            ct = ct<<1;
        }
        divisor = abs(divisor);
        while(divisor <= a){
            count++;
            a -= divisor;
        }
        return neg ? 0 - count : count;
    }
};