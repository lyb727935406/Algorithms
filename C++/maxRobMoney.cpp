#include<iostream>
#include<vector>
using namespace std;

//opt[i] = max {opt[i-2]+vi, opt[i-1]}
class Solution{

public:
	int rob(vector<int>& nums) {
		int len = nums.size();
		int pre = 0, now = 0;
        int i = 0, temp = 0;
		for(i = 0; i < len; i++) {
			temp = now;
			now = (pre + nums[i]) > temp ? (pre + nums[i]):temp;
			pre = temp;
		}
		return now;
    }
};

int main()
{
	int n = 0, i = 0, temp = 0, result = 0;  
	vector<int> house_money;
	cin >> n;
	for(i = 0; i < n; i++){
		cin >> temp;
		house_money.push_back(temp);
	}
	Solution solution;
	result = solution.rob(house_money);
	cout << result <<endl;
	return 0;
}
