#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct TreeNode{
	TreeNode *left;
	TreeNode *right;
	int val;

	TreeNode(int value) : val(value){
		left = right = NULL;
	}
};

vector<int> inOrder(TreeNode* root){
	vector<int> ans;
	if (root == NULL)
		return ans;
	else if ((root -> left == NULL) and (root -> right == NULL)){
			cout<<"BOOBSNN "<< root->val<<endl;

		ans.push_back(root -> val);
		return ans;
	}
	else if (root -> left == NULL){
			cout<<"BOOBS LN "<< root->val<<endl;

		ans.push_back(root -> val);
		vector<int> ans1 = inOrder(root -> right);
		ans.insert(ans.end(), ans1.begin(), ans1.end());
		return ans;
	}
	else if (root -> right == NULL){
			cout<<"BOOBS RN"<< root->val<<endl;

		vector<int> ans1 = inOrder(root -> left);
		ans1.push_back(root -> val);
		return ans1;
	}
	else {
			cout<<"BOOBS "<< root->val<<endl;

		vector<int> ans1 = inOrder(root -> left);
		ans1.push_back(root -> val);
		vector<int> ans2 = inOrder(root -> right);
		ans1.insert(ans1.end(), ans2.begin(), ans2.end());
		return ans1;
	}
}

TreeNode* balance(vector<int> ordered){
	if (ordered.empty() )
	{
		cout<<" THIS PART IS EMPTY"<<endl;
		return NULL;
	}
	else if (ordered.size() == 1){
		TreeNode Ans(ordered[0]);
		cout << ordered[0]<<" Balancing"<<endl;
			cout<<"BOOBS"<<"size 1"<<endl;
			for( auto &it: ordered)
				cout<< it<<endl;
		TreeNode *ans;
		ans->val = ordered[0];
		ans->right = ans->left = NULL;
		return ans;
	}
	else {
		cout<<"BOOBS"<<"size more"<<endl;
		for( auto &it: ordered)
			cout<< it<<endl;
		vector<int> left; 
		vector<int> right;
		int size = ordered.size();
		left.insert(left.end(), ordered.begin(), (ordered.begin()+(size/2)));
		cout<<"BOOBS l"<<endl;
		for( auto &it: left)
			cout<< it<<endl;
		right.insert(right.end(), (ordered.begin() + (size/2) + 1), ordered.end());
		cout<<"BOOBS r"<<endl;
		for( auto &it: right)
			cout<< it<<endl;
		TreeNode root(ordered[size/2]);
		cout<<root.val<<"balancing more"<<endl;
		cout<<"BOOBS c "<<root.val<<endl;
		TreeNode *r;
		r->val = ordered[size/2];
		
		r->left = balance(left);
		r->right = balance(right);
		return r;
	}
}

TreeNode* balanceThisTree(TreeNode *root)
{
	//return the root of the balanced BST
	vector<int> ordered = inOrder(root);
	// cout<<"BOOBS"<<endl;
	// for( auto &it: ordered)
	// 	cout<< it<<endl;
	return balance(ordered);

}



int main(){
	TreeNode aa(1);
	TreeNode* a = &aa; 
		// cout<<"BOOBS"<<endl;

	TreeNode bb(2);
	TreeNode* b = &bb; 
		// cout<<"BOOBS"<<endl;

	TreeNode cc(3);
	TreeNode* c = &cc; 
		// cout<<"BOOBS"<<endl;

	TreeNode dd(4);
	TreeNode* d = &dd; 
		// cout<<"BOOBS"<<endl;

	a -> right = b;
	b -> right = c;
	c -> right = d;

	// cout<<"BOOBS"<<endl;
	TreeNode* ans = balanceThisTree(a);
		// cout<<"BOOBS"<<endl;

	vector<int> ansvec = inOrder(ans);
	// 	cout<<"BOOBS"<<endl;


	for (int i = 0; i < ansvec.size(); i++)
		cout << ansvec[i] << " ";
	cout << endl;

	return 0;
}