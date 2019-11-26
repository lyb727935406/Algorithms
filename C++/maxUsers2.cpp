#include<stdio.h>
#define TASK_NUM_MAX 1001
#define USER_MAX 100000001

typedef struct task_struct{
	int spc;
	int mem;
	int num;
}itask;

itask task[TASK_NUM_MAX]={0};
int opt[TASK_NUM_MAX][TASK_NUM_MAX] = {0};

/* 
 *    OPT[i][m][n] = max{OPT[i-1][m-Xi][n-Yi]+Ui£¬OPT[i-1][m][n]}
 * => OPT[m][n] = max{OPT[m-Xi][n-Yi]£¬OPT[m][n]}
 */
void maxUsers(int spc, int mem, int num)
{
	int i = 0, j = 0, k = 0;
	for(i = 1; i <= num; i++ )
	{
		for(j = spc; j >= task[i].spc; j--)
		{
			for(k = mem; k >= task[i].mem; k--)
			{
				int tspc = task[i].spc;
				int tmem = task[i].mem;
				int tnum = task[i].num;
				if(opt[j][k] < opt[j-tspc][k-tmem] + tnum)
				{
					opt[j][k] = opt[j-tspc][k-tmem] + tnum;
				}
			}
		}
	}
}
int main()
{
	/*
	15 10 4
	5 1 1000
	2 3 3000
	5 2 15000
	10 4 16000
	
	output:31000
	*/
	int m=0, n=0, k=0, i=0;
	int user_num=0;
	scanf("%d%d%d",&m,&n,&k);
	for(i = 1; i <= k; i++)
	{
		scanf("%d%d%d",&task[i].spc,&task[i].mem,&task[i].num);
	}
	maxUsers(m,n,k);
	printf("%d\n",opt[m][n]);
	return 0;
}
