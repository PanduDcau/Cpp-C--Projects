#include<bits/stdc++.h>
using namespace std;
struct _ { ios_base::Init i; _() { cin.sync_with_stdio(0); cin.tie(0); } } _;

const int N = 100006;
long long a[N];

long long gcd(long long a, long long b)
{
    if(a < 0) a = -a; if(b < 0) b = -b;
    return b ? gcd(b, a % b) : a;
}

int main()
{
    int n, q; cin >> n >> q;
    long long temp;
    assert (n<=100000 && n>=1 && q<=100000 && q>=1);
    for(int i = 0; i < n; ++i) {
      cin >> temp;
      assert (temp<=100000000000000L && temp>=0);
      a[i] = temp;
    }

    long long d = 0;
    for(int i = 0; i < n; ++i)
        d = gcd(d, a[i] - a[1]);

    while(q--)
    {
        int k; cin >> k;
        assert (k>=0 && k<=1000000000);
        cout << gcd(d, a[0] + k) << '\n';
    }
    return 0;
}

