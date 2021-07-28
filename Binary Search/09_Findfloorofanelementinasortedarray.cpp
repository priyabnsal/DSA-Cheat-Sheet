
#include<iostream>
using namespace std;

int main(){
	int arr[]={1,2,3,4,8,10,12,19};
	int n=sizeof(arr)/sizeof(arr[0]);
	
	int target=11;
	
	int s,e,m;
	s=0;
	e=n-1;
	
	while(s<=e){
		m=s+(e-s)/2;
		
		if(arr[m]<target && (m==e || arr[m+1]>target)){
			cout<<"Found element "<<arr[m]<<" at index "<<m;
			return 0;
		}else if(arr[m]<target){
			s=m+1;
		}else{
			e=m-1;
		}
	}
	
	cout<<"No floor element is present";
}
