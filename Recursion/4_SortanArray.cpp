#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void insertAtBack(vector<int> &v, int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int val=v.back();
    // int val= v[v.size()-1];
    v.pop_back();
    insertAtBack(v,temp);
    v.push_back(val);
    return;
}

void sortArray(vector<int> & v){
    if(v.size()==1) return ;
    int temp=v.back();
    // int temp=v[v.size()-1];
    v.pop_back();
    sortArray(v);
    insertAtBack(v,temp);
}

int main(){

    vector<int> v={1,4,3,5,6,7,1,2,3};

    int n = v.size();
    sortArray(v);
     for (auto i : v) {
       cout<<i<<" ";
    }
    return 0;
}