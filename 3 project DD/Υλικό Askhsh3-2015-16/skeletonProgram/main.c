/************************************************************************
Programma pelaths	: main.c
Syggrafeas			: 
Skopos				: skeleton main for askhsh 3
*************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include "typos_stoixeiouDDA.h"
#include "Words.h"


void InitialiseTree(FILE *wordlist, typosWords W);
void SearchUpdateTree(FILE *wordlist, typosWords W);
void Results(FILE *out, typosWords W);


int main(int argc, char *argv[])
{ 	typosWords A;
   FILE *WordList, *Text, *Output ;

/* need to add appropriate open and close files */

  	A=dhmiourgia_Words();
  	InitialiseTree(WordList, A);
	SearchUpdateTree(Text, A);
	Results(Output, A);
	katastrofh_Words(&A);
	
  getchar();	
  return 0;
}

void InitialiseTree(FILE *wordlist, typosWords W)
{
	/* Reads words from wordlist and inserts into DDA using InsertWord
		after 1024, 2048, 4096,... words sets array times using SetInsertTime 
	*/
}

void SearchUpdateTree(FILE *wordlist, typosWords W)
{
	/* Reads words from wordlist and calls CheckWord 
	   updates times using SetCheck Time
	*/ 
}

void Results(FILE *out, typosWords W)
{/* calls ShowCommonWords, updates time diadromh using SetDiadromhTime and Prints times and Counters*/
	ShowCommonWords(out, W);
	
	PrintData(out, W);
}
