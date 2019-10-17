#include<iostream>
#include<vector>

using namespace std;

#define INF 1000000000;
class Solution{
public:
	int findGridLocalMin(vector< vector<int> > &G, int n){
		int min = 0;
		if(n == 1)
			return G[0][0];
		else{
			min = gProbe(G, n, 0, 0);
		}
		return min;
	}
private:
	int gProbe(vector< vector<int> > &G, int n, int i, int j){
		//探测上下左右，如果i,j最小则返回v(i,j)，否则探测值最小的那个点 
		int t = minPoint(G, n, i, j);
		switch(t){
			case 0:return G[i][j];break;
			case 1:gProbe(G, n, i, j+1);break;
			case 2:gProbe(G, n, i+1, j);break;
			case 3:gProbe(G, n, i, j-1);break;
			case 4:gProbe(G, n, i-1, j);break;
			default:break;
		}	
	}
	
	//选出上下左右中五个值中的最小值 
	int minPoint(vector< vector<int> > &G, int n, int i, int j)
	{
		int tmp[5];
		int a = 0, min = 0;
		tmp[0] = G[i][j];
		if(j+1<n){
			tmp[1] = G[i][j+1];
		}
		else{
			tmp[1] = INF;
		}
		if(i+1<n){
			tmp[2] = G[i+1][j];
		}
		else{
			tmp[2] = INF;
		}
		if(j-1>=0){
			tmp[3] = G[i][j-1];
		}
		else{
			tmp[3] = INF;
		}
		if(i-1>=0){
			tmp[4] = G[i-1][j];
		}
		else{
			tmp[4] = INF;
		}
		for(a=0; a<5; a++ )
		{
			if(tmp[a] < tmp[min]){
				min = a;
			}
		}
		return min;
	}

};

int main()
{
	int n = 0, i = 0, j = 0, t = 0;
	int result = 0;
	vector< vector<int> > grid;
	vector<int> row;
	cin >> n;
	for(i = 0; i<n; i++){
		row.clear();
		for(j = 0; j<n; j++){
			cin >> t;
			row.push_back(t);
		}
		grid.push_back(row);
	}
	Solution solution;
	result = solution.findGridLocalMin(grid , n);
	cout << result <<endl;
	return 0; 
} 
