#include   <stdio.h>
#include   <string.h>
#include   <memory.h>
#include   <malloc.h>
#include   <assert.h>

#include "LISTA.h"

typedef struct tabuleiro{
	LIS_tppLista ListaCasas;
} tpTabuleiro;

typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetListaVazia ,
               /* A lista n�o cont�m elementos */

         TAB_CondRetListaNaoExiste ,
			   /*A lista n�o foi criada*/	   
			   
		 TAB_CondRetTabuleiroNaoExiste ,
               /* o tabuleiro n�o foi criado */

		 TAB_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada de 24 n�s.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� CondRetFaltouMemoria.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro(void) ;

   
/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar tabuleiro
*
*  $ED Descri��o da fun��o
*     Arruma as pe�as j� criadas na lista duplamente encadeada (tabuleiro) de acordo com as regras do jogo.
*
*  $EP Par�metros
*   
*
*  $FV Valor retornado
*     Se executou corretamente retorna o CondRetOk.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� CondRetFaltouMemoria.
*     Se o time de pe�as n�o existir previamente retornar� CondRetListaNaoExiste.
*
***********************************************************************/

   TAB_tpCondRet TAB_DistribuirPecas(tpPeca** timeA, tpPeca** timeB) ;


/***********************************************************************
*
*  $FC Fun��o: TAB  &Destruir tabuleiro
*
*  $ED Descri��o da fun��o
*    Destroi o tabuleiro e executa o free em todos os n�s da lista
*
*  $EP Par�metros
*     
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Se o tabuleiro n�o existir previamente retornar� CondRetTabuleiroNaoExiste.
*
***********************************************************************/

   TAB_tpCondRet TAB_DestruirTabuleiro(void) ;
