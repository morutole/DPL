#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n;
    cin >> n;
    vector<ll> a(n);
    for(i = 0;i < n;++i){
        cin >> a.at(i);
    }
    ll INF = 1e14;
    vector<ll> dp(n,INF);
    for(i = 0;i < n;++i){
        //入れられるところを二分探索
        auto itr = lower_bound(all(dp), a.at(i));
        *itr = a.at(i);
    }
    //INFとなるインデックスの一つ前までの長さが答え
    ll ans = lower_bound(all(dp), INF) - dp.begin();
    cout << ans << endl;
    return 0;
}