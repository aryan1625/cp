#pragma GCC optimize (3)
#pragma GCC optimize ("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define fIO freopen("input.in","r",stdin), freopen("input.out","w",stdout)
#define io ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define all(a) a.begin(),a.end()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define F first
#define S second
#define pb push_back
#define ins insert
const int N = 1e5 + 10;
const int mod = 998244353;
inline int ls(int x) { return x << 1; }
inline int rs(int x) { return x << 1 | 1; }
int lowbit(int x) { return x & -x; }
int dx[8] = { 1,0,0,-1,-1,-1,1,1 };
int dy[8] = { 0,-1,1,0,-1,1,-1,1};
// /---------------------------------------Code begins----------------------------------------/
void solve()
{
        ll n,m;
        cin>>n>>m;
        vector<ll> a1(n);
        vector<ll> b1(m);
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }
        for(int i=0;i<m;i++){
            cin>>b1[i];
        }
        //sort the second vector
        //then apply two pointer and greedy 
        ll sum =0;
        sort(b1.begin(),b1.end());
        sort(a1.begin(),a1.end());
        ll i1=0,i2=0;
        ll j1=m-1,j2=n-1;
        ll count=0;
        while(i2!=j2){
            ll cond1 = abs(a1[i2]-b1[i1]);
            ll cond2 = abs(a1[i2]-b1[j1]);
            ll cond3 = abs(a1[j2]-b1[i1]);
            ll cond4 = abs(a1[j2]-b1[j1]);
            ll maxi1,candid1,candid2,maxi2;
            if(cond1>cond2){
                maxi1 = cond1;
                candid1 = i1;
            }
            else{
                maxi1=cond2;
                candid1 = j1;
            }
            if(cond3>cond4){
                maxi2 = cond3;
                candid2 = i1;
            }
            else{
                maxi2=cond4;
                candid2 = j1;
            }
            if(maxi1>maxi2){
                sum+=maxi1;
                if(candid1==i1){
                    i1++;
                    i2++;
                }
                else{
                    j1--;
                    i2++;
                }
            }
            else{
                sum+=maxi2;
                if(candid2==i1){
                    i1++;
                    j2--;
                }
                else{
                    j1--;
                    j2--;
                }
            }

        }
        sum+=max(abs(a1[i2]-b1[i1]),abs(a1[i2]-b1[j1]));
        cout<<sum<<'\n';
    
}
signed main()
{
    io;
    //fIO;
    ll tt=1;
    cin >> tt;
    while(tt--)
    {
        solve();
    }
    return 0;
}