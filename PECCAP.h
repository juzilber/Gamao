# Gamao
#if ! defined( PECCAP_ )
#define PECCAP_
/***************************************************************************
*
*  $MCD Módulo de definição: PCA  Peças capturadas
*
*  Arquivo gerado:              PECCAP.h
*  Letras identificadoras:      PCA
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      2.00	ea    19/10/2015  adaptações na insere e retira
*      1.00    ea    09/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa as listas para armazenar as peças capturadas
*     As listas de capturadas são estaticas no modulo, só podem existir duas listas.
*     A estrutura possui uma cabeça encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( PECCAP_OWN )
#define PECCAP_EXT
#else
#define PECCAP_EXT extern
#endif


#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: PCA Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do tabuleiro
*
***********************************************************************/

   typedef enum {

         PCA_CondRetOK ,
               /* Concluiu corretamente */

         PCA_CondRetListaVazia ,
               /* A lista não contém elementos */
		 
		 PCA_CondRetEstruturaCapturadasNaoExiste ,
               /* A estrutura de peças capturadas não foi criada */
		 
		 PCA_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

		 PCA_JogadorNaoExiste,
			   /* Jogador não existe */
		 
		 PCA_PecaErrada
			   /*Retorna peça diferente da esperada*/
   } PCA_tpCondRet ;

   typedef struct PCA_tagPecasCapturadas * PCA_tppPecasCapturadas ;
   
/***********************************************************************
*
*  $FC Função: TAB  &Criar Tabuleiro
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

   PCA_tpCondRet PCA_CriarPecasCapturadas (PCA_tppPecasCapturadas * pPecasCapturadas);


/***********************************************************************
*
*  $FC Função: LIS  &Destruir tabuleiro
*
*  $ED Descrição da função
*     Destrói o tabuleiro criado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*     TAB_CondRetTabuleiroNaoExiste - tabuleiro nao foi criado
*
***********************************************************************/

   PCA_tpCondRet PCA_DestruirPecasCapturadas (PCA_tppPecasCapturadas * pPecasCapturadas);


/***********************************************************************
*
*  $FC Função: TAB  &Inserir peca
*
*  $ED Descrição da função
*     insere uma peca na casa do tabuleiro passada como parametro 
*
*  $EP Parâmetros
*     pPeca   - ponteiro para a peca a ser inserida
*     Casa    - casa onde a peca sera inserida
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu inserir corretamente
*	  TAB_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*
***********************************************************************/

   PCA_tpCondRet PCA_InserirPecaCapturada (PCA_tppPecasCapturadas pPecasCapturadas, int jogador, void *pPeca);


/***********************************************************************
*
*  $FC Função: TAB  &Retirar peca
*
*  $ED Descrição da função
*     retira uma peca na casa do tabuleiro passada como parametroe retorna por referencia
*
*  $EP Parâmetros
*     pPeca   - ponteiro para a peca a ser recebida
*     Casa    - casa onde a peca sera retirada
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu retirar corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*
***********************************************************************/

  PCA_tpCondRet PCA_RetirarPecaCapturada (PCA_tppPecasCapturadas pPecasCapturadas, int jogador, void **ppPeca);



#undef PECCAP_EXT

   /********** Fim do módulo de definição: PCA  peças capturadas **********/

#else
#endif
