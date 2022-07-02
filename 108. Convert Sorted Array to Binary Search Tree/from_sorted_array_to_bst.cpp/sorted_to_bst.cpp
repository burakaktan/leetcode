// This comment is given by LeetCode
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

/*
    Time Complexity: O(n)
    Space Complexity: O(logn)  // because recursion and call stack
    
    Main Idea:
    Make the median element, root of the BST
    Recursively repeat it with (left subtree,leftsubarray) and (right subtree,right sub array)
*/
class Solution {
public:
    TreeNode* sortedArrayToBST(const vector<int>& nums,int begin = 0,int end = INT_MIN) {
        if(end == INT_MIN)
            end = (int)nums.size()-1;
        if(end < begin)
            return nullptr;
        int median = (begin + end)/2;
        TreeNode* root =  new TreeNode(nums[median]);
        root -> left = sortedArrayToBST(nums,begin,median-1);
        root -> right = sortedArrayToBST(nums,median+1,end);
        return root;
    }
};
