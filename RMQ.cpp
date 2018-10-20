#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
//求区间最值
#define MAXN 300000
#define MAXJ 20 
int rmq[MAXN][MAXJ];
int num[MAXN];
void init(int n)
{
	for (int i = 1; i <= n; ++i) {
		rmq[i][0] = num[i];
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			rmq[i][j] = max(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
		}
	}
}
int RMQ(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) {
		++k;
	}
	return max(rmq[l][k], rmq[r - (1 << k) + 1][k]);
}