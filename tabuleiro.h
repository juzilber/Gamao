#if ! defined( TABULEIRO_ )
#define TABULEIRO_
/***************************************************************************
*
*  $MCD Módulo de definição: TAB  Tabuleiro
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*
*  $ED Descrição do módulo
*     Implementa um tabuleiro de gamao.
*     O tabuleiro é estatico no modulo, só pode existir um tabuleiro
*     O tabuleiro possui uma cabeça encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( TABULEIRO_OWN )
#define TABULEIRO_EXT
#else
#define TABULEIRO_EXT extern
#endif


#include "LISTA.H"

typedef struct TAB_tagTabuleiro tpTabuleiro;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do tabuleiro
*
***********************************************************************/

   typedef enum {

         TAB_CondRetOK ,
               /* Concluiu corretamente */

         TAB_CondRetCasaVazia ,
               /* A Casa não contém elementos */

         TAB_CondRetListaNaoExiste ,
			   /* A lista não foi criada*/	   
			   
		 TAB_CondRetTabuleiroNaoExiste ,
               /* O tabuleiro não foi criado */

		 TAB_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

		 TAB_CondRetErroNaEstrutura ,
		       /* Erro na estrutura do tabuleiro*/

		 TAB_CondRetCasaNaoExiste
		       /* Casa buscada nao existe*/
   } TAB_tpCondRet ;


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

   TAB_tpCondRet TAB_CriarTabuleiro( void );


/***********************************************************************
*
*  $FC Função: LIS  &Destruir tabuleiro
*
*  $ED Descrição da função
*     Destrói o tabuleiro criado.
*
*  $FV Valor retornado
*     TAB_CondRetOK    - destruiu sem problemas
*     TAB_CondRetErroNaEstrutura - estrutura do tabuleiro esta errada
*     TAB_CondRetTabuleiroNaoExiste - tabuleiro nao foi criado
*
***********************************************************************/

   TAB_tpCondRet TAB_DestruirTabuleiro( void );


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
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_InserirPeca(void *pPeca, int Casa);


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
*     TAB_CondRetOK  - se conseguiu inserir corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_RetirarPeca(void **pPeca, int Casa);


/***********************************************************************
*
*  $FC Função: TAB  &Mover peca
*
*  $ED Descrição da função
*     move uma peca na casa do tabuleiro para outra casa
*
*  $EP Parâmetros
*     Casa    - casa onde a peca sera retirada
*	  Passos  - numero de passos a andar com a peça
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu mover corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_MoverPeca(int Casa, int Passos);


/***********************************************************************
*
*  $FC Função: TAB  &quantidade pecas casa
*
*  $ED Descrição da função
*     conta o numero de pecas na casa e retorna o valor por referencia
*
*  $EP Parâmetros
*     Casa    - casa onde a peca sera retirada
*	  Quatidade  - quatidade de peças na casa
*
*  $FV Valor retornado
*     TAB_CondRetOK  - se conseguiu contar corretamente
*	  TAB_CondRetCasaVazia - se a casa nao tiver pecas
*     TAB_CondRetCasaNaoExiste - se a casa passada nao faz parte do tabuleiro
*     TAB_CondRetTabuleiroNaoExiste   - se o tabuleiro nao foi criado
*	  TAB_CondRetErroNaEstrutura - se a estrutura estiver errada
*
***********************************************************************/

   TAB_tpCondRet TAB_QuantidadePecasCasa(int Casa, int *Quantidade);


#undef TABULEIRO_EXT

   /********** Fim do módulo de definição: TAB  tabuleiro **********/

#else
#endif
