#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    string s;
    int n=21;
    int r=1;
    vector<int> ncr(n+1);
    ncr[0]=1;
    for(int i=1;i<n+1;i++){
        ncr[i]=ncr[i-1]*(n-i+1)/i;
    }
    long long int sum=0;
    while(getline(cin,s)){
        vector<int> num;
        istringstream iss(s);
        int x;
        while(iss>>x){
            num.push_back(x);
        }
        bool neg=false;
        long long int res=0;
        for(int i=0;i<num.size();i++){
            if(!neg){
                res+=(long long)ncr[i+1]*num[i];
            }
            else    
                res-=(long long)ncr[i+1]*num[i];
            neg=!neg;
        }
            sum+=res;
    }
    cout<<sum<<endl;
}