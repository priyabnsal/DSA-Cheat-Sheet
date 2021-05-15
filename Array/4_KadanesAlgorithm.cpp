#include <iostream>
#include<vector>
using namespace std;

int main(){
    vector<int> a={2,3,2,4,-1,2,3,-2};
    int n=a.size();
    int max_sum=INT8_MIN;
    int curSum=0;
    for (int i = 0; i < n; i++)
    {
        curSum+= a[i];
 
        if(curSum>max_sum){
            max_sum=curSum;
        }
         if(curSum<0)
                curSum=0;
    }
    cout<<"Max Sum is "<<max_sum;
    
}