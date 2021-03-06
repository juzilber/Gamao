/***************************************************************************
*  $MCI Modulo de implementa��o: TPEC Teste pecas gamao
*
*  Arquivo gerado:              TESTPEC.C
*  Letras identificadoras:      TPEC
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			jdz - Juliana Dana Zilberberg
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	   2.00    lsm  16/09/2015  revisao e comentarios
*	   1.00    jdz  15/09/2015  inicio de implementacao
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"PECA.H"


#define     CRIAR_PECA_CMD      "=criarpeca"
#define     DESTRUIR_PECA_CMD   "=destruirpeca"
#define     OBTER_COR_CMD		"=obtercor"

PEC_tpPeca * vtPeca[10];

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TPEC &Testar pecas
*
*  $ED Descri��o da fun��o
*     a fun�ao tem objetivo de testar o modulo PECA.C
*
*     Comandos dispon�veis:
*
*     =criarpeca				int		condret
*     =destruirpeca				int		condret
*	  =obtercor					int		char	condret
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	int numLidos = -1,
		CondRetEsp = -1,
		indice = -1 ;

	char cor[10], corEsp[10];

	TST_tpCondRet Ret;

	PEC_tpCondRet CondRet;

	/* testar criar uma peca */

	if (strcmp(ComandoTeste, CRIAR_PECA_CMD) == 0)
	{
		numLidos = LER_LerParametros("isi",
			&indice, cor, &CondRetEsp);

		if (numLidos != 3) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PEC_CriarPeca(cor, &vtPeca[indice]);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao criar peca.");

	} /* Fim ativa: Testar criar uma peca */

	/* Testar destruir peca */

	else if (strcmp(ComandoTeste, DESTRUIR_PECA_CMD) == 0)
	{

		numLidos = LER_LerParametros("ii",
			&indice, &CondRetEsp);

		if (numLidos != 2) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PEC_DestruirPeca(&vtPeca[indice]);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao destruir peca.");

	} /* Fim ativa: Testar destruir peca  */

	/* Testar obter cor */

	else if (strcmp(ComandoTeste, OBTER_COR_CMD) == 0)
	{

		numLidos = LER_LerParametros("isi",
			&indice, corEsp, &CondRetEsp);

		if (numLidos != 3) {
			return TST_CondRetParm;
		} /* if */

		CondRet = PEC_ObterCor(vtPeca[indice], cor);

		Ret = TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao obter cor.");

		if (Ret != TST_CondRetOK)
			return Ret;

		if (CondRet == PEC_CondRetPecaNaoExiste)
			return TST_CondRetOK;

		return TST_CompararString(corEsp, cor, "cor errada");

	} /* Fim ativa: Testar obter cor  */

	return TST_CondRetNaoConhec;

} /* Fim fun��o: TPEC &Testar peca */


/********** Fim do m�dulo de implementa��o: TPEC Teste Peca **********/