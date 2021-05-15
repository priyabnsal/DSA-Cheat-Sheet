#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<string>
using namespace std;

int main(){
    // map<string,int> mp;
    // mp["p"]=22;
    // mp["a"]=8;
    // mp["v"]=92;
    // map<string,int>:: iterator it;
    // cout<<"Key"<<" "<<"Value";
    // for(it=mp.begin();it!=mp.end();it++){
    //     cout<<it->first<<" "<<it->second<<endl;
    // }
    cout<<"2nd way"<<endl;
    map<int,int> mp1;
    mp1.insert(pair<int, int>(10, 40));
    mp1.insert(pair<int, int>(2, 30));
    mp1.insert(pair<int, int>(3, 60));
    mp1.insert(pair<int, int>(4, 20));
    mp1.insert(pair<int, int>(5, 50));

    for(auto it1=mp1.begin();it1!=mp1.end();it1++){
        cout<<it1->first<<" "<<it1->second<<endl;
    }
    return 0;
}