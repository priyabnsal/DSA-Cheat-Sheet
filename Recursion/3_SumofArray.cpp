#include <iostream>
using namespace std;

//sum(n,a) => sum of elementa upto n index
//sum(n,a) => a[n]+ sum(n-1,a)


int sum(int n, int a[])
{
	if (n<0)
		return 0;
	return sum(n-1,a)+a[n];
}

int main()
{
	int n=5;
	int a[n]={1,2,3,4,5};
    // cout<<sum(n-1,a);
    cout<<sum(2,a);

	return 0;
}
