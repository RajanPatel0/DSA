#include<iostream>
#include<queue>
#include<stack>
#include<algorithm>
#include <climits>
#include<vector>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data=val;
        left=right=NULL;
    }
};

//1. creating/Inserting (arr nodes) in BST
Node* insert(Node*root, int val){   //To insert one single Node
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left=insert(root->left, val);
    }
    if(val>root->data){
        root->right=insert(root->right, val);
    }
    return root;
}

Node* buildBST(vector<int> arr){    //To insert all of the values for entire tree
    Node* root=NULL;
    for(int val: arr){
        root = insert(root, val);
    }
    return root;
}

//Now we'll create an inorder function for verify/Print BST
void inOrder(Node*root){
    if(root==NULL){
        return ;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}


//2. Search In BST
bool search(Node* root, int key){
    if(root==NULL){
        return false;
    }
    if(root->data==key){    //either we finds ans
        return true;
    }
    if(key < root->data){   //or go left
        return search(root->left, key);
    }else{      //or go right
        return search(root->right, key);
    }
}

//3. Delete In BST: ( possible by finding key has how many children)

Node* getIS(Node* root){    //(leftmost Node in right sub Tree)-aise node jha root ki left NULL ho jaaye
    while(root !=NULL && root->left!=NULL){
        root=root->left;
    }
    return root;
}
Node* delNode(Node* root, int key){
    if(root==NULL){ //first step- searching of key Node
        return NULL;        
    }
    if(key<root->data){
        root->left = delNode(root->left, key);
    }else if(key>root->data){
        root->right = delNode(root->right, key);
    }else{  //main step actual deletion
        if(root->left==NULL){   //0, 1 children case: Attaching Not Null wla child above(if 1 child)
            Node*temp=root->right;
            delete root;
            return temp;    //means returning NULL(if 0 child case) OR back join right wla(if 1-right child case)
        }else if(root->right==NULL){
            Node* temp= root->left;
            delete root;
            return temp;    //means returning NULL(if 0 child case) OR back join left wla(if 1-left child case)
        }else{  //2 children exist case
            Node* IS= getIS(root->right);   //inorder successor-just right wla
                root->data = IS->data;  //mtlb jo delete krna hai(jiske 2 child hai)-usme uske IS(just right=leftmost of rightsubtree) ko store kra do
                root->right = delNode(root->right, IS->data);   //or ye del wle ke right wla ab uper chala gya so ye bhi delete
        }
    }
    return root;
}

//LC_108: Convert Sorted Array to Balanced(both side have same no. children) BST
Node* helper(vector<int>& nums, int st, int end){
    if(st>end){
        return NULL;
    }
    int mid = st+(end-st)/2;
    Node* root= new Node(nums[mid]);
    root->left=helper(nums, st, mid-1);
    root->right=helper(nums, mid+1, end);
    return root;
}


Node* arrToBST(vector<int>& nums){
    return helper(nums, 0,nums.size()-1);
}

//LC_98: Validate a BST(leftMax < root < rightMin)
bool isBST(Node* root, Node*min, Node* max){
    if(root==NULL){
        return true;
    }
    if(min!=NULL && root->data<=min->data){  //these 2 loops
        return false;
    }
    if(max!=NULL && root->data>=max->data){
        return false;
    }

    return isBST(root->left, min,root)&&
    isBST(root->right, root, max);
}
bool isValid(Node* root){
    return isBST(root, NULL, NULL);
}

//LC_783: Minimum distance b/w BST Nodes
Node* prevNode=NULL;
int minDiffInBST(Node* root) {
    if(root==NULL){
        return INT8_MAX;
    }
    int ans=INT8_MAX;

    if(root->left!=NULL){
        int leftMin=minDiffInBST(root->left);
        ans=min(ans, leftMin);
    }
    if(prevNode!=NULL){
        ans=min(ans,root->data - prevNode->data); //1-0 for 1 leaf
    }        
    prevNode=root;

    if(root->right!=NULL){
        int rightMin=minDiffInBST(root->right);
        ans=min(ans, rightMin);
    }
    return ans;
}

//LC_230: Kth Smallest In BST
int prevOrder = 0;
int kthSmallest(Node* root, int k) {
    if (root == NULL) return -1;

    if (root->left) {
        int leftAns = kthSmallest(root->left, k);
        if (leftAns != -1) return leftAns;
    }

    if (prevOrder + 1 == k) return root->data;
    prevOrder++;

    if (root->right) {
        int rightAns = kthSmallest(root->right, k);
        if (rightAns != -1) return rightAns;
    }

    return -1;
}

//LC_235: Lowest Common Ancestor In BST
Node* LCA(Node* root, Node*p, Node*q){
    if(root==NULL){
        return NULL;
    }
    if(p->data<root->data && q->data<root->data){
        LCA(root->left,p,q);
    }
    else if(p->data>root->data && q->data>root->data){
        LCA(root->right,p,q);
    }else{
        return root;
    }
}

Node* searchConvert(Node* root, int key) { //helper to convert / find a node by value
    if (!root || root->data == key) return root;
    if (key < root->data)
        return searchConvert(root->left, key);
    return searchConvert(root->right, key);
}

//LC_700: Search in a Binary Search Tree
    Node* searchBST(Node* root, int val) {
        if(root==NULL){
            return NULL;
        }
        if(val<root->data){
            return searchBST(root->left, val);
        }
        else if(val>root->data){
            return searchBST(root->right, val);
        }else{
            return root;
        }
    }


int main(){
    vector<int> arr={5,3,6,2,4,1};

    //1. Inserting (arr nodes) in BST
    Node* root=buildBST(arr);
    //Printing BST Now(via inorder only cuzz only this one supports BST property)
    inOrder(root);

    //2. Searching in BST
    cout<<endl<<search(root,7)<<endl;

    //3. Delete In BST
    delNode(root, 6);
    cout<<"after Delete: "<<endl;
    inOrder(root);
    cout<<endl;
    
    //LC_108: Convert Sorted Array to Balanced BST
    vector<int> arr2={-10,-3,0,5,9};
    Node* ans=arrToBST(arr2);
    cout << "Inorder Traversal of BST: ";
    inOrder(ans);
    cout << endl;

    //LC_98: Validate a BST
    cout<<isValid(root)<<endl;

    //LC_783: minimum distance between bst nodes
    cout<<minDiffInBST(root)<<endl;

    //LC_230: Kth Smallest In BST
    cout<<kthSmallest(root,3)<<endl;

    //LC_235: LCA in BST
    Node* p = searchConvert(root, 5);
    Node* q = searchConvert(root, 2);
    Node* ans3 = LCA(root, p, q);
    cout<<ans3->data<<endl;

    //LC_700: Search till in a Binary Search Tree
    Node* ans4=searchBST(root, 2);
    inOrder(ans4);

    return 0;
}