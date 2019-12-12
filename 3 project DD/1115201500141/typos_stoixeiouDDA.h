/************************************************************************
Header File         : TStoixeioyDDA.h
Syggrafeas			: Y. Cotronis
Skopos       		: diepafh synarthsevn typou stoixeiou
*************************************************************************/
#ifndef __TStoixeioyDDA__
#define __TStoixeioyDDA__
#include <stdio.h>

 struct dedomena {
        char*  word; /* a word, the key of DDA*/
        int index; /* the index of a word to an element of the array of frequencies */
};
typedef struct dedomena  TStoixeiouDDA;
/* basikes sygkriseis gia xrhsh sthn eisagogh-diagarfh-anazhthsh se DDA */
int TSDDA_iso(TStoixeiouDDA Elem1, TStoixeiouDDA Elem2);
int TSDDA_mikrotero(TStoixeiouDDA Elem1, TStoixeiouDDA Elem2);
int TSDDA_megalytero(TStoixeiouDDA Elem1, TStoixeiouDDA Elem2);

void TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source);
char* TSDDA_readValue (char *from, TStoixeiouDDA * Elem,int p);
void TSDDA_writeValue(FILE *to, TStoixeiouDDA Elem);
#endif
