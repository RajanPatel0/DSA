#include<iostream>
#include<vector>
#include<queue>

using namespace std;
//Apna College:Binary Tree with the help of recurrsion
//solution solving starts first's from left sub tree then from right sub tree && then for combined solving root 
//It's like DFS in recursive approach way
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

static int idx=-1;
Node* BuildTree(vector<int> preOrder){
    idx++;

    if (preOrder[idx]==-1){
        return NULL;
    }

    Node*root = new Node(preOrder[idx]);
    root->left=BuildTree(preOrder); //Left
    root->right=BuildTree(preOrder); //Right

    return root; 
};

// 3 DFS Approaches::
//PREORDER TRAVERSAL: Root->left->right
void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

//INORDER TRAVERSAL: left->root->right
void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//POSTORDER TRAVERSAL: left->right->root
void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

//Level Order Traversal:(breadth first search)-cuzz exploration is at each level
//push root
//then pop & print that root
//them pushing left & right child of that root node-& same steps go on

void levelOrder(Node* root){
    queue<Node*> q; //storing node pointers to q
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();

        if(curr==NULL){
            //next line
            if(!q.empty()){ //1st case non-empty
                cout<<endl;
                q.push(NULL);
                continue;
            }else{  //2nd case if empty
                break;
            }
        }

        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

//Transform to SumTree 
int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);
    root->data+=leftSum+rightSum;
    return root->data;
}

int main(){
        vector<int> preOrder={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

        Node* root = NULL;
        root = BuildTree(preOrder);

        cout<<root->data<<endl;
        cout<<root->left->data<<endl;
    
        cout<<"before conversion: "<<endl; 
        preorder(root);
        cout<<endl;

        inorder(root);
        cout<<endl;

        postorder(root);
        cout<<endl;

        cout<<"Here Level Order Traveral:"<<endl;
        levelOrder(root);

        cout<<"sum of tree: "<<sumTree(root)<<endl;

        cout<<"after conversion: "<<endl; 
        preorder(root);
        cout<<endl;


    return 0;
}