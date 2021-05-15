#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    set<int> s = {10,5,2,5,6,8};
    cout<<"Size "<< s.size() << "\n"; // 4
    for (auto x : s) {
    cout << x << "\t";
    }
    return 0;
}

