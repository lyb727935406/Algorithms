#include<iostream>
#include<vector>
using namespace std;

class Solution{
public:
	int sortAndCountInversion(vector<int> &A, vector<int> &B, int left, int right){
		int rc = 0, sum = 0, mid = 0;
		mid = (left + right)/2;
		if(left == right){
			sum = 0;
		}
		else{
			sum += sortAndCountInversion(A, B, left, mid);
			sum += sortAndCountInversion(A, B, mid+1, right);
			sum += mergeAndCountInversion(A, B, left, right, mid);
		}
		return sum;
	}
private:
	int mergeAndCountInversion(vector<int> &A, vector<int> &B, int l, int r, int mid){
		int i = 0, j = 0, k = 0, rc = 0;
		i = l;
		j = mid + 1;
		//����ͨ����Ե���������Ҫ��������������������� 
		for(k = l; k < r+1; k++){
			if(i <= mid && j <= r){
				if(A[i] > (long long)3 * A[j]){
					rc += (mid + 1 - i);
					j++;
				}
				else{
					i++;
				}
			}
		}
		i = l;
		j = mid + 1;
		for(k = l; k < r+1; k++){
			B[k] = A[k];
		}
		for(k = l; k < r+1; k++){
			//�߽�������������һ�������Ѿ�ȫ������A�� 
			if(i > mid && j <= r){
				A[k] = B[j];
				j++;
			}
			if(j > r && i <= mid){
				A[k] = B[i];
				i++;
			}
			if(i <= mid && j <= r){
				if(B[i] >  B[j]){
					A[k] = B[j];
					j++;
				}
				else{
					A[k] = B[i];
					i++;
				}
			}
		}
		return rc;
	}
};

int main(){
	int result = 0, n = 0, i = 0, temp = 0;
	vector<int> array, tarray;
	cin >> n;
	for(i = 0; i<n; i++)
	{
		cin >> temp;
		array.push_back(temp);
		tarray.push_back(temp);
	}
	Solution solution;
	result = solution.sortAndCountInversion(array, tarray, 0, n-1);
	cout << result << endl;
	return 0;
}
