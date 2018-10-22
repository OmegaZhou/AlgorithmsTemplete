
//左偏树，用于优先队列的合并操作
#define MAXN 100005
using namespace std;
void swap(int &i, int &j)
{
	int temp = i;
	i = j;
	j = temp;
}


int id;
struct LeftistTree
{
	int r_node, l_node, val, dis, root;
};
LeftistTree mem[MAXN];
void init()
{
	mem[0].l_node = 0;
	mem[0].r_node = 0;
	mem[0].root = 0;
	mem[0].dis = -1;
}
int build(int val)
{
	LeftistTree&k = mem[id];
	k.root = id;
	k.val = val;
	k.l_node = 0;
	k.r_node = 0;
	k.dis = 0;
	int temp = id;
	++id;
	return temp;
}
int merge(int a, int b)
{
	if (a == 0 || b == 0) {
		return mem[a + b].root = a + b;
	}
	if (mem[a].val < mem[b].val) {
		swap(a, b);
	}
	mem[a].r_node = merge(mem[a].r_node, b);
	if (mem[a].r_node != 0) {
		mem[mem[a].r_node].root = a;
	}
	if (mem[mem[a].r_node].dis > mem[mem[a].l_node].dis) {
		swap(mem[a].r_node, mem[a].l_node);
	}
	mem[a].dis = mem[mem[a].r_node].dis + 1;
	mem[a].root = a;
	return a;
}
int find_root(int x)
{
	if (mem[x].root == x) {
		return x;
	}
	mem[x].root = find_root(mem[x].root);
	return mem[x].root;
}
int push(int heap, int val)
{
	int a = build(val);
	return merge(heap, a);
}
int top(int id)
{
	return find_root(id);
}
int pop(int id)
{
	id = find_root(id);
	if (mem[id].l_node == 0) {
		return 0;
	}
	return merge(mem[id].l_node, mem[id].r_node);
}