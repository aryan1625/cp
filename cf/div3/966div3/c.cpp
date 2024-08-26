#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        map<int,vector<int>> um;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            um[arr[i]].push_back(i);
        }
        int m;
        cin>>m;
        for(int i=0;i<m;i++){
            string s;
            cin>>s;
            set<char> st;
            if(s.size()!=n){
                cout<<"No"<<endl;
                continue;
            }
            bool flag = true;
            for(auto i: um){
                char ch = s[i.second[0]];
                st.insert(ch);
                for(int j=1;j<i.second.size();j++){
                    char ch2 = s[i.second[j]];
                    st.insert(ch2);
                    if(ch2!=ch){
                        flag  = false;
                        break;
                    }
                }
                if(flag==false)break;
            }
            if(flag==false || st.size()!=um.size()){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }

        }
    }
    return 0;
}