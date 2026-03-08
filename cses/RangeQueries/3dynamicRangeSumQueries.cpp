#include<bits/stdc++.h>
using namespace std;
using ll = long long ;
//we will use segment tree
struct Node {
    ll sum;
    Node():sum(0){}
};
class SegmentTree {
private:
    vector<Node> tree;
    ll n;
    // Build the segment tree recursively
    void build(vector<ll>& arr, ll root, ll s, ll e) {
        if (s==e) {
            tree[root].sum=arr[s];
            return;
        }
        ll m = s+(e-s)/2;
        build(arr,2*root,s,m);
        build(arr,2*root+1,m+1,e);
        tree[root].sum = tree[2*root].sum+tree[2*root+1].sum;       
    }
    // Query the segment tree recursively
    ll query(ll root, ll s, ll e, ll l, ll r) {
        if(r<s || l>e)return 0;
        if(l<=s && e<=r)return tree[root].sum;
        ll m = s+(e-s)/2;
        ll lS = query(2*root,s,m,l,r);
        ll rS = query(2*root+1,m+1,e,l,r);
        return lS+rS;
    }
    // Update the segment tree recursively
    void update(ll root, ll s, ll e, ll i, ll val) {
        if (s==e) {
            tree[root].sum=val;
            return ;
        }
        ll m = s+(e-s)/2;
        if(i<=m){
            update(2*root,s,m,i,val);
        }else{
            update(2*root+1,m+1,e,i,val);
        }
        tree[root].sum = tree[2*root].sum+tree[2*root+1].sum;
        
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

    // Update function
    void update(ll i, ll val) {
        update(1,0,n-1,i,val);
    }
};
int main(){
    ll n,q;
    cin>>n>>q;
    vector<ll> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    SegmentTree st(arr);
    for(int i=0;i<q;i++){
        ll a,b,c;
        cin>>a>>b>>c;
        if(a==1){
            st.update(b-1,c);
        }else{
            cout<<st.query(b-1,c-1)<<endl;
        }
    }   
    return 0;
}