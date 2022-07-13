// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


 // } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/


class Solution
{
    public:
   
    int findlength(Node* head,Node* &last){
        
        int len = 0;
        
        while(head){
            last = head;
            head = head->next;
            len++;
        }
        
        return len;
    }
   
    Node* rotate(Node* head, int k)
    {
        if(head == NULL)return head;
        
        Node* last = NULL;
        
        int len = findlength(head,last);
        
        k = k%len;
        
        if(k == 0)return head;
        
        Node* nex = head , *cur = head;
        
        for(int i=0;i<k;i++){
            cur = nex;
            nex = nex->next;
        }
        
        cur->next = NULL;
        last->next = head;
        
        return nex;
  
    }
};
    


// { Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}
  // } Driver Code Ends