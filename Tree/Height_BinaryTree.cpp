
#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// Define the TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


int height( TreeNode *root) {

    if( !root )
        return 0;
    //stack to process the tree nodes
    stack<std::pair<TreeNode*,int>> st;
    // To store height of each Node and it's height
    std::unordered_map<TreeNode*,int> heightMap;
    // Second element in pair reprsents the node whether it's traversed first time i.e 0.
    // 1: It's child elements are already processed and it's getting traversed second time.
    st.push(make_pair(root,0));

    while( !st.empty() ) {

        TreeNode *temp = st.top().first;
        //Getting traversed for first time. Process it's child elements and make it's second element to 1 as childs are prcocessed.
        if ( temp && (st.top().second == 0) ) {
            st.top().second = 1;
            if( temp->left)
                st.push(make_pair(temp->left,0));
            if(temp->right)
                st.push(make_pair(temp->right,0));

        } else {
            //Child nodes of the temp node are already processed, pop it.
            st.pop();
            if( temp){
                //calc height and store in height map.
                int lheight = temp->left ? heightMap[temp->left] :0;
                int rheight = temp->right ? heightMap[temp->right]:0;
                heightMap[temp] = max(lheight,rheight)+1;
            }
        }
    }

    return heightMap[root];

}


int main() {
    // Construct a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->left->left = new TreeNode(7);   // Additional node
    root->left->left->right = new TreeNode(8); 
    root->left->left->right->left = new TreeNode(6); 
    root->left->left->right->left->left = new TreeNode(6);

    // Call the height function and print the result
    int treeHeight = height(root);
    cout << "The height of the binary tree is: " << treeHeight << endl;

    // Clean up memory (not shown in this example, but important in real applications)
    return 0;
}