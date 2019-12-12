/************************************************************************
Implementation File	: TStoixeiouDDA.c
Syggrafeas			: Y. Cotronis
Skopos				: Ylopoihsh synarthsevn typou stoixeiou
*************************************************************************/
#include "typos_stoixeiouDDA.h"
#include <string.h>

int TSDDA_iso(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
  /* synthikh word part == */

	return strcmp(s1.word, s2.word) == 0;
};

int TSDDA_mikrotero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
 /* synthikh word part < */
	return strcmp(s1.word, s2.word)<0;
};

int TSDDA_megalytero(TStoixeiouDDA s1, TStoixeiouDDA s2)
{
  /* synthikh word part > */
	return strcmp(s1.word, s2.word)>0;
};

void TSDDA_setValue (TStoixeiouDDA *target, TStoixeiouDDA source)
{
	*target = source;
}

 char* TSDDA_readValue (char *from, TStoixeiouDDA * Elem,int p)
{
	if (p == 1) {
		Elem->word = strtok(from, " \n");
	}
	else {
		Elem->word = strtok(NULL, " \n");
	}
	return Elem->word;
}

void TSDDA_writeValue(FILE *to,TStoixeiouDDA Elem)
{
	fprintf(to, "%s", Elem.word);
}
