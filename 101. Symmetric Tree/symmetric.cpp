// the comment below is given by LeetCode
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
    Space Complexity: O(h)
    where n is number of nodes and h is depth of the tree
    
    Main idea:
    Run 2 DFSs simultaneously
    First DFS should discover left subtree
    Order of traversal is (left,current,right)
    Second DFS should discover right subtree
    Order of traversal is (right,current,left)
    
    Note: DFSs could also be done recursively, I've done it iteratively by using stacks
    */
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr)
            return true;
        // if one of them is null but the other is not, return false
        if((nullptr == root->right) ^ (nullptr == root->left))
            return false;
        stack<TreeNode*> left;
        stack<TreeNode*> right;
        
        left.push(root->left);
        right.push(root->right);
        
        while(!left.empty() && !right.empty())
        {
            TreeNode *l = left.top(), *r = right.top();
            right.pop();left.pop();
            if(l == nullptr && r == nullptr)
                continue;
            if((nullptr == l) ^ (nullptr == r))
                return false;

            if(r->val != l->val)
                return false;
            
            //now values of l and r are same and l and r are not-null
            right.push(r->right);
            right.push(r->left);
            
            left.push(l->left);
            left.push(l->right);
        }
        if(!left.empty() || !right.empty())
            return false;
        return true;
    }
};
