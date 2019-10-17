#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		/*�������δѭ����ֻ��һ��Ԫ�أ��򷵻ص�һ��Ԫ��*/ 
		if (len == 1 || nums[0] < nums[len - 1])
			return nums[0];
		return rotatedSortedFindMin(nums, 0, len - 1);
	}
private:
	/*���ֲ�����Сֵ*/ 
	int rotatedSortedFindMin(vector<int> &nums, int l, int r) {
		/*���������ֻ��һ��Ԫ�أ��򷵻ش�Ԫ��*/ 
		if (nums[l] < nums[r] || l == r) {
			return nums[l];
		}
		int pivot = (r + l) / 2;
		if (nums[pivot] < nums[l]) {
			return rotatedSortedFindMin(nums, l, pivot);
		}
		else if (nums[pivot] > nums[l]) {
			return rotatedSortedFindMin(nums, pivot + 1, r);
		}
		/*�������Ԫ����Ԫ����ͬһ����˵����ʱֻ������Ԫ�أ��򷵻�С���Ǹ�*/ 
		else if (nums[pivot] == nums[l]) {
			return nums[pivot] < nums[pivot + 1] ? nums[pivot] : nums[pivot + 1];
		}
		return -1;
	}
};

int main()
{
	/*Leetcode 153*/
	vector<int> a;
	int i, min;
	/*��������ĸ����*/
	while(cin>>i)
	{
		a.push_back(i);
	}
	Solution solution;
	cout << solution.findMin(a);
	
	return 0;
} 

