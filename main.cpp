#include <iostream>
#include <fstream>
#include "generator.h"
#include "second.h"
#include <iomanip>
using namespace std;


int main() {
	NVP a;
	a.Read("input.txt"); 
	a.subsequence();
	a.Print();

	cout << endl << endl;

	multiply zxc;
	zxc.Read("matrix.txt");
	zxc.Multiplication();
	zxc.Print();
	return 0;
}