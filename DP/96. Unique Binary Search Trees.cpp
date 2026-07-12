class Solution {
public:
    int solve(int i,vector<int> &dp)
    {
        if(i==0 || i==1) return 1;
        if(dp[i]!=-1) return dp[i];
        int ans = 0;
        for(int j = 1;j<=i;j++)
        {
            int left = solve(j-1,dp);
            int right = solve(i-j,dp);
            ans += left*right;
        }
    return dp[i] = ans;

    }
    int numTrees(int n) 
    {
        vector<int> dp(n+1,0);
        dp[0]=1,dp[1]=1;
        int ans = 0;
        for (int i = 2;i<=n;i++)
        {
            int ans = 0;
            for (int j = 1;j<=i;j++)
            {
                ans += dp[j- 1] * dp[i-j];
                dp[i] =ans;
            }
        }
    return dp[n];
    }
};
