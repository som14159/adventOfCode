#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> loop;
void findMax(int i,int j,vector<string> &t,vector<vector<int>> &dist,vector<vector<bool>> &visited,int prev_d,int prev_i,int prev_j){
    cout<<i<<" "<<j<<endl;
    if(t[i][j]=='.')
        return;
    dist[i][j]=min(prev_d+1,dist[i][j]);
    if(!visited[i][j])
        loop.push_back({i,j});
    visited[i][j]=true;
    switch(t[i][j]){
        case 'S':
            if((i+1!=prev_i || j!=prev_j)&& i!=t.size()-1 && (t[i+1][j]=='L' || t[i+1][j]=='J' || t[i+1][j]=='|')){
                findMax(i+1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i-1!=prev_i || j!=prev_j) && i!=0 && (t[i-1][j]=='7' || t[i-1][j]=='F' || t[i-1][j]=='|')){
                findMax(i-1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j+1!=prev_j) &&j!=t[i].size()-1 && (t[i][j+1]=='7' || t[i][j+1]=='J' || t[i][j+1]=='-')){
                findMax(i,j+1,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j-1!=prev_j) &&j!=0 && (t[i][j-1]=='F' || t[i][j-1]=='L' || t[i][j-1]=='-')){
                findMax(i,j-1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case '7':
            if((i+1!=prev_i || j!=prev_j) &&i!=t.size()-1 && (t[i+1][j]=='L' || t[i+1][j]=='J' || t[i+1][j]=='|')){
                findMax(i+1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j-1!=prev_j) &&j!=0 && (t[i][j-1]=='F' || t[i][j-1]=='L' || t[i][j-1]=='-')){
                findMax(i,j-1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case 'J':
            if((i-1!=prev_i || j!=prev_j) &&i!=0 && (t[i-1][j]=='7' || t[i-1][j]=='F' || t[i-1][j]=='|')){
                findMax(i-1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j-1!=prev_j) &&j!=0 && (t[i][j-1]=='F' || t[i][j-1]=='L' || t[i][j-1]=='-')){
                findMax(i,j-1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case 'F':
            if((i+1!=prev_i || j!=prev_j) &&i!=t.size()-1 && (t[i+1][j]=='L' || t[i+1][j]=='J' || t[i+1][j]=='|')){
                findMax(i+1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j+1!=prev_j) &&j!=t[i].size()-1 && (t[i][j+1]=='7' || t[i][j+1]=='J' || t[i][j+1]=='-')){
                findMax(i,j+1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case 'L':
            if((i-1!=prev_i || j!=prev_j) &&i!=0 && (t[i-1][j]=='7' || t[i-1][j]=='F' || t[i-1][j]=='|')){
                findMax(i-1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j+1!=prev_j) &&j!=t[i].size()-1 && (t[i][j+1]=='7' || t[i][j+1]=='J' || t[i][j+1]=='-')){
                findMax(i,j+1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case '-':
            if((i!=prev_i || j+1!=prev_j) &&j!=t[i].size()-1 && (t[i][j+1]=='7' || t[i][j+1]=='J' || t[i][j+1]=='-')){
                findMax(i,j+1,t,dist,visited,dist[i][j],i,j);
            }
            if((i!=prev_i || j-1!=prev_j) &&j!=0 && (t[i][j-1]=='F' || t[i][j-1]=='L' || t[i][j-1]=='-')){
                findMax(i,j-1,t,dist,visited,dist[i][j],i,j);
            }
            break;
        case '|':
            if((i+1!=prev_i || j!=prev_j) && i!=t.size()-1 && (t[i+1][j]=='L' || t[i+1][j]=='J' || t[i+1][j]=='|')){

                findMax(i+1,j,t,dist,visited,dist[i][j],i,j);
            }
            if((i-1!=prev_i || j!=prev_j) &&i!=0 && (t[i-1][j]=='7' || t[i-1][j]=='F' || t[i-1][j]=='|')){
                findMax(i-1,j,t,dist,visited,dist[i][j],i,j);
            }
            break;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w+",stdout);
    string s;
    vector<string> tileGrid;
    vector<vector<int>>dist;
    vector<vector<bool>>vis;
    loop.clear();
    while(getline(cin,s)){
        tileGrid.push_back(s);
        vector<int>temp(s.size(),INT_MAX);
        vector<bool>temp1(s.size(),false);
        dist.push_back(temp);
        vis.push_back(temp1);
    }
    pair<int,int> start;
    for(int i=0;i<tileGrid.size();i++){
        for(int j=0;j<tileGrid[i].size();j++){
            if(tileGrid[i][j]=='S')
            {
                start={i,j};
            }
        }
    }
    findMax(start.first,start.second,tileGrid,dist,vis,-1,-1,-1);
    int maxDist=0;
    for(int i=0;i<dist.size();i++){
        for(int j=0;j<dist[i].size();j++){
            if(dist[i][j]!=INT_MAX){
                maxDist=max(maxDist,dist[i][j]);
                cout<<dist[i][j]<<" ";
            }
            else    
                if(tileGrid[i][j]=='.')
                    cout<<".";
                else
                    cout<<" ";
        }
        cout<<endl;
    }
    cout<<maxDist<<endl;
    // loop.clear();
    // loop.push_back({0,0});
    // loop.push_back({0,1});
    // loop.push_back({1,1});
    // loop.push_back({1,0});
    int pos_sum=0,neg_sum=0;
    for(int i=0;i<loop.size()-1;i++){
        pos_sum+=loop[i].first*loop[i+1].second;
        neg_sum+=loop[i].second*loop[i+1].first;
        cout<<loop[i].first<<" "<<loop[i].second<<endl;
    }
    pos_sum+=loop[loop.size()-1].first*loop[0].second;
    neg_sum+=loop[loop.size()-1].second*loop[0].first;
    double area=abs(pos_sum-neg_sum)/2;
    cout<<"Area : "<<area-(loop.size()-1)/2<<endl;
    cout<<loop.size();
}