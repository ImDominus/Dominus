// Euler's formula
// vertex - v, edge - e, face - f
// 3d -> v - e + f = 2; 2d -> v - e + f = 1;

// Euler's Theorem
// if gcd(a, n) == 1, // a**(φ(n)) = 1 (mod n) // (φ(n) = count of coprimes that smaller than n)
// 1. if a is prime, φ(n) = n - 1
// 2. if gcd(a, b) == 1, φ(nm) = φ(n)φ(m)
// 3. if n = (p1 ** k1) * (p2 ** k2) * (p3 ** k3)-------(pr ** kr), (if p == primes)
//    φ(n) = n * (1 - 1 / p1) * (1 - 1 / p2)... (1 - pr)
//    ex) 60 = (2^2) * (3^1) * (5^1), φ(30) = 60 * (1 - (1 / 2)) * (1 - (1 / 3)) * (1 - (1 / 5)) = 16
