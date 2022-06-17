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
    time complexity: O(n)
    space complexity: O(h)
    where n is number of nodes, h is height of the tree
    */
    const int inf = 1e8;
    inline int min_of_three_tuple(tuple<int,int,int> t){return min(get<0>(t),min(get<1>(t),get<2>(t)));}
    /*
    seems like a dynamic programming question
    
    there are 3 sub answers for each node:
    0-cover substree of this node (node has camera)
    1-cover subtree of this node (node hasn't camera)
    2- cover subtree of this node but not this node
    */
    tuple<int,int,int> f(TreeNode *node)
    {
        if(node == nullptr)
        {
            return make_tuple(inf,0,0);
        }
        if(node->right == nullptr && node->left == nullptr)
        {
            return make_tuple(1,inf,0);
        }
        tuple<int,int,int> left = f(node->left);
        tuple<int,int,int> right = f(node->right);
        
        int s1 = 1 + min_of_three_tuple(left) + min_of_three_tuple(right);
        int s2 = min(
        get<0>(left) + min(get<0>(right),get<1>(right)),
        get<0>(right) + min(get<0>(left),get<1>(left))
        );
        int s3 = get<1>(left) + get<1>(right);
        s2 = min(s2,inf);
        s3 = min(s3,inf);
        return make_tuple(s1,s2,s3);
    }
    
    int minCameraCover(TreeNode* root) {
        tuple<int,int,int> sub_ans_root = f(root);
        return min(get<0>(sub_ans_root), get<1>(sub_ans_root));
    }
};
