
// vector<int> solver(vector<int> input)
// {
//     unordered_map<int, int> umap;
//     int uniqCount = 0;
//     for( auto &it : input)
//         if( umap.find(it)== umap.end())
//             {umap[it] = 1; uniqCount++;}
//         else
//             umap[it]++;
    
//     vector<int> ret(input.size());
//     int skipLength = input.size() / uniqCount;
//     while( !umap.empty() )
//     {
//         keySet = umap.keyset();
//         vector<int> curr;
//         for( auto &it : keyset)
//         {
//             curr.pushback(it)
//             if(umap[it]==1)
//                 umap.removeKey(it);
//             else
//                 umap[it]--;
//         }

//         curr = fisheryates(curr)
//         int count = 0;
//         for(int i=0;i<input.size();i+=skiplength)
//             {
//                 int currElem = curr[count];
//                 searchForPosition()
//             }
//     }
// }

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std; 

vector<int> solver(vector<int> input)
{
    sort(input.begin(), input.end());
    vector<int> ret(input.size());
    int count = 0;
    for(int i=0;i<ret.size();i+=2)
    {
        ret[i] = input[count];
        count++;
    }
    for(int i=1;i<ret.size();i+=2)
    {
        ret[i] = input[count];
        count++;
    }

    return ret;
}

int main()
{
    vector<int> input = {1,1,2,2,3,3,3,3};
    input = solver(input);
    for( auto &it: input)
        cout<< it<<endl;
    
    return 0;
}