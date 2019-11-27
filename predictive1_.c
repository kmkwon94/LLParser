#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define NONTERMINALS 2
#define TERMINALS 3
#define RULESIZE 4
#define MAX 100

char create_rule[RULESIZE][MAX];
int parsing_table[NONTERMINALS][TERMINALS];
char stack[999];
int top;

void input_data(char *str)
{
	printf("Input string of a, ceadb ,ceceadbdb = ");
	scanf("%s", str);
	strcat(str, "$");
}

/*
	1. S -> cAb
	2. S -> a
	3. A -> eSB
	4. B -> d

	문자를 인덱스로 표시하기 위하여 아래와 같이 차례대로 A, B..nonterminal 이름 변경.

	
	0. A -> cBb
	1. A -> a
	2. B -> eAC
	3. C -> d
*/
void load_create_rule()
{
	strcpy(create_rule[0], "cBb");
	strcpy(create_rule[1], "a");
	strcpy(create_rule[2], "eAC");
	strcpy(create_rule[3], "d");

	puts("CFG rules:");
	puts("\t1. A -> cBb");
	puts("\t2. A -> a");
	puts("\t3. B -> eAC");
	puts("\t4. C -> d");
}

/*
	   Vn/Vt |	a	b	c	d	e	$
	   --------------------------------------
	     S	 |		1		0		
	     A	 |						2	
		 B	 |					3
	생성 규칙이 없는 빈칸은 -1 로 표시.

	1. S -> cAb
	2. S -> a
	3. A -> eSB
	4. B -> d
*/
void load_parsing_table()
{
	parsing_table[0][0] = 1;
	parsing_table[0][2] = 0;
	parsing_table[1][4] = 2;
	parsing_table[2][3] = 3;
}

char stack_top()
{
	return stack[top-1];
}

void push(char ch)
{
	stack[top++] = ch;
}

void pop()
{
	top--;
}

void init_stack()
{
	top=0;
	push('$');
	push('A');
}

int is_nonterminal(char ch)
{
	if ('A' <= ch && ch <= 'Z') return 1;
	else return 0;
}

void predictive_parsing(int table[NONTERMINALS][TERMINALS], char rule[RULESIZE][MAX], char *input)
{
	char *p = input;
	char *str_p;
	int i, index=0, len;

	while (*p != '$') {
		if (*p == stack_top()) { /* pop */
			pop();
			p++;
		} else { /* expand -- nonterminal */
			index = parsing_table[stack_top()-'A'][*p-'a'];
			if (index != -1) {
				str_p = rule[index];
				len = strlen(str_p);
				printf("[생성규칙 %d] %c -> %s\n", index+1, stack_top(), str_p);
				pop();
				for (i=len-1; i>=0; i--) {
					push(str_p[i]);
				}
			} else { /* error */
				printf("[error] %c -> %c\n", stack_top(), *p);
				return;
			}
		}
	}
	if (*p == '$' && stack_top() == '$') /* accept */
		printf("[accept]\n");
	else printf("[error] is not stack empty \n");
}

int main()
{
	char input[100];

	load_create_rule();
	load_parsing_table();

	input_data(input);
	init_stack();  //시작기호로 초기화

	predictive_parsing(parsing_table, create_rule, input);
	return 0;
}
