#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: PEC  Peca
*
*  Arquivo gerado:              PEC.h
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   1.00    jdz   15/09/15   inicio de desenvolvimento
*
*  $ED Descri��o do m�dulo
*	  define o modulo peca peca para ser usada no jogo de Gamao
*
*
***************************************************************************/

#if defined( PECA_OWN )
#define PECA_EXT
#else
#define PECA_EXT extern
#endif


typedef struct PEC_tagPeca PEC_tpPeca;

/***********************************************************************
*
*  $TC Tipo de dados: PEC Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno das fun��es de peca
*
***********************************************************************/

   typedef enum {

        PEC_CondRetOK  ,
               /* Concluiu corretamente */

		PEC_CondRetPecaNaoExiste  ,
			   /* A peca n�o foi criada*/	

        PEC_CondRetFaltouMemoria   
			   /* Faltou Memoria*/


   } PEC_tpCondRet ;

/***********************************************************************
*
*  $FC Fun��o: PEC  &Criar Peca
*
*  $ED Descri��o da fun��o
*    Cria uma nova peca vazia
*
*	$EP Par�metros
*    cor - um vetor cor para colocar na peca.
*    pPeca - ponteiro para criar peca e definir cor. 
*
*
*  $FV Valor retornado
*     PEC_CondRetOK - Se executou corretamente a cria�ao da peca
*	  PEC_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   PEC_tpCondRet PEC_CriarPeca(char *cor, PEC_tpPeca **pPeca);


 /***********************************************************************
*
*  $FC Fun��o: PEC Destruir peca
*
*  $ED Descri��o da fun��o
*     Destroi uma peca passada como parametro.
*
*  $FV Valor retornado
*     PEC_CondRetOK - se executou ok
*     PEC_CondRetPecaNaoExiste - se a peca nao foi criada
*
***********************************************************************/

   PEC_tpCondRet PEC_DestruirPeca(PEC_tpPeca **pPeca);

/***********************************************************************
*
*  $FC Fun��o: PEC Obter cor
*
*  $ED Descri��o da fun��o
*     Obtem a cor e recebe como parametros a peca para descobrir a cor e um vetor cor onde sera preenchida a cor.
*
*  $EP Par�metros
*    cor - um vetor cor onde sera preenchida a cor.
*    pPeca - ponteiro onde sera obtida a cor. 
*
*
*  $FV Valor retornado
*     PEC_CondRetOk - se executou ok
*     PEC_CondRetPecaNaoExiste - se a peca nao foi criada
*
***********************************************************************/
   PEC_tpCondRet PEC_ObterCor(PEC_tpPeca *pPeca, char *cor);

#undef PECA_EXT


/********** Fim do m�dulo de defini��o: M�dulo peca **********/


#else
#endif