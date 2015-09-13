/***************************************************************************
*  $MCI Modulo de implementa��o: TTAB Teste tabuleiro gamao
*
*  Arquivo gerado:              TESTTAB.c
*  Letras identificadoras:      TTAB
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"TABULEIRO.H"


#define     CRIAR_TABULEIRO_CMD       "=criartabuleiro"
#define     DESTRUIR_TABULEIRO_CMD    "=destruirtabuleiro"
#define     INSERIR_PECA_CMD		  "=inserirpeca"
#define     RETIRAR_PECA_CMD		  "=retirarpeca"
#define     MOVER_PECA_CMD		      "=moverpeca"
#define     QUANTIDADE_PECA_CMD		  "=quantidadepeca"


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TTAB &Testar tabuleiro
*
*  $ED Descri��o da fun��o
*     a fun�ao tem objetivo de testar o modulo TABULEIRO.C
*
*     Comandos dispon�veis:
*
*     =criartabuleiro				condret  
*     =destruirtabuleiro			condret     
*	  =inserirpeca					int		int		condret
*	  =retirarpeca					int		int		condret
*	  =moverpeca					int	    int		condret
*     =quantidadepeca				int		int		condret
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  int indice,
		  numLidos = -1,
		  CondRetEsp = -1,
		  indicePeca,
		  casa,
		  passos,
		  quantidadePecasEsp,
		  quantidadePecas;

	  void *valorPeca;

	  int * pecaRecebida;
	  int * vtPeca[10];

	  TST_tpCondRet Ret;

	  for (indice = 0; indice < 10; indice++){

		  vtPeca[indice] = (int*)malloc(sizeof(int));
		  if (vtPeca == NULL)
		  {
			  return TST_CondRetMemoria;

		  } /* if */

		  *vtPeca[indice] = indice;
		  

	  } /* for */

      TAB_tpCondRet CondRet ;

      /* testar criar um tabuleiro */

         if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if  ( numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_CriarTabuleiro();

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao criar tabuleiro.");

         } /* Fim ativa: Testar criar um tabuleiro */

      /* Testar destruir um tabuleiro */

         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if (  numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_DestruirTabuleiro();

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao destruir tabuleiro.");

         } /* Fim ativa: Testar destruir tabuleiro  */

	  /* Testar inserir peca */

		 else if (strcmp(ComandoTeste, INSERIR_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				 &indicePeca, &casa, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = TAB_InserirPeca(vtPeca[indicePeca], casa);

			 if (CondRet != TAB_CondRetOK)
				 free(vtPeca[indicePeca]);

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao inserir peca.");

		 } /* Fim ativa: Testar inserir peca  */

	  /* Testar retirar peca */

		 else if (strcmp(ComandoTeste, RETIRAR_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				 &indicePeca, &casa, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = TAB_RetirarPeca(&valorPeca, casa);

			 Ret = TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao retirar peca.");

			 if (Ret != TST_CondRetOK)
				 return Ret;

			 pecaRecebida = (int *)valorPeca;

			 return TST_CompararInt(*vtPeca[indicePeca], *pecaRecebida, "peca recebida errada");

		 } /* Fim ativa: Testar retirar peca  */

	  /* Testar mover peca */

		 else if (strcmp(ComandoTeste, MOVER_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				 &casa, &passos, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = TAB_MoverPeca(casa, passos);

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao mover peca.");

		 } /* Fim ativa: Testar mover peca  */

	  /* Testar quantidade peca */

		 else if (strcmp(ComandoTeste, QUANTIDADE_PECA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				 &casa, &quantidadePecasEsp, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet =TAB_QuantidadePecasCasa(casa, &quantidadePecas);

			 Ret = TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao contar peca.");

			 if (Ret != TST_CondRetOK)
				 return Ret;

			 return TST_CompararInt(quantidadePecasEsp, quantidadePecas, "numero de pecas errado");

		 } /* Fim ativa: Testar quantidade peca  */

      return TST_CondRetNaoConhec ;

   } /* Fim fun��o: TTAB &Testar tabuleiro */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/********** Fim do m�dulo de implementa��o: TLIS Teste lista de s�mbolos **********/
