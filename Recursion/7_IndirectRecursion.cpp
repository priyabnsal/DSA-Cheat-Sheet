// Indirect Recursion => when a func call another fun 
// like Fun(a) calls fun(b), 
// Fun(b) calls fun(c), 
// fun(c) calls fun(A)

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