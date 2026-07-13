class Solution {
public:
    int climbStairs(int n) {
        vector<int>dp(n+1);
        if(n==0 || n==1 ||n==2)
        return n;// if it not then dp[2 ] will overflow when n=1,in that case dp is of 2 size
        dp[0]=0;//only index 0 and 1 so accessing dp[2]will give heap oveflow
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];


    }
};
