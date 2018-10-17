
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