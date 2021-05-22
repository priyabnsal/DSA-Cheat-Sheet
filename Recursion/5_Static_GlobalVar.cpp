#include<bits/stdc++.h>
#include<iostream>
using namespace std;

//Globally declare=> value of x remains same
int x=0;

int glob(int n)
{
    if(n>0){
       x++;
        return glob(n-1)+x; //x is returned at return time firstly fun is exectued
    }
    return 0;
}
int stat(int n)
{
    // Static Value of x remains same
    static int y=0; 
    if(n>0){
       y++;
        return stat(n-1)+y; //x is returned at return time firstly fun is exectued
    }
    return 0;
}
int fun1(int n)
{
    if(n>0){
        return fun1(n-1)+n;
    }
    return 0;
}

int main(){

    int r;
    cout<<"Function 1 for n: ";
    cout<<fun1(5)<<endl;
    cout<<"Global variale x: ";
    cout<<glob(5)<<endl;
    cout<<"Static variale y: ";
    cout<<stat(5)<<" ";

    
    return 0;   
}