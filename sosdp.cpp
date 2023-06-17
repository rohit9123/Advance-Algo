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

vector<int> m(1e5+1);
//adding element to all its superset
void claculate_forward1(){
    for(int i=0;i<20;i++){
        for(int j=0;j<=100000;j++){
            if(j&(1<<i)){
                m[j]+=m[j^(1<<i)];
            }
        }
    }
}
void calculate_backword1(){
    for(int i=0;i<20;i++){
        for(int j=100000;j>=0;j--){
            if(j&(1<<i)){
                m[j]-=m[j^(1<<i)];
            }
        }
    }
}
//adding element to its subset
void calculate_forward2(){
    for(int i=0;i<20;i++){
        for(int j=100000;j>=0;j--){
            if(i&(1<<j)){
                m[j^(1<<i)]+=m[j];
            }
        }
    }
}

void calculate_backward2(){
    for(int i=0;i<20;i++){
        for(int j=0;j<=100000;j++){
            if(i&(1<<j)){
                m[j^(1<<i)]-=m[j];
            }
        }
    }
}


int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
        m[arr[i]]++;
    }
    calculate_forwad();

}