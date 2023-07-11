#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef vector<ll> vl;
typedef vector<vl> vvl;

#define ms(s,n) memset(s,n,sizeof(s))
#define all(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define f0(i,n) for (int i=0; i<n; i++)
#define f1(i,n) for (int i=1; i<=n; i++)
#define FastIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define TC() int t; cin >> t; while (t--)
#define el cout << "\n"
#define pb push_back
#define pf push_front
#define fi first
#define se second
#define maxn 

const int MOD = (int) 1e9+7;

void FileIO(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}

struct team{
	string name;
	int numSub[4];
	int time[4];
};

int main(){
    FileIO();
    FastIO;
    int n; cin >> n;
    team a[n];
    int x[n], y[n];
    f0 (i, n){
    	cin >> a[i].name;
    	int cnt = 0, res = 0;
    	f0 (j, 4){
    		cin >> a[i].numSub[j] >> a[i].time[j];
    		if (a[i].time[j]) {
    			++cnt;
    			res += a[i].time[j];
    		}
    		if (a[i].time[j] > 1) res += 20 * (a[i].numSub[j] - 1);
    	}
    	x[i] = cnt; y[i] = res;
    }
    vi v;
    int maxNumSub = *max_element(x, x + n);
    f0 (i, n){
    	if (x[i] == maxNumSub){
    		int res = 0;
    		f0 (j, 4){
	    		if (a[i].time[j]) {
	    			res += a[i].time[j];
	    		}
	    		if (a[i].time[j] > 1) res += 20 * (a[i].numSub[j] - 1);
	    	}
	    	v.pb(res);
    	}
    }
    int minTime = *min_element(all(v));
    f0 (i, n){
    	if (x[i] == maxNumSub && y[i] == minTime){
    		cout << a[i].name << ' ' << maxNumSub << ' ' << minTime << '\n';
    		break;
    	}
    }
    return 0;
}