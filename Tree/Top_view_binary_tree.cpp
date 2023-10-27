
/**
 *  Approach : 
 *  Here we have to do a level order traversal of tree while keeping the count of horizontal distance of each node.
 *  We need to display only the first node of horizontal distance while traversing level order.
 *  Note: Here DFS won't work.
 * 
 *  A node x is there in the output if x is the topmost node at its horizontal distance. 
 *  The horizontal distance of the left child of a node x is equal to a horizontal distance of x minus 1, and that of a right child is the horizontal distance of x plus 1.
 * 
*/


#include "iostream"
#include <map>
#include <queue>
#include<utility>


using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void TopView( TreeNode * root ) {

    //Stores node and corresponding horizontal distance.
    std::queue<pair<TreeNode*,int>> nodequeue;

    nodequeue.push( make_pair(root,0));
    //This keeps the top view element against each horizontal distance.
    std::map<int,int> topVal;

    while( !nodequeue.empty() ) {
        TreeNode *node = nodequeue.front().first;
        int hd = nodequeue.front().second;
        nodequeue.pop();
        //Stores only the first node of the corresponding hd level.
        if( topVal.count(hd) == 0 )
            topVal[hd]=node->val;

        if( node->left)
            nodequeue.push(make_pair(node->left,hd-1));
        if(node->right)
            nodequeue.push(make_pair(node->right,hd+1));
        
    }
    //Extract the top view elements
    for( auto x: topVal)
        cout<<x.second <<"\t";

}

int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    
     TopView(root);

     return 0;

}