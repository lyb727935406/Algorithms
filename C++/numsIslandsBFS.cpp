#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution{
public:
	typedef pair<int,int> P;
	int numsIslandsBFS(vector<vector<int> > &map, int m, int n){
		int i = 0, j = 0, a = 0, b = 0, count = 0;
		queue<P> unprobe_point;
		for(i =0; i < m; i++)
		{
			for(j = 0; j < n; j++)
			{
				if(unprobe_point.size()==0 && map[i][j]==1)
				{
					unprobe_point.push(P(i,j));
					map[i][j] = -1;
					count++;
				}
				while(!unprobe_point.empty())
				{
					P front = unprobe_point.front();
					a = front.first;
					b = front.second;
					unprobe_point.pop();
					if(a-1>=0 && map[a-1][b]==1)
					{
						unprobe_point.push(P(a-1,b));
						map[a-1][b]=-1;
					}
					if(b+1<n && map[a][b+1]==1)
					{
						unprobe_point.push(P(a,b+1));
						map[a][b+1]=-1;
					}
					if(a+1<m && map[a+1][b]==1)
					{
						unprobe_point.push(P(a+1,b));
						map[a+1][b]=-1;
					}
					if(b-1>=0 && map[a][b-1]==1)
					{
						unprobe_point.push(P(a,b-1));
						map[a][b-1]=-1;
					}
				}			
			}
		}
		return count; 
	}
};

int main()
{
	vector<vector<int> > G;
	vector<int> row;
	int m = 0, n = 0, i = 0, j = 0, temp = 0, result = 0;
	Solution solution;
	
	cin >> m >> n;
	for(i = 0; i < m; i++){
		row.clear();
		for(j = 0; j < n; j++){
			cin >> temp;
			row.push_back(temp);
		}
		G.push_back(row);
	}
	result = solution.numsIslandsBFS(G, m, n);
	cout << result <<endl;
	return 0;
}
