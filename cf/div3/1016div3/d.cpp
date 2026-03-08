#include<bits/stdc++.h>
using namespace std;
long long int extract1(string &s){
    long long int val = 0;
    for(int i=3;i<s.size();i++){
        val = val*10 + (s[i]-'0');
    }
    return val;
}
pair<long long int,long long int> extract2(string &s){
    long long val1 = 0;
    long long i = 0;
    for(i=3;i<s.size() && s[i]!=' ';i++){
        val1 = val1*10 + (s[i]-'0');
    }
    long long val2 = 0;
    for(int j=i+1;j<s.size();j++){
        val2 = val2*10 + (s[j]-'0');
    }
    return {val1,val2};
}
long long int solve(string &s,int n){
    pair<long long int,long long int> p = extract2(s);
    long long int x = p.first-1;
    long long int y = p.second-1;
    long long val = 0;
    long long div = 1LL<<(2*n-2);
    while(div>0) {
        long long int inc=sqrt(div);
        long long int quot;
        if(x>=inc&&y>=inc){
            quot=2;
            x-=inc;
            y-=inc;
        } else if(x>=inc){
            quot=3;
            x-=inc;
        } else if(y>=inc){
            quot=4;
            y-=inc;
        } else{
            quot=1;
        }
        val+=(quot-1)*div;
        div/= 4;
    }
    return val + 1; 
}
pair<long long int,long long int> solve2(string &s,int n){
    long long int val = extract1(s);
    long long  x = 0;
    long long  y = 0;
    long long int div = 1LL<<(2*n-2);
    while(div>0){
        long long int quot = (val+div-1)/div;
        long long int newDiv = (quot-1)*div;
        long long int newVal = val-newDiv;
        long long int inc = sqrt(div);
        if(quot==2){
            x+=inc;
            y+=inc;
        }else if(quot==3){
            x+=inc;
        }else if(quot==4){
            y+=inc;
        }
        val = newVal;
        div = div/4;
    }
    return {x,y};
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        cin.ignore();
        vector<string> vec(q);
        for(int i=0;i<q;i++){
            getline(cin, vec[i]);
        }
        for(int i=0;i<q;i++){
            if(vec[i][0]=='-'){
                cout<<solve(vec[i],n)<<endl;
                // pair<int,int> p = extract2(vec[i]);
                // cout<<p.first<<" "<<p.second<<endl;
            }else{
                pair<int,int> p = solve2(vec[i],n);
                cout<<p.first+1<<" "<<p.second+1<<endl;
                // cout<<extract1(vec[i])<<endl;
            }
        }

    }
    return 0;
}