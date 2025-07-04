#include<iostream>
#include<vector>
#include<climits>
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

Node* insert(Node* root, int val){
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

Node* buildBST(vector<int> arr){
    Node* root=NULL;
    for(int val: arr){
        root=insert(root,val);
    }
    return root;
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

//Merge Two BST's:
//1. firstly merge their inorder
//2. then converting merged sorted temp or inorder to Balanced BST

void InOrder(Node* root, vector<int> &arr){
    if(root==NULL) return;

    InOrder(root->left, arr);
    arr.push_back(root->data);
    InOrder(root->right, arr);
}

Node* buildBSTfromSorted(vector<int> arr, int s, int e){
    if(s>e) return NULL;
        int mid=s+(e-s)/2;
        Node* root= new Node(arr[mid]);

        root->left = buildBSTfromSorted(arr, s, mid-1);
        root->right = buildBSTfromSorted(arr, mid+1, e);

    return root;
}

Node* mergeBST(Node* root1, Node* root2){
    vector<int> arr1, arr2;
    InOrder(root1, arr1);
    InOrder(root2, arr2);

    vector<int> temp;
    int i=0, j=0;
    while(i<arr1.size() && j< arr2.size()){
        if(arr1[i]<arr2[j]){
            temp.push_back(arr1[i++]);
        }
        else{
            temp.push_back(arr2[j++]);
        }
    }
    while(i<arr1[i]){
        temp.push_back(arr1[i++]);
    }
    while(j<arr2[j]){
        temp.push_back(arr2[j++]);
    }

    return buildBSTfromSorted(temp,0,temp.size()-1);
}


//LC_99: Correct Swapped BST nodes :
// Node* prev=NULL;    //for prev element track for comparing & checking while finding pair    
// Node* first=NULL;   //first anomly of pair
// Node* second=NULL;  //second anomly of swapped
// void inOrder(Node* root){   //this function will sort root with assign swapped value by find them
//     if(root==NULL){
//         return;
//     }

//     inOrder(root->left);
//     if(prev!=NULL && prev->data > root->data){  //condition for finding swapped pair
//         if(!first){ //assigning first found swapped no. to first i.e. not changeable once assigned
//             first=prev;
//         }
//         second=root;    //second swapped no. of pair this is changeable if found later traversal
//     }
//     prev=root;  //before going to traverse root->right

//     inOrder(root->right);
// }

// void swapBST(Node* root){
//     inOrder(root);

//     swap(first->data, second->data);
// }


int main(){
    vector<int> arr1={4,9,1,3,6,8};
    vector<int> arr2={2,5,0};

    Node* root1=buildBST(arr1);
    Node* root2=buildBST(arr2);

    Node* root= mergeBST(root1, root2);

    vector<int> seq;

    InOrder(root, seq);
    for(int val: seq){
        cout<<val<<" ";
    }
    cout<<endl;


    return 0;
}