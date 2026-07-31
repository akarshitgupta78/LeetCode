class Solution {
public:
    TreeNode* solve(vector<int>& nums, int l, int r) 
    {
        if(l>r) return nullptr;
        int in=l;
        for (int i = l;i<=r;i++) 
        {
            if (nums[i]>nums[in]) in = i;
        }
        TreeNode* root = new TreeNode(nums[in]);
        root->left = solve(nums,l,in-1);
        root->right = solve(nums,in+1,r);
    return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) 
    {
        int n=nums.size();
    return solve(nums,0,n-1);
    }
};
