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

vector<long long> findCandidates(vector<string>s){
	vector<long long> temp;
	for(int i=s.size()-1;i>0;i--){
		vector<long long> tempT;
		vector<vector<long long>> rangeArr;
		while(isNumber(s[i][0])) {
			
			cout<<s[i]<<endl;

			vector<long long> range;
			for(int j=0;j<s[i].size();j++){
				string t="";
				while(j<s[i].size() && isNumber(s[i][j])){
					t+=s[i][j++];	
				}
				range.push_back(stoll(t));
			}
			rangeArr.push_back(range);
			tempT.push_back(range[1]);
			i--;
		}
		for(int j=0;j<temp.size();j++)
		{
			for(int k=0;k<rangeArr.size();k++) {
				if(temp[j]>rangeArr[k][0] && temp[j]<rangeArr[k][2]+rangeArr[k][0])
				{
					temp[j]=rangeArr[k][1]-rangeArr[k][0]+temp[j];
					break;
				}
			}
		}
		cout<<s[i]<<"   ======Ok"<<endl;
		i--;
		for(auto val : tempT)
			temp.push_back(val);
	}
	return temp;
}

int main () {
	freopen("inputf.txt","r",stdin);
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

	
	vector<long long> cand=findCandidates(s);
	vector<long long> finalCand;
	
	for(int i=0;i<seeds.size();i+=2)
	{
		finalCand.push_back(seeds[i]);
		finalCand.push_back(seeds[i]+seeds[i+1]-1);
	}
	
	for(int i=0;i<cand.size();i++){
		for(int j=0;j<seeds.size();j+=2)
		{
			if(cand[i]>seeds[j] && cand[i]<(seeds[j]+seeds[j+1]))
			{
				finalCand.push_back(cand[i]);
				break;
			}
		}
	}
	
	cout<<"Size:"<<finalCand.size()<<endl;
	for(int i=0;i<finalCand.size();i++){		
		long long start=finalCand[i];
		cout<<"Start:"<<start;
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
			cout<<"->"<<start;
		}
		result=min(result,start);
		cout<<"Done"<<endl;
	}
	cout<<"Result:"<<result<<endl;
	return 0;
}
