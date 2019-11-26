#include<iostream>
#include<vector>
using namespace std;

/* 
 *    OPT[i][k][0] = max{OPT[i-1][k][1] + v_i , OPT[i-1][k][0]}
 *    OPT[i][k][1] = max{OPT[i-1][k-1][0] - v_i , OPT[i-1][k][1]}

 * => OPT[k][0] = max{OPT[k][1] + v_i，OPT[k][0]}
 *    OPT[k][1] = max{OPT[k-1][0] - v_i，OPT[k][1]}

 */
class Solution{

public:
	int numsProfit(vector<int> &prices, int k) {
		int i = 0, j =0;
		int n = prices.size();
		/*在k超过天数一半时，因为最多只有n/2次交易，
		所以就利润最大值就是所有连续的峰和谷，
		此时已经与k无关。选用贪心*/
		if (k >= n / 2) {
            int res = 0;
            for (i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1]) {
                    res += prices[i] - prices[i - 1];
                }
            }
            return res;
        }
        int opt[k+1][2] = {0};
		for(i = 0; i<n; i++){
			for(j =k; j>=1; j--){
				if (i - 1 == -1) { 
                /* 处理 base case */
                	opt[j][0] = 0;
                	opt[j][1] = -prices[i];
                	continue;
            	}
				opt[j][0] = opt[j][1] + prices[i] > opt[j][0]?opt[j][1] + prices[i] : opt[j][0];
				opt[j][1] = opt[j-1][0] - prices[i] > opt[j][1]?opt[j-1][0] - prices[i] : opt[j][1];
			}
		}
		return opt[k][0];
    }
};

int main()
{
	//n=6,k=2,prices=[3,2,6,5,0,3]; 
	int k=0, n=0, temp = 0;  
	vector<int> V;
	cin >> n >> k;
	for(int i =0; i<n; i++){
		cin >> temp;
		V.push_back(temp);
	}
	Solution solution;
	cout << solution.numsProfit(V,k) <<endl;
	return 0;
}
