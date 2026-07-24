class Solution {
public:
    int MOD =1e9 +7;
    int dfs(int i,int j,vector<vector<int>> &grid,vector<vector<int>> &dp)
    {
        int m=grid.size(),n=grid[0].size();
        if(i<0 || i>=m || j<0 || j>=n) return 0;  
        if(dp[i][j]!=-1) return dp[i][j];
        int dr[4] ={1,0,-1,0} ,dc[4] = {0,-1,0,1};
        int pick =1;
        for(int d=0;d<4;d++)
        {
            int nr = i + dr[d] , nc = j+dc[d];
            if(nr<0 || nr>=m || nc<0 || nc>=n) continue; 
            if(grid[nr][nc] > grid[i][j]) pick  = (pick + dfs(nr,nc,grid,dp))%MOD;
        }
        return dp[i][j] = pick;
    }
    int countPaths(vector<vector<int>>& grid) 
    {
        int m=grid.size(),n=grid[0].size();
        int ans=0;
        vector<vector<int>> dp(m,vector<int> (n,-1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans = (ans+ dfs(i,j,grid,dp))%MOD;
            }
        }
    return ans;
    }
};
