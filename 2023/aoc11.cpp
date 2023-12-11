#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    string s;
    vector<string> grid;
    while(getline(cin,s)){
        grid.push_back(s);
    }
    vector<long long int> mx(grid.size(),0);
    vector<long long int> my(grid[0].size(),0);
    vector<long long int> hashx;
    vector<long long int> hashy;
    long long int extra=0;
    for(int i=0;i<grid.size();i++){
        bool flag=true;
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='#'){
                hashx.push_back(i);
                hashy.push_back(j);
                flag=false;
            }
        }
        mx[i]=i+extra;
        if(flag){
            extra+=1000000;
            extra--;
        }
    }
    extra=0;
    for(int j=0;j<grid[0].size();j++){
        bool flag=true;
        for(int i=0;i<grid.size();i++){
            if(grid[i][j]=='#'){
                flag=false;
                break;
            }
        }
        my[j]=j+extra;
        if(flag){
            extra+=1000000;
            extra--;
        }
    }
    
    sort(hashx.begin(),hashx.end());
    sort(hashy.begin(),hashy.end());
    long long int dist=0;
    long long int sum=0;
    int no=0;
    for(auto x:hashx){
        dist+=(long long)no*mx[x];
        dist-=(long long)sum;
        sum+=mx[x];
        no++;
    }
    sum=0;
    no=0;
    for(auto y:hashy){
        dist+=(long long)no*my[y];
        dist-=(long long)sum;
        sum+=my[y];
        no++;
    }
    cout<<"Distance :"<<dist<<endl;
}