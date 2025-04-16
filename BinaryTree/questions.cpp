#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>

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

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftHT=height(root->left);
    int rightHT=height(root->right);
    return max(leftHT, rightHT)+1;
}

int count(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftcount=count(root->left);
    int rightcount=count(root->right);
    return (leftcount+rightcount+1);
}

int sumOfNodes(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumOfNodes(root->left);
    int rightSum=sumOfNodes(root->right);

    return leftSum+rightSum+root->data;
}

int main(){

    Node*root=NULL;

    vector<int> nodes={1,2,-1,-1,3,4,-1,-1,5,-1,-1};

    root=BuildTree(nodes);

    //1. Find Height of Binary Tree
    cout<<"Height: "<<height(root)<<endl;

    //2. Find Count of Binary Tree
    cout<<"Count: "<<count(root)<<endl;

    //3. Find Sum of Binary Tree
    cout<<"Sum: "<<sumOfNodes(root)<<endl;

    return 0;
}
