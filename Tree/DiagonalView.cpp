
/**
 * https://www.geeksforgeeks.org/diagonal-traversal-of-binary-tree/
 * 
 * Print the binary tree in diagonal view. 
 * Approach :
 *  Use a map to keep the slope distances as the key and the coreesponding slope elements in a vector. 
 *  
 * Complexities:
 * Time: O(n) --> As we traverse each node of tree
 * Space: O(n)  --> Map stores all the elements of tree.
*/
#include "iostream"
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void getDiagonalElements( TreeNode *root,
                            int slope, 
                            map<int,vector<int>> &diagTree ) {

    if(!root)
        return;
    
    diagTree[slope].push_back(root->val);
    
    //For left elements/subtree slope will increase by 1.
    getDiagonalElements(root->left,slope+1,diagTree);
    //For right elements/subtree slope will remain same.
    getDiagonalElements(root->right,slope,diagTree);

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

    std::map<int,vector<int>> diagTree;
    getDiagonalElements(root,0,diagTree);

    for( auto it: diagTree) {
        for( auto i : it.second){
            cout<<i<<"\t";
        }
        cout<<"\n";
            
    }
    return 0;
}
