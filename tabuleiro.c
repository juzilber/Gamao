/***************************************************************************
*  $MCI Módulo de implementação: TAB  Tabuleiro 
*
*  Arquivo gerado:              TABULEIRO.C
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*
***************************************************************************/
#define TABULEIRO_OWN
#include "TABULEIRO.H"
#undef TABULEIRO_OWN

#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor da cabeça do tabuleiro
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {

	   LIS_tppLista pBaseTabuleiro;
	   /* Ponteiro para a cabeca da lista principal do tabuleiro */

	   LIS_tppLista pCasaCorr;
	   /* ponteiro para a casa corrente do tabuleiro */

   } TAB_tpTabuleiro;


/*****  Dados encapsulados no módulo  *****/

   static tpTabuleiro * pTabuleiro = NULL;
      /* Ponteiro para a cabeca do tabuleiro */


/***** Protótipos das funções encapuladas no módulo *****/

   void DestruirCasa(void * pValor);

   void DestruirBase(void * pValor);


/***************************************************************************
*
*  Função: TAB  &Criar tabuleiro
*  ****/

   TAB_tpCondRet TAB_CriarTabuleiro( void ){

	   int indice;
	   LIS_tpCondRet CondRet;

	   if (pTabuleiro != NULL)
	   {
		   TAB_DestruirTabuleiro();

	   } /* if */

	   pTabuleiro = (tpTabuleiro *)malloc(sizeof(tpTabuleiro));
	   if (pTabuleiro == NULL)
		   return TAB_CondRetFaltouMemoria;

	   pTabuleiro->pBaseTabuleiro = LIS_CriarLista(DestruirBase);

	   if (pTabuleiro->pBaseTabuleiro == NULL)
		   return TAB_CondRetFaltouMemoria;

	   for (indice = 0; indice < 24; indice++){

		   pTabuleiro->pCasaCorr = LIS_CriarLista(DestruirCasa);

		   if (pTabuleiro->pCasaCorr == NULL)
			   return TAB_CondRetFaltouMemoria;

		   CondRet = LIS_InserirElementoAntes(pTabuleiro->pBaseTabuleiro, pTabuleiro->pCasaCorr);

		   if (CondRet == LIS_CondRetFaltouMemoria)
			   return TAB_CondRetFaltouMemoria;

	   } /* for */

	   return TAB_CondRetOK;

   } /* Fim função: TAB  &Criar tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Destruir tabuleiro
*  ****/

   TAB_tpCondRet TAB_DestruirTabuleiro( void ){

	   int indice;
	   LIS_tpCondRet CondRet;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   IrInicioLista(pTabuleiro->pBaseTabuleiro);

	   for (indice = 0; indice < 23; indice++){

		   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);
		   
		   if (pTabuleiro->pCasaCorr == NULL)
			   return TAB_CondRetErroNaEstrutura;

		   LIS_DestruirLista(pTabuleiro->pCasaCorr);

		   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseTabuleiro, 1);

		   if (CondRet != LIS_CondRetOK)
			   return TAB_CondRetErroNaEstrutura;

	   } /* for */

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);

	   if (pTabuleiro->pCasaCorr == NULL)
		   return TAB_CondRetErroNaEstrutura;

	   LIS_DestruirLista(pTabuleiro->pCasaCorr);
   
	   LIS_DestruirLista(pTabuleiro->pBaseTabuleiro);

	   pTabuleiro = NULL;

	   return TAB_CondRetOK;
   
   } /* Fim função: TAB  &Destruir tabuleiro */


/***************************************************************************
*
*  Função: TAB  &Inserir peca
*  ****/

   TAB_tpCondRet TAB_InserirPeca( void *pPeca, int Casa){

	   LIS_tpCondRet CondRet;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista(pTabuleiro->pBaseTabuleiro);
	   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseTabuleiro, Casa - 1);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetErroNaEstrutura;

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);

	   if (pTabuleiro->pCasaCorr == NULL)
		   return TAB_CondRetErroNaEstrutura;

	   CondRet = LIS_InserirElementoApos(pTabuleiro->pCasaCorr, pPeca);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetFaltouMemoria;

	   return TAB_CondRetOK;

   } /* Fim função: TAB  &inserir peca */

   
/***************************************************************************
*
*  Função: TAB  &retirar peca
*  ****/
   
   TAB_tpCondRet TAB_RetirarPeca(void **pPeca, int Casa){

	   LIS_tpCondRet CondRet;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista(pTabuleiro->pBaseTabuleiro);
	   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseTabuleiro, Casa - 1);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetErroNaEstrutura;

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);

	   if (pTabuleiro->pCasaCorr == NULL)
		   return TAB_CondRetErroNaEstrutura;

	   IrFinalLista(pTabuleiro->pCasaCorr);

	   *pPeca = LIS_ObterValor(pTabuleiro->pCasaCorr);

	   if (*pPeca == NULL)
		   return TAB_CondRetCasaVazia;

	   CondRet = LIS_ExcluirElemento(pTabuleiro->pCasaCorr);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetErroNaEstrutura;

	   return TAB_CondRetOK;

   } /* Fim função: TAB  &destruir peca */


/***************************************************************************
*
*  Função: TAB  &mover peca
*  ****/

   TAB_tpCondRet TAB_MoverPeca(int Casa, int Passos){

	   TAB_tpCondRet CondRet;
	   void* aux;

	   CondRet = TAB_RetirarPeca(&aux, Casa);

	   if (CondRet != TAB_CondRetOK)
		   return CondRet;

	   CondRet = TAB_InserirPeca(aux, Casa + Passos);

	   return CondRet;

   } /* Fim função: TAB  &mover peca */


/***************************************************************************
*
*  Função: TAB  &quantidade pecas casa
*  ****/

   TAB_tpCondRet TAB_QuantidadePecasCasa(int Casa, int *Quantidade){

	   LIS_tpCondRet CondRet;

	   *Quantidade = 0;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista(pTabuleiro->pBaseTabuleiro);
	   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseTabuleiro, Casa - 1);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetErroNaEstrutura;

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);

	   if (pTabuleiro->pCasaCorr == NULL)
		   return TAB_CondRetErroNaEstrutura;

	   IrInicioLista(pTabuleiro->pCasaCorr);

	   while (CondRet == LIS_CondRetOK){

		   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pCasaCorr, 1);
		   *Quantidade+=1;

	   } /* while */

	   if (CondRet == LIS_CondRetListaVazia){

		   *Quantidade = 0;
		   return TAB_CondRetCasaVazia;

	   }

	   return TAB_CondRetOK;
   }
   
   
/*****  Código das funções encapsuladas no módulo  *****/

/***********************************************************************
*
*  $FC Função: TAB - Destruir casa
*
***********************************************************************/

   void DestruirCasa(void * pValor)
   {

	   free(pValor);

   } /* Fim função: TAB - Destruir casa */


/***********************************************************************
*
*  $FC Função: TAB - Destruir base
*
***********************************************************************/

   void DestruirBase(void * pValor)
   {

	   pValor = NULL;

   } /* Fim função: TAB - Destruir base */
