#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

ll solve (int n, int p)
{
    int ans = 0;
    for (int i = p; i <= n; i *= p)
    {
        ans += n / i;
    }
    return ans;
}

int main(){
    FastIO;
    int t; cin >> t;
    while (t--)
    {
        int n, x; cin >> n >> x;
        cout << solve(n, x) << '\n';
    }
    return 0;
}
