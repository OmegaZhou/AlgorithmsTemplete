
//线段树
#define MAXN 100005
#define ILLGAL 0
int min(int a, int b)
{
	return a<b ? a : b;
}
long long quick_pow(long long base, long long exp, long long mod_value)
{
	long long k = base;
	long long result = 1;
	while (exp != 0) {
		if (exp % 2) {
			result *= k;
			result %= mod_value;
		}
		k *= k;
		k %= mod_value;
		exp /= 2;
	}
	return result;
}

#define ILLGAL INF
struct Tree_Node
{
	int value;
	int l;
	int r;
	int lazy;
	Tree_Node()
	{
		value = 0;
		l = 0;
		r = 0;
		//lazy = 0;
	}
};

struct Segment_Tree
{
	Tree_Node tree_node[4 * MAXN];
	void build_tree(int id, int l, int r)
	{
		//给lazy赋初值
		//tree_node[id].lazy = 0;
		tree_node[id].l = l;
		tree_node[id].r = r;
		if (l == r) {
			init(id, l);
		} else {
			int mid = (l + r) / 2;
			build_tree(id * 2, l, mid);
			build_tree(id * 2 + 1, mid + 1, r);
			update_from_son(id);
		}
	}

	void init(int id, int position)
	{
		//赋初值为0
		/*
		tree_node[id].value = 0;
		*/
	}
	void update_from_son(int id)
	{
		//求最小值
		/*
		tree_node[id].value = min(tree_node[id * 2].value, tree_node[id * 2 + 1].value);
		*/
	}

	int query(int id, int q_l, int q_r)
	{
		if (tree_node[id].r<q_l || tree_node[id].l>q_r) {
			return ILLGAL;
		}
		if (tree_node[id].l >= q_l && tree_node[id].r <= q_r) {
			return tree_node[id].value;
		} else {
			give_lazy_to_son(id);
			int a = query(id * 2, q_l, q_r);
			int b = query(id * 2 + 1, q_l, q_r);
			return merge_value(a, b);
		}
	}
	int merge_value(int a, int b)
	{
		//求最小值
		/*
		return min(a, b);
		*/
	}

	void update(int id, int origin_position, int value)
	{
		if (tree_node[id].l == tree_node[id].r) {
			tree_node[id].value = value;
			return;
		}
		int mid = (tree_node[id].l + tree_node[id].r) / 2;
		if (mid >= origin_position) {
			update(id * 2, origin_position, value);
		} else {
			update(id * 2 + 1, origin_position, value);
		}
		update_from_son(id);
	}

	void update_by_lazy(int id, int q_l, int q_r, int value)
	{
		if (tree_node[id].r<q_l || tree_node[id].l>q_r) {
			return;
		}
		if (tree_node[id].l >= q_l && tree_node[id].r <= q_r) {
			//给区间内每一元素加上value
			/*
			tree_node[id].value += value;
			tree_node[id].lazy += value;
			*/
			return;
		} else {
			give_lazy_to_son(id);
			update_by_lazy(id * 2, q_l, q_r, value);
			update_by_lazy(id * 2 + 1, q_l, q_r, value);
			update_from_son(id);
			return;
		}
	}
	void give_lazy_to_son(int id)
	{
		//给区间内每一元素加上value
		/*
		tree_node[id * 2].value += tree_node[id].lazy;
		tree_node[id * 2].lazy += tree_node[id].lazy;
		tree_node[id * 2 + 1].value += tree_node[id].lazy;
		tree_node[id * 2 + 1].lazy += tree_node[id].lazy;
		tree_node[id].lazy = 0;
		*/
	}
};

