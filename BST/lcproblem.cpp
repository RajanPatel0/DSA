#include <iostream>
#include <climits>
using namespace std;

// ✅ TreeNode structure as per LeetCode
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// ✅ Helper struct to return info from each subtree
class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

// ✅ Solution class with core logic
class Solution {
public:
    info solve(TreeNode* root, int& ans) {
        if (root == NULL) {
            return {INT_MIN, INT_MAX, true, 0};
        }

        info left = solve(root->left, ans);
        info right = solve(root->right, ans);

        info currNode;
        currNode.sum = root->val + left.sum + right.sum;
        currNode.maxi = max(root->val, right.maxi);
        currNode.mini = min(root->val, left.mini);

        if (left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini)) {
            currNode.isBST = true;
            ans = max(ans, currNode.sum);
        } else {
            currNode.isBST = false;
        }

        return currNode;
    }

    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        solve(root, maxSum);
        return maxSum;
    }
};

// ✅ Build sample tree manually
TreeNode* buildSampleTree() {
    /*
        Tree:
              1
             / \
            4   3
           / \
          2   4
    */
    TreeNode* root = new TreeNode(6);
    root->left = new TreeNode(3);
    root->right = new TreeNode(4);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(9);
    return root;
}

void InOrder(TreeNode* root, vector<int> &arr){
    if(root==NULL) return;

    InOrder(root->left, arr);
    arr.push_back(root->data);
    InOrder(root->right, arr);
}

//LC_99: Correct Swapped BST nodes :
Node* prev=NULL;    //for prev element track for comparing & checking while finding pair    
Node* first=NULL;   //first anomly of pair
Node* second=NULL;  //second anomly of swapped
void inOrder(TreeNode* root){   //this function will sort root with assign swapped value by find them
    if(root==NULL){
        return;
    }

    inOrder(root->left);
    if(prev!=NULL && prev->data > root->data){  //condition for finding swapped pair
        if(!first){ //assigning first found swapped no. to first i.e. not changeable once assigned
            first=prev;
        }
        second=root;    //second swapped no. of pair this is changeable if found later traversal
    }
    prev=root;  //before going to traverse root->right

    inOrder(root->right);
}

void swapBST(TreeNode* root){
    inOrder(root);

    swap(first->data, second->data);
}


//LC_501: FInding Mode Of BST

    vector<int> modes;
    int maxFreq = 0;
    int count = 0;
    int prevVal = INT_MIN;

    void inorder(TreeNode* root) {
        if (!root) return;

        inorder(root->left);

        // process current node
        if (prevVal == root->val) {
            count++;
        } else {
            count = 1;
        }

        if (count == maxFreq) {
            modes.push_back(root->val);
        } else if (count > maxFreq) {
            modes.clear();
            modes.push_back(root->val);
            maxFreq = count;
        }

        prevVal = root->val;

        inorder(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return modes;
    }

// ✅ Main function to run in VS Code terminal
int main() {
    TreeNode* root = buildSampleTree();
    // Solution s;
    // int result = s.maxSumBST(root);
    // cout << "Maximum Sum of BST in the tree: " << result << endl;

    //99:
    int 
    TreeNode* result = swapBST(root);
    InOrder(result, )

    return 0;
}
