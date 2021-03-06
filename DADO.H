#if ! defined( DADO_ )
#define DADO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: DAD  Dado
*
*  Arquivo gerado:              DADO.h
*  Letras identificadoras:      DAD
*
*  Nome da base de software:    Jogo  de Gamao
*
*  Projeto: INF 1301 Jogo Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   1.00    jdz  22/09/2015  inicio de implementacao
*
*  $ED Descri��o do m�dulo
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
*  $TC Tipo de dados: DAD Condi��es de retorno
*
*
*  $ED Descri��o do tipo
*     Condi��es de retorno da fun�ao do dado
*
***********************************************************************/

   typedef enum {

	   DAD_CondRetOK
	   /* Concluiu corretamente */

   } DAD_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: DAD  &Jogar dados
*
*  $ED Descri��o da fun��o
*     retorna dois valores aleatorios por referencia.
*
*  $EP Par�metros
*     dado1 - dado para armazenar valor 1
*	  dado2 - dado para armazenar valor 2
*
*  $FV Valor retornado
*     DAD_CondRetOK - Se executou corretamente
*
***********************************************************************/

   DAD_tpCondRet DAD_JogarDados(int *dado1, int *dado2);

#undef DADO_EXT

/********** Fim do m�dulo de defini��o: DAD dado **********/

#else
#endif