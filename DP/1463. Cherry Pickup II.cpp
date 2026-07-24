class Solution {
public:
    int solve(int i1,int j1,int j2,vector<vector<int>> &grid,vector<vector<vector<int>>> &dp)
    {
        int m=grid.size(),n=grid[0].size();
        if(i1>=m || j1>=n || j2>=n || j1<0 || j2<0) return 0;
        if(i1 == m-1)
        {
            if(j1==j2) return grid[i1][j1];
            return grid[i1][j2] + grid[i1][j1];
        }
        if(dp[i1][j1][j2]!=-1) return dp[i1][j1][j2];
        int curr = grid[i1][j1];
        if(j1 != j2)
            curr += grid[i1][j2];
        int ans=0;
        for(int d1=-1;d1<=1;d1++)
        {
            for(int d2=-1;d2<=1;d2++)
            {
                ans=max(ans,solve(i1+1,j1+d1,j2+d2,grid,dp));
            }
        }
        curr += ans;
        return dp[i1][j1][j2] = curr;
    }
    int cherryPickup(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>> (n,vector<int> (n,-1)));
    return solve(0,0,n-1,grid,dp);
    }
};
