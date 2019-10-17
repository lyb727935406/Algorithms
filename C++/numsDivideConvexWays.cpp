#include<iostream>
using namespace std;

//This problem can be proved by Catalan number
class Solution{
public:
	int numsDivideConvexWays(int n){
		int num = 0;
		if(n == 3){
			return 0;
		}
		else{
			num = numsDC(n);
		}
		return num;
	}
private:
	int numsDC(int n){
		int number = 0;
		int k = 2;
		if(n == 2 || n==3)
			return 1;
		for(k = 2; k<n; k++){
			number += numsDC(k)*numsDC(n-k+1);
		}
		return number;
	}
};


int main()
{
	int n = 0, result = 0;
	cin >> n;
	Solution solution;
	result = solution.numsDivideConvexWays(n);
	cout << result << endl;
}
