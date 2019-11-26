#include<iostream>
using namespace std;

/* i是每个子问题的长度 
OPT[i] = 求和(OPT[k-1] * OPT[i-k]) 
*/
class Solution{

public:
	int numBST(int n) {
		int i = 0, k = 0;
		int opt[n+1]={0};
		if(n == 0){
			return 0;
		}
		opt[0] = 1;
		opt[1] = 1;
		for(i = 2; i<=n; i++){
			for(k = 1; k<=i; k++){
				opt[i] += opt[k-1]*opt[i-k];
			}
		}
		//cout << opt[n] << endl;
		return opt[n]; 
    }
};

int main()
{
	int n;  
	cin >> n;
	Solution solution;
	cout << solution.numBST(n) <<endl;
	return 0;
}
