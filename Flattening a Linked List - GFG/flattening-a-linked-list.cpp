// { Driver Code Starts
#include <bits/stdc++.h>

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends

Node *flatten(Node *root)
{
        if(root == NULL)return root;

        Node* temp1 = root;
        Node* temp2 = flatten(root->next);

        Node* dummy = new Node(0);
        Node* head = dummy;
        dummy->next = NULL;
        
        while(temp1 && temp2){
            
            if(temp1->data < temp2->data){
                dummy->bottom = temp1;
                temp1 = temp1->bottom;
            }
            else {
                dummy->bottom = temp2;
                temp2 = temp2->bottom;
            }
            
            dummy = dummy->bottom;
        }
    
    
        while(temp1){
            dummy->bottom = temp1;
            dummy = dummy->bottom;
            temp1 = temp1->bottom;
        }
   
        while(temp2){
            dummy->bottom = temp2;
            dummy = dummy->bottom;
            temp2 = temp2->bottom;
        }
  
      return head->bottom;  
}

