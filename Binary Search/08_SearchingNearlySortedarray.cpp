#include <bits/stdc++.h>
using namespace std;

int bs(int arr[], int low, int high, int x)
{
	while(low <= high)
	{
		int mid = low + (high-low)/2;
		if(arr[mid] == x)
			return mid;
		if(mid > low && arr[mid-1] == x)
			return mid-1;
		if(mid < high && arr[mid+1] == x)
			return mid+1;
		if(arr[mid] < x)
		{
			low = mid + 2;
		}
		if(arr[mid] > x)
			high = mid - 2;
	}
	return -1;
}

int main()
{
	int arr[] = {5,10,30,20,40};
	cout << bs(arr,0,4,20);
	return 0;
}