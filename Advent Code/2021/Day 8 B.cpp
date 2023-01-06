#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
//6=0
//2=1
//5=2
//5=3
//4=4
//5=5
//6=6
//3=7
//7=8
//6=9

//    0000
//   1    2
//   1    2
//	  3333
//   4    5
//   4    5
//	  6666

void decode(vector<string> &v, vector<char> &code) {
	int pos1=0, pos2=0; char aux; bool flag1, flag2;
	for(int i=0;i<10;++i){ // ENCONTRAR 1 Y 7
		if(v[i].size()==2)pos1=i;
		else if(v[i].size()==3)pos2=i;
	}
	for(size_t i=0;i<v[pos2].size();++i){
		if(v[pos2].at(i)!=v[pos1].at(0) && v[pos2].at(i)!=v[pos1].at(1)){aux=v[pos2].at(i);break;}
	} // ENCONTRAR CODE[0] EN BASE A 1 Y 7
	code[0]=aux;
	for(int i=0;i<10;++i){ // ENCONTRAR CODE[2] Y CODE[5] EN BASE A CODE[0], 1 Y 6
		if(v[i].size()==6){
			flag1=flag2=0;
			for(size_t j=0;j<v[i].size();++j){
				if(v[i].at(j)==v[pos1].at(0)) flag1=1;
				else if(v[i].at(j)==v[pos1].at(1)) flag2=1;
			}
			if( (flag1==1 && flag2==0) || (flag1==0 && flag2==1)){
				if(flag1==1){code[5]=v[pos1].at(0);code[2]=v[pos1].at(1);}
				else {code[5]=v[pos1].at(1);code[2]=v[pos1].at(0);}
				break;
			}
		}
	}
	for(int i=0;i<10;++i){ // ENCONTRAR 4
		if(v[i].size()==4){pos1=i;break;}
	}
	for(int i=0;i<10;++i){ //Encontrar codigos de 3 en base a 4
		if(v[i].size()==5){
			flag1=flag2=0;
			for(size_t j=0;j<v[i].size();++j){
				if(v[i].at(j)==code[2]) flag1=1;
				else if(v[i].at(j)==code[5]) flag2=1;
			}
			if(flag2 && flag1){
				char aux1='x', aux2='x', aux3='x';
				flag1=flag2=0;
				for(int j=0;j<4;++j){
					if(v[pos1].at(j)!=code[2]&& v[pos1].at(j)!=code[2] && v[pos1].at(j)!=code[5] && aux1=='x')aux1=v[pos1].at(j);
					else if(v[pos1].at(j)!=code[2] && v[pos1].at(j)!=code[5] && aux1!='x')aux2=v[pos1].at(j);
				}
				for(size_t j=0;j<v[i].size();++j){
					if(v[i].at(j)==aux1) flag1=1;
					else if(v[i].at(j)==aux2) flag2=1;
					if(v[i].at(j)!=aux1 && v[i].at(j)!=aux2 && v[i].at(j)!=code[2] && v[i].at(j)!=code[5]&& v[i].at(j)!=code[0])aux3=v[i].at(j);
				}
				code[6]=aux3;
				if(flag1) {code[1]=aux2;code[3]=aux1;}
				else {code[1]=aux1;code[3]=aux2;}
				break;
			}
		}
	}
	for(int i=0;i<10;++i){
		if(v[i].size()==7){
			for(size_t j=0;j<v[i].size();++j){
				if(v[i].at(j)!=code[0] && v[i].at(j)!=code[1] && v[i].at(j)!=code[2] && v[i].at(j)!=code[3] && v[i].at(j)!=code[5] && v[i].at(j)!=code[6]) aux=v[i].at(j);
			}
		}
	}
	code[4]=aux;
}
void imprimir_8(vector<char> &code);
int main() {
	string str, num; char trash;
	vector<string> v(10);
	vector<char> code(7,'x');
	ll sum=0;
	while(cin >> v[0]){
		for(int i=1;i<10;++i){
			cin >> v[i];
		}
		decode(v,code);
//		imprimir_8(code);
		cin >> trash;num="";
		for(int i=0;i<4;++i){
			cin >> str;
			if(str.size()==2)num+="1";
			else if(str.size()==4)num+="4";
			else if(str.size()==3)num+="7";
			else if(str.size()==7)num+="8";
			else{
				vector<bool> l(7,0);
				for(size_t j=0;j<str.size();++j){
					for(int k=0;k<7;++k){
						if(str[j]==code[k]){
							l[k]=1; break;
						}
					}
				}
				if(l[0] && l[1] && l[2] && l[4] && l[5] && l[6])num+="0";
				else if(l[0] && l[1] && l[3] && l[4] && l[5] && l[6])num+="6";
				else if(l[0] && l[1] && l[2] && l[3] && l[5] && l[6])num+="9";
				else if(l[0] && l[2] && l[3] && l[6] && l[5])num+="3";
				else if(l[0] && l[2] && l[3] && l[4] && l[6])num+="2";
				else if(l[0] && l[1] && l[3] && l[5] && l[6])num+="5";
			}
		}
		cout << num << endl;
		sum+=stoi(num);
	}
	cout << sum << endl;
	return 0;
}
	
void imprimir_8(vector<char> &code){
	cout << " " << code[0] << code[0] << code[0] << code[0] << endl;
	cout << code[1] << "    " << code[2] << endl;
	cout << code[1] << "    " << code[2] << endl;
	cout << " " << code[3] << code[3] << code[3] << code[3] << endl;
	cout << code[4] << "    " << code[5] << endl;
	cout << code[4] << "    " << code[5] << endl;
	cout << " " << code[6] << code[6] << code[6] << code[6] << endl;	
}

