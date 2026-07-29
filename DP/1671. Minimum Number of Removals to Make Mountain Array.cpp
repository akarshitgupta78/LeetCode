class Solution {
public:
    vector<int> getlis(vector<int>& nums)
    {
        int n = nums.size();
        vector<int> lis(n);
        vector<int> temp;
        for(int i = 0;i<n;i++)
        {
            auto it = lower_bound(temp.begin(), temp.end(), nums[i]);
            int idx = it - temp.begin();
            if(it == temp.end()) temp.push_back(nums[i]);
            else *it = nums[i];
            lis[i] = idx ;
        }
    return lis;
    }
    vector<int> getlds(vector<int>& nums)
    {
        vector<int> rev = nums;
        reverse(rev.begin(), rev.end());
        vector<int> lds= getlis(rev);
        reverse(lds.begin(), lds.end());
        return lds;
    }
    int minimumMountainRemovals(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> lis=getlis(nums),lds=getlds(nums);
        int ans = 0;
        for(int i=1;i<n-1;i++)
        {
            if(lis[i] > 0 && lds[i] > 0)
            {
                ans = max(ans, lis[i]+lds[i]+1);
            }
        }
    return n-ans;
    }
};
