#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD Módulo de definição: PEC  Peca
*
*  Arquivo gerado:              PEC.h
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	   1.00    jdz   15/09/15   inicio de desenvolvimento
*
*  $ED Descrição do módulo
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
*  $TC Tipo de dados: PEC Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de peca
*
***********************************************************************/

   typedef enum {

        PEC_CondRetOK  ,
               /* Concluiu corretamente */

		PEC_CondRetPecaNaoExiste  ,
			   /* A peca não foi criada*/	

        PEC_CondRetFaltouMemoria   
			   /* Faltou Memoria*/


   } PEC_tpCondRet ;

/***********************************************************************
*
*  $FC Função: PEC  &Criar Peca
*
*  $ED Descrição da função
*    Cria uma nova peca vazia
*
*	$EP Parâmetros
*    cor - um vetor cor para colocar na peca.
*    pPeca - ponteiro para criar peca e definir cor. 
*
*
*  $FV Valor retornado
*     PEC_CondRetOK - Se executou corretamente a criaçao da peca
*	  PEC_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   PEC_tpCondRet PEC_CriarPeca(char *cor, PEC_tpPeca **pPeca);


 /***********************************************************************
*
*  $FC Função: PEC Destruir peca
*
*  $ED Descrição da função
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
*  $FC Função: PEC Obter cor
*
*  $ED Descrição da função
*     Obtem a cor e recebe como parametros a peca para descobrir a cor e um vetor cor onde sera preenchida a cor.
*
*  $EP Parâmetros
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


/********** Fim do módulo de definição: Módulo peca **********/


#else
#endif