#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<string>

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

int topView(Node* root){    //via level order traversal-TC: O(nlogn)
    queue<pair<Node*, int>>q;   //(Node, HD)
    map<int,int>m;    //(HD, node val)
    q.push({root,0});   //pushed first elem(root) which is at hor.distance=0 

    while(!q.empty()){
        Node* temp=q.front().first; //representing node
        int tempHD=q.front().second;    //representing hor.dist. of that node
        q.pop();

        if(m.find(tempHD)==m.end()){    //agr nhi milta hai(map mei)-means first time aaya hai hor.dist.
            m[tempHD]=temp->data;   //toh add kar denge
        }

        if(temp->left){
            q.push({temp->left,tempHD-1});
        }
        if(temp->right){
            q.push({temp->right, tempHD+1});
        }
    }

    for(auto it:m){ //cuzz we'want to print based on hor.dist. & early coming nodes(-1 to 0 to 1)
        cout<<it.second<<" ";   //& here's m.second prints node val of that hor.dist. based node
     }
    cout<<endl;
}

void kthlevel(Node* root,int k){
    if(root==NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    kthlevel(root->left,k-1);
    kthlevel(root->right,k-1);
}

//LC_105: Constructing Tree from preorder(RLR) & inorder(LRR) sequence
//*Take starting value as root from preorder & find that same value in inoder wherever it finds from it's left in inorder is left tree & on right is right sub tree & so on..
int search(vector<int>&in, int left, int right, int val){
    for(int i=left; i<=right; i++){
        if(in[i]==val){
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int>& pre, vector<int>&in,int& preIdx, int left, int right ){

    if(left>right){
        return NULL;
    }

    Node*root= new Node(pre[preIdx]);
    int inIdx=search(in,left,right,pre[preIdx]);
    preIdx++;
    root->left=buildTree(pre,in,preIdx,left,inIdx-1);
    root->right=buildTree(pre,in,preIdx,inIdx+1,right);
    return root;
}

//LC_236:Lowest Common Ancestor- done

//Transform to Sum Tree= node = node val+ left subtree value + right subtree value
int sumTree(Node* root){
    if(root==NULL){
        return 0;
    }
    int leftSum=sumTree(root->left);
    int rightSum=sumTree(root->right);
    root->data+=leftSum+rightSum;
    return root->data;
}

//LC_257:Binary Tree Path - returning all possible path i.e. are from root to leaf node
void allPaths(Node* root, string path, vector<string>& ans) {
    if (!root->left && !root->right) {
        ans.push_back(path);
        return;
    }

    if (root->left) {
        allPaths(root->left, path + "->" + to_string(root->left->data), ans);
    }

    if (root->right) {
        allPaths(root->right, path + "->" + to_string(root->right->data), ans);
    }
}
vector<string> binaryTreePaths(Node* root) {
    vector<string> ans;
    if (!root) return ans;
    string path = to_string(root->data);
    allPaths(root, path, ans);
    return ans;
}

//LC_662: maximum width of binary tree: max no. of nodes in one level of complete binary tree
int widthOfBinaryTree(Node* root) {
        queue<pair<Node*, unsigned long long>>q;
        q.push({root,0});

        int maxWidth=0;
        while(!q.empty()){
            int currSize=q.size();
            unsigned long long stIdx=q.front().second;
            unsigned long long endIdx=q.back().second; 

            maxWidth=max(maxWidth,(int)(endIdx-stIdx+1));   //it'll give max-width of any level

            for(int i=0; i<currSize; i++){
                auto curr = q.front();
                q.pop();

                if(curr.first->left){
                    q.push({curr.first->left, curr.second*2+1});
                }
                if(curr.first->right){
                    q.push({curr.first->right, curr.second*2+2});
                }
            }    
        }

        return maxWidth;
    }

//LC_94:binary-tree-inorder-traversal(without recursion) by using IP
vector<int> inorderTraversal(Node* root) {
        Node* curr=root;
        vector<int>ans;
        while(curr!=NULL){
            if(curr->left==NULL){ 
                //printing curr then update to right of it
                ans.push_back(curr->data);
                curr=curr->right;
            }
            else{
                //find Inorder predecessor
                Node* IP=curr->left;
                while(IP->right!=NULL && IP->right!=curr){
                    IP=IP->right;
                }   //IP mil gya

                if(IP->right==NULL){    //checking connection create krna pdega
                    IP->right=curr; //creating thread with curr
                    curr=curr->left;
                }
                else{   //agr connection already exist krta hai
                    IP->right=NULL; //deleting that linked thread
                    ans.push_back(curr->data);
                    curr=curr->right;
                }
            }
        }
    return ans;
}

// LC_114:Flatten Binary Tree to Linked List
Node* nextRight=NULL;
void flatten(Node* root){
    if(root==NULL){
        return;
    }
    flatten (root->right);
    flatten (root->left);
    root->left=NULL;
    root->right=nextRight;
    nextRight=root;
    
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

    //5. Printing of Kth level of Binary Tree
    kthlevel(root,2);
    cout<<endl;
    //6. Binary Tree Path - returning all possible path
    vector<string> paths = binaryTreePaths(root);
    
    cout << "All root-to-leaf paths:\n";
    for (string path : paths) {
        cout << path << endl;
    }
    
    //7. maximum width of binary tree
    cout<<"Here's max - width";
    cout<<widthOfBinaryTree(root);

    //8. MORRIS binary-tree-inorder-traversal
    vector<int> inOrder = inorderTraversal(root);
        cout << "\nInorder Traversal: ";
    for (int val : inOrder) {
        cout << val << " ";
    }
    cout << endl;
    
    //9. flatten BT to linked list
    // cout<<flatten(root); //it return nothing cuzz void return type in cout
    flatten(root);
    cout << "Flattened tree (right-skewed list): ";
    Node* curr = root;
    while (curr != NULL) {  //printing that list now
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;


    return 0;
}
