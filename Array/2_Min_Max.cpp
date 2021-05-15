// Maximum and minimum of an array using minimum number of comparisons
// Ques Link https://www.geeksforgeeks.org/maximum-and-minimum-in-an-array/

#include<iostream>
using namespace std;

struct Pair{
    int min;
    int max;
};

struct Pair getMINMax (int arr[], int n)
{
    struct Pair minmax;
    int i;

    if(n==1){
        minmax.min=arr[0];
        minmax.max=arr[0];
        return minmax;
    }

    if (arr[0]>arr[1])
    {
        minmax.min=arr[1];
        minmax.max=arr[0];
    }
    else{
         minmax.min=arr[0];
        minmax.max=arr[1];
    }
    for (int i = 2; i <n; i++)
    {
        if(arr[i]>minmax.max){
            minmax.max=arr[i];
        }
        else if(arr[i]<minmax.min){
            minmax.min=arr[i];
        }
    }
        return minmax;
    
};


int main(){
    int arr[]={100,600,200,300,400,500};
    int size=6;

    struct Pair minmax= getMINMax(arr, size);

    cout<< "Min   "<<minmax.min<<endl;
    cout<< "Max   "<<minmax.max<<endl;
}

