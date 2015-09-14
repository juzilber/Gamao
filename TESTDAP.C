/***************************************************************************
*  $MCI Modulo de implementação: TDAP Teste dadopontos gamao
*
*  Arquivo gerado:              TESTDAP.C
*  Letras identificadoras:      TDAP
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			jdz - Juliana Dana Zilberberg
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"DADOPONTOS.H"


#define     CRIAR_DADOPONTOS_CMD      "=criardadopontos"
#define     DESTRUIR_DADOPONTOS_CMD   "=destruirdadopontos"
#define     DOBRAR_PONTUACAO_CMD	  "=dobrarpontuacao"
#define     OBTER_PONTUACAO_CMD		  "=obterpontuacao"


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TDAP &Testar dadoPontos
*
*  $ED Descrição da função
*     a funçao tem objetivo de testar o modulo DADOPONTOS.C
*
*     Comandos disponíveis:
*
*     =criardadopontos				condret
*     =destruirdadopontos			condret
*	  =dobrarpontuacao				int		condret
*	  =obterpontuacao				int		condret
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	int numLidos = -1,
		CondRetEsp = -1,
		jogador,
		pontuacao,
		pontuacaoEsp;

	TST_tpCondRet Ret;

	DAP_tpCondRet CondRet;

	/* testar criar um dadopontos */

	if (strcmp(ComandoTeste, CRIAR_DADOPONTOS_CMD) == 0)
	{
		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1) {
			return TST_CondRetParm;
		} /* if */

		CondRet =DAP_CriarDadoPontos();

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao criar dadopontos.");

	} /* Fim ativa: Testar criar um dadopontos */

	/* Testar destruir um dadopontos */

	else if (strcmp(ComandoTeste, DESTRUIR_DADOPONTOS_CMD) == 0)
	{

		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1) {
			return TST_CondRetParm;
		} /* if */

		CondRet =DAP_DestruirDadoPontos();

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao destruir dadopontos.");

	} /* Fim ativa: Testar destruir dadopontos  */

	/* Testar dobrar pontuacao */

	else if (strcmp(ComandoTeste, DOBRAR_PONTUACAO_CMD) == 0)
	{

		numLidos = LER_LerParametros("ii",
			&jogador, &CondRetEsp);

		if (numLidos != 2) {
			return TST_CondRetParm;
		} /* if */

		CondRet = DAP_DobrarPontuacao(jogador);

		return TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao dobrar pontuacao.");

	} /* Fim ativa: Testar dobrar pontuacao  */

	/* Testar obter pontuacao */

	else if (strcmp(ComandoTeste, OBTER_PONTUACAO_CMD) == 0)
	{

		numLidos = LER_LerParametros("ii",
			&pontuacaoEsp, &CondRetEsp);

		if (numLidos != 2) {
			return TST_CondRetParm;
		} /* if */

		CondRet = DAP_ObterPontuacao(&pontuacao);

		Ret = TST_CompararInt(CondRetEsp, CondRet,
			"Condicao de retorno errada ao obter pontuacao.");

		if (Ret != TST_CondRetOK)
			return Ret;

		if (CondRet == DAP_CondRetDadoPontosNaoExiste)
			return TST_CondRetOK;

		return TST_CompararInt(pontuacaoEsp, pontuacao, "pontuacao errada");

	} /* Fim ativa: Testar obter pontuacao  */

	return TST_CondRetNaoConhec;

} /* Fim função: TDAP &Testar dadopontos */
