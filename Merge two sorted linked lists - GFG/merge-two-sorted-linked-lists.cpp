// { Driver Code Starts
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;
    
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* l1, Node* l2)  
{  
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