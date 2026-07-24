class Solution {
public:
    int check(int i,int j,string &s)
    {
        int c=0;
        while(i<j) 
        if(s[i++]!=s[j--]) c++;
        return c;
    }
    int solve(int i,int k,string &s,vector<vector<int>> &dp)
    {
        int n=s.size();
        if(k==1)
        {
           return check(i,n-1,s);
        }
        if(dp[i][k]!=-1) return dp[i][k];
        int ans=INT_MAX;
        for(int j=i;j<=n-k;j++)
        {
            int curr= check(i,j,s);
            int cut =  solve(j+1,k-1,s,dp);
            ans=min(ans,cut+curr);
               
        }
        return dp[i][k] = ans;
    }
    int palindromePartition(string s, int k) 
    {
        int n=s.size();
        vector<vector<int>> dp(n,vector<int> (k+1,-1));
        return solve(0,k,s,dp);
    }
};
