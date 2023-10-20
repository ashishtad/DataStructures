
/**
 * Given a binary tree, print it vertically. The following examples illustrate the vertical order traversal.
 *                   1
                  /    \ 
                2      3
               / \   /   \
             4   5  6   7
                         /  \ 
                       8    9 

    Output:
    4
    2
    1 5 6
    3 8
    7
    9

    We need to check the Horizontal Distances from the root for all nodes. If two nodes have the same Horizontal Distance (HD), then they are on the same vertical line.
    HD for root is 0, a right edge (edge connecting to right subtree) is considered as +1 horizontal distance and a left edge is considered as -1 horizontal distance. 
*/

#include<iostream>
#include<vector>
#include<map>

using namespace std;

 struct TreeNode {
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


void printVertical( TreeNode *root, int hd, map<int,vector<int>> &verticalMap ) {

    if(!root)
        return;
    
    verticalMap[hd].push_back(root->val);

    printVertical(root->left,hd-1,verticalMap);
    printVertical(root->right,hd+1,verticalMap);

}

int main() {
    // Create a sample binary tree
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // Initialize map for vertical traversal
    map<int,vector<int>> verticalMap;

    // Perform vertical order traversal
    printVertical(root, 0, verticalMap);

    // Print the vertical order traversal
    for (auto it = verticalMap.begin(); it != verticalMap.end(); ++it) {
        cout << "Vertical distance " << it->first << ": ";
        for (int val : it->second) {
            cout << val << " ";
        }
        cout << endl;
    }

    // Clean up memory (deallocate nodes)
    delete root->right->right;
    delete root->right->left;
    delete root->left->right;
    delete root->left->left;
    delete root->right;
    delete root->left;
    delete root;

    return 0;
}






