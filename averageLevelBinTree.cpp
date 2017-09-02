/**
Given a non-empty binary tree, return the average value of the nodes on each level in the form of an array.
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        std::vector<double> ret;
        std::queue<std::pair<TreeNode* , int>> q;
        q.push(std::make_pair(root, 0));
        long long sum = 0;
        int currLevel = 0;
        int prevLevel = 0;
        int currLevelElems = 0;
        while(!q.empty()){
            std::pair<TreeNode*, int> currPair = q.front();
            q.pop();
            currLevel = currPair.second;
            cout<<currLevel<<" "<<currPair.first->val<<endl;
            if(currLevel != prevLevel)
            {
                ret.push_back( (1.0*sum/currLevelElems));
                sum = currPair.first->val;
                currLevelElems = 1;
                prevLevel = currLevel;
            }
            else
            {
                sum += currPair.first->val;
                currLevelElems ++ ;
            }
            
            if(currPair.first->left!=NULL)
                q.push(std::make_pair(currPair.first->left, currLevel+1));
            if(currPair.first->right!=NULL)
                q.push(std::make_pair(currPair.first->right, currLevel+1));
        }
        ret.push_back((1.0*sum/currLevelElems));
        return ret;
    }
};