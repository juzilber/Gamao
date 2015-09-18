/***************************************************************************
*  $MCI M�dulo de implementa��o: DAP  DadoPontos
*
*  Arquivo gerado:              DADOPONTOS.C
*  Letras identificadoras:      DAP
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   2.00    lsm  13/09/2015  revisao e comentarios
*	   1.00    jdz  12/09/2015  inicio de implementacao
*
***************************************************************************/
#define DADOPONTOS_OWN
#include "DADOPONTOS.H"
#undef DADOPONTOS_OWN

#include <malloc.h>
#include <stdio.h>

/***********************************************************************
*
*  $TC Tipo de dados: DAP Descritor da estrutura do dado
*
*
***********************************************************************/

   typedef struct DAP_tagDadoPontos {

	   int pontuacao;
	   /* Pontua�ao atual do jogo */

	   int jogador;
	   /* Ultimo jogador a dobrar a partida (1 ou 2), comeca com 0 */

   } DAP_tpDadoPontos;


/*****  Dados encapsulados no m�dulo  *****/

   static DAP_tpDadoPontos * pDadoPontos = NULL;
      /* Ponteiro para a estrutura de dadoPontos */


/***************************************************************************
*
*  Fun��o: DAP  &Criar dadoPontos
*  ****/

   DAP_tpCondRet DAP_CriarDadoPontos( void ){

	   if (pDadoPontos != NULL)
		   DAP_DestruirDadoPontos();

	   pDadoPontos = (DAP_tpDadoPontos*)malloc(sizeof(DAP_tpDadoPontos));
	   if (pDadoPontos == NULL)
		   return DAP_CondRetFaltouMemoria;

	   pDadoPontos->jogador = 0;
	   pDadoPontos->pontuacao = 1;

	   return DAP_CondRetOK;

   } /* Fim fun��o: DAP  &Criar dadoPontos */


/***************************************************************************
*
*  Fun��o: DAP  &Destruir dadoPontos
*  ****/

   DAP_tpCondRet DAP_DestruirDadoPontos( void ){

	   if (pDadoPontos == NULL)
		   return DAP_CondRetDadoPontosNaoExiste;

	   free(pDadoPontos);

	   pDadoPontos = NULL;

	   return DAP_CondRetOK;

   } /* Fim fun��o: DAP  &Destruir dadoPontos */


/***************************************************************************
*
*  Fun��o: DAP  &Dobrar pontuacao
*  ****/

   DAP_tpCondRet DAP_DobrarPontuacao(int jogador){

	   if (pDadoPontos == NULL)
		   return DAP_CondRetDadoPontosNaoExiste;

	   if (pDadoPontos->pontuacao == 64)
		   return DAP_CondRetPontuacaoMaxima;

	   if (pDadoPontos->jogador == jogador)
		   return DAP_CondRetJogadorNaoPodeDobrar;

	   pDadoPontos->pontuacao *= 2;
	   pDadoPontos->jogador = jogador;

	   return DAP_CondRetOK;

   } /* Fim fun��o: DAP  &Dobrar potuacao */



/***************************************************************************
*
*  Fun��o: DAP  &Obter pontuacao
*  ****/

   DAP_tpCondRet DAP_ObterPontuacao(int * Pontuacao){

	   if (pDadoPontos == NULL)
		   return DAP_CondRetDadoPontosNaoExiste;

	   *Pontuacao = pDadoPontos->pontuacao;

	   return DAP_CondRetOK;

   } /* Fim fun��o: DAP  &Obter potuacao */


   /********** Fim do m�dulo de implementa��o: DAP  DadoPontos **********/