#include<bits/stdc++.h>
using namespace std;

bool isNumber(char c){
	if(c>47 && c<58)
		return 1;
	return 0;
}

long long mapNumber(string line,long long num){
	vector<long long> range;
	for(int i=0;i<line.size();i++){
		string t="";
		while(i<line.size() && isNumber(line[i])){
			t+=line[i++];	
		}
		range.push_back(stoll(t));
	}
	if(num > range[1]-1 && num < range[1]+range[2])
		return range[0]+(num-range[1]);
	else 
		return num;

}

int main () {
	freopen("input.txt","r",stdin);
	vector<string> s;
	string temp;
	while (getline(cin,temp)) {
		s.push_back(temp);
	}
	vector<long long> seeds;
	for(int i = 7;i < s[0].size();i++){
		string temp = "";
		while(i < s[0].size() && s[0][i] != ' '){
			temp+=s[0][i++];	
		}
		seeds.push_back(stoll(temp));
	}
	long long result=LLONG_MAX;
	cout<<"Size:"<<seeds.size()<<endl;
	for(int i=0;i < seeds.size();i+=2){
		for(long long st=seeds[i];st<(seeds[i]+seeds[i+1]);st++){
			long long start=st;
//			cout<<"Start:"<<start;
			for(int j=0;j<s.size();j++){
				while(j<s.size() && !isNumber(s[j][0])){
					j++;
				}	
				bool found=false;
				while(j<s.size() && isNumber(s[j][0])){
					long long temp=mapNumber(s[j],start);
					if( !found && temp!=start ){
						found=true;
						start=temp;
					}
					j++;
				}
			}
//			cout<<"->"<<start<<endl;
			result=min(result,start);
		}
		cout<<"Done"<<endl;
	}
	cout<<"Result:"<<result<<endl;
	return 0;
}
