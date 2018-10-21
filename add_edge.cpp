#define MAXN 100005
struct Node
{
	int to;
	//int v;
	int next;
	Node() = default;
};
int mark[MAXN];
int K;//³õÖµÎª1;
void add(int fa, Node son)
{
	son.next = head[fa];
	head[fa] = K;
	edge[K] = son;
	++K;
}
void dfs(int root)
{
	/*
	...
	*/
	for (int i = head[root]; i != 0; i = edge[i].next) {
		Node& son = edge[i];
		if (!mark[son.to]) {
			/*
			...
			*/
			dfs(son.to, d + 1, count);
			/*
			...
			*/
		}
	}
	/*
	...
	*/
}