#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define loop(i,a,b) for(int i=a;i<b;i++)

int main(){

    int a[5]={5,1,2,6,3};
    loop(i,0,5){
        cout<<a[i]<<"";
    }
    set<int> s = {2,5,6,8};
    cout << s.size() << "\n"; // 4
    for (auto x : s) {
    cout << x << "\n";
    }

    return 0;
}
