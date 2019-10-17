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

/*�˶�������һ�����⣬�����������������Ϊ��*/ 
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
    int maxDistance(TreeNode* &root) {
    	int ld = 0, rd = 0;
    	int d = tDepth(root->left) + tDepth(root->right);
    	/*ע���ж϶���Ϊ�յ����*/
    	if(root->left!=NULL){
    		ld = tDepth(root->left->left) + tDepth(root->left->right);
		}
    	if(root->right!=NULL){
    		rd = tDepth(root->right->left) + tDepth(root->right->right);
		}
    	return max(d,ld,rd);
        
    }
private:
	int tDepth(TreeNode* &root){
		if(root == NULL)
		{
			return 0;
		}
		else
		{
			int l = tDepth(root->left);
			int r = tDepth(root->right);
			return l>r?l+1:r+1;
		}	
	}
	
	int max(int a, int b, int c)
	{
		if(a>=b && a>=c)
			return a;
		if(b>=a && b>=c)
			return b;
		if(c>=a && c>=b)
			return c;
	}
};


int main()
{
	int ss = 0;
	TreeNode * tree = NULL;
	createBinaryTree(tree);
	//preTranVersing(tree);
	Solution solution;
	cout << solution.maxDistance(tree);
	
	return 0;
} 

