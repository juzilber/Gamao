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
               /* A lista não contém elementos */

         TAB_CondRetListaNaoExiste ,
			   /*A lista não foi criada*/	   
			   
		 TAB_CondRetTabuleiroNaoExiste ,
               /* o tabuleiro não foi criado */

		 TAB_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Função: TAB  &Criar tabuleiro
*
*  $ED Descrição da função
*     Cria uma lista genérica duplamente encadeada de 24 nós.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro será utilizado pelas funções que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará CondRetFaltouMemoria.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro(void) ;

   
/***********************************************************************
*
*  $FC Função: TAB  &Criar tabuleiro
*
*  $ED Descrição da função
*     Arruma as peças já criadas na lista duplamente encadeada (tabuleiro) de acordo com as regras do jogo.
*
*  $EP Parâmetros
*   
*
*  $FV Valor retornado
*     Se executou corretamente retorna o CondRetOk.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará CondRetFaltouMemoria.
*     Se o time de peças não existir previamente retornará CondRetListaNaoExiste.
*
***********************************************************************/

   TAB_tpCondRet TAB_DistribuirPecas(tpPeca** timeA, tpPeca** timeB) ;


/***********************************************************************
*
*  $FC Função: TAB  &Destruir tabuleiro
*
*  $ED Descrição da função
*    Destroi o tabuleiro e executa o free em todos os nós da lista
*
*  $EP Parâmetros
*     
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Se o tabuleiro não existir previamente retornará CondRetTabuleiroNaoExiste.
*
***********************************************************************/

   TAB_tpCondRet TAB_DestruirTabuleiro(void) ;
