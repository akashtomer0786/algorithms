// C++ program to find modular inverse of a under modulo m
// This program works only if m is prime.
#include<iostream>
using namespace std;

// To find GCD of a and b
int gcd(int a, int b);

// To compute x raised to power y under modulo m
long long binpow(long long  x, long long  y, long long m);

// Function to find modular inverse of a under modulo m
// Assumption: m is prime
void modInverse(int a, int m)
{
	int g = gcd(a, m);
	if (g != 1)
		cout << "Inverse doesn't exist";
	else
	{
		// If a and m are relatively prime, then modulo inverse
		// is a^(m-2) mode m
		cout << "Modular multiplicative inverse is "
			<< binpow(a, m-2, m);
	}
}

// To compute x^y under modulo m
long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

// Function to return gcd of a and b
int gcd(int a, int b)
{
	if (a == 0)
		return b;
	return gcd(b%a, a);
}

// Driver Program
int main()
{
	int a = 3, m = 11;
	modInverse(a, m);
	return 0;
}
