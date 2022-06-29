// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


class Solution{
    public:
    
    unordered_map<int,int> mp;
    
    Node* find(int instart,int inend,int in[],int prestart,int preend,int pre[]){
        
        if(instart > inend || prestart > preend)return NULL;
        
        Node* root = new Node(pre[prestart]);
        
        if(preend == prestart){
            return root;
        }
        
        int loc = mp[root->data];
        int ele = loc-instart;
        
        root->left = find(instart,loc-1,in,prestart+1,prestart + ele,pre);
        root->right = find(loc+1,inend,in,prestart+ele+1,preend,pre);
        
        return root;
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
    
        for(int i=0;i<n;i++){
            mp[in[i]] = i;
        }
        
        return find(0,n-1,in,0,n-1,pre);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends