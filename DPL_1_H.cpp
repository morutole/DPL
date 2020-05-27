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
    ll n,W;
    cin >> n >> W;
    vector<ll> v(n);
    vector<ll> w(n);
    for(i = 0;i < n;++i){
        cin >> v.at(i) >> w.at(i);
    }

    ll n2 = n/2;
    vector<pair<ll,ll>> tmp_sum1;
    for(ll bit = 0;bit < (1 << n2);++bit){
        ll w_sum = 0;
        ll v_sum = 0;
        for(i = 0;i < n2;++i){
            if(bit & (1 << i)){
                w_sum += w.at(i);
                v_sum += v.at(i);
            }
        }
        if(w_sum <= W) tmp_sum1.emplace_back(w_sum,-v_sum);
    }
    sort(all(tmp_sum1));
    vector<pair<ll,ll>> sum1;
    for(i = 0;i < tmp_sum1.size();++i){
        ll w_sum = tmp_sum1.at(i).first;
        ll v_sum = -tmp_sum1.at(i).second;
        if(i == 0){
            sum1.emplace_back(w_sum, v_sum);
        }else{
            if(sum1.back().second < v_sum) sum1.emplace_back(w_sum, v_sum);
        }
    }

    ll n22 = n - n2;
    vector<pair<ll,ll>> tmp_sum2;
    for(ll bit = 0;bit < (1 << n22);++bit){
        ll w_sum = 0;
        ll v_sum = 0;
        for(i = 0;i < n22;++i){
            if(bit & (1 << i)){
                w_sum += w.at(i + n2);
                v_sum += v.at(i + n2);
            }
        }
        if(w_sum <= W) tmp_sum2.emplace_back(w_sum,-v_sum);
    }
    sort(all(tmp_sum2));
    vector<pair<ll,ll>> sum2;
    for(i = 0;i < tmp_sum2.size();++i){
        ll w_sum = tmp_sum2.at(i).first;
        ll v_sum = -tmp_sum2.at(i).second;
        if(i == 0){
            sum2.emplace_back(w_sum, v_sum);
        }else{
            if(sum2.back().second < v_sum) sum2.emplace_back(w_sum, v_sum);
        }
    }

    ll ans = 0;
    for(i = 0;i < sum1.size();++i){
        ll w_sum = sum1.at(i).first;
        ll v_sum = sum1.at(i).second;
        ll ind = lower_bound(all(sum2), make_pair(W-w_sum+1, 0ll)) - sum2.begin();
        if(ind != 0) ans = max(ans, v_sum + sum2.at(ind-1).second);
    }
    cout << ans << endl;
    return 0;
}