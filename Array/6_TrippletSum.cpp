#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<vector<int> > triplets(vector<int> v,int targetSum){
	//Logic 
	sort(v.begin(),v.end());
    vector<vector<int>> result;
    int n=v.size();
    for (int i = 0; i < n-3; i++)
    {
        int j=i+1;
        int k=n-1;
        while (j<k)
        {
            int curSum=v[i];
            curSum+=v[j];
            curSum+=v[k];

            if(curSum==targetSum){
                result.push_back({v[i],v[j],v[k]});
                j++; k--;
            }
            else if(curSum > targetSum)
                k--;
            else 
                j++;
        }
    }
	return result;
}

int main(){

	vector<int> arr{1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

	auto result = triplets(arr,S);

	for(auto v : result){
		for(auto no : v){
			cout<<no<<",";
		}
		cout<<endl;
	}


	return 0;
}