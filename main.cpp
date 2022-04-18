#include <iostream>
#include <fstream>
#include "generator.h"
#include <iomanip>
using namespace std;


int main() {
	NVP a;
	a.Read("input.txt"); 
	a.subsequence();
	a.same_char('C');
	a.Print();
	return 0;
}