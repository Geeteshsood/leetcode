// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


 // } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    node *reverseList(node *root,node* &cur,node* &nex,int len){
        
        if(root == NULL){
            return NULL;
        }
        
        if(len == 1){
            nex = root->next;
            cur = root;
            return root;
        }
        
        node *temp = reverseList(root->next,cur,nex,len-1);
       
        if(temp)temp->next = root;
        else cur = root,nex = root->next;
        
     return root;   
    }
    
    struct node *reverse (struct node *head, int k)
    { 
        
      node * pre = NULL,* cur = NULL , *nex = head ,*start = head;
       
       while(nex!=NULL){
           
          node* temp = reverseList(head,cur,nex,k);
           
          temp->next = nex;
           
         if(pre){
             pre->next = cur;
         }
         else{
             start = cur;
             head = cur;
         }
           
         pre = temp;
         head = pre->next;
       }
       
      return start;  
    }
};


// { Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}

  // } Driver Code Ends