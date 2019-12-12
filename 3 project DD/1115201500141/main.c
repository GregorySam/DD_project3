/************************************************************************
Programma pelaths	: main.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "typos_stoixeiouDDA.h"
#include "Words.h"
#define Simple 1 /* 0 for AVL and 1 for Simple BST */


clock_t StartTime, EndTime;
double ratio = 1. / CLOCKS_PER_SEC;

void InitialiseTree(FILE *wordlist, typosWords W);
void SearchUpdateTree(FILE *wordlist, typosWords W);
void Results(FILE *out, typosWords W);

int main(int argc, char *argv[])
{ 	typosWords A;
   FILE *WordList, *Text, *Output ;

/* need to add appropriate open and close files */
   if (argc == 1) {
	   WordList = stdin;
	   Text = stdin;
	   printf("H eisagogh kai h anazitish tha ginoun mono apo ton xrhsth ,grapse Exit gia na samathsh h eisagogh h h anazitish\n");
   }
   else if (argc == 2) {
	   WordList = fopen(argv[1], "r");
	   Text = stdin;
	   printf("H anazitish tha ginei mono apo ton xrhsth ,Exit gia na stamathsei\n");
   }
   else {
	   WordList = fopen(argv[1], "r");
	   Text = fopen(argv[2], "r");
	   printf("H eisagogh kai h anazitish tha ginoun automata\n");
   }
  	A=dhmiourgia_Words();
	StartTime = clock();
  	InitialiseTree(WordList, A);
	EndTime = clock();
	SetInsertTime(A, (float)ratio*(long)EndTime - (float)ratio*(long)StartTime, 7);
	StartTime = clock();
	SearchUpdateTree(Text, A);
	EndTime = clock();
	SetCheckTime(A, (float)ratio*(long)EndTime - (float)ratio*(long)StartTime);
	#if (Simple) 
		if (argv[1] == NULL) {
			Output = fopen("BST_Results.txt", "w");
		}
		else if (strcmp(argv[1], "wordsByABC.txt") == 0) {
			Output = fopen("BST_ResultsByABC.txt", "w");
		}
		else if (strcmp(argv[1], "wordsByRandom.txt") == 0) {
			Output = fopen("BST_ResultsByRandom.txt", "w");
		}
		else if(strcmp(argv[1], "wordsByFrequency.txt") == 0) {
			Output = fopen("BST_ResultsByFrequency.txt", "w");
		}
	#else
		if (argv[1] == NULL) {
			Output = fopen("AVL_Results.txt", "w");
		}
		else if (strcmp(argv[1], "wordsByABC.txt") == 0) {
			Output = fopen("AVL_ResultsByABC.txt", "w");
		}
		else if (strcmp(argv[1], "wordsByRandom.txt") == 0) {
			Output = fopen("AVL_ResultsByRandom.txt", "w");
		}
		else if (strcmp(argv[1], "wordsByFrequency.txt") == 0) {
			Output = fopen("AVL_ResultsByFrequency.txt", "w");
		}
	#endif
	Results(Output, A);
	printf("DONE___________________________\n");
	katastrofh_Words(&A);
	fclose(WordList);
	fclose(Text);
	fclose(Output);
	
  getchar();	
  return 0;
}

void InitialiseTree(FILE *wordlist, typosWords W)
{/* Reads words from wordlist and inserts into DDA using InsertWord
		after 1024, 2048, 4096,... words sets array times using SetInsertTime 
	*/
	printf("Eisagogh words\n");
	int p = 1;
	char words_str[500];
	TStoixeiouDDA word_from_file;
	while (fgets(words_str, 500, wordlist) != NULL && strcmp(words_str,"Exit\n")!=0) {
		while (TSDDA_readValue(words_str, &word_from_file,p) != NULL) {
			InsertWord(W, word_from_file.word,StartTime);
			p++;
		}
		p = 1;
	}
}

void SearchUpdateTree(FILE *wordlist, typosWords W)
{	/* Reads words from wordlist and calls CheckWord
	   updates times using SetCheck Time
	*/
	printf("Searching words in tree\n");
	int p = 1;
	char words_str[500];
	TStoixeiouDDA word_to_find;
	while (fgets(words_str,500,wordlist)!= NULL && strcmp(words_str, "Exit\n") != 0) {
		while (TSDDA_readValue(words_str, &word_to_find,p)!=NULL) {
			CheckWord(W, word_to_find.word);
			p++;
		}
		p = 1;
	}

}

void Results(FILE *out, typosWords W)
{/* calls ShowCommonWords, updates time diadromh using SetDiadromhTime and Prints times and Counters*/
	StartTime = clock();
	ShowCommonWords(out, W);
	EndTime = clock();
	SetDiadromhTime(W, (float)ratio*(long)EndTime - (float)ratio*(long)StartTime);
	PrintData(out, W);
}
