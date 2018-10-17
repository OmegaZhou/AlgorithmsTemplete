
//�߶���
#define maxn 100005
#define illegal 0
int min(int a, int b)
{
	return a < b ? a : b;
}

struct tree_node
{
	int value;
	int l;
	int r;
	int lazy;
	tree_node()
	{
		value = 0;
		l = 0;
		r = 0;
		//lazy = 0;
	}
};

struct segment_tree
{
	tree_node tree_node[4 * maxn];
	void build_tree(int id, int l, int r)
	{
		//��lazy����ֵ
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
		//����ֵΪ0
		//tree_node[id].value = 0;

	}
	void update_from_son(int id)
	{
		//����Сֵ
		/*
		tree_node[id].value = min(tree_node[id * 2].value, tree_node[id * 2 + 1].value);
		*/

		//���
		/*
		tree_node[id].value = tree_node[id * 2].value + tree_node[id * 2 + 1].value;
		*/
	}

	int query(int id, int q_l, int q_r)
	{
		if (tree_node[id].r<q_l || tree_node[id].l>q_r) {
			return illegal;
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
		//����Сֵ
		/*
		return min(a, b);
		*/

		//���
		/*
		return (a+b);
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
			//��������ÿһԪ�ؼ���value,������Сֵ
			/*
			tree_node[id].value += value;
			tree_node[id].lazy += value;
			*/

			//��������ÿһ��Ԫ�ظ�ֵΪvalue,�����
			/*
			tree_node[id].value = value * (tree_node[id].r - tree_node[id].l + 1);
			tree_node[id].value = value;
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
		//��������ÿһԪ�ؼ���value
		/*
		tree_node[id * 2].value += tree_node[id].lazy;
		tree_node[id * 2].lazy += tree_node[id].lazy;
		tree_node[id * 2 + 1].value += tree_node[id].lazy;
		tree_node[id * 2 + 1].lazy += tree_node[id].lazy;
		tree_node[id].lazy = 0;
		*/

		//��������ÿһ��Ԫ�ظ�ֵΪvalue,�����
		/*
		if (tree_node[id].lazy != illegal) {
			tree_node[id*2].value = tree_node[id].lazy * (tree_node[id*2].r - tree_node[id*2].l + 1);
			tree_node[id * 2].lazy = tree_node[id].lazy;
			tree_node[id * 2+1].value = tree_node[id].lazy * (tree_node[id * 2+1].r - tree_node[id * 2+1].l + 1);
			tree_node[id * 2+1].lazy = tree_node[id].lazy;
			tree_node[id ].lazy = illegal;
		}
		*/
	}
};

