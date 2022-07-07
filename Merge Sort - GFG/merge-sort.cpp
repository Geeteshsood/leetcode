// { Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


 // } Driver Code Ends
class Solution
{
    public:
    
    void merge(int arr[], int l, int mid, int r)
    {
         int left[mid-l+1] , right[r-mid];

         for(int i=l,k=0;i<=mid;i++,k++){
             left[k] = arr[i];
         }
    
         for(int j=mid+1,k=0;j<=r;j++,k++){
             right[k] = arr[j];
         }
      
         int i=0 , j=0 , m = mid-l+1 , n = r-mid,k=l;

        while(i < m && j < n){
            
            if(left[i] > right[j]){
                arr[k] = right[j];
                j++;
            }
            else{
                arr[k] = left[i];
                i++;
            }
            
            k++;
        }
        
        while(i<m){
            arr[k] = left[i];
            i++,k++;
        }
        
        while(j < n){
            arr[k] = right[j];
            j++,k++;
        }
         
       
    }
    
    public:
    
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r)return ;
        
        int m = l + (r - l)/2;
        
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        
        merge(arr,l,m,r);
 
    }
};

// { Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}  // } Driver Code Ends