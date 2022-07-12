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

class Solution{
  public:
    //Function to merge K sorted linked list.
    typedef pair<int,Node*> pi;
    
    Node * mergeKLists(Node *arr[], int k)
    {

        Node* pre = NULL , *head = NULL;
        
        priority_queue<pi,vector<pi>,greater<pi>> pq;

        for(int i=0;i<k;i++){
            if(arr[i]){
                pq.push({arr[i]->data,arr[i]});
            }
        }
        
        while(pq.size()){
            
            Node* node = pq.top().second;
            
            pq.pop();
            
            if(node->next)pq.push({node->next->data,node->next});
            
            if(head == NULL){
                head = node;
                pre =  node;
            }
            else {
                pre->next = node;
                pre = pre->next;
            }
            
        }
        
        return head;
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