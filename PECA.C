/***************************************************************************
*  $MCI Módulo de implementação: PEC  Peca 
*
*  Arquivo gerado:              PECA.C
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 jogo de Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
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

	   char cor[10];

   } PEC_tpPeca;
/***************************************************************************
*
*  Função: PEC  &Criar Peca
*
******/

   PEC_tpCondRet PEC_CriarPeca( char cor[], tpPeca **pPeca ){;

	   if ((*pPeca) != NULL)
	   {
		   PEC_DestruirPeca(pPeca);

	   } /* if */

	   *pPeca = (tpPeca *)malloc(sizeof(tpPeca));
	   if (*pPeca == NULL)
		   return PEC_CondRetFaltouMemoria;
	  
	   strcpy(cor, (*pPeca)->cor);
	   
	   return PEC_CondRetOK;

   } /* Fim função: PEC  &Criar peca */


   /***************************************************************************
*
*  Função: PEC  &Destruir Peca
*
******/

   PEC_tpCondRet PEC_DestruirPeca(tpPeca **pPeca)
   {
   
	   if (*pPeca == NULL)
		   return PEC_CondRetPecaNaoExiste;

	   free(*pPeca);

	   return PEC_CondRetOK;
   
   } /* Fim funçao: PEC destruir peca*/


/***************************************************************************
*
*  Função: PEC  &Obter cor Peca
*
******/ 

   PEC_tpCondRet PEC_ObterCor(tpPeca **pPeca, char cor[])
   {
	
	   if (*pPeca == NULL)
		   return PEC_CondRetPecaNaoExiste;

	   strcpy((*pPeca)->cor, cor);
	   
   } /* Fim funçao: PEC obter peca*/

/********** Fim do módulo de implementação: Módulo peca **********/