# Gamao
/***************************************************************************
*
*  $MCD Módulo de implementação: PFN  Peças finalizadas
*
*  Arquivo gerado:              PFIN.c
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00    ea    14/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*      Implementa as listas para armazenar as peças finalizadas
*     As listas de Finalizadas são estaticas no modulo, só podem existir duas listas.
*     A estrutura possui uma cabeça encapsulando o seu estado.
*
***************************************************************************/
#define PFIN_OWN
#include "PFIN.H"
#undef PFIN_OWN
#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: PFN Descritor das peças finalizadas
*
*
***********************************************************************/

   typedef struct PFN_tagPecasFinalizadas {

	   LIS_tppLista pFinalizadasUm;
	   /* Ponteiro para a cabeca da primeira lista de Finalizadas */

	   LIS_tppLista pFinalizadasDois;
	   /* Ponteiro para a cabeca da segunda lista de Finalizadas */

   } PFN_tpPecasFinalizadas;

   
/***** Protótipos das funções encapuladas no módulo *****/

   
   void DestruirPecasFinalizadas(void * pValor);


/***************************************************************************
*
*  Função: PFN  &Criar estrutura de peças Finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tppPecasFinalizadas * ppPecasFinalizadas){
	   
	   PFN_tpCondRet CondRet;
	   PFN_tppPecasFinalizadas pPecasFinalizadas;

	   if (ppPecasFinalizadas == NULL)
		   return PFN_CondRetFaltouMemoria;

	   if (*ppPecasFinalizadas != NULL)
		   PFN_DestruirPecasFinalizadas(*ppPecasFinalizadas);

	   pPecasFinalizadas = (PFN_tpPecasFinalizadas *)malloc(sizeof(PFN_tpPecasFinalizadas));
	   if (pPecasFinalizadas == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas->pFinalizadasUm = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas->pFinalizadasUm == NULL)
		   return PFN_CondRetFaltouMemoria;

	   pPecasFinalizadas->pFinalizadasDois = LIS_CriarLista(NULL);
	   if (pPecasFinalizadas->pFinalizadasDois == NULL)
		   return PFN_CondRetFaltouMemoria;

	   *ppPecasFinalizadas= pPecasFinalizadas;

	   return PFN_CondRetOK;

   } /* Fim função: PFN  &Criar estrutura das listas de finalizadas */


/***************************************************************************
*
*  Função: PFN  &Destruir estrutura que contém lista das peças Finalizadas
*
***************************************************************************/

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tppPecasFinalizadas * ppPecasFinalizadas){

	   PFN_tppPecasFinalizadas pPecasFinalizadas;

	   if (ppPecasFinalizadas == NULL || *ppPecasFinalizadas == NULL)
		   return PFN_CondRetEstruturaFinalizadasNaoExiste;

	   pPecasFinalizadas = *ppPecasFinalizadas;

	   LIS_DestruirLista(pPecasFinalizadas->pFinalizadasUm);

	   LIS_DestruirLista(pPecasFinalizadas->pFinalizadasDois);
	   
	   free(pPecasFinalizadas);
	   
	   *ppPecasFinalizadas = NULL;

	   return PFN_CondRetOK;
   
   } /* Fim função: PFN  &Destruir estrutura de peças Finalizadas */


/***************************************************************************
*
*  Função: PFN  &Inserir peca finalizada
*
****************************************************************************/

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador){

	   LIS_tpCondRet CondRet;

	   if (pPecasFinalizadas == NULL)
		   return PFN_CondRetEstruturaFinalizadasNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PFN_CondRetJogadorNaoExiste;
	   	   
	   if (jogador == 1 )
			CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasUm, NULL);

	   else
		   CondRet = LIS_InserirElementoApos(pPecasFinalizadas->pFinalizadasDois, NULL);

	   if (CondRet != LIS_CondRetOK)
		   return PFN_CondRetFaltouMemoria;

	   return PFN_CondRetOK;

   } /* Fim função: PFN  &inserir peca finalizada*/

   
/***************************************************************************
*
*  Função: PFN  &Contar peca finalizada
*  
***************************************************************************/
   
   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador, int *finalizadas){
	   
	   LIS_tpCondRet CondRet=0;
	   //LIS_tpCondRet CondRetFimLista;
	   *finalizadas = 0;


	   if (pPecasFinalizadas == NULL)
		   return PFN_CondRetEstruturaFinalizadasNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PFN_CondRetJogadorNaoExiste;
	   	   
	   if (jogador == 1 ){
		  IrInicioLista(pPecasFinalizadas->pFinalizadasUm);
			  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente( pPecasFinalizadas->pFinalizadasUm, 1);
				if (CondRet != 2) 
					*finalizadas++;
			  }		
	   }
	   else{
		  IrInicioLista(pPecasFinalizadas->pFinalizadasDois);
			  while (CondRet != 2){
				CondRet = LIS_AvancarElementoCorrente( pPecasFinalizadas->pFinalizadasDois, 1);
				if (CondRet != 2) 
					*finalizadas++;
			  }		
	   }


	   return PFN_CondRetOK;

   } /* Fim função: PFN  &contar peca capturada*/


   
/*****  Código das funções encapsuladas no módulo  *****/

   /********** Fim do módulo de implementação: PFN Peças Finalizadas **********/
