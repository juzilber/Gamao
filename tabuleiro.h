#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: TAB  Tabuleiro
*
*  Arquivo gerado:              TABULEIRO.h
*  Letras identificadoras:      TAB
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   3.00    lsm   14/09/2015  checagem final
*      2.00    lsm   12/09/2015  adicao de mais definicoes
*      1.00    ea    11/09/2015  inicio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Implementa um tabuleiro de gamao.
*     O tabuleiro � estatico no modulo, s� pode existir um tabuleiro
*     O tabuleiro possue uma cabe�a encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( TABULEIRO_OWN )
#define TABULEIRO_EXT
#else
#define TABULEIRO_EXT extern
#endif


#include "LISTA.H"

/***** Declara��es exportadas pelo m�dulo *****/

/* Tipo refer�ncia para uma lista */

typedef struct TAB_tagTabuleiro TAB_tpTabuleiro;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es do tabuleiro
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetCasaVazia ,
               /* A Casa n�o cont�m elementos */

         TAB_CondRetListaNaoExiste ,
			   /* A lista n�o foi criada*/	   
			   
		 TAB_CondRetTabuleiroNaoExiste ,
               /* O tabuleiro n�o foi criado */

		 TAB_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

		 TAB_CondRetErroNaEstrutura ,
		       /* Erro na estrutura do tabuleiro*/

		 TAB_CondRetCasaNaoExiste
		       /* Casa buscada nao existe*/
   } TAB_tpCondRet ;


/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar Tabuleiro
*
*  $ED Descri��o da fun��o
*     Cria uma tabuleiro de gamao, com 24 casas. 
*	  Ele pode armazenar pe�as de qualquer tipo
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para criar
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente a cria�ao do tabuleiro
*	  TAB_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   TAB_tpCondRet TAB_CriarTabuleiro( TAB_tpTabuleiro **pTabuleiro );


/***********************************************************************
*
*  $FC Fun��o: LIS  &Destruir tabuleiro
*
*  $ED Descri��o da fun��o
*     Destr�i o tabuleiro criado.
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para destruir
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*     TAB_CondRetErroNaEstrutura - estrutura do tabuleiro esta errada
*     TAB_CondRetTabuleiroNaoExiste - tabuleiro nao foi criado
*
***********************************************************************/

   TAB_tpCondRet TAB_DestruirTabuleiro( TAB_tpTabuleiro **pTabuleiro );


/***********************************************************************
*
*  $FC Fun��o: TAB  &Inserir peca
*
*  $ED Descri��o da fun��o
*     insere uma peca na casa do tabuleiro passada como parametro 
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para inserir a peca
*     pPeca   - ponteiro para a peca a ser inserida
*     Casa    - casa onde a peca sera inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu inserir corretamente
*	  TAB_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_InserirPeca( TAB_tpTabuleiro **pTabuleiro, void *pPeca, int Casa);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Retirar peca
*
*  $ED Descri��o da fun��o
*     retira uma peca na casa do tabuleiro passada como parametroe retorna por referencia
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para retirar a peca
*     pPeca   - ponteiro para a peca a ser recebida
*     Casa    - casa onde a peca sera retirada
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu inserir corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_RetirarPeca( TAB_tpTabuleiro **pTabuleiro, void **pPeca, int Casa);


/***********************************************************************
*
*  $FC Fun��o: TAB  &Mover peca
*
*  $ED Descri��o da fun��o
*     move uma peca na casa do tabuleiro para outra casa
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para mover a peca
*     Casa    - casa onde a peca sera retirada
*	  Passos  - numero de passos a andar com a pe�a
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu mover corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_MoverPeca( TAB_tpTabuleiro **pTabuleiro, int Casa, int Passos);


/***********************************************************************
*
*  $FC Fun��o: TAB  &quantidade pecas casa
*
*  $ED Descri��o da fun��o
*     conta o numero de pecas na casa e retorna o valor por referencia
*
*  $EP Par�metros
*     pTabuleiro - tabuleiro para contar as pecas
*     Casa    - casa onde a peca sera retirada
*	  Quatidade  - quatidade de pe�as na casa
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu contar corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_QuantidadePecasCasa( TAB_tpTabuleiro *pTabuleiro, int Casa, int *Quantidade);


#undef TABULEIRO_EXT

   /********** Fim do m�dulo de defini��o: TAB  tabuleiro **********/

#else
#endif
