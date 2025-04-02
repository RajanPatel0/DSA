#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node{
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int d){    //constructor
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};

//Build using Recurssion  
Node* buildTree(Node* root){
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);    //Making first data as root

    if(data==-1) return NULL;
    cout<<"Enter data for inserting at left:"<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting at right:"<<data<<endl;
    root->right=buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    //By using Queue(dfs=level order traversal)
    queue<Node*> q;
    q.push(root);   //sabse pehle root push karke uske baad hi NUll(NewLine) de diya
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){  //agr front NULL hai toh
            cout<<endl; //give newLine
            if(!q.empty()){ //ye NUll traverse karne ke baad bhi check if remaining isn't empty
                q.push(NULL);   //because iss level ke baad toh endl karna hi hai i.e. we need null at end if nonEmpty
            }
        }else{
            cout<<temp->data<<" ";  //printing starts here(temp!=NUll) because what if root is NULL
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

void inOrderTraversal(Node* root){
    //LNR
    if(root==NULL)return ;

    inOrderTraversal(root->left);   //L
    cout<<root->data<<" ";  //N
    inOrderTraversal(root->right);   //R
}

void preOrderTraversal(Node* root){
    //LNR
    if(root==NULL)return ;

    cout<<root->data<<" ";  //N
    preOrderTraversal(root->left);   //L
    preOrderTraversal(root->right);   //R
}

void postOrderTraversal(Node* root){
    //LNR
    if(root==NULL)return ;

    postOrderTraversal(root->left);   //L
    postOrderTraversal(root->right);   //R
    cout<<root->data<<" ";  //N
}


void buildFromLevelOrder(Node* &root){
    queue<Node*>q;
    cout<<"Enter data for Root Node: "<<endl; 
    int data;
    cin>>data; 
    root=new Node(data);    //jo input li thi uski new node as root bna di
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter left Node data for: "<<temp->data<<endl;
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }
        cout<<"Enter right Node data for: "<<temp->data<<endl;
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }

}


int main(){

    Node* root=NULL;

    //creating a tree via recursion:    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // root=buildTree(root);

    //creating a tree via levelorder:   //1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
    buildFromLevelOrder(root);

    cout<<"Printing the level order traversal output"<<endl;
    levelOrderTraversal(root);

    //InOrder Traversal
    cout<<"InOrder Traversal Is: "<<endl;
    inOrderTraversal(root);
    cout<<endl;

    //PreOrder Traversal
    cout<<"PreOrder Traversal Is: "<<endl;
    preOrderTraversal(root);
    cout<<endl;
    
    //PostOrder Traversal
    cout<<"PostOrder Traversal Is: "<<endl;
    postOrderTraversal(root);


    return 0;
}