#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>

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

int topView(Node* root){    //via level order traversal
    queue<pair<Node*, int>>q;   //(Node, HD)
    map<int,int>m;    //(HD, node val)
    q.push({root,0});

    while(!q.empty()){
        Node* temp=q.front().first;
        int tempHD=q.front().second;
        q.pop();

        if(m.find(tempHD)==m.end()){    //agr nhi milta hai
            m[tempHD]=temp->data;
        }

        if(temp->left){
            q.push({temp->left,tempHD-1});
        }
        if(temp->right){
            q.push({temp->right, tempHD+1});
        }
    }

    for(auto it:m){
        cout<<it.second<<" ";
    }
    cout<<endl;

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

    //4. Top View Printing of Binary Tree
    topView(root);

    return 0;
}
