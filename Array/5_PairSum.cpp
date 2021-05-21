#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
vector<int> pairSum(vector<int> &v,int sum){

    vector<int> result;
    unordered_set<int> s;

    for (int i = 0; i < v.size(); i++)
    {
        int x=sum-v[i];
        if(s.find(x)!=s.end()){
            result.pb(x);
            result.pb(v[i]);
            return result;
        }
    s.insert(v[i]);
        
    }
    return {};
}

int main(){
    vector<int> v={10,2,3,5,-6,9};
    int s=4;
    for(auto i :v){
        cout<<i<<" ";
    }
    cout<<endl;
    cout<<"PairSum is ";
    auto p = pairSum(v,s);
    if(p.size()==0)
        cout<<"No such pair";
    else
        cout<<p[0]<<", "<<p[1]<<endl;
    
}