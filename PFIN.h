# Gamao#if ! defined( PFIN_ )
#define PFIN_
/***************************************************************************
*
*  $MCD Módulo de definição: PFN  Peças finalizadas
*
*  Arquivo gerado:              PFIN.h
*  Letras identificadoras:      PFN
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*      1.00    ea    14/10/2015  inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Implementa as listas para armazenar as peças finalizadas
*     As listas de capturadas são estaticas no modulo, só podem existir duas listas.
*     A estrutura possui uma cabeça encapsulando o seu estado.
*
*
***************************************************************************/

#if defined( PFIN_OWN )
#define PFIN_EXT
#else
#define PFIN_EXT extern
#endif


#include "LISTA.H"


/***********************************************************************
*
*  $TC Tipo de dados: PFN Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do tabuleiro
*
***********************************************************************/

   typedef enum {

         PFN_CondRetOK ,
               /* Concluiu corretamente */

         PFN_CondRetListaVazia ,
               /* A lista não contém elementos */
		 
		 PFN_CondRetEstruturaFinalizadasNaoExiste ,
               /* A estrutura de peças finalizadas não foi criada */
		 
		 PFN_CondRetFaltouMemoria , 
			   /* Faltou Memoria*/

		 PFN_CondRetJogadorNaoExiste,
			   /* Jogador não existe */

		 PFN_CondRetQuantidadeErrada,
			  /*Quantidade de peças contadas errada*/
			   
   } PFN_tpCondRet ;

   typedef struct PFN_tagPecasFinalizadas* PFN_tppPecasFinalizadas ;
   
/***********************************************************************
*
*  $FC Função: PFN  &Criar estrutura de peças finalizadas
*
*  $ED Descrição da função
*     Cria uma estrutura para armazenar as peças finalizadas
*	  Ele pode armazenar peças de qualquer tipo
*
*  $FV Valor retornado
*     PFN_CondRetOK - Se executou corretamente a criaçao da estrutura
*	  PFN_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   PFN_tpCondRet PFN_CriarPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas);


/***********************************************************************
*
*  $FC Função: PFN  &Destruir estrutura de peças finalizadas
*
*  $ED Descrição da função
*     Destrói a estrutura de peças finalizadas
*
*  $FV Valor retornado
*     PFN_CondRetOK    - destruiu a estrutura sem problemas
*     PFN_CondRetTabuleiroNaoExiste - estrutura nao foi criada
*
***********************************************************************/

   PFN_tpCondRet PFN_DestruirPecasFinalizadas (PFN_tppPecasFinalizadas * pPecasFinalizadas);


/***********************************************************************
*
*  $FC Função: PFN  &Inserir peca
*
*  $ED Descrição da função
*     insere uma peca na lista correspontente passada como parâmetro
*
*  $EP Parâmetros
*     jogador    - lista onde a peca sera inserida
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu inserir corretamente
*	  PFN_CondRetFaltouMemoria - se nao conseguiu inserir a peca por problema de memoria
*     PFN_CondRetJogadorNaoExiste - se a lista passada nao faz parte da estrutura de pecas finalizadas
*     PFN_CondRetEstruturaFinalizadasNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*
***********************************************************************/

   PFN_tpCondRet PFN_InserirPecaFinalizada (PFN_tppPecasFinalizadas pPecasFinalizadas, int jogador);


/***********************************************************************
*
*  $FC Função: PFN  &Contar peca finalizada
*
*  $ED Descrição da função
*		conta quantas peças já foram finalizadas e retorna como parâmetro
*
*  $EP Parâmetros
*     jogador    - lista de onde a peca sera retirada
*	  finalizadas - retorno por referência de quantas peças há na lista
*
*  $FV Valor retornado
*     PFN_CondRetOK  - se conseguiu retirar corretamente
*     PFN_CondRetJogadorNaoExiste - se o jogador passado nao faz parte do jogo
*     PFN_CondRetEstruturaFinalizadasNaoExiste   - se a estrutura de pecas finalizadas nao foi criada
*
***********************************************************************/

   PFN_tpCondRet PFN_ContarPecaFinalizada (PFN_tppPecasFinalizadas* pPecasFinalizadas, int jogador, int *finalizadas);



#undef PFIN_EXT

   /********** Fim do módulo de definição: PFN  peças finalizadas **********/

#else
#endif
