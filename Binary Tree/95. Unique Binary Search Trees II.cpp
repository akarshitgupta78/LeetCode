class Solution {
public:
    vector<TreeNode*> solve(int i,int j)
    {
        if(i>j) return {nullptr};
        vector<TreeNode*> ans;
        for(int root=i;root<=j;root++)
        {
            vector<TreeNode*> left = solve(i,root-1);
            vector<TreeNode*> right = solve(root+1,j);
            for (TreeNode* leftTree:left)
                {
                    for (TreeNode* rightTree : right)
                    {
                        TreeNode * node=new TreeNode(root);
                        node->left=leftTree;
                        node->right=rightTree;
                        ans.push_back(node);
                    }
                }
        }
    return ans;
    }
    vector<TreeNode*> generateTrees(int n) 
    {
    return solve(1,n);    
    }
};
