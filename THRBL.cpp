#include <bits/stdc++.h>
using namespace std;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 50001

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<pi> vii;

const int MOD = (int) 1e9+7;

int n,m,l,r,a[maxn],f[maxn][25];

int get (int l, int r){
    int k=log2(r-l+1);
    return max(f[l][k],f[r-(1<<k)+1][k]);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        f[i][0]=a[i];
    }
    for (int j=1; (1<<j)<=n; j++){
        for (int i=1; i+(1<<j)-1<=n; i++)
            f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]);
    }
    ll ans=0;
    while (m--){
        cin >> l >> r;
        if (abs(l-r)<=1){
            ++ans; continue;
        }
        int x=a[l];
        if (l>r) swap(l,r);
        if (x>=get(l+1,r-1)) ++ans;
    }
    cout << ans;
    return 0;
}
