class Solution {
public:
    int n;
    unordered_map<int,int> m;
    bool solve(int i,int prev,vector<int> &stones,vector<vector<int>> &dp)
    {
        if(i==n-1) return 1;
        if(dp[i][prev] !=-1) return dp[i][prev];
        for(int j=prev-1;j<=prev+1;j++)
        {
            if (j <= 0) continue;
            int in = stones[i]+j;
            if (m.count(in)) 
            {
                if(solve(m[in],j,stones,dp))return dp[i][prev] = 1;
            }
        }
        return dp[i][prev]=0;
    }
    bool canCross(vector<int>& stones) 
    {
        n=stones.size();
        if(n>1 && stones[1] != 1) return false;
        for (int i = 0;i<n;i++)
            m[stones[i]]=i;
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
     return solve(0,0,stones,dp);
    }
};
