#include<bits/stdc++.h>
using namespace std;

bool chackParanthesis(char s[]){
	stack<char> st;
	int length=strlen(s);
	for(int i=0;i<length;i++){
		if(s[i]=='('){
			st.push(s[i]);
		}
		else{
			if(st.empty()|| st.top()!='('){
				return false;
			}
			else{
				st.pop();
			}
		}
	}

	return true;

}

int main(){
	char s[100000];
	cin>>s;	

	if(chackParanthesis(s)){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
	return 0;
}
