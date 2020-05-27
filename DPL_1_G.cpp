#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    ll n, W;
    cin >> n >> W;
    vector<ll> v(n);
    vector<ll> w(n);
    vector<ll> m(n);
    for(i = 0;i < n;++i){
        cin >> v.at(i) >> w.at(i) >> m.at(i);
    }
    vector<vector<ll>> dp(n+1, vector<ll>(W+1,0));
    for(i = 1;i <= n;++i){
        ll a;
        //modでそれぞれ考える。
        rep(a, w.at(i-1)){
            //スライド最小値のためのdeq
            deque<pair<ll,ll>> deq;
            for(j = 0;j*w.at(i-1) + a <= W;++j){
                //それぞれでの重さ
                ll tmpw = j*w.at(i-1) + a;
                //b[j]の値
                ll val = dp.at(i-1).at(tmpw) - j*v.at(i-1);
                //空ではない時、valより小さい値はもう使わない。
                while((!deq.empty()) && deq.back().first <= val) deq.pop_back();
                deq.emplace_back(val, j);
                //先頭が最大で、漸化式の計算に使われる。
                dp.at(i).at(tmpw) = deq.front().first + j*v.at(i-1);
                //期限が来たらpop
                if(j - deq.front().second == m.at(i-1)) deq.pop_front();
            }
        }
    }
    cout << dp.at(n).at(W) << endl;
    return 0;
}