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
    ll n,m;
    cin >> n >> m;
    vector<ll> c(m);
    for(i = 0;i < m;++i){
        cin >> c.at(i);
    }
    vector<vector<ll>> dp(m+1,vector<ll>(n+1, 1e9));
    dp.at(0).at(0) = 0;
    for(i = 1;i <= m;++i){
        rep(j, n+1){
            if(j < c.at(i-1)) dp.at(i).at(j) = dp.at(i-1).at(j);
            else dp.at(i).at(j) = min({dp.at(i-1).at(j), dp.at(i-1).at(j - c.at(i-1)) + 1, dp.at(i).at(j - c.at(i-1)) + 1});
        }
    }
    cout << dp.at(m).at(n) << endl;
    return 0;
}