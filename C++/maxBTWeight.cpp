#include<iostream>
#include<vector>
#include<cstdlib>
using namespace std;

/*�����������ο���https://blog.csdn.net/SunnyYoona/article/details/44114577*/ 
struct TreeNode
{
	int val;
	TreeNode * left;
	TreeNode * right;	
	TreeNode(int x):val(x),left(NULL),right(NULL){}
}; 

/*ǰ��������������������ӽڵ�ֵΪ-1*/ 
int createBinaryTree(TreeNode* &root)
{
	int data; 
	cin >> data;
	if(data != -1)
	{
		/*�����ڴ��ڶ��У��������غ��Դ���*/
		root = new TreeNode(data); 
		createBinaryTree(root->left);
		createBinaryTree(root->right);
	}
	else
	{
		root = NULL; /*����-1��ʾ�ýڵ����ӽڵ㣬������*/
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
	int maxBTWeight(TreeNode* &root){
		int select = 0, unselect = 0, max = 0;
		if(root == NULL){
			return 0;
		}
		if(root->left!=NULL){
			select += maxBTWeight(root->left->left) + maxBTWeight(root->left->right);
		}
		if(root->right!=NULL){
			select += maxBTWeight(root->right->left) + maxBTWeight(root->right->right);
		}
		select += root->val;
		unselect = maxBTWeight(root->left) + maxBTWeight(root->right);
		max = select>unselect ? select:unselect;
		return max;
	}
};


int main()
{
	int ss = 0;
	TreeNode * tree = NULL;
	createBinaryTree(tree);
	//preTranVersing(tree);
	Solution solution;
	cout << solution.maxBTWeight(tree);
	
	return 0;
} 
