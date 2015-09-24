#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD Módulo de definição: DAD  Dado
*
*  Arquivo gerado:              DADO.h
*  Letras identificadoras:      DAD
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	   1.00    jdz  22/09/2015  inicio de implementacao
*
*  $ED Descrição do módulo
*     Implementa o dado de uma partida de Gamao
*
*
***************************************************************************/

#if defined( DADO_OWN )
#define DADO_EXT
#else
#define DADO_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: DAD Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno da funçao do dado
*
***********************************************************************/

   typedef enum {

	   DAD_CondRetOK
	   /* Concluiu corretamente */

   } DAD_tpCondRet;


/***********************************************************************
*
*  $FC Função: DAD  &Jogar dados
*
*  $ED Descrição da função
*     retorna dois valores aleatorios por referencia.
*
*  $EP Parâmetros
*     dado1 - dado para armazenar valor 1
*	  dado2 - dado para armazenar valor 2
*
*  $FV Valor retornado
*     DAD_CondRetOK - Se executou corretamente
*
***********************************************************************/

   DAD_tpCondRet DAD_JogarDados(int *dado1, int *dado2);

#undef DADO_EXT

/********** Fim do módulo de definição: DAD dado **********/

#else
#endif