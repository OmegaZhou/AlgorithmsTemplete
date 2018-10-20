#include<iostream>
#include<cstdio>
#include<vector>
//倍增法实现最近公共祖先
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

//RMQ算法求最近公共祖先
#define MAXN 100005
#define MAXJ 20 
struct QueryNode
{
	int depth;
	int id;
	friend bool operator<(const QueryNode& i, const QueryNode& j)
	{
		return i.depth < j.depth;
	}
};
QueryNode rmq[2 * MAXN][MAXJ];
QueryNode num[2 * MAXN];
int mark[MAXN];
void init(int n)
{
	for (int i = 1; i <= n; ++i) {
		rmq[i][0] = num[i];
	}
	for (int j = 1; (1 << j) <= n; ++j) {
		for (int i = 1; i + (1 << j) - 1 <= n; ++i) {
			rmq[i][j] = min(rmq[i][j - 1], rmq[i + (1 << (j - 1))][j - 1]);
		}
	}
}
QueryNode RMQ(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1)) <= r - l + 1) {
		++k;
	}
	return min(rmq[l][k], rmq[r - (1 << k) + 1][k]);
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
int r[MAXN];
int dis[MAXN];
int depth[MAXN];
vector<Node> tree_child[MAXN];
void add(int fa, Node son)
{
	tree_child[fa].push_back(son);
}
void dfs(int root, int d, int &count)
{
	depth[root] = d;
	mark[root] = 1;
	num[count].depth = depth[root];
	num[count].id = root;
	r[root] = count;
	++count;
	for (int i = 0; i<tree_child[root].size(); ++i) {
		Node son = tree_child[root][i];
		if (!mark[son.to]) {
			dis[son.to] = dis[root] + son.v;
			dfs(son.to, d + 1, count);
			num[count].depth = depth[root];
			num[count].id = root;
			++count;
		}
	}
}
void LCA_init(int n)
{
	init(2 * n - 1);
}
QueryNode query(int a, int b)
{
	if (r[a] > r[b]) {
		swap(a, b);
	}
	return RMQ(r[a], r[b]);
}
void LCA_clear(int n = MAXN - 1)
{
	for (int i = 1; i <= n; ++i) {
		vector<Node> x;
		tree_child[i].swap(x);
		tree_child[i].clear();
		mark[i] = 0;
	}
}
