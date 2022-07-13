// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};





// Function to Build Tree
Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



 // } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
    public:
    //Function to return a list of integers denoting the node 
    //values of both the BST in a sorted order.
    vector<int> merge(Node *root1, Node *root2)
    {
      
      vector<int> res;
      
      stack<Node*> st1 , st2;
     
      while(root1){
          st1.push(root1);
          root1 = root1->left;
      }
      
      while(root2){
          st2.push(root2);
          root2 = root2->left;
      }
      
      while(st1.size() || st2.size()){

          bool f1 = st1.empty() , f2 = st2.empty();
          
          if(f2 || (!f1 && !f2 && st1.top()->data <= st2.top()->data)){
              
              Node* temp = st1.top();
              st1.pop();
            //   cout<<temp->data<<endl;
              res.push_back(temp->data);
              temp = temp->right;
              
              while(temp){
                  st1.push(temp);
                  temp = temp->left;
              }
              
          }
          else if(f1 || (!f1 && !f2 && st1.top()->data > st2.top()->data)){
              
              Node* temp = st2.top();
              st2.pop();
            //   cout<<temp->data<<endl;
              res.push_back(temp->data);
              temp = temp->right;
              
              while(temp){
                  st2.push(temp);
                  temp = temp->left;
              }
              
          }
      
      }
      
    //   cout<<st1.size()<<" "<<st2.size()<<endl;
      
      return res;
    }
};

// { Driver Code Starts.
int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);
       Solution obj;
       vector<int> vec = obj.merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}  // } Driver Code Ends