#include <iostream>
#include <vector>
#include <complex>
#include <cmath>


using namespace std;

typedef long long ll;
typedef complex<double> Point;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main() 
{
    int n;
    cin >> n;
    vector<Point> v(n);
    for (int i = 0; i < n; i++) 
    {
        double x, y;
        cin >> x >> y;
        v[i] = { x, y };
    }
    v.push_back(v[0]);
    ll area = 0;
    ll b = 0;
    for (int i = 0; i < n; i++) 
    {
        Point x = v[i], y = v[i + 1];
        area += imag(conj(x) * y);
        Point z = y - x;
        ll g = gcd(static_cast<ll>(real(z)), static_cast<ll>(imag(z)));
        b += abs(g);
    }

    ll a = abs(area) - b + 2;
    cout << a / 2 << ' ' << b;

    return 0;
}
