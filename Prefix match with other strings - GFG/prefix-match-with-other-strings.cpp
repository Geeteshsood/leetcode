// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++

class Solution{   
public:
   
    class Node{
        public:
        Node* links[26];
        int count;
    };
    
    Node* root;
    
    void insert(string &word){
        
        Node* node = root;
        
        for(auto &ch : word){
            
            if(node->links[ch-'a'] == NULL){
                Node* temp = new Node();
                node->links[ch-'a'] = temp;
            }
            
            node = node->links[ch-'a'];
            node->count += 1;
        }
        
    }

    int klengthpref(string arr[], int n, int k, string str){    
        
        root = new Node();
        
        for(int i=0;i<n;i++){
            insert(arr[i]);
        }
        
        string temp = str.substr(0,k);
        
        Node* node = root;
        
        for(auto &ch : temp){
            
            if(node->links[ch-'a'] == NULL)return 0;
        
            node = node->links[ch-'a'];
        }
      
      return node->count;
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
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends