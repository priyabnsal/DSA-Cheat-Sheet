#include<bits/stdc++.h>
#include<iostream>
using namespace std;

void insertAtBack(vector<int> &v, int temp){
    if(v.size()==0 || v[v.size()-1]<=temp){
        v.push_back(temp);
        return;
    }
    int val= v[v.size()-1];
    v.pop_back();
    insertAtBack(v,temp);
    v.push_back(val);
    return;
}

void sortArray(vector<int> & v){
    if(v.size()==1) return ;
    int temp=v[v.size()-1];
    v.pop_back();
    sortArray(v);
    insertAtBack(v,temp);
}

int main(){

    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(1);
    v.push_back(5);
    v.push_back(4);

    int n = v.size();
    sortArray(v);
     for (auto i : v) {
       cout<<i<<" ";
    }
    return 0;
}