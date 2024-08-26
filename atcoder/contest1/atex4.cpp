#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
ull power(int val){
    ull ans = 1;
    while(val>0){
        ans*=10;
        val--;
    }
    return ans;
}
string solve(ull n){
    n--;
    if(n<10)return to_string(n);
    ull len = 1;
    ull cnt = 9;
    ull k = n;
    while(k>=cnt){
        k -= cnt;
        len++;
        int ele = (len-1)/2;
        cnt = 9*power(ele);
    }
    int ele = (len-1)/2;
    ull st = power(ele);
    // cout<<st<<endl;
    ull val = st + k - 1 ;
    string s = to_string(val);
    // cout<<s<<endl;
    string rev(s.rbegin(), s.rend());
    if (len % 2 == 1) {
        s.pop_back();
    }
    s += rev;
    return s;
}
int main(){
    ull n;
    cin>>n;
    string ans = solve(n);
    cout<<ans<<endl;
    return 0;
}