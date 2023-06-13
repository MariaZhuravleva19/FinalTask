#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Point
{
public:
    ll x, y;

    Point(ll _x, ll _y) : x(_x), y(_y) {}
};

ll calculateArea(const vector<Point>& points)
{
    int n = points.size();
    ll area = 0;
    for (int i = 0; i < n; i++)
    {
        ll x1 = points[i].x;
        ll x2 = points[(i + 1) % n].x;
        ll y1 = points[i].y;
        ll y2 = points[(i + 1) % n].y;
        area += (x1 + x2) * (y2 - y1);
    }
    return area;
}

ll countBoundaryPoints(const vector<Point>& points)
{
    int n = points.size();
    ll b = 0;
    for (int i = 0; i < n; i++)
    {
        ll x1 = points[i].x;
        ll x2 = points[(i + 1) % n].x;
        ll y1 = points[i].y;
        ll y2 = points[(i + 1) % n].y;
        ll dx = abs(x2 - x1);
        ll dy = abs(y2 - y1);
        b += gcd(dx, dy);
    }
    return b;
}

int main()
{
    int n;
    cin >> n;
    vector<Point> points;
    for (int i = 0; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }
    points.emplace_back(points[0].x, points[0].y);

    ll area = calculateArea(points);
    ll b = countBoundaryPoints(points);

    ll a = abs(area) - b + 2;
    cout << a / 2 << ' ' << b;

    return 0;
}
