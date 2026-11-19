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
    int height(TreeNode* root, int& diameter){
        if(root == nullptr){return 0;}

        //their heights tells us how far can we travel
        //first solve the left side then to right side 
        int left = height(root->left,diameter);
        int right = height(root->right,diameter);

        diameter = max(diameter, left + right);
        return 1 + max(left,right);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root,diameter);
        return diameter;
    }
};