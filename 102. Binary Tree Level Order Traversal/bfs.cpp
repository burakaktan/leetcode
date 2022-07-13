// The comment below is given by LeetCode
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    /*
    Time Complexity: O(n)
    Space Complexity: O(n)
    where n is number of nodes in the tree
    */
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return vector< vector<int> >{};
        queue<TreeNode*> q;
        q.push(root);
        
        vector< vector<int> >ans;
        while(!q.empty())
        {
            vector<int> curr_level;
            int curr_level_size = q.size();
            for(int i = 0;i<curr_level_size;i++)
            {
                TreeNode *node = q.front();
                q.pop();
                curr_level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ans.push_back(curr_level);
        }
        return ans;
    }
};
