#include "IUPAC.h"
#include <ctype.h>
#include <vector>
#include <iostream>

using namespace std;

IUPAC::IUPAC() {
	Sequence = vector<Nuclio>();
}
IUPAC::IUPAC(string iupac) {
	Sequence = vector<Nuclio>();

	for (string::const_iterator itr = iupac.begin();
		itr != iupac.end(); ++itr) {
		Sequence.push_back( charToNuc(*itr) );
	}
}
bool IUPAC::isNuc(char n) {
	n = toupper(n);
	switch (n) {
		case 'A':
		case 'C':
		case 'G':
		case 'T':
		case 'U':
		case 'R':
		case 'Y':
		case 'S':
		case 'W':
		case 'K':
		case 'M':
		case 'B':
		case 'D':
		case 'H':
		case 'V':
		case 'N':
		case '.':
		case '-':
			return true;
			break;
		default:
			return false;
			break;
	}
}
int IUPAC::match(Nuclio& n1, Nuclio& n2) {
	Nuclio bases[] = {A,C,G,T};

	if ((n1 == DOT || n1 == DASH) || (n2 == DOT || n2 == DASH)) {
		return -1;
	}
	if (n1 == N || n2 == N) {
		return 1;
	}
	for (size_t i = 0; i < 4; i++) {
		if (n1 % bases[i] == 0 && n2 % bases[i] == 0) {
			return 1;
		}
	}
	return -1;
}
Nuclio IUPAC::charToNuc(char n) {
	n = toupper(n);
	switch (n) {
	case 'A':
		return A;
	case 'C':
		return C;
	case 'G':
		return G;
	case 'T':
		return T;
	case 'U':
		return U;
	case 'R':
		return R;
	case 'Y':
		return Y;
	case 'S':
		return S;
	case 'W':
		return W;
	case 'K':
		return K;
	case 'M':
		return M;
	case 'B':
		return B;
	case 'D':
		return D;
	case 'H':
		return H;
	case 'V':
		return V;
	case 'N':
		return N;
	case '.':
		return DOT;
	case '-':
		return DASH;
	default:
		return INVALID;
	}

}
char IUPAC::nucToChar(Nuclio n){
	switch (n) {
	case A:
		return 'A';
	case C:
		return 'C';
	case G:
		return 'G';
	case T:
		return 'T';
	case R:
		return 'R';
	case Y:
		return 'Y';
	case S:
		return 'S';
	case W:
		return 'W';
	case K:
		return 'K';
	case M:
		return 'M';
	case B:
		return 'B';
	case D:
		return 'D';
	case H:
		return 'H';
	case V:
		return 'V';
	case N:
		return 'N';
	case DOT:
		return '.';
	case DASH:
		return '-';
	default:
		return '!';
	}
}
bool IUPAC::check() {
	vector<Nuclio>::const_iterator itr;
	for (itr = Sequence.begin(); itr != Sequence.end(); ++itr) {
		if ( !isNuc(*itr) ) {
			return false;
		}
	}
	return true;
}
int IUPAC::Score(IUPAC& s1, IUPAC& s2) {
	int s = 0;
	if (s1.size() != s2.size()) {
		cout << "Sequences are not the same length\nReturning 0" << endl;
		return 0;
	}
	for (size_t i = 0; i < s1.size(); i++) {
		s += match(s1[i], s2[i]);
	}
	return s;
}
ostream& operator<<(ostream & out, const IUPAC& s) {
	vector<Nuclio>::const_iterator itr;
	for (itr = s.Sequence.begin(); itr != s.Sequence.end(); ++itr) {
		out << IUPAC::nucToChar(*itr);
	}
	return out;
}
Nuclio& IUPAC::operator[](size_t index){
	return Sequence[index];
}
const Nuclio& IUPAC::operator[](size_t index)const{
	return Sequence[index];
}
size_t IUPAC::size() {
	return Sequence.size();
}
