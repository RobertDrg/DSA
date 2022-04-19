#include"kmp.h"
#include <time.h>
#include <stdio.h>
int main()
{
	FILE* f;
	errno_t res = fopen_s(&f, "input.txt", "r");
	clock_t  tic;
	clock_t  toc;
	long double elapsed;
	int textLen, patternLen;
	fscanf_s(f, "%d", &textLen);
	fscanf_s(f, "%d", &patternLen);


	char* text = (char*)malloc(textLen * sizeof(char));
	char* pattern = (char*)malloc(patternLen * sizeof(char));

	Read_String(text, f);
	Read_String(pattern, f);

	fclose(f);

	printf("NFA\n");
	tic = clock();
	KMP_Matcher_NFA(text, pattern, textLen, patternLen);
	toc = clock();
	elapsed = (long double)(toc - tic) / CLOCKS_PER_SEC;
	printf("Elapsed time for algorithm is:%.11lf", elapsed);
	printf("\nDFA\n");
	KMP_Matcher_DFA(text, pattern, textLen, patternLen);

	return 0;
}