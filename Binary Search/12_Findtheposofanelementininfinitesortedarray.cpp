// C++ program to demonstrate working of an algorithm that finds
// an element in an array of infinite size
#include<bits/stdc++.h>
using namespace std;

// Simple binary search algorithm
int binarySearch(int nums[], int l, int r, int target)
{
	 int start= 0;
        int end= 10;
        while (start <= end)
        {
            int mid = start + (end-start)/2;
            if (target==nums[mid])
                return mid;
            else if (target<nums[mid])
                end= mid-1;
            else 
                start= mid+1;
        }
        return -1;
}
int findPos(int A[], int key)
{
	int low =0, high =1;
if (low <= high) {
            int mid = low + (high - low) / 2;
            if (A[mid] == key)
                return mid;
            else if (A[mid] < key)
                return binarySearch(A, mid + 1, 2 * high, key);
            else
                return binarySearch(A, low, mid - 1, key);
        } else
            return -1;
}

// Driver program
int main()
{
	int arr[] = {3, 5, 7, 9, 10, 90, 100, 130,
							140, 160, 170};
	int ans = findPos(arr, 10);
	if (ans==-1)
		cout << "Element not found";
	else
		cout << "Element found at index " << ans;
	return 0;
}
// int low =0, high =1;
// if (low <= high) {
//             int mid = low + (high - low) / 2;
//             if (A[mid] == key)
//                 return mid;
//             else if (A[mid] < key)
//                 return solve(A, mid + 1, 2 * high, key);
//             else
//                 return solve(A, low, mid - 1, key);
//         } else
//             return -1;