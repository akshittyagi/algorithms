#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Comparator{
	bool operator()(const pair<int, int> &a, const pair<int, int> &b){
		return a.first>b.first;
	}
};

vector<int> mergeArrays (vector<vector<int> > arrays){
	vector<int> ans;
	int numArrays = arrays.size();
	if (numArrays == 0) return ans;
	int sizeArray = arrays[0].size();
	if (sizeArray == 0) return ans;

	//in pq, first elem is number, second elem is vector it comes from
	priority_queue<pair<int, int> , vector<pair<int, int> > , Comparator> pq;
	vector<int> index;
	for (int i = 0; i < numArrays; i++){
		index.push_back(0);
		pq.push(make_pair(arrays[i][0], i));
	}
	for (int i = 0; i < numArrays*sizeArray; i++){
		int num = pq.top().first;
		int whichArray = pq.top().second;
		pq.pop();
		ans.push_back(num);
		index[whichArray]++;
		if(index[whichArray]<sizeArray)
			pq.push(make_pair(arrays[whichArray][index[whichArray]], whichArray));
	}	

	return ans;
}


int main (){
	vector<int> a = {1,3,5,7,9};
	vector<int> b = {2,4,6,8,10};
	vector<int> c = {-1,-2,-3,5,8};

	vector<vector<int> > abc = {a,b,c};

	vector<int> ans = mergeArrays(abc);

	for (auto &it: ans)
		cout<<it<<" ";
	cout<<endl;

	return 0;
}
