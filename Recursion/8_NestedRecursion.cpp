// Nested Recursion
#include <iostream>
using namespace std;

int fun(int n)
{
    if(n>100)
        return n-10;
    return fun(fun(n+11));
}
int main()
{
    int r;
    r=fun(95);
    cout<<r<<" ";
    return 0;
}

// fun(fun(95+11)) => fun(fun(106))
//                     fun(106) => n-10= 96
//                     fun(fun(96-11))=> fun(fun(86=5))
