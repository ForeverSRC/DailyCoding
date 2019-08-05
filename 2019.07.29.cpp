/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int distributeCoins(TreeNode* root) 
    {
        int ans=0;
        dfs(root,ans);
        return ans;
    }
    
    int dfs(TreeNode* root,int& ans)
    {
        if(!root)
            return 0;
        int L=dfs(root->left,ans);
        int R=dfs(root->right,ans);
        ans+=abs(L)+abs(R);
        return root->val+L+R-1;
    }
};
