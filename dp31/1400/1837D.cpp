#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
pair<ll,vector<ll>> solve(string &s){
    int n = s.size();
    ll cnt = 0;
    vector<ll> vec(n,1);
    vector<ll> vec2(n,1);
    stack<char> st;
    bool flag = true;
    for(int i=0;i<n;i++){
        if(st.empty()){
            if(s[i]==')'){
                flag = false;
            }else{
                flag = true;
            }
            if(flag)vec[i] = 1;
            else{
                vec[i] = 2;
            }
            st.push(s[i]);
            continue;
        }
        if(flag)vec[i] = 1;
        else{
            vec[i] = 2;
        }
        char c = st.top();
        if(c=='('){
            if(s[i]==')'){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }else{
            if(s[i]=='('){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
    }
    bool flag2 = true;
    vector<ll> v(2,0);
    for(int i=0;i<n;i++){
        if(v[0]==1 && v[1]==1){
            flag2 = false;
            break;
        }
        if(vec[i]==1){
            v[0] = 1;
            
        }else{
            v[1] = 1;
        }
    }
    if(st.empty()){
        if(!flag2){
            return {2,vec};
        }else{
            return {1,vec2};
        }
    }else{
        return {-1,{-1}};
    }
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string s;
        cin>>s;
        pair<ll,vector<ll>> p = solve(s);
        if(p.first == -1){
            cout<<"-1\n";
            continue;
        }
        cout<<p.first<<"\n";
        for(int i=0;i<n;i++){
            cout<<p.second[i]<<" ";
        }
        cout<<"\n";   
    }
    return 0;
}