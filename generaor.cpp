#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int &i:a) cin>>i;
    int ans=0;
    for(int i=0;i<n;i++){
        int xors=0,local_ans=0;
        for(int j=i;j>=0;j--){
          xors=(xors^a[j]);
            int no=xors;
            int count=0;
            while(no){
                if(no&1) count++;
                no=no/2;
            }
            if(count%2!=0) local_ans++;
            // cout<<i<<" "<<j<<" "<<xors<<" "<<local_ans<<endl;
        }
        // cout<<local_ans<<endl;
        ans+=local_ans;
    }
    cout<<ans<<endl;
    return 0;
}