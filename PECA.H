#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PEC  Peca
*
*  Arquivo gerado:              PEC.h
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*
*  $ED Descri��o do m�dulo
*   Obtem a cor e retorna por referencia. 
*	Recebe como parametros a peca para descobrir a cor e um vetor cor onde sera preenchida a cor.
*   Retorna CondRetOk, CondRetPecaNaoExiste
*
***************************************************************************/

#if defined( PECA_OWN )
#define PECA_EXT
#else
#define PECA_EXT extern
#endif


typedef struct PEC_tpPeca;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de peca
*
***********************************************************************/

   typedef enum {

        PEC_CondRetOK ,
               /* Concluiu corretamente */

		PEC_CondRetPecaNaoExiste ,
			   /* A peca n�o foi criada*/	

        PEC_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/


} PEC_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: TAB  &Criar Peca
*
*  $ED Descri��o da fun��o
*     Cria uma tabuleiro de gamao, com 24 casas. 
*	  Ele pode armazenar pe�as de qualquer tipo
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente a cria�ao do tabuleiro
*	  TAB_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   PEC_tpCondRet PEC_CriarPeca(char *cor, tpPeca **pPeca);







#else
#endif