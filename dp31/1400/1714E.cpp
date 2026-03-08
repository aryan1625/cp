#include<bits/stdc++.h>
using namespace std;
int mod = 998244353;
using ll = long long ;
using ld = long double ;
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector<ll> chck(10,0);
        bool flag = true;
        ll val5 = -1;
        ll val0 = -1;
        set<ll> st1;
        set<ll> st2;
        for(int i=0;i<n;i++){
            ll rem = v[i]%10;
            if(rem==5){
                val5 = v[i];
            }
            if(rem==0){
                val0 = v[i];
            }   
            ll rem2 = v[i]%20;
            if(chck[rem]==0){
                chck[rem] = rem2;
                if(rem==rem2){
                    st1.insert(rem);
                }
                else{
                    st2.insert(rem);
                }
            }
            else{
                if(chck[rem]!=rem2){
                    flag = false;
                    break;
                }
            }
        }
        if(!flag){
            cout<<"no"<<endl;
            continue;
        }
        //check for 5 and 0
        if(val5!=-1 && val0!=-1 && val5+5!=val0){
            cout<<"NO"<<endl;
            continue;
        }
        if(val5!=-1 || val0!=-1){
            for(int i=0;i<n;i++){
                ll rem = v[i]%10;
                if((rem!=5 && rem!=0) || (rem==5 && v[i]!= val5) || (rem==0 && v[i]!= val0)){
                    flag = false;
                    break;
                }
            }
            if(!flag){
                cout<<"No"<<endl;
                continue;
            }else{
                cout<<"Yes"<<endl;
                continue;
            }    
        }
        
        //check for st1 and st2
        set<ll> st3 = {1,2,4,8};
        set<ll> st4 = {3,6,7,9};
        bool isv1 = includes(st3.begin(), st3.end(), st1.begin(), st1.end());     
        bool isv2 = includes(st4.begin(), st4.end(), st2.begin(), st2.end());     
        bool isv3 = includes(st3.begin(), st3.end(), st2.begin(), st2.end());     
        bool isv4 = includes(st4.begin(), st4.end(), st1.begin(), st1.end());     
        if((isv1 && isv2) || (isv3 && isv4)){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"nO"<<endl;
        }
        
    }
    return 0;
}