#include<iostream>
#include<cstdio>
#include<vector>
//倍增法实现最近公共祖先
/*
#define MAXN 40005
#define MAX_INDEX 25
using namespace std;
void swap(int &i, int&j)
{
	int temp = i;
	i = j;
	j = temp;
}
struct Node
{
	int to;
	int v;
	Node() = default;
	Node(int to_, int v_)
	{
		to = to_;
		v = v_;
	}
};
int dis[MAXN];
int depth[MAXN];
vector<Node> tree_child[MAXN];
int grand[MAXN][MAX_INDEX];
int mark[MAXN];
void add(int fa, Node son)
{
	tree_child[fa].push_back(son);
}
void dfs(int root, int d)
{
	depth[root] = d;
	mark[root] = 1;
	for (int i = 0; i<tree_child[root].size(); ++i) {
		Node son = tree_child[root][i];
		if (!mark[son.to]) {
			dis[son.to] = dis[root] + son.v;
			dfs(son.to, d + 1);
			grand[son.to][0] = root;

		}
	}
}
void grand_clear()
{
	for (int i = 0; i<MAXN; ++i) {
		grand[i][0] = 0;
		tree_child[i].clear();
		mark[i] = 0;
	}
}
void init(int n)
{
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i <= n; ++i) {
			grand[i][j] = grand[grand[i][j - 1]][j - 1];
		}
	}
}
int jump(int node, int target_depth, int node_depth)
{
	int k = node_depth - target_depth;
	for (int i = 0; (1 << i) <= k; ++i) {
		if ((1 << i)&k) {
			node = grand[node][i];
		}
	}
	return node;
}
int query_LCA(int a, int b)
{
	if (depth[a]>depth[b]) {
		swap(a, b);
	}
	b = jump(b, depth[a], depth[b]);
	if (a != b) {
		for (int i = MAX_INDEX - 1; i >= 0; --i) {
			if (grand[a][i] != grand[b][i]) {
				a = grand[a][i];
				b = grand[b][i];
			}
		}
		a = grand[a][0];
	}
	return a;
}
*/