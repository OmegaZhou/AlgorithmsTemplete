//���鼯
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


//�ò��鼯Ѱ�����ļ�����
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

//�Բ��鼯���ڵ�Ϊ����ֵ���ӽڵ�Ϊ���ڵ�����ֵ�������Ȩ���鼯
//��:�����������ԣ�����m�Բ�ͬ����ļ��ϣ����Ƿ�����ͻ
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


//����
//����ѹ��+�ǵݹ����+·��ѹ���Ĳ��鼯
int parent[MAXN];
int rank[MAXN];
// ��ʼ��n��Ԫ��
void init(int n)
{
	for (int i = 0; i<n; i++) {
		parent[i] = i;
		rank[i] = 0;   // ��ʼ���ĸ߶�Ϊ0
	}
}
//�ǵݹ����
int find(int x)
{
	int k, j, r;
	r = x;
	while (r != parent[r])     //���Ҹ��ڵ�
		r = parent[r];      //�ҵ����ڵ㣬��r��¼��
	k = x;
	while (k != r)             //�ǵݹ�·��ѹ������
	{
		j = parent[k];         //��j�ݴ�parent[k]�ĸ��ڵ�
		parent[k] = r;        //parent[x]ָ����ڵ�
		k = j;                    //k�Ƶ����ڵ�
	}
	return r;         //���ظ��ڵ��ֵ            
}
//����ѹ��
void init(int n)
{
	for (int i = 0; i<n; i++) {
		parent[i] = i;
		rank[i] = 0;   // ��ʼ���ĸ߶�Ϊ0
	}
}
// �ϲ�x��y�����ļ���
void unite(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) return;
	if (rank[x]<rank[y])
		parent[x] = y;  // �ϲ��Ǵ�rankС����rank�������
	else {
		parent[y] = x;
		if (rank[x] == rank[y]) rank[x]++;
	}
}