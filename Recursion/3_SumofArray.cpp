#include <iostream>
using namespace std;

//sum(n,a) => sum of elementa upto n index
//sum(n,a) => a[n]+ sum(n-1,a)

//digitSum => 1234 =>1+2+3+4=11
// m=n%10;    1234 % 10 = LastDigit =4
// sum=sum+m;    sum=4
// n=n/10;    n=1234 => n/10 =>123

//Using Recursion =>
// digitSum(n/10) + lastdigit
// digitSum(n/10) + n%10

int sum(int n, int a[])
{
	if (n<0)
		return 0;
	return sum(n-1,a)+a[n];
}

int digitSum(int m){
	if(m==0) return 0;
	return digitSum(m/10)+m%10;
}
int main()
{
	int n=5;
	int a[n]={1,2,3,4,5};
    // cout<<sum(n-1,a);
    cout<<"Sum of Array is "<<sum(2,a);
	cout<<endl;
	//sum(2) a[2]+3 => a[2]=3+3=6
	//sum(1) a[1]+1=>a[1]=2 retuen 2+1=3
	//sum(0) a[0]+0 =>a[0]=1 return 1upper
	//sum(-1) return
	int m;
	cout<<"Enter The Digit for Sum ";
	cin>>m;
	cout<<digitSum(m);
	return 0;
}
