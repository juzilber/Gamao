#if ! defined( DADOPONTOS_ )
#define DADOPONTOS_
/***************************************************************************
*
*  $MCD Módulo de definição: DAP  DadoPontos
*
*  Arquivo gerado:              DADOPONTOS.h
*  Letras identificadoras:      DAP
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	   2.00    lsm  13/09/2015  revisao e comentarios
*	   1.00    jdz  12/09/2015  inicio de implementacao
*
*  $ED Descrição do módulo
*     Implementa a struct que cuida da pontuaçao do jogo.
*     O dadopontos é estatico no modulo, só pode existir um dadopontos
*
*
***************************************************************************/

#if defined( DADOPONTOS_OWN )
#define DADOPONTOS_EXT
#else
#define DADOPONTOS_EXT extern
#endif

typedef struct DAP_tagDadoPontos DAP_tpDadoPontos;

/***********************************************************************
*
*  $TC Tipo de dados: DAP Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções do dadoPontos
*
***********************************************************************/

   typedef enum {

	   DAP_CondRetOK,
	      /* Concluiu corretamente */

	   DAP_CondRetDadoPontosNaoExiste,
	      /* O dado de pontos nao foi criado */

	   DAP_CondRetJogadorNaoPodeDobrar,
	      /* O jogador foi o ultimo a dobrar */

	   DAP_CondRetPontuacaoMaxima,
	      /* A potuacao maxima foi atingida */

	   DAP_CondRetFaltouMemoria
	      /* Faltou Memoria */

   } DAP_tpCondRet;


/***********************************************************************
*
*  $FC Função: TAB  &Criar dadoPontos
*
*  $ED Descrição da função
*     Cria um estrutura de dadoPontos para o gamao.
*
*  $EP Parâmetros
*     pDadoPontos - dado para criar
*
*  $FV Valor retornado
*     DAP_CondRetOK - Se executou corretamente a criaçao do dadoPontos
*	  DAP_CondRetFaltouMemoria - Se houve algum problema de memoria ao criar
*
***********************************************************************/

   DAP_tpCondRet DAP_CriarDadoPontos( DAP_tpDadoPontos **pDadoPontos );


/***********************************************************************
*
*  $FC Função: DAP  &Destruir dadoPontos
*
*  $ED Descrição da função
*     Destroi a estrutura de dadosPontos
*
*  $EP Parâmetros
*     pDadoPontos - dado para destruir
*
*  $FV Valor retornado
*     DAP_CondRetOK - Se executou corretamente e destruiu o dadoPontos
*	 DAP_CondRetDadoPontosNaoExiste - Se nao foi criado
*
***********************************************************************/

   DAP_tpCondRet DAP_DestruirDadoPontos( DAP_tpDadoPontos **pDadoPontos );


/***********************************************************************
*
*  $FC Função: DAP  &Dobrar pontuacao
*
*  $ED Descrição da função
*     dobra a pontuacao da partida
*
*  $EP Parâmetros
*     pDadoPontos - dado para dobrar
*     jogador - jogador que deseja dobrar a partida
*
*  $FV Valor retornado
*    DAP_CondRetOK - Se executou corretamente e dobrou a partida
*    DAP_CondRetPontucaoMaxima - o jogo ja atingiu a pontuacao maxima
*    DAP_CondRetJogadorNaoPodeDobrar - se o jogador foi o ultimo a dobrar a partida
*	 DAP_CondRetDadoPontosNaoExiste - Se nao foi criado
*
***********************************************************************/

   DAP_tpCondRet DAP_DobrarPontuacao( DAP_tpDadoPontos **pDadoPontos, int jogador);


/***********************************************************************
*
*  $FC Função: DAP  &Obter pontuacao
*
*  $ED Descrição da função
*     retorna a pontuacao da partida
*
*  $EP Parâmetros
*	  pDadoPontos - dado para obter a pontuacao
*     pontuacao - ponteiro para passar a pontuacao atual
*
*  $FV Valor retornado
*    DAP_CondRetOK - Se executou corretamente
*	 DAP_CondRetDadoPontosNaoExiste - Se nao foi criado
*
***********************************************************************/

   DAP_tpCondRet DAP_ObterPontuacao( DAP_tpDadoPontos *pDadoPontos, int *Pontuacao);


/***********************************************************************
*
*  $FC Função: DAP  &Obter ultima dobra
*
*  $ED Descrição da função
*     retorna o jogador que dobrou pela ultima vez
*
*  $EP Parâmetros
*	  pDadoPontos - dado para obter o jogador
*     jogador - ponteiro para passar o jogador atual
*
*  $FV Valor retornado
*    DAP_CondRetOK - Se executou corretamente
*	 DAP_CondRetDadoPontosNaoExiste - Se nao foi criado
*
***********************************************************************/

   DAP_tpCondRet DAP_ObterUltimaDobra(DAP_tpDadoPontos *pDadoPontos, int *jogador);



#undef DADOPONTOS_EXT

/********** Fim do módulo de definição: DAP dadoPontos **********/

#else
#endif