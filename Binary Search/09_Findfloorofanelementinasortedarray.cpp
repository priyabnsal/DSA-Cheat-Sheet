
#include<iostream>
using namespace std;

int florr(int arr[],int target,int n){

	int s,e,m;
	s=0;
	e=n-1;
	int res=0;
	
	while(s<=e){
		m=s+(e-s)/2;
		// if(arr[m]<target && (m==e || arr[m+1]>target))
		if(arr[m]==target)
		{
			cout<<"Found element "<<arr[m]<<" at index "<<m<<endl;
			break;
		}else if(arr[m]<target){
			res=arr[m];
			s=m+1;
		}else{
			e=m-1;
		}
	}
	return res;
}
int ceil(int arr[],int target,int n){

	int s,e,m;
	s=0;
	e=n-1;
	int res=0;
	
	while(s<=e){
		m=s+(e-s)/2;
		// if(arr[m]<target && (m==e || arr[m+1]>target))
		if(arr[m]==target)
		{
			cout<<"Found element "<<arr[m]<<" at index "<<m<<endl;
			break;
		}else if(arr[m]<target){
			s=m+1;
		}else{
			res=arr[m];
			e=m-1;
		}
	}
	return res;
}
int main(){
	int arr[]={1,2,3,4,8,10,12,19};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int target=11;
	cout<<"Floor is "<<florr(arr,target,n)<< " " ;
	cout<<"Ceil is "<<ceil(arr,target,n);

}

// #include<bits/stdc++.h>
// using namespace std;
// int main()
// {
//     int n=5,ele=4;
//     // cin>>n;
// 	int a[n]={1,2,4,8,10};
//     // for(int i=0;i<n;i++)cin>>a[i];
//     // cout<<"enter the element whose lower bound you want to find ";
//     // cin>>ele;
//     int start =0,end=n-1,res=-1;
//     while(start<=end)
//     {
//         int mid=(start+end)/2;
//         if(a[mid]==ele)
//         {
//             return a[mid];
//         }
//         else if(a[mid]<ele)
//         {
//             res=mid;
//             start=mid+1;
//         }
//         else if(a[mid]>ele)
//         {
//             end=mid-1;
//         }
//     }
//     cout<<res;
// }