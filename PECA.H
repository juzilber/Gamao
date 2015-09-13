#if ! defined( PECA_ )
#define PECA_
/***************************************************************************
*
*  $MCD Módulo de definição: PEC  Peca
*
*  Arquivo gerado:              PEC.h
*  Letras identificadoras:      PEC
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*
*  $ED Descrição do módulo
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
*  $TC Tipo de dados: LIS Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções de peca
*
***********************************************************************/

   typedef enum {

        PEC_CondRetOK ,
               /* Concluiu corretamente */

		PEC_CondRetPecaNaoExiste ,
			   /* A peca não foi criada*/	

        PEC_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/


} PEC_tpCondRet ;

/***********************************************************************
*
*  $FC Função: TAB  &Criar Peca
*
*  $ED Descrição da função
*     Cria uma tabuleiro de gamao, com 24 casas. 
*	  Ele pode armazenar peças de qualquer tipo
*
*  $FV Valor retornado
*     TAB_CondRetOK - Se executou corretamente a criaçao do tabuleiro
*	  TAB_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   PEC_tpCondRet PEC_CriarPeca(char *cor, tpPeca **pPeca);







#else
#endif