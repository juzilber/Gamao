/***************************************************************************
*  $MCI M�dulo de implementa��o: TAB  Tabuleiro 
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   3.00    lsm   14/09/2015  checagem final
*      2.00    lsm   12/09/2015  adicao de mais funcoes
*      1.00    ea    11/09/2015  inicio do desenvolvimento
*
***************************************************************************/
#define TABULEIRO_OWN
#include "TABULEIRO.H"
#undef TABULEIRO_OWN

#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: TAB Descritor da cabe�a do tabuleiro
*
*
***********************************************************************/

   typedef struct TAB_tagTabuleiro {

	   LIS_tppLista pBaseTabuleiro;
	   /* Ponteiro para a cabeca da lista principal do tabuleiro */

	   LIS_tppLista pCasaCorr;
	   /* ponteiro para a casa corrente do tabuleiro */

   } TAB_tpTabuleiro;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

   void Destruir(void * pValor);


/***************************************************************************
*
*  Fun��o: TAB  &Criar tabuleiro
*  ****/

   TAB_tpCondRet TAB_CriarTabuleiro( TAB_tpTabuleiro **pTabuleiro ){

	   int indice;
	   LIS_tpCondRet CondRet;

	   if ((*pTabuleiro) != NULL)
	   {
		   TAB_DestruirTabuleiro(pTabuleiro);

	   } /* if */

	   *pTabuleiro = (TAB_tpTabuleiro *)malloc(sizeof(TAB_tpTabuleiro));
	   if ((*pTabuleiro) == NULL)
		   return TAB_CondRetFaltouMemoria;

	   (*pTabuleiro)->pBaseTabuleiro = LIS_CriarLista(Destruir);

	   if ((*pTabuleiro)->pBaseTabuleiro == NULL)
		   return TAB_CondRetFaltouMemoria;

	   for (indice = 0; indice < 24; indice++){

		   (*pTabuleiro)->pCasaCorr = LIS_CriarLista(Destruir);

		   if ((*pTabuleiro)->pCasaCorr == NULL)
			   return TAB_CondRetFaltouMemoria;

		   CondRet = LIS_InserirElementoAntes((*pTabuleiro)->pBaseTabuleiro, (*pTabuleiro)->pCasaCorr);

		   if (CondRet == LIS_CondRetFaltouMemoria)
			   return TAB_CondRetFaltouMemoria;

	   } /* for */

	   return TAB_CondRetOK;

   } /* Fim fun��o: TAB  &Criar tabuleiro */


/***************************************************************************
*
*  Fun��o: TAB  &Destruir tabuleiro
*  ****/

   TAB_tpCondRet TAB_DestruirTabuleiro( TAB_tpTabuleiro **pTabuleiro ){

	   int indice;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   IrInicioLista((*pTabuleiro)->pBaseTabuleiro);

	   for (indice = 0; indice < 23; indice++){

		   (*pTabuleiro)->pCasaCorr = (LIS_tppLista)LIS_ObterValor((*pTabuleiro)->pBaseTabuleiro);
		   

		   LIS_DestruirLista((*pTabuleiro)->pCasaCorr);

		   LIS_AvancarElementoCorrente((*pTabuleiro)->pBaseTabuleiro, 1);

	   } /* for */

	   (*pTabuleiro)->pCasaCorr = (LIS_tppLista)LIS_ObterValor((*pTabuleiro)->pBaseTabuleiro);

	   LIS_DestruirLista((*pTabuleiro)->pCasaCorr);
   
	   LIS_DestruirLista((*pTabuleiro)->pBaseTabuleiro);

	   free(*pTabuleiro);

	   return TAB_CondRetOK;
   
   } /* Fim fun��o: TAB  &Destruir tabuleiro */


/***************************************************************************
*
*  Fun��o: TAB  &Inserir peca
*  ****/

   TAB_tpCondRet TAB_InserirPeca( TAB_tpTabuleiro **pTabuleiro, void *pPeca, int Casa){

	   LIS_tpCondRet CondRet;

	   if ((*pTabuleiro) == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista((*pTabuleiro)->pBaseTabuleiro);
	   LIS_AvancarElementoCorrente((*pTabuleiro)->pBaseTabuleiro, Casa - 1);

	   (*pTabuleiro)->pCasaCorr = (LIS_tppLista)LIS_ObterValor((*pTabuleiro)->pBaseTabuleiro);

	   CondRet = LIS_InserirElementoApos((*pTabuleiro)->pCasaCorr, pPeca);

	   if (CondRet != LIS_CondRetOK)
		   return TAB_CondRetFaltouMemoria;

	   return TAB_CondRetOK;

   } /* Fim fun��o: TAB  &inserir peca */

   
/***************************************************************************
*
*  Fun��o: TAB  &retirar peca
*  ****/
   
   TAB_tpCondRet TAB_RetirarPeca( TAB_tpTabuleiro **pTabuleiro, void **pPeca, int Casa){

	   if ((*pTabuleiro) == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista((*pTabuleiro)->pBaseTabuleiro);
	   LIS_AvancarElementoCorrente((*pTabuleiro)->pBaseTabuleiro, Casa - 1);

	   (*pTabuleiro)->pCasaCorr = (LIS_tppLista)LIS_ObterValor((*pTabuleiro)->pBaseTabuleiro);

	   IrFinalLista((*pTabuleiro)->pCasaCorr);

	   *pPeca = LIS_ObterValor((*pTabuleiro)->pCasaCorr);

	   if (*pPeca == NULL)
		   return TAB_CondRetCasaVazia;

	   LIS_ExcluirElemento((*pTabuleiro)->pCasaCorr);

	   return TAB_CondRetOK;

   } /* Fim fun��o: TAB  &destruir peca */


/***************************************************************************
*
*  Fun��o: TAB  &mover peca
*  ****/

   TAB_tpCondRet TAB_MoverPeca( TAB_tpTabuleiro **pTabuleiro, int Casa, int Passos){

	   TAB_tpCondRet CondRet;
	   void* aux;

	   CondRet = TAB_RetirarPeca(pTabuleiro, &aux, Casa);

	   if (CondRet != TAB_CondRetOK)
		   return CondRet;

	   CondRet = TAB_InserirPeca(pTabuleiro, aux, Casa + Passos);

	   return CondRet;

   } /* Fim fun��o: TAB  &mover peca */


/***************************************************************************
*
*  Fun��o: TAB  &quantidade pecas casa
*  ****/

   TAB_tpCondRet TAB_QuantidadePecasCasa( TAB_tpTabuleiro *pTabuleiro, int Casa, int *Quantidade){

	   LIS_tpCondRet CondRet;

	   *Quantidade = 0;

	   if (pTabuleiro == NULL)
		   return TAB_CondRetTabuleiroNaoExiste;

	   if (Casa < 1 || Casa > 24)
		   return TAB_CondRetCasaNaoExiste;

	   IrInicioLista(pTabuleiro->pBaseTabuleiro);
	   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pBaseTabuleiro, Casa - 1);

	   pTabuleiro->pCasaCorr = (LIS_tppLista)LIS_ObterValor(pTabuleiro->pBaseTabuleiro);

	   IrInicioLista(pTabuleiro->pCasaCorr);

	   while (CondRet == LIS_CondRetOK){

		   CondRet = LIS_AvancarElementoCorrente(pTabuleiro->pCasaCorr, 1);
		   *Quantidade+=1;

	   } /* while */

	   if (CondRet == LIS_CondRetListaVazia){

		   *Quantidade = 0;
		   return TAB_CondRetCasaVazia;

	   } /* if */

	   return TAB_CondRetOK;
   }
   
   
/*****  C�digo das fun��es encapsuladas no m�dulo  *****/

/***********************************************************************
*
*  $FC Fun��o: TAB - Destruir base
*
***********************************************************************/

   void Destruir(void * pValor)
   {

	   pValor = NULL;

   } /* Fim fun��o: TAB - Destruir base */


   /********** Fim do m�dulo de implementa��o: TAB  Tabuleiro **********/
