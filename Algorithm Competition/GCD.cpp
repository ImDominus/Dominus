long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
