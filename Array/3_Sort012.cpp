#include<bits/stdc++.h>
using namespace std;

int main(){
    int arr[]={0,2,2,0,1,2,1,2,0,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    int l=0,m=0,h=n-1;

    while(m<=h){
        int x=arr[m];
        if(x==0){
            swap(arr[l],arr[m]);
            l++;
            m++;
        }
        else if(x==1){
            m++;
        }
        else{
            swap(arr[m], arr[h]);
            h--;
        }
    }
    cout<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}