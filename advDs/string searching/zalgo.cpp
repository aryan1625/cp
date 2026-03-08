#include<bits/stdc++.h>
using namespace std;
//zalgo
vector<int> zAlgo(string &s){
    int n = s.size();
    vector<int> ans(n,0);
    int l = 0,r = 0;
    for(int i=1;i<n;i++){
        if(i>r){
            r = i;
            // code snippet for pattern match
            l = i;
            while(r<n && s[r]==s[r-l])r++;
            ans[i] = r-l;
            r--;

        }else{
            //operating inside the box
            int k = i-l;
            //if value doesnt stretches till right bound then just copy it
            if(ans[k]<r-i+1){
                ans[i] = ans[k];
            }else{
                //reusing the code snippet above for checking if there are any further matches
                l = i;
                while(r<n && s[r]==s[r-l])r++;
                ans[i] = r-l;
                r--;
            }
        }
    }
    return ans;
}

//return list of indices where pattern is found
vector<int> patternMatch(string &txt, string &pat){
    string s = pat + '$' + txt;
    int n = pat.size();
    int m = txt.size();
    vector<int> ans;
    vector<int> lcp = zAlgo(s);
    for(int i=n;i<=n+m;i++){
        if(lcp[i]==n){
            ans.push_back(i-n-1);
        }
    }
    return ans;
}
int main(){
    
    return 0;
}