#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
void hex_a_bin(string &hexd, string &bina);
int bin_a_dec(string str);
void procesar(int &v, int &t, string &str);

int main() {
	ios_base::sync_with_stdio(false);cin.tie(nullptr);
	string hexd, str, aux;
	int version, tid, l=0, s=0;
	cin >> hexd;
	hex_a_bin(hexd,str);
	procesar(version,tid,str);
	cout << str  << endl;
	if(tid!=4){
		while(str.size()>11){
			aux="";
			if(str[0]==1)l=15;
			else l=11;
			str.erase(0,1);
			for(int i=0;i<l;++i){
				aux+=str[i];
			}
			s+=bin_a_dec(aux);
			str.erase(0,l);
			cout << aux << endl;
		}
	}
	cout << s << endl;
	return 0;
}

int bin_a_dec(string str){
	reverse(str.begin(),str.end());
	int aux=0, p=1;
	for(size_t i=0;i<str.size();++i){
		if(str[i]=='1')aux+=p;
		p*=2;
	}
	return aux;
}
void procesar(int &v, int &t, string &str){
	string aux;
	aux=str.substr(0,3);
	str.erase(0,3);
	v=bin_a_dec(aux);
	aux=str.substr(0,3);
	str.erase(0,3);
	t=bin_a_dec(aux);
}
void hex_a_bin(string &hexd, string &bina) {
	for(size_t i=0;i<hexd.size();++i){
		if(hexd[i]=='0')bina+="0000";
		else if(hexd[i]=='1')bina+="0001";
		else if(hexd[i]=='2')bina+="0010";
		else if(hexd[i]=='3')bina+="0011";
		else if(hexd[i]=='4')bina+="0100";
		else if(hexd[i]=='5')bina+="0101";
		else if(hexd[i]=='6')bina+="0110";
		else if(hexd[i]=='7')bina+="0111";
		else if(hexd[i]=='8')bina+="1000";
		else if(hexd[i]=='9')bina+="1001";
		else if(hexd[i]=='A')bina+="1010";
		else if(hexd[i]=='B')bina+="1011";
		else if(hexd[i]=='C')bina+="1100";
		else if(hexd[i]=='D')bina+="1101";
		else if(hexd[i]=='E')bina+="1110";
		else if(hexd[i]=='F')bina+="1111";
	}
}
