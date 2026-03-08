//rabin karp or rolling hash
#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int prime = 101LL;
//the code is not complete as of now i have to complete it later
ull createHash(string &str,int end){
    ull hash = 0;
    for(int i=0;i<=end;i++){
        hash += (str[i]*pow(prime,i));
    }
    return hash;
}
int patternSearch(string &txt, string &pat){
    int n = txt.size();
    int m = pat.size();
    ull patHash = createHash(pat,m-1);
    ull txtHash = createHash(txt,m-1);
    for(int i=0;i<=n-m;i++){
        if(patHash == txtHash){
            //check if the pattern is present in the text or not
            bool flag = true;
            for(int j=0;j<m;j++){
                if(txt[i+j] != pat[j]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                cout<<i<<" ";
            }
        }
        //calculate the hash of the next window of text
        if(i<n-m){
            txtHash = (txtHash - txt[i])/(prime*pow(prime,m-1)) + (txt[i+m]*pow(prime,m-1));
        }
    }

}
int main(){   
    return 0;
}