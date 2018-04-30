#include "IUPAC.h"
#include <string>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;

void test() {


	string operands1[] = {"ACGTRYSWKMBDHVN","RYSWKMBDHV","BDNHV..RY","MYAC--CGDHVN","......"};
	string operands2[] = {"ACGUBHVN--BDHVN","NNNNNNNNNN","CATUWS.RY","DRV-NTTGDSWK","------"};
	int truth[] = {11,10,5,3,-6};
	IUPAC s1, s2;
	for (size_t i = 0; i < 5; i++) {
		cout << "Test " << i << endl;
		int value;
		s1 = IUPAC(operands1[i]);
		s2 = IUPAC(operands2[i]);
		cout << "\tSequence 1: " << s1 << endl;
		cout << "\tSequence 2: " << s2 << endl;
		value = IUPAC::Score(s1, s2);
		cout << "\tScore: " << value << endl;
		cout << "\tTruth: " << truth[i] << endl;
		if (value == truth[i]) {
			cout << "\tPassed!" << endl;
		}
		else {
			cout << "\tFailed!" << endl;
		}
		cout << "---------------------------" << endl;
	}

}

void userin() {
	string s1,s2;
	IUPAC seq1, seq2;
	cout << "Enter First IUPAC Sequence: ";
	cin >> s1;
	cout << "Enter Second IUPAC Sequence: ";
	cin >> s2;
	seq1 = IUPAC(s1);
	seq2 = IUPAC(s2);
	cout << "Sequence alignment Score: " << IUPAC::Score(seq1, seq2) << endl;
}

int main(int argv, char* argc[]){
	size_t i = 1;
	bool flags[] = {false,false};
	while (i < argv) {
		if (strcmp(argc[i],"-test") == 0) {
			cout << "Running Tests" << endl;
			flags[0] = true;
		}
		if (strcmp(argc[i],"-user") == 0) {
			flags[1] = true;
		}
		i++;
	}
	if (flags[0]) {
		test();
	}
	if (flags[1]) {
		userin();
	}

	return 0;
}
