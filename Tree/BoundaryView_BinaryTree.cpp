/**
 * 
 * Given a binary tree, print boundary nodes of the binary tree Anti-Clockwise starting from the root.
 *
 *   The boundary includes 
 *
 *  left boundary (nodes on left excluding leaf nodes)
 *   leaves (consist of only the leaf nodes)
 *   right boundary (nodes on right excluding leaf nodes)
 * 
 *  Apraoch:
 *  1. Print the left boundary in top-down manner. 
    2. Print all leaf nodes from left to right, which can again be sub-divided into two sub-parts: 
        …..2.1 Print all leaf nodes of left sub-tree from left to right. 
        …..2.2 Print all leaf nodes of right subtree from left to right. 
    3. Print the right boundary in bottom-up manner.
    We need to take care of one thing that nodes are not printed again. e.g. The left most node is also the leaf node of the tree.
 *   
 * 
 * 
*/


#include "iostream"
#include<vector>

using namespace std;

struct  TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    
};

//Get the left boundary nodes in top-down manner
void getLeftBoundary( TreeNode *root, vector<int> &result) {

    // For leaf node and any nullptr node return.
    // Do not get leaf node here.
    if( !root || (!root->left && !root->right) )
        return;
    
    if( root->left) {
        //Get the node first to ensure the top down manner.
        result.push_back(root->val);
        getLeftBoundary(root->left,result);

    } else if ( root->right) {

        result.push_back(root->val);
        getLeftBoundary(root->right,result);
    }
}

//Get the right boundary nodes in bottom-up manner
void getRightBoundary( TreeNode *root, vector<int> &result) {

    // For leaf node and any nullptr node return.
    // Do not get leaf node here.
    if( !root || (!root->left && !root->right) )
        return;
    
    if( root->right) {
 
        getRightBoundary(root->right,result);
        result.push_back(root->val);

    } else if ( root->left) {
        
        getRightBoundary(root->left,result);
        result.push_back(root->val);
    }
}

void getLeafNodes ( TreeNode *root, vector<int> &result ) {
    if( !root)
        return;

    getLeafNodes( root->left, result);
    //Ensure it's a leaf node
    if( !root->left && !root->right )
        result.push_back(root->val);

    getLeafNodes( root->right, result);
    
}

int main() {

    // Construct a sample binary tree
    TreeNode* root = new TreeNode(8);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(6);
    root->right->right = new TreeNode(14);
    root->right->right->left = new TreeNode(13);
    root->left->right->left = new TreeNode(4);
    root->left->right->right = new TreeNode(7);

    vector<int> result;
    if( root)
        result.push_back(root->val);

    getLeftBoundary(root->left,result);

    getLeafNodes(root,result);

    getRightBoundary(root->right,result);

    for( auto i: result)
        cout<<i <<"\t";

    return 0;
}
