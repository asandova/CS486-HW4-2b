#ifndef IUPAC_H
#define IUPAC_H

#include <vector>

enum Nuclio
{
	//Follows the give IUPAC nucluotide code table
	//translating them to usable value
	//mapping the base to prime numbers
	//and the product of any combination of these base are nucliotides
	A = 2,			//A Adenine 
	C = 3,			//C Cytosine
	G = 5,			//G Guanine
	T = 7,			//T Thymine
	U = T,			//U Uracil
	R = A * G,		//R = A | G
	Y = C * T,		//Y = C | T
	S = G * C,		//S = G | C
	W = A * T,		//W = A | T
	K = G * T,		//K = G | T
	M = A * C,		//M = A | C
	B = C * G * T,	//B = C | G | T
	D = A * G * T,	//D = A | G | T
	H = A * C * T,	//H = A | C | T 
	V = A * C * G,	//V = A | C | G
	N = 1,			//N ANY
	DOT=-1,
	DASH=-2,
	INVALID=0	//for invalid nucliotides
};

using namespace std;
class IUPAC {
private:
	vector<Nuclio> Sequence;
	bool isNuc(char n);
	static int match(Nuclio& c1, Nuclio& c2);
public:
	friend ostream& operator<<(ostream & out, const IUPAC& s);

	IUPAC();
	IUPAC(string IUPAC);
	static Nuclio charToNuc(char n);
	static char nucToChar(Nuclio n);
	Nuclio& operator[](size_t index);
	const Nuclio& operator[](size_t index)const;
	static int Score(IUPAC& s1, IUPAC& s2);
	bool check();
	size_t size();
};

#endif // !IUPAC_H

