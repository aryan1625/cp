//cannot handle duplicates
//insertion in O(log n)
//deletion in O(log n)
// access by order in O(log n)
// order of key in O(log n)
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
// typedef pair<long long, int> pli;
// typedef tree<pli,null_type,less<pli>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>ordered_set;
using ll = long long;

int main(){
    ordered_set oset;
    ll a;
    cin>>a;

    // all ops are o(logn)
    
    //return number of elements strictly smaller than a
    oset.order_of_key(a);
    // oset.order_of_key({a,-1}); -> for pli

    //returns iterator to k-th largest element(0 indexed)
    oset.find_by_order(a); 
    // oset.find_by_order({a,i}); -> for pli


    //insert into ordered set 
    oset.insert(a);
    // i is index
    // oset.insert({a,i});

    return 0;
}
