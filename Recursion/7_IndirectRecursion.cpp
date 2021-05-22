// Indirect Recursion => when a func call another fun 
// like Fun(a) calls fun(b), 
// Fun(b) calls fun(c), 
// fun(c) calls fun(A)

// Recursive Tree below ⬇
#include <iostream>
using namespace std;
void funB(int n);

void funA(int n)
{
    if(n>0){
        cout<<"A "<<n<<", ";
        funB(n-1);
    }
}

void funB(int n)
{
    if(n>1)
    {
        cout<<"B "<<n<<" ";
        funA(n/2);
    }
}
int main()
    {
    funA(20);
    return 0;
}

// Recursive Tree
//   fun a(20)
// 20  funb(19)
//     19  funA(9)
//         9   funB(8)
//             8   funA(4)
//                 4   funB(3)
//                     3   funA(2)
//                         2   funB(1)
//                             1   Stop