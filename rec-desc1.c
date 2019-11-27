#include <stdio.h>

char ch;
int errflag = 0;

/*
	Recognition-failed message.
*/
void error()
{
	if (!errflag) {
		puts("FAIL");
		errflag = 1;
	}
}

void pa()
{
	if (ch == 'a')
		ch = getchar();
	else error();
}

void pb()
{
	if (ch == 'b')
		ch = getchar();
	else error();
}

void pc()
{
	if (ch == 'c')
		ch = getchar();
	else error();
}

void pd()
{
	if (ch == 'd')
		ch = getchar();
	else error();
}

void pe()
{
	if (ch == 'e')
		ch = getchar();
	else error();
}


/*
	S --> cAb
	S --> a
*/

void pS()
{
	void pA();
	
	switch (ch) {
	case 'c':
		pc(); pA(); pb();
		break;
	case 'a':
		pa();
		break;
	default:
		error();
	}
}

/*
	A --> eSB
*/
void pA()
{
	void pB();

	if (ch == 'e') {
		pe(); pS(); pB();
	}
	else error();
}
/*
	B --> d
*/

void pB()
{
	if (ch == 'd') {
		pd();
	}
	else error();
}

/*
	S --> cAb
	S --> a
	A --> eSB
	B --> d
*/
int main()
{
	puts("CFG rules:");
	puts("\t1. S -> cAb");
	puts("\t2. S -> a");
	puts("\t3. A -> eSB");
	puts("\t4. B -> d");

	printf("Input(a, ceadb, ceceadbdb) = ");

	ch = getchar();
	pS();
	if (!errflag && ch == '\n') puts("OK");
	else error();

	return 0;
}

