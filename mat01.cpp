#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int> > updateMatrix(vector<vector<int> >& matrix) {
        cout<<"HERE"<<endl;
        if (matrix.empty()) return matrix;
        if (matrix[0].empty()) return matrix;

                cout<<"HERE"<<endl;

        for (int i = 0; i < matrix.size(); i++){
            for (int j = 0; j < matrix[0].size(); j++){
                if (matrix[i][j] != 0){
                    if ((i>0) and (j>0))
                        matrix[i][j] = min(matrix[i-1][j], matrix[i][j-1]) + 1;
                    else if (i>0)
                        matrix[i][j] = matrix[i-1][j] + 1;
                    else if (j>0)
                        matrix[i][j] = matrix[i][j-1] + 1;
                }
            }
        }
                cout<<"HERE"<<endl;

        for (int i = matrix.size()-1; i >=0; i--){
            for (int j = matrix[0].size()-1; j>=0; j--){
                if(matrix[i][j]!=0){
                    if ((i < matrix.size()-1) and (j < matrix[0].size() -1))
                    {matrix[i][j] = min(matrix[i+1][j], matrix[i][j+1], (matrix[i][j] -1)) + 1;}
                     else if (i < matrix.size() -1)
                     {matrix[i][j] = min(matrix[i+1][j], (matrix[i][j] -1)) + 1;}
                     else if (j < matrix[0].size() -1)
                     {matrix[i][j] = min(matrix[i][j+1], (matrix[i][j] -1)) + 1;}
                }
            }
        }
        return matrix;
    }
};

int main()
{
    Solution sol;
    vector<vector<int> > mat;
    mat = {{0,0,0},{0,1,0},{0,1,1}};
    sol.updateMatrix(mat);
    for(int i=0;i<mat.size();i++)
    {
        for(int j=0;j<mat[0].size();j++)
            cout<<mat[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
