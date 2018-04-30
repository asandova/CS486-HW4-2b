August B. Sandoval
CS486
Assignment: HW 4

Part 2B:
	Compile:
		To compile use the privided makefile(in a linux system)
		To use the makefile use command: make
		The makefile will then output a executable named "HW4_2B"
	Run:
		To run the program type: ./HW4_2B
		The program uses command line arguments
		Valid args:
			-user
				This command primes the program to accept user input
			-test
				This command runs test cases

	Tests used:
		Test 0:
		"ACGTRYSWKMBDHVN"
		"ACGUBHVN--BDHVN"
		True result = 11

		Test 1:
		"RYSWKMBDHV"
		"NNNNNNNNNN"
		True result = 10

		Test 2:
		"BDNHV..RY"
		"CATUWS.RY"
		True result = 5

		Test 3:
		"MYAC--CGDHVN"
		"DRV-NTTGDSWK"
		True result = 3

		Test 4:
		"......"
		"------"
		True result = -6