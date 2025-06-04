#include <iostream>
#include <vector>

using namespace std;

class Solution3 {
public:
    // Refer to Bounded Integer Composition (Inclusion-Exclusion) in README.md for formula
    int numRollsToTarget(int n, int k, int target) {
        if (n * k < target || n > target) return 0;
        long long sum = 0;
        precompute();
        for (int i = 0, imax = (target - n) / k; i <= imax; i++) {
            sum = (sum + boundedIntegerComposition(i, n, k, target)) % MOD;
        }
        return sum;
    }
private:
    const int MOD = 1e9 + 7;
    static const int MAX_TARGET = 1001;   // constraint: 1 <= target <= 1000
    vector<long long> fact = vector<long long>(MAX_TARGET), inv_fact = vector<long long>(MAX_TARGET);
    long long boundedIntegerComposition(int i, int n, int k, int target) {
        long long ways = combination(n, i) * combination(target - k * i - 1, n - 1) % MOD;
        // Ensure modulo arithmetic is not negative
        return (i % 2 == 1) ? MOD - ways : ways;
    }
    long long combination(int n, int v) {
        return fact[n] * inv_fact[v] % MOD * inv_fact[n - v] % MOD;
    }
    long long power(long long base, int power) {
        long long ans = 1;
        while (power > 0) {
            if (power % 2 == 1) {
                ans = (ans * base) % MOD;
            }
            base = (base * base) % MOD;
            power /= 2;
        }
        return ans;
    }
    // Precompute factorial and inverse factorial for constant lookup
    void precompute() {
        fact[0] = 1;
        for (int i = 1; i < MAX_TARGET; i++) {
            fact[i] = fact[i - 1] * i % MOD;
        }
        // Fermat's Little Theorem
        // If p is a prime and a is an integer not divisible by p, a^(p - 1) ≡ 1 (mod p)
        // Extended version: if p is a prime and a is any integer, a^p ≡ a (mod p)
        //
        // modular inverse, a^-1, of a modulo p is an integer x, such that: a * x ≡ 1 (mod p)
        // To get modular inverse, multiply both sides of the theorem by a^-1
        // a^(p - 2) ≡ a^-1 (mod p)
        inv_fact[MAX_TARGET - 1] = power(fact[MAX_TARGET - 1], MOD - 2);
        for (int i = MAX_TARGET - 2; i >= 0; i--) {
            inv_fact[i] = inv_fact[i + 1] * (i + 1) % MOD;
        }
    }
};
