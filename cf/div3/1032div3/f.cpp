#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
vector<vector<ll>> SparseTable(vector<ll> &arr){
    int n = arr.size();
    //calculate length of binary representation
    ll len = 32- __builtin_clz(n);
    vector<vector<ll>> st(n,vector<ll>(len));
    for(int i=0;i<n;i++){
        st[i][0] = arr[i];
    }
    for(int j = 1; (1<<j)<=n; j++){
        for(int i=0; i + (1 << j) <= n;i++){
            st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
        }
    }
    return st;
}
ll query(ll l, ll r, vector<vector<ll>>& st){
    if (l > r || l < 0) return LLONG_MIN;
    ll len = 31- __builtin_clz(r-l+1);
    return max(st[l][len],st[r-(1<<len)+1][len]);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin>>t;
    while(t--){
        ll n,s,x;
        cin>>n>>s>>x;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<vector<ll>> ST = SparseTable(v);

        // we cannot use segment tree as it is very heavy for our input array 
        // so we use sparse table!!
        // SegmentTree ST(v);
        //our approach is we will find subarray sum equal to k first 
        //by storing indexes and then do the second part of the problem which is 
        //finding the max also
        
        //now another obs -> max is monotonically increasing that means
        // l1......l2.....r we can say that max(l1,r)>=max(l2,r) so we will store
        map<ll,vector<ll>> m;
        m[0].push_back(-1);
        ll ans = 0;
        ll sum = 0;
        for(int i=0;i<n;i++){
            sum += v[i];
            m[sum].push_back(i);
            ll req = sum-s;
            if(m.count(req)){
                //we have to find the first index and last index
                // in the vector m[req] that have the max value equals to x
                // we will use binary srch to find the first and last idx
                //then we will add it to our total

                //this is very imp the address symbol as it prevents copying!!!!!!
                vector<ll> &vec = m[req];
                
                ll first = -1,last = -1;
                ll st = 0,end = vec.size()-1;
                //find the first index
                while(st<=end){
                    ll mid = st+(end-st)/2;
                    ll val = vec[mid]+1;
                    // cout<<"val: "<<val<<endl;
                    // cout<<"query val: "<<ST.query(val,i)<<endl;
                    ll val1 = query(val,i,ST);
                    if(val1<=x){
                        first = mid;
                        end = mid-1;
                    }else{
                        st = mid+1;
                    }
                }
                st = 0;
                end = vec.size()-1;
                //find the last index
                while(st<=end){
                    ll mid = st+(end-st)/2;
                    ll val = vec[mid]+1;
                    ll val1 = query(val,i,ST);
                    if(val1>=x){
                        last = mid;
                        st = mid+1;
                    }else{
                        end = mid-1;
                    }
                }
                if(first!=-1 && last!=-1){
                    ans += (last-first+1);
                }
            }

        }
        cout<<ans<<endl;
        
    }
    return 0;
}