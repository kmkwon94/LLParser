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
	S --> aA
*/

void pS()
{
	void pA();

	if (ch == 'a') {
		pa(); pA();
	}
	else error();
}

/*
	A --> bBBB
	A --> cSd
	A --> d
*/
void pA()
{
	void pB();

	switch (ch) {
	case 'b':
		pb(); pB(); pB(); pB();
		break;
	case 'c':
		pc(); pS(); pd();
		break;
	case 'd':
		pd();
		break;
	default:
		error();
	}

}
/*
	B --> z
*/

void pB()
{
	if (ch == 'e') {
		pe();
	}
	else error();
}

/*
	S --> aA
	A --> bBBB
	A --> cSd
	A --> d
	B --> e
*/
int main()
{
	puts("CFG rules:");
	puts("\t1. S --> aA");
	puts("\t2. A --> bBBB");
	puts("\t3. A --> cSd");
	puts("\t4. A --> d");
	puts("\t5. B --> e");

	printf("Input(ad, abeee, acacabeeedd) = ");

	ch = getchar();
	pS();
	if (!errflag && ch == '\n') puts("OK");
	else error();

	return 0;
}

