#include <stdlib.h>
#include <string.h>
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

typosWords dhmiourgia_Words()
{
   typosWords WordsNew=malloc(sizeof(RecWords));
   
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&(WordsNew->WordsRiza));
#else   
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&(WordsNew->WordsRiza));
#endif	

	WordsNew->wordCounter=0;
	WordsNew->wordsFound=WordsNew->wordsNotFound=0;
	
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

void InsertWord(typosWords Words, char * w)
{
	/* Input w
		sets stoixeio DDA (kai ta 2 melh) word + index (wordCounter)
		calls eisagogi_komvou sto DDA 
		sets SearchFrequency[wordCounter]=0;
		wordCounter++;
	*/
}

void CheckWord(typosWords Words, char * w)
{
	/* Input w
		sets w se neo stoixeio DDA
		calls anazitisi_komvou and
		if found 
			calls periexomena and increases frequency in array SearchFrequencies[index]
	*/
}

void ShowCommonWords(FILE *out, typosWords Words)
{
	/* diadromh DDA kai emfanish  if frequenxy >= 1 */
}

/* praxeis poy diaxeirizontai toys xronoys */

void SetInsertTime(typosWords Words, float time, int position)
{
	/* Input time, position
		sets Words.InsertTime[position]=time;
	*/
}

void SetCheckTime(typosWords Words, float time){
	/* Sets Serach Times */
}

void SetDiadromhTime(typosWords Words, float time)
{	
	/* Input time
		sets Words.DiadromhTime=time;
	*/
}

void PrintData(FILE *out, typosWords Words)
{
	/* emfanizei InsertTimes, DiadromhTime and Counters*/
}



