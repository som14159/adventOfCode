#include<bits/stdc++.h>
using namespace std;
long long gcd(long long a,long long b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main(){
    freopen("input.txt","r",stdin);
    string dir;
    getline(cin,dir);
    string s;
    getline(cin,s);
    unordered_map<string,pair<string,string>> m;
    vector<string> curr;
    string temp;
    while(getline(cin,s)){
        temp=s.substr(0,3);
        if(temp[2]=='A')
            curr.push_back(temp);
        m[temp]={s.substr(7,3),s.substr(12,3)};
        // cout<<" " << s.substr(0,3)<<" "<<s.substr(7,3)<<" "<<s.substr(12,3)<<endl;
    }
    long long int steps=0;
    int i=0;
    int noZ=0;
    cout<<"Curr : "<<curr.size()<<endl;
    for(auto st:curr)
        cout<<st<<endl;
    int lastZ=0;
    int diff=0;
    vector<pair<int,int>> equation;
    for(int j=0;j<curr.size();j++,i=0,steps=0,lastZ=0,diff=0){
        while(true) {
            if(dir[i]=='L'){
                curr[j]=m[curr[j]].first;
                if(curr[j][2]=='Z')
                {
                    if(steps-lastZ==diff){
                        cout<<diff<<endl;
                        equation.push_back({lastZ,diff});
                        break;
                    }
                    diff=steps-lastZ;
                    lastZ=steps;
                    cout<<" "<<steps<<" - "<<diff<<endl;
                }
            }
            else {
                curr[j]=m[curr[j]].second;
                if(curr[j][2]=='Z')
                {
                    if(steps-lastZ==diff){
                        equation.push_back({lastZ,diff});
                        break;
                    }
                    diff=steps-lastZ;
                    lastZ=steps;
                    cout<<" "<<steps<<" - "<<diff<<endl;
                    noZ++;
                }
            }
            i=(i+1)%dir.size();
            steps++;
        }
        // for(auto st:curr)
        //     cout<<st<<endl;
        // cout<<"------------------------------------------------"<<endl;
    }
    vector<int> lcm;
    for(auto p:equation){
        lcm.push_back(p.second);
        cout<<p.first%p.second<<" "<<p.second<<endl;
    }
    //find LCM of all the second values;
    long long result=equation[0].second;
    for(int i=1;i<equation.size();i++){
        result=(result*equation[i].second)/gcd(result,equation[i].second);
    }
    cout<<result<<endl;
}