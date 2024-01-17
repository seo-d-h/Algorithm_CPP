#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define ll long long

bool cmp(const pair<ll,ll>& a,  const pair<ll,ll>& b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    return a.second > b.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll N, num;
    map<ll,ll> mp;
    cin >> N;

    for(ll i=0;i<N;i++){
        cin >> num;
        mp[num]++;
    }

    vector<pair<ll,ll>> vec(mp.begin(), mp.end());
    sort(vec.begin(), vec.end(), cmp);

    cout << vec[0].first;

    return 0;
}