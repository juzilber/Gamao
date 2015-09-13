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

/***********************************************************************
*
*  $TC Tipo de dados: PEC Descritor da estrutura peca
*
*
***********************************************************************/

typedef struct TAB_tagTabuleiro {

	   char *cor;

   } PEC_tpPeca;
/***************************************************************************
*
*  Função: PEC  &Criar Peca
*
******/

   PEC_tpCondRet PEC_CriarPeca( char *cor, PEC_tpPeca **pPeca ){

	   int indice;
	   PEC_tpCondRet CondRet;

	   if (pPeca != NULL)
	   {
		   PEC_DestruirPeca();

	   } /* if */

	   pPeca = (PEC_tpPeca **)malloc(sizeof(pPeca));
	   if (pPeca == NULL)
		   return PEC_CondRetFaltouMemoria;

	   
	   return PEC_CondRetOK;

   } /* Fim função: PEC  &Criar peca */