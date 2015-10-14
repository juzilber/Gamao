# Gamao
/***************************************************************************
*
*  $MCD Módulo de implementação: PCA  Peças capturadas
*
*  Arquivo gerado:              PECCAP.c
*  Letras identificadoras:      PCA
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00    ea    09/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa as listas para armazenar as peças capturadas
*     As listas de capturadas são estaticas no modulo, só podem existir duas listas.
*     A estrutura possui uma cabeça encapsulando o seu estado.
*
*
***************************************************************************/
#define PECCAP_OWN
#include "PECCAP.H"
#undef PECCAP_OWN
#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: PCA Descritor das peças capturadas
*
*
***********************************************************************/

   typedef struct PCA_tagPecasCapturadas {

	   LIS_tppLista pCapturadosUm;
	   /* Ponteiro para a cabeca da primeira lista de capturados */

	   LIS_tppLista pCapturadosDois;
	   /* Ponteiro para a cabeca da segunda lista de capturados */

   } PCA_tpPecasCapturadas;

   
/***** Protótipos das funções encapuladas no módulo *****/

   
   void DestruirPecasCapturadas(void * pValor);


/***************************************************************************
*
*  Função: PCA  &Criar estrutura de peças capturadas
*
***************************************************************************/

   PCA_tpCondRet PCA_CriarPecasCapturadas (PCA_tppPecasCapturadas * ppPecasCapturadas){
	   
	   PCA_tpCondRet CondRet;
	   PCA_tppPecasCapturadas pPecasCapturadas;

	   if (ppPecasCapturadas == NULL)
		   return PCA_CondRetFaltouMemoria;

	   if (*ppPecasCapturadas != NULL)
		   PCA_DestruirPecasCapturadas(*ppPecasCapturadas);

	   pPecasCapturadas = (PCA_tpPecasCapturadas *)malloc(sizeof(PCA_tpPecasCapturadas));
	   if (pPecasCapturadas == NULL)
		   return PCA_CondRetFaltouMemoria;

	   pPecasCapturadas->pCapturadosUm = LIS_CriarLista(NULL);
	   if (pPecasCapturadas->pCapturadosUm == NULL)
		   return PCA_CondRetFaltouMemoria;

	   pPecasCapturadas->pCapturadosDois = LIS_CriarLista(NULL);
	   if (pPecasCapturadas->pCapturadosDois == NULL)
		   return PCA_CondRetFaltouMemoria;

	   *ppPecasCapturadas= pPecasCapturadas;

	   return PCA_CondRetOK;

   } /* Fim função: PCA  &Criar estrutura das listas de finalizadas */


/***************************************************************************
*
*  Função: PCA  &Destruir estrutura que contém lista das peças capturadas
*
***************************************************************************/

   PCA_tpCondRet PCA_DestruirPecasCapturadas (PCA_tppPecasCapturadas * ppPecasCapturadas){

	   PCA_tppPecasCapturadas pPecasCapturadas;

	   if (ppPecasCapturadas == NULL || *ppPecasCapturadas == NULL)
		   return PCA_CondRetEstruturaCapturadasNaoExiste;

	   pPecasCapturadas = *ppPecasCapturadas;

	   LIS_DestruirLista(pPecasCapturadas->pCapturadosUm);

	   LIS_DestruirLista(pPecasCapturadas->pCapturadosDois);
	   
	   free(pPecasCapturadas);
	   
	   *ppPecasCapturadas = NULL;

	   return PCA_CondRetOK;
   
   } /* Fim função: PCA  &Destruir estrutura de peças capturadas */


/***************************************************************************
*
*  Função: PCA  &Inserir peca capturada
*
****************************************************************************/

   PCA_tpCondRet PCA_InserirPecaCapturada (PCA_tppPecasCapturadas pPecasCapturadas, int jogador){

	   LIS_tpCondRet CondRet;

	   if (pPecasCapturadas == NULL)
		   return PCA_CondRetEstruturaCapturadasNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PCA_CondRetJogadorNaoExiste;
	   	   
	   if (jogador == 1 )
			CondRet = LIS_InserirElementoApos(pPecasCapturadas->pCapturadosUm, NULL);

	   else
		   CondRet = LIS_InserirElementoApos(pPecasCapturadas->pCapturadosDois, NULL);

	   if (CondRet != LIS_CondRetOK)
		   return PCA_CondRetFaltouMemoria;

	   return PCA_CondRetOK;

   } /* Fim função: PCA  &inserir peca capturada*/

   
/***************************************************************************
*
*  Função: PCA  &Retirar peca capturada
*  
***************************************************************************/
   
   PCA_tpCondRet PCA_RetirarPecaCapturada (PCA_tppPecasCapturadas pPecasCapturadas, int jogador){

	     
	   if (pPecasCapturadas == NULL)
		   return PCA_CondRetEstruturaCapturadasNaoExiste;

	   if (jogador != 1 && jogador != 2)
		   return PCA_CondRetJogadorNaoExiste;

	   
	   if (jogador == 1 )
		   LIS_ExcluirElemento(pPecasCapturadas->pCapturadosUm);

	   else
		   LIS_ExcluirElemento(pPecasCapturadas->pCapturadosDois);


	   return PCA_CondRetOK;

   } /* Fim função: PCA  &destruir peca capturada*/


   
/*****  Código das funções encapsuladas no módulo  *****/

   /********** Fim do módulo de implementação: PCA Peças capturadas **********/
