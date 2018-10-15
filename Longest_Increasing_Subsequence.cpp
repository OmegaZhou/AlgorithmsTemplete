#define MAXN 100005
int low[MAXN];
int find_fun(int len, int value)
{
	int l = 1;
	int r = len;
	int mid;
	while (l <= r) {
		mid = (l + r) / 2;
		if (low[mid]>value) {
			r = mid - 1;
		} else if (low[mid]<value) {
			l = mid + 1;
		} else {
			return mid;
		}
	}
	return l;
}
int cal_LIS(int* a, int n)
{
	for (int i = 0; i <= n; ++i) {
		low[i] = 0;
	}
	int len = 0;
	for (int i = 0; i<n; ++i) {
		if (a[i]>low[len]) {
			low[++len] = a[i];
		} else {
			int index = find_fun(len, a[i]);
			low[index] = a[i];
		}
	}
	return len;
}