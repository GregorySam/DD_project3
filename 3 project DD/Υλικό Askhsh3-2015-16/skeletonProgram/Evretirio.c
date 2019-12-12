#include "Evretirio.h"

#define Simple 1 /* 0 for AVL - any Evr integer for Simple  */

/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - mporeite na xrhsimopoihsete 
   thn  domh #if ... #else ...#endif gia na diaforopihsete tis dyo ylopoihseis  */
   
#if (Simple)
#include "BST/ch8_BSTpointer.h" /* gia Simple Ylopoihsh */
#else
#include "AVL/ch8_AVLpointer.h" /* gia AVL Ylopoihsh */
#endif


struct EvrNode{
       TStoixeiouEvr *DataArray; /* array of size MaxSize */
       int Index;              /* index of first available element in array */
       typos_deikti TreeRoot;     /* Root of DDA */
} EvrNode;

EvrPtr EvrConstruct(int MaxSize){
/* Oi diafores tvn ylopoihsevn Simple kai AVL einai mikres - 
	mporeite na xrhsimopoihsete thn  domh #if ... #else ...#endif */
   
   typos_deikti TreeRoot;
#if (Simple)
   printf("use simple BST\n");
   Tree_dimiourgia(&TreeRoot);
#else   
    printf("use AVL BST\n");
    AVLTree_dimiourgia(&TreeRoot);
#endif

}

int Evr_Insert(EvrPtr E, TStoixeiouEvr Data){TStoixeiouDDA x;}

int EvrSearch(EvrPtr E, keyType key, int * found){ }


int Evr_PrintAll(EvrPtr E, FILE *out, int * counter){
typos_deikti a=E->TreeRoot;

/* endo-diadromh - use recursion with apaidi-depaidi */ 
/* example of use */
#if (Simple)
    a=Tree_apaidi(a);
#else   
    a=AVLTree_apaidi(a);
#endif
}

int Evr_katastrofi(EvrPtr *E){}
