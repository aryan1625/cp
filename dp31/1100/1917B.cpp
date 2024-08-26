#include<bits/stdc++.h>
using namespace std;
//gives mle
// void solve(string &s,unordered_set<string> &us){
//     int n = s.size();
//     if(n==0)return ;
//     //first letter remove
//     string a = s.substr(1,n-1);
//     if(us.find(a)==us.end()){
//          us.insert(a);
//         solve(a,us);
//     }
//     //second lettr remove
//     if(n>=2){
//         string b = s;
//         b.erase(1,1);
//         if(us.find(b)==us.end()){
//             us.insert(b);
//             solve(b,us);
//         }
//     }
//     return ;
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        //try to build logic by finding patterns
        //find the number of distinct char 
        //for ex  - ababa
        //n -> 1(ababa) Ababa
        //n-1 -> 2(because of 2 distinct chars(a,b)) - ABaba
        //n-2 -> 2(because of 2 distinct chars(a,b)) - ABAba
        //n-3 -> 2(because of 2 distinct chars(a,b)) - ABABa
        //n-4 -> 2(because of 2 distinct chars(a,b)) - ABABA

        unordered_set<char> st;
        // solve(s,st);
        long long int ans = 0;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            ans += st.size();
        }
        cout<<ans<<endl;
    }
    return 0;
}