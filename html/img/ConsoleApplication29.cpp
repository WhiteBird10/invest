#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (a < b)  swap(a, b);
    if ((a % b) != 0) {
        gcd(b, a % b);
    }
    else {
        return b;
    }
}

int ff(int n, int f, int k) {
    if (n % f == 0) {
        n /= f;
        return ff(n, f, k + 1);
    }
    else { return k; }
}

int modexp(int x, int y, int N)
{
    if (y == 0) return 1;
    if (y % 2 == 0)
        return (modexp(x, y / 2, N) * modexp(x, y / 2, N)) % N;
    else
        return ((x % N) * ((modexp(x, y / 2, N) * modexp(x, y / 2, N)) % N)) % N;
}

int main() {
    long int a;
    cout << "a = ";
    cin >> a;
    long int q;
    cout << "q = ";
    cin >> q;;
    long int n;
    cout << "n = ";
    cin >> n;
    int m = n;

    long int f = 2;
    long int k = 1, res = 1;

    while (m != 1) {
        if (m % f == 0) {
            k = ff(m, f, k - 1);
            m /= pow(f, k);
            res *= pow(f, k) - pow(f, k - 1);
        }
        else
        {
            f += 1;
            k = 1;
        }
    }
    // cout << "phi = " << res << endl;
    q = fmod(q, res);
    //cout << "q= " << q << endl;
    //cout << "a= " << a << endl;
    cout << "Result = " << modexp(a, q, n);


    return 0;
}