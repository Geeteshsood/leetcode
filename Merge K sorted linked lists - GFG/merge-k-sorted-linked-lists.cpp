// { Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}

 // } Driver Code Ends
/*Linked list Node structure

struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

class Solution{
  public:
        Node* mergeTwoLists(Node* l1, Node* l2) {
        
       Node* temp = NULL , *node = NULL;  
        
       if(!l1 && !l2)return NULL;
       else if(l1 && l2==NULL)return l1; 
       else if(l1==NULL && l2)return l2;

        
       while(l1!=NULL && l2!=NULL){
         
          if(l1->data<l2->data){
               if(temp == NULL){
                 temp = l1;
                 node = l1;
                 l1 = l1->next;
               }
               else{
                 temp->next = l1;
                 temp = l1;
                 l1 = l1->next;
               }    
          }
          else{
              if(temp == NULL){
                 temp = l2;
                 node = l2;
                 l2 = l2->next;
              }
              else{
                temp->next = l2;
                temp = l2;
                l2 = l2->next;
              }    
          }
       }  
        
       while(l1){
         temp->next = l1;
         temp = l1;
         l1 = l1->next;
       }
       
       while(l2){
         temp->next = l2;
         temp = l2;
         l2 = l2->next;
       } 
        
     return node;   
    }
    
    Node* merge(int start,int end,Node* arr[]){
        
        if(start > end)return NULL;
        else if(start == end){
            return arr[start];
        }
        
        int mid = start + (end - start)/2;
        
        Node* l1 = merge(start,mid,arr);
        Node* l2 = merge(mid+1,end,arr);
        
        return mergeTwoLists(l1,l2);
    }
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        return merge(0,k-1,arr);
    }
};



// { Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}
  // } Driver Code Ends