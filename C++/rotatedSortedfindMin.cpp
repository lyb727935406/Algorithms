#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int>& nums) {
		int len = nums.size();
		/*如果数组未循环或只有一个元素，则返回第一个元素*/ 
		if (len == 1 || nums[0] < nums[len - 1])
			return nums[0];
		return rotatedSortedFindMin(nums, 0, len - 1);
	}
private:
	/*二分查找最小值*/ 
	int rotatedSortedFindMin(vector<int> &nums, int l, int r) {
		/*如果分组中只有一个元素，则返回此元素*/ 
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
		/*如果中心元和首元素是同一个，说明此时只有两个元素，则返回小的那个*/ 
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
	/*以任意字母结束*/
	while(cin>>i)
	{
		a.push_back(i);
	}
	Solution solution;
	cout << solution.findMin(a);
	
	return 0;
} 

