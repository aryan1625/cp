    #include<bits/stdc++.h>
    using namespace std;
    int mod = 998244353;
    using ll = long long ;
    using ld = long double ;
    vector<ll> findF(ll n){
        vector<ll> ans;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(n/i<=26)ans.push_back(i);
                if(i!=n/i){
                    if(i<=26)ans.push_back(n/i);
                }
            }
        }
        return ans;
    }
    int main(){
        ll t;
        cin>>t;
        while(t--){
            ll n;
            cin>>n;
            string s;
            cin>>s;
            vector<ll> f = findF(n);
            vector<ll> v(26,0);
            for(int i=0;i<n;i++){
                v[s[i]-'a']++;
            }
            sort(v.rbegin(),v.rend());
           
            for(int i=25;i>=0;i--){
                if(v[i]==0)v.pop_back();
                else break;
            }
             if(v.size()==1){
                // cout<<"flafff"<<endl;
                cout<<0<<endl;
                cout<<s<<endl;
                continue;
            }
            ll minChanges = n;
            ll freq = -1;
            for(int x:f){
                ll cnt = n/x;
                ll tmpsz = v.size();
                vector<ll> temp = v;
                vector<ll> ideal(cnt,x);
                ll balance = 0;
                ll total = 0;
                int i = 0;
                for(i=0;i<min(cnt,tmpsz);i++){
                    if(temp[i]>=x){
                        balance+=temp[i]-x;
                        total+=temp[i]-x;
                    }else{
                        if(balance>=x-temp[i]){
                            balance-=(x-temp[i]);
                        }else{
                            total+=x-temp[i]-balance;
                            balance = 0;
                        }
                    }
                }
                while(i<cnt){
                    if(balance>=x){
                        balance-=x;
                    }else{
                        total+=x-balance;
                        balance = 0;
                    }
                    i++;
                }
                if(total<minChanges){
                    minChanges = total;
                    freq = x;
                }

            }
            // cout<<"freq is "<<freq<<endl;
            vector<ll> temp(26,0);
            for(int i=0;i<n;i++){
                temp[s[i]-'a']++;
            }   
            vector<pair<ll,char>> t2(26);
            for(int i=0;i<26;i++){
                t2[i] = {temp[i],char('a'+i)};
            }
            sort(t2.rbegin(),t2.rend());
            ll count = 0;
            bool flag = false;
            for(int i=0;i<26;i++){
                if(count>=n){
                    flag = true;
                }
                if(flag){
                    t2[i].first = 0;
                    continue;
                }else{
                    t2[i].first = freq;
                    count+=freq;
                }
            }
            vector<ll> temp2(26,0);
            for(int i=0;i<26;i++){
                temp2[t2[i].second-'a'] = t2[i].first;
            }
            string ans = string(n,'*');
            for(int i=0;i<n;i++){
                char ch = s[i];
                int val = ch-'a';
                if(temp2[val]>0){
                    temp2[val]--;
                    ans[i] = ch;
                }
            }
            // cout<<ans<<endl;
            for(int i=0;i<n;i++){
                if(ans[i]=='*'){
                    for(int j=0;j<26;j++){
                        if(temp2[j]>0){
                            temp2[j]--;
                            ans[i] = 'a'+j;
                            break;
                        }
                    }
                }
            }
            cout<<minChanges<<endl;
            cout<<ans<<endl;


            
        }
        return 0;
    }