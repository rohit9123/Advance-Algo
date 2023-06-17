#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cmath>
#include<string.h>
#include<math.h>
#include<unordered_map>
#include<iomanip>
#include<unordered_set>
 
#define rep(i,x,n) for(int i=x;i<n;i++)
#define ll long long
#define fs first
#define ss second
#define mod 1000000007
#define pb push_back
#define in insert
#define pres(c,x) ((c).find(x)!=c.end());
#define lli long long int
#define vl vector<ll>
#define mp(a,b) make_pair(a,b)
#define maxn 200005
 
 
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
using namespace std;
long long fact[100001];

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        if(i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while(i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if(i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}
long long pow(long long a,int b){
    if(b==0) return 1;
    if(b==1) return a;
    long long ans=pow(a,b/2);
    ans=(ans*ans)%mod;
    if(b%2==1) ans=(ans*a)%mod;
    return ans;
}

long long ncr(int total,int k){
    long long ans=1;
    ans=(fact[total]*pow(fact[k],mod-2)*pow(fact[total-k],mod-2))%mod;
    return ans;
}

void intialize(){
    fact[0]=1;
    for(int i=1;i<=100000;i++){
        fact[i]=(fact[i-1]*i)%mod;
    }
}
int main(){
    intialize();
    int test;
    cin>>test;
    while(test--){
        string s;
        long long n,q;
        cin>>n>>q;
        cin>>s;
        string p="";
        long long total_s=0;
        for(int i=0;i<n;i++){
            p+=s[i];
            vector<int> z=z_function(p+s);
            long max=0;
            for(int j=p.size();j<z.size();j++){
                if(z[j]>max) max=z[j];
            }
            total_s+=s.size()+1-max;

        }
        cout<<total_s<<endl;
        // unordered_map<int,int> ok;
        // unordered_set<string> st;
        // for(int i=0;i<n;i++){
        //     string p="";
        //     for(int j=i;j<n;j++){
        //         p+=s[j];
        //         if(st.find(p)!=st.end()) continue;
        //         st.insert(p);
        //         vector<int> z=z_function(p+'$'+s);
        //         long long total=0;
        //         for(int k=0;k<z.size();k++){
        //             if(z[k]==p.size()){
        //                 total++;
        //             }
        //         }
        //         for(int k=2;k<=total;k++){
        //             long long ways=ncr(total,k);
        //             ok[k]=(ok[k]+ways)%mod;
        //         }
        //     }
        // }
        // while(q--){
        //     int no;cin>>no;
        //     if(no==1){
        //         cout<<(n*(n+1))/2<<endl;
        //     }else{
        //         cout<<ok[no]<<endl;
        //     }
        // }
    }
}