#include<iostream>
#include<vector>
using namespace std;

/* 
 *     OPT[i][w]= ¡ÆOPT[i-1][w-k*v_i] (k=0..n)
 * =>  OPT[i][w] = OPT[i-1][w] + OPT[i-1][w-v_i]
 * =>  OPT[w] = OPT[w] + OPT[w-v_i] 
 *
 */
class Solution{

public:
	int numsCoinChange(vector<int> &coin, int W) {
		int i = 0, w = 0;
		int n = coin.size();
		int opt[W+1]={0};
		opt[0] = 1;
		for(i = 1; i<=n; i++){
			for(w = 1; w<=W; w++){
				if(w>=coin[i-1]){
					opt[w] = opt[w] + opt[w-coin[i-1]];
				}
			}
		}
		return opt[W]; 
    }
};

int main()
{
	//n=3,W=5,coin=[1,2,5]; 
	int W=0, n=0, temp = 0;  
	vector<int> V;
	cin >> n >> W;
	for(int i =0; i<n; i++){
		cin >> temp;
		V.push_back(temp);
	}
	Solution solution;
	cout << solution.numsCoinChange(V,W) <<endl;
	return 0;
}
