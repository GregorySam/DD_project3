#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include "Words.h"
#include "typos_stoixeiouDDA.h"
#define Simple 1 /* 0 for AVL and 1 for Simple BST */
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres -
mporeite na xrhsimopoihsete thn  domh
#if ... #else ...#endif
gia na diaforopihsete tis dyo ylopoihseis
Akolou9oyn paradeignata xrhshs
*/

#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif
TStoixeiouDDA data;
typedef struct RecWords
{
     typos_deikti WordsRiza; 	/* to Words apoteleitai apo to DDA */
     int SearchFrequencies[100000]; /* array of times each word is found */
     int wordCounter;				/* counts current number of words in DDA*/
     int wordsFound;				/* counter of words found in DDA */
     int wordsNotFound;				/* counter of words not found in DDA */
     double InsertTime [10];   /* xronoi eisagvghs ana 1024, 2048,...*/
     double CheckTime;         /* xronos anazhthshs */
     double DiadromhTime;	  /* xronos diadromhs */
} RecWords;
clock_t StartTime_2, EndTime_2;
double ratio_2= 1. / CLOCKS_PER_SEC;
typosWords dhmiourgia_Words()
{
   typosWords WordsNew=malloc(sizeof(RecWords));
   unsigned int i ;
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&(WordsNew->WordsRiza));
#else
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&(WordsNew->WordsRiza));
#endif
	data.index=0;
	WordsNew->wordCounter=0;
	WordsNew->wordsFound=WordsNew->wordsNotFound=0;
	for (i = 0;i <= 99999;i++) {
		WordsNew->SearchFrequencies[i] = 0;
	}
	for (i = 0;i <= 6;i++) {
		WordsNew->InsertTime[i] = 0;
	}
   return WordsNew;
}

void katastrofh_Words(typosWords * Wordsptr)
{
#if (Simple)
   Tree_katastrofi(&(*Wordsptr)->WordsRiza);
#else
   AVLTree_katastrofi(&(*Wordsptr)->WordsRiza);
#endif
   free(*Wordsptr);
   *Wordsptr=NULL;
}
int pos = -1;
void InsertWord(typosWords Words, char * w,clock_t StartTime_2)
{
	/* Input w
	sets stoixeio DDA (kai ta 2 melh) word + index (wordCounter)
	calls eisagogi_komvou sto DDA
	sets SearchFrequency[wordCounter]=0;
	wordCounter++;
	*/
	unsigned int error = 0;
	data.word =malloc(strlen(w)+1);
	strcpy(data.word,w);
#if (Simple)
	Tree_eisagogi(&(Words->WordsRiza), data,&error);
#else
	unsigned int x = 0;
	AVLTree_eisagogi(&(Words->WordsRiza), data,&x,&error);
#endif
	if(error){
   	/*failed to insert*/
   }
	else {
		data.index++;
		Words->SearchFrequencies[Words->wordCounter] = 0;
		Words->wordCounter++;
	}
	if (Words->wordCounter == 1024 || Words->wordCounter == 2048 || Words->wordCounter == 4096||
		Words->wordCounter == 8192 || Words->wordCounter == 16384 || Words->wordCounter == 32768 || Words->wordCounter == 65536){
		pos++;
		EndTime_2= clock();
		SetInsertTime(Words, (float)ratio_2*(long)EndTime_2 - (float)ratio_2*(long)StartTime_2, pos);
	}

}

void CheckWord(typosWords Words, char * w)
{
	/* Input w
	sets w se neo stoixeio DDA
	calls anazitisi_komvou and
	if found
	calls periexomena and increases frequency in array SearchFrequencies[index]
	*/
	typos_deikti WordsRiza;
	unsigned int found=0;
	data.word = malloc(strlen(w) + 1);
	strcpy(data.word, w);
	#if (Simple)
		Tree_anazitisi(Words->WordsRiza, data, &(WordsRiza),&found);
		if (found) {
			Tree_periexomeno(WordsRiza, &data);
		}
	#else
		AVLTree_anazitisi(Words->WordsRiza, data, &(WordsRiza),&found);
		if (found) {
			AVLTree_periexomeno(WordsRiza, &data);
		}
	#endif
	if (found) {
		Words->SearchFrequencies[data.index]++;
		Words->wordsFound++;
	}
	else {
		Words->wordsNotFound++;
	}

}
void endodiataksi(typos_deikti pateras,FILE *out,typosWords Words)
{
	#if(Simple)
		if (!Tree_keno(pateras)){
			endodiataksi(Tree_apaidi(pateras),out, Words);
			Tree_periexomeno(pateras, &data);
			if (Words->SearchFrequencies[data.index] >= 1) {
				TSDDA_writeValue(out, data);
				fprintf(out, " with search frequency %d\n", Words->SearchFrequencies[data.index]);
			}
			endodiataksi(Tree_dpaidi(pateras),out, Words);
		}
	#else
		if (!AVLTree_keno(pateras)) {
			endodiataksi(AVLTree_apaidi(pateras), out, Words);
			AVLTree_periexomeno(pateras, &data);
			if (Words->SearchFrequencies[data.index] >= 1) {
				TSDDA_writeValue(out, data);
				fprintf(out, " with search frequency %d\n", Words->SearchFrequencies[data.index]);
			}
			endodiataksi(AVLTree_dpaidi(pateras), out, Words);
		}
	#endif
}
void ShowCommonWords(FILE *out, typosWords Words)
/* diadromh DDA kai emfanish  if frequenxy >= 1 */
{
	fprintf(out,"Common Words:\n");
	endodiataksi(Words->WordsRiza,out,Words);

}

/* praxeis poy diaxeirizontai toys xronoys */

void SetInsertTime(typosWords Words, float time, int position)
{
	/* Input time, position
	Words.InsertTime[position]=time;
	*/

	if (position <= 6) {
		Words->InsertTime[position] = time;
		return;
	}
	Words->InsertTime[7] = time;

}

void SetCheckTime(typosWords Words, float time){
	/* Sets Serach Times */
	Words->CheckTime = time;
}

void SetDiadromhTime(typosWords Words, float time)
{
	/* Input time
		sets Words.DiadromhTime=time;
	*/
	Words->DiadromhTime = time;
}

void PrintData(FILE *out, typosWords Words)
{
	/* emfanizei InsertTimes, DiadromhTime and Counters*/
	unsigned int i,f=1024;

	for (i = 0;i <= 6;i++) {
		fprintf(out, "InsertTime:%g seconds meta apo %d lexeis\n",Words->InsertTime[i],f);
		f = f * 2;
	}
	fprintf(out, "InsertTime (all words):%g seconds\nCheckTime:%g seconds\nDiadromhTime:%g seconds\nWordsFound:%d\nWordsNotFound:%d\nWordsCounter:%d\n", Words->InsertTime[7],
		Words->CheckTime, Words->DiadromhTime, Words->wordsFound, Words->wordsNotFound, Words->wordCounter);
}



