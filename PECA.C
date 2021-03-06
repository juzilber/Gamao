/***************************************************************************
*  $MCI M�dulo de implementa��o: PEC  Peca 
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 jogo de Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   1.00    jdz   15/09/15   inicio de desenvolvimento 
*
***************************************************************************/
#define PECA_OWN
#include "PECA.H"
#undef PECA_OWN

#include <malloc.h>
#include <stdio.h>
#include <string.h>

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor da estrutura peca
*
*
***********************************************************************/

typedef struct PEC_tagPeca {

	   char *cor;

   } PEC_tpPeca;
/***************************************************************************
*
*  Fun��o: PEC  &Criar Peca
*
******/

   PEC_tpCondRet PEC_CriarPeca( char *cor, PEC_tpPeca **pPeca ){;

	   if ((*pPeca) != NULL)
	   {
		   PEC_DestruirPeca(pPeca);

	   } /* if */

	   *pPeca = (PEC_tpPeca *)malloc(sizeof(PEC_tpPeca));
	   if (*pPeca == NULL)
		   return PEC_CondRetFaltouMemoria;

	   (*pPeca)->cor = (char *)malloc(10 * sizeof(char));
	  
	   strcpy((*pPeca)->cor, cor);
	   
	   return PEC_CondRetOK;

   } /* Fim fun��o: PEC  &Criar peca */


   /***************************************************************************
*
*  Fun��o: PEC  &Destruir Peca
*
******/

   PEC_tpCondRet PEC_DestruirPeca(PEC_tpPeca **pPeca)
   {
   
	   if (*pPeca == NULL)
		   return PEC_CondRetPecaNaoExiste;

	   free(*pPeca);

	   return PEC_CondRetOK;
   
   } /* Fim fun�ao: PEC destruir peca*/


/***************************************************************************
*
*  Fun��o: PEC  &Obter cor Peca
*
******/ 

   PEC_tpCondRet PEC_ObterCor(PEC_tpPeca *pPeca, char *cor)
   {
	
	   if (pPeca == NULL)
		   return PEC_CondRetPecaNaoExiste;

	   strcpy(cor, pPeca->cor);

	   return PEC_CondRetOK;
	   
   } /* Fim fun�ao: PEC obter peca*/

/********** Fim do m�dulo de implementa��o: M�dulo peca **********/