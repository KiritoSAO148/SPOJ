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

int n, a[20], ok;

void gray (string s)
{
    cout << s[0];
    for (int i=1; i<s.size(); ++i)
    {
        if (s[i] == s[i-1]) cout << 0;
        else cout << 1;
    }
    cout << "\n";
}

void ktao()
{
    f1 (i,n) a[i] = 0;
}

void sinh()
{
    int i = n;
    while (i >= 1 && a[i] == 1)
    {
        a[i] = 0;
        --i;
    }
    if (i == 0) ok = 0;
    else a[i] = 1;
}

int main(){
    FastIO;
    cin >> n;
    ok = 1;
    ktao();
    while (ok)
    {
        string res = "";
        f1 (i,n)
        {
            res += to_string(a[i]);
        }
        gray(res);
        sinh();
    }
    return 0;
}
