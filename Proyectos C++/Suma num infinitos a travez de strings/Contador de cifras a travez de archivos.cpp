#include <iostream>
#include <fstream>
using namespace std;

int main() {
	string a;
	ifstream fichero("Num1.txt");
	getline(fichero,a);
	cout << a.length() << endl;
	fichero.close();
	return 0;
}
