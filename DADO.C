/***************************************************************************
*  $MCI M�dulo de implementa��o: DAD  Dado
*
*  Arquivo gerado:              DADO.C
*  Letras identificadoras:      DAD
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 jogo de Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   1.00    jdz  22/09/2015  inicio de implementacao
*
***************************************************************************/
#define DADO_OWN
#include "DADO.H"
#undef DADO_OWN

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/***************************************************************************
*
*  Fun��o: DAD  &Jogar dados
*  ****/

	DAD_tpCondRet DAD_JogarDados(int *dado1, int *dado2){
	
		srand((unsigned)time(NULL));

		*dado1 = 1 + (rand((unsigned)time(NULL)) % 6);
		*dado2 = 1 + (rand((unsigned)time(NULL)) % 6);
		
		return DAD_CondRetOK;

	}

	/********** Fim do m�dulo de implementa��o: DAD  Dado **********/