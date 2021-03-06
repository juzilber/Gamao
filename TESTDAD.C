/***************************************************************************
*  $MCI Modulo de implementa��o: TDAD Teste dado gamao
*
*  Arquivo gerado:              TESTDAD.C
*  Letras identificadoras:      TDAD
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   1.00    jdz  12/09/2015  inicio de implementacao
*
***************************************************************************/

#include    <stdio.h>
#include	<string.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"DADO.H"


#define     JOGAR_DADOS_CMD      "=jogardados"

/***********************************************************************
*
*  $FC Fun��o: TDAD &Testar dado
*
*  $ED Descri��o da fun��o
*     a fun�ao tem objetivo de testar o modulo DADO.C
*
*     Comandos dispon�veis:
*
*     =jogardados		int		int		CondRet
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	int numLidos = -1,
		CondRetEsp = -1,
		dado1,
		dado2;


	/* testar jogar dados */

	if (strcmp(ComandoTeste, JOGAR_DADOS_CMD) == 0)
	{
		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1) {
			return TST_CondRetParm;
		} /* if */

		return TST_CompararInt(CondRetEsp, DAD_JogarDados(&dado1, &dado2),
			"Condicao de retorno errada ao jogar dados.");


	} /* Fim ativa: Testar jogar dado */

	return TST_CondRetNaoConhec;

} /* Fim fun��o: TDAD &Testar dado */


/********** Fim do m�dulo de implementa��o: TDAD Teste Dado **********/