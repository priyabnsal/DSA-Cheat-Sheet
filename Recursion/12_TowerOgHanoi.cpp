// #include<iostream>
// using namespace std;
// int main() {
//    int n, a;
//    cout<<"\nEnter the no of Disks: ";
//    cin>>n;
//    for (a = 1; a < (1 << n); a++) {
//       cout<<"\nDisk Move from Peg "<<(a&a-1)%3 <<" to Peg "<<((a|a-1)+1)%3;
//    }
//    cout<<"\n";
// }

// C++ recursive function to
// solve tower of hanoi puzzle
#include <bits/stdc++.h>
using namespace std;

void towerOfHanoi(int n, char A,char C, char B)
{
	if (n == 1){
		cout << "Move disk 1 from " << A <<" to " << C<<endl;
		return;
	}
	towerOfHanoi(n - 1, A, B, C);
	cout << "Move disk " << n << " from " << A <<" to " << C << endl;
	towerOfHanoi(n - 1, B, C, A);
}

// Driver code
int main()
{
	int n; cin>>n;
	towerOfHanoi(n, 'A', 'C', 'B'); // A, B and C are names of rods
	return 0;
}

// This is code is contributed by rathbhupendra
