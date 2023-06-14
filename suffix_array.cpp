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

vector<int> suffix_array(string s){
    s+="$";
    int n=s.size();
    vector<int> p(n),c(n);
    {
        vector<pair<char,int>> a(n);
        for(int i=0;i<n;i++) a[i]={s[i],i};
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) p[i]=a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i].fs==a[i-1].fs) c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
    }
    int k=0;
    while((1<<k)<n){
        vector<pair<pair<int,int>,int>> a(n);
        for(int i=0;i<n;i++) a[i]={{c[i],c[(i+(1<<k))%n]},i};
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++) p[i]=a[i].ss;
        c[p[0]]=0;
        for(int i=1;i<n;i++){
            if(a[i].fs==a[i-1].fs) c[p[i]]=c[p[i-1]];
            else c[p[i]]=c[p[i-1]]+1;
        }
        k++;
    }
    return p;
}

int main(){
    string s;
    cin>>s;
    vector<int> p=suffix_array(s);
    for(int i=0;i<p.size();i++) cout<<p[i]<<" ";
    cout<<endl;
    return 0;
}

