#define MAXN 500005
using namespace std;
long long sum[MAXN];
int num[MAXN];
//Ê÷×´Êý×é
int lowbit(int i)
{
	return i & (-i);
}
void add(int position, int n)
{
	for (int i = position; i <= n; i += lowbit(i)) {
		sum[i] += num[position];
	}
}
long long query(int x)
{
	long long result = 0;
	for (int i = x; i >= 1; i -= lowbit(i)) {
		result += sum[i];
	}
	return result;
}
long long query(int l, int r)
{
	return query(r) - query(l - 1);
}
void change(int position, int value, int n)
{
	for (int i = position; i <= n; i += lowbit(i)) {
		sum[i] -= num[position];
	}
	num[position] = value;
	for (int i = position; i <= n; i += lowbit(i)) {
		sum[i] += num[position];
	}
}