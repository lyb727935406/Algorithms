#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*二叉树创建参考：https://blog.csdn.net/SunnyYoona/article/details/44114577*/ 
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;	
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}; 

int createBinaryTree(TreeNode* &root)
{
	int data; 
	cin >> data;
	if(data != -1)
	{
		/*申请内存在堆中，函数返回后仍存在*/
		root = new TreeNode(data); 
		createBinaryTree(root->left);
		createBinaryTree(root->right);
	}
	else
	{
		root = NULL; /*输入-1表示该节点无子节点，即空树*/
	}
	return 0;
}

void preTranVersing(TreeNode* &root)
{
	if(root != NULL)
	{
		printf("%d ", root->val);
		preTranVersing(root->left);
		preTranVersing(root->right);
	}
}

class Solution {
public:
    int findLocalMin(TreeNode* &root) {
    	int v = root->val;
    	int l_v = root->left->val;
    	int r_v = root->right->val;
		if(v<l_v && v<r_v){
			return v;
		}
		if(l_v<v && l_v<r_v){
			return findLocalMin(root->left);
		}	
		if(r_v<v && r_v<l_v)		
		{
			return findLocalMin(root->right); 
		}
    }
};


int main()
{
	int ss = 0;
	TreeNode * tree = NULL;
	createBinaryTree(tree);
	//preTranVersing(tree);
	Solution solution;
	cout << solution.findLocalMin(tree);
	
	return 0;
} 
