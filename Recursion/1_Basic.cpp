#include<bits/stdc++.h>
using namespace std;

int fan(int n){
    if(n==0) return 1;
    // cout<<n<<endl;
    return fan(n-1)*n;
}

void fun(int n){

    if(n==0) return;
    cout<<n<<endl;
    // Op: 54321
    fun(n-1);
    cout<<n<<endl;
    // op:12345

}
void print(int n){
    if(n==0){
        // cout<<n;
        return;
    }
    cout<<n;
    print(n-1);
}
int main(){
   
    cout<< fan(5)<<" ";
    fun(5);
    cout<<"Print";
    print(7);
}