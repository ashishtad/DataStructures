/**
 *  Display the left view of a binary Tree
 * 
 *  Approach:
 *  Traverse the tree recursively from root and print each level first element which is nothing but the left boundary nodes. 
 *  level: Keeps the track of each node levels
 *  maxLevel : Indicates the max level traversal has been done till now.
 * 
 *  Time complexity: O(n) -> As we need to traverse each node of tree
 *  Space complexity: O(n) -> Worst case when tree is a skewed binary  tree. This represents the call stack of recursive functions.
*/



#include <iostream>
#include <vector>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


void leftView(TreeNode* root, int level, int& maxlevel, vector<int>& result) {
    // Implementation of leftView function
    if(!root)
        return;
    
    if( level > maxlevel) {
        result.push_back(root->val);
        maxlevel = level;
    }

    leftView(root->left, level+1, maxlevel, result);
    leftView(root->right, level+1, maxlevel, result);
}

// Driver function to initiate left view calculation
vector<int> getLeftView(TreeNode* root) {
    vector<int> result;
    int maxlevel = -1;
    leftView(root, 0, maxlevel, result);
    return result;
}

int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Get the left view
    vector<int> leftViewElements = getLeftView(root);

    // Print the left view elements
    cout << "Left View Elements: ";
    for (int elem : leftViewElements) {
        cout << elem << " ";
    }

    return 0;
}
