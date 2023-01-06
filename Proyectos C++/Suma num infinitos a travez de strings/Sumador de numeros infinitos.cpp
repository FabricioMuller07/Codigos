#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string a, b, c, d;
	long long int lon;
	int co=0, ml=0, co1;
	ifstream Num1("Num1.txt");
	getline(Num1,a);
	ifstream Num2("Num2.txt");
	getline(Num2,b);
	lon=min(a.length(),b.length())-1;
	for(int x=lon;x>=0;--x){
		c=to_string((int(a[a.length()-1-co])-48)+(int(b[b.length()-1-co])-48));
		if(c.length()==1){
			d.insert(0,c);
			co++;
		}
		else{
			co1=1;
			c=to_string(stoi(c)-10);
			d.insert(0,c);
			ml++;
			while(ml>0){
				if(a.length()>=b.length()){
					if(a.length()-1-co-co1>=0 && a.length()-1-co-co1<=a.length()){
						c=to_string(int(a[a.length()-1-co-co1]-48)+1);
						if(c.length()>1){
							c=to_string(stoi(c)-10);
							a[a.length()-1-co-co1]=c[0];
						}
						else{
							a[a.length()-1-co-co1]=c[0];
							ml=0;
						}
					}
					else{
						a.insert(0,"1");
						ml=0;
					}
				}
				else if(b.length()>a.length()){
					if(b.length()-1-co-co1>=0 && b.length()-1-co-co1<=b.length()){
						c=to_string(int(b[b.length()-1-co-co1]-48)+1);
						if(c.length()>1){
							c=to_string(stoi(c)-10);
							b[b.length()-1-co-co1]=b[b.length()-1-co-co1]=c[0];
						}
						else{
							b[b.length()-1-co-co1]=c[0];
							ml=0;
						}
					}
					else{
						b.insert(0,"1");
						ml=0;
					}
				}
				co1++;
			}
			co++;
		}
	}
	if(a.length()>b.length()){
		a.erase(a.begin()+a.length()-co,a.end());
		d.insert(0,a);
	} 
	else if(b.length()>a.length()){
		b.erase(b.begin()+b.length()-co,b.end());
		d.insert(0,b);
	}
	cout << d << endl;
	return 0;
}
