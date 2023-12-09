#include<bits/stdc++.h>
using namespace std;
int findType(string s){
    int distinct=0;
    int maxSimilar=0;
    int noJ=0;
    unordered_map<char,int> m;
    for(auto c:s){
        if(c=='J')
        {
            noJ++;
            continue;
        }
        m[c]++;
        maxSimilar=max(m[c],maxSimilar);
    }
    maxSimilar+=noJ;
    distinct=m.size();
    switch(distinct)
    {
        case 5:
            return 6;
        case 4:
            return 5;
        case 3:
            if(maxSimilar==2)
                return 4;
            else
                return 3;
        case 2:
            if(maxSimilar==3)
                return 2;
            else
                return 1;
        case 1:
            return 0;
    }
    return 0;
}

void sortBucket(vector<int> &bucket,vector<string> card){
    unordered_map<char,int> m;
    m['J']=0;
    m['2']=1;
    m['3']=2;
    m['4']=3;
    m['5']=4;
    m['6']=5;
    m['7']=6;
    m['8']=7;
    m['9']=8;
    m['T']=9;
    m['Q']=10;
    m['K']=11;
    m['A']=12;
    // cout<<"Hi"<<endl;
    // for(auto i:bucket)
    //     cout<<card[i]<<endl;
    // cout<<endl;
    // cout<<endl;
    // cout<<endl;
    for(int d=4;d>-1;d--){
        vector<vector<int>> c(13);
        for(int  i=0;i<bucket.size();i++){
            c[12-m[card[bucket[i]][d]]].push_back(bucket[i]);
        }
        bucket.clear();
        for(auto c_vec:c){
            for(auto c_element:c_vec){
                bucket.push_back(c_element);
            }
        }
    }
}
void sortCards(vector<int> &index,vector<string> card){
    vector<vector<int>> bucketCards(7);
    for(int i=0;i<card.size();i++){
        cout<<findType(card[i])<<" "<<card[i]<<endl;
        bucketCards[findType(card[i])].push_back(i);
    }
    for(int i=0;i<7;i++){
        if(bucketCards[i].size()==0)
            continue;
        sortBucket(bucketCards[i],card);
    }
    for(auto vec:bucketCards){
        for(int i:vec)
        {
            cout<<card[i]<<endl;
            index.push_back(i);
        }
    }
}
int main(){
    freopen("input.txt","r",stdin);
    string s;
    vector<int> bids;
    vector<string> card;
    vector<int> index;
    int n=0;
    while(cin>>s){
        int temp;
        cin>>temp;
        card.push_back(s);
        bids.push_back(temp);
        n++;
    }
    index.clear();
    sortCards(index,card);
    long long result=0;
    for(int i=0;i<n;i++){
        result+=bids[index[i]]*(n-i);
    }
    cout<<"Result : "<<result<<endl;
}