#include<bits/stdc++.h>

using namespace std;

bool isNumber(char c){
	if(c>47 && c<58)
		return 1;
	return 0;
}

long long int lowestLosingTime(long long int t,long long int d){

	long long int llt;
	for(int i=0;i<t/2+1;i++){
		long long int distTravelled=i*(t-i);
		if(distTravelled > d)
			return llt;
		llt=i;
	}
	return llt;
}
	
int main(){
	freopen("input.txt","r",stdin);
	int n=0;
	long long int time;
	long long int dist;
	string s;
	getline(cin,s);
	string t="";
	for(int i=5;i<s.size();){
		while(i<s.size() && s[i]==' ')
			i++;
		while(i<s.size() && isNumber(s[i]))
			t+=s[i++];
		cout<<t<<endl;
	}
	time=stoll(t);
	t="";
	getline(cin,s);
	for(int i=10;i<s.size();){
		while(i<s.size() && s[i]==' ')
			i++;
		while(i<s.size() && isNumber(s[i]))
			t+=s[i++];
	}
	dist=stoll(t);
	long long int l=lowestLosingTime(time,dist);
	long long int answer=(time+1-(l+1)*2);
	cout<<"Answer:"<<answer<<endl;
}
