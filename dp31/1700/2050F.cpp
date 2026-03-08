#include<bits/stdc++.h>
using namespace std;
// int mod = 998244353;
using ll = long long ;
using ld = long double ;
#include<bits/stdc++.h>
using namespace std;
//1600 cp31 q1(1920C) + segment tree on diff array  --> good question


// Segment Tree Node
struct Node {
    ll mod;
    Node():mod(0){}
};
class SegmentTree {
private:
    vector<Node> tree;
    ll n;
    // Build the segment tree recursively
    void build(vector<ll>& arr, ll root, ll s, ll e) {
        if (s==e) {
            tree[root].mod=arr[s];
            return;
        }
        ll m = s+(e-s)/2;
        build(arr,2*root,s,m);
        build(arr,2*root+1,m+1,e);
        
        tree[root].mod = __gcd(tree[2*root].mod,tree[2*root+1].mod);
    }
    // Query the segment tree recursively
    ll query(ll root, ll s, ll e, ll l, ll r) {
        if(r<s || l>e)return 0;
        if(l<=s && e<=r)return tree[root].mod;
        ll m = s+(e-s)/2;
        ll lS = query(2*root,s,m,l,r);
        ll rS = query(2*root+1,m+1,e,l,r);
        ll val = __gcd(lS,rS);
        return val;
    }
    

public:
    // Constructor
    SegmentTree(vector<ll>& arr) {
        n = arr.size();
        tree.resize(4*n); // Maximum size of the segment tree is 4n
        build(arr,1,0,n-1);
    }

    // Query function
    ll query(ll l, ll r) {
        return query(1,0,n-1,l,r);
    }

    
};
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(n==1){
            for(int i=0;i<q;i++){
                ll val1,val2;
                cin>>val1>>val2;
                cout<<0<<" ";
            }
            cout<<endl;
            continue;
        }
        vector<ll> dif;
        for(int i=1;i<n;i++){
            dif.push_back(abs(v[i]-v[i-1]));
        }
        // vector<pair<ll,ll>> p(q);
        SegmentTree seg(dif);
        vector<ll> ans(q);
        for(int i=0;i<q;i++){
            ll val1,val2;
            cin>>val1>>val2;
            val1--;
            val2--;
            if(val1==val2){
                ans[i] = 0;
                continue;
            }
            ans[i] = seg.query(val1,val2-1);
            
        }
        for(int i=0;i<q;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
        
    }
    return 0;
}