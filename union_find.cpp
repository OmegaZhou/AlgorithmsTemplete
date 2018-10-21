//并查集
#define MAXN 1005
int father[MAXN];
int find_fa(int i)
{
	if (father[i] == i) {
		return i;
	}
	father[i] = find_fa(father[i]);
	return father[i];
}
bool add(int i, int j)
{
	int fi = find_fa(i);
	int fj = find_fa(j);
	if (fi == fj) {
		return false;
	} else {
		father[fj] = fi;
		return true;
	}
}


//用并查集寻找最大的集合数
#define MAXN 10000001
using namespace std;
int father[MAXN];
int num[MAXN];
int max_num;
int find_fa(int i)
{
	if (father[i] == i) {
		return i;
	}
	father[i] = find_fa(father[i]);
	return father[i];
}
bool add(int i, int j)
{
	int fi = find_fa(i);
	int fj = find_fa(j);
	if (fi == fj) {
		return false;
	} else {
		num[fi] += num[fj];
		if (max_num < num[fi]) {
			max_num = num[fi];
		}
		father[fj] = fi;
		return true;
	}
}

//以并查集根节点为绝对值，子节点为父节点的相对值，计算带权并查集
//例:设有两种属性，给出m对不同种类的集合，问是否会起冲突
#define MAXN 10000001
using namespace std;
int father[MAXN];
int num[MAXN];
int find_fa(int i)
{
	if (father[i] == i) {
		return i;
	}
	int temp = find_fa(father[i]);
	num[i] ^= num[father[i]];
	father[i] = temp;
	return father[i];
}
bool add(int i, int j)
{
	int fi = find_fa(i);
	int fj = find_fa(j);
	if (fi == fj) {
		return num[i] ^ num[j];
	} else {
		if (num[i] ^ num[j] ^ num[fj] == 0) {
			num[fj] ^= 1;
		}
		father[fj] = fi;
		return true;
	}
}


//补充
//按秩压缩+非递归查找+路径压缩的并查集
int parent[MAXN];
int rank[MAXN];
// 初始化n个元素
void init(int n)
{
	for (int i = 0; i<n; i++) {
		parent[i] = i;
		rank[i] = 0;   // 初始树的高度为0
	}
}
//非递归查找
int find(int x)
{
	int k, j, r;
	r = x;
	while (r != parent[r])     //查找跟节点
		r = parent[r];      //找到跟节点，用r记录下
	k = x;
	while (k != r)             //非递归路径压缩操作
	{
		j = parent[k];         //用j暂存parent[k]的父节点
		parent[k] = r;        //parent[x]指向跟节点
		k = j;                    //k移到父节点
	}
	return r;         //返回根节点的值            
}
//按秩压缩
void init(int n)
{
	for (int i = 0; i<n; i++) {
		parent[i] = i;
		rank[i] = 0;   // 初始树的高度为0
	}
}
// 合并x和y所属的集合
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rank[x]<rank[y])
		parent[x] = y;  // 合并是从rank小的向rank大的连边
	else {
		parent[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}