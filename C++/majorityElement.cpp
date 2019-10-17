#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int majorityElement(vector<int> &A){
		int len = A.size();
		int i = 0, key = 0, cnt = 1;
		key = A[0];
		for(i = 1; i < len; i++){
			if(A[i] == key){
				cnt++;
			}
			else{
				cnt--;
			}
			if(cnt == 0){
				key = A[i+1];
			}
		}
		return key;
	}
};

int main()
{
	vector<int> a;
	int n = 0, i = 0, temp = 0, result = 0;
	Solution solution;
	cin >> n;
	for(i = 0; i<n; i++){
		cin >> temp;
		a.push_back(temp);
	} 
	result = solution.majorityElement(a);
	cout << result << endl;
	return 0;
}
