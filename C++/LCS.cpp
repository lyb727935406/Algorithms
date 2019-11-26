#include<stdio.h>
#define MAX 1005

char l1[MAX];
char l2[MAX];
int result[101];
int score[MAX];
int newscore[MAX];

int LCS(int l1_len, int l2_len)
{
	int i = 0, j = 0;
	for(i = 0; i <= l1_len; i++)
	{
		score[i] = 0;
	}
	for(j = 1; j <= l2_len; j++)
	{
		newscore[0] = 0;
		for(i = 1; i <= l1_len; i++)
		{
			if(l2[j] == l1[i])
			{
				newscore[i] = score[i-1] + 1;
			}
			else
			{
				if(score[i] > newscore[i-1])
				{
					newscore[i] = score[i];
				}
				else
				{
					newscore[i] = newscore[i-1];
				}
			}
		}
		for(i = 1; i <= l1_len; i++)
		{
			score[i] = newscore[i];
		}
	}
	return score[l1_len];
}

int main()
{
/*	input:
	2
	4 4
	ABCD AEFC
	5 3
	SCFEZ BNI
	output:
	2
	0
	*/
	int n = 0, l1_len = 0, l2_len = 0;
	int i = 0, j = 0;
	char space;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d ",&l1_len,&l2_len);
		for(j = 1; j <= l1_len; j++)
		{
			scanf("%c",&l1[j]);
		}
		scanf("%c",&space);
		for(j = 1; j <= l2_len; j++)
		{
			scanf("%c",&l2[j]);
		}
		result[i] = LCS(l1_len,l2_len); 
	}
	for(i = 0; i < n; i++)
	{
		printf("%d\n",result[i]);
	}
	return 0;
}
