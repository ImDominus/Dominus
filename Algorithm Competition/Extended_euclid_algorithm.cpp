
pair <long long, long long> extended_euclid(long long a, long long b) {
	if (b > a) swap(a, b);
	long long s0, t0, s1, t1, q, tempa, temps, tempt;
	s0 = 1; s1 = 0; t0 = 0; t1 = 1;
	while (a % b > 0) {
		q = a / b;
		tempa = a % b; tempt = t0 - q * t1; temps = s0 - q * s1;
		s0 = s1; t0 = t1; a = b;
		s1 = temps; t1 = tempt; b = tempa;
	}
	return { s1, t1 };
}

ex) gcd(240, 46) = 2, 2 = 240 * (-9) + 46 * 47
