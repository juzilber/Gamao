# Gamao
/***************************************************************************
*  $MCI Modulo de implementação: TPCA Teste pecas capturadas
*
*  Arquivo gerado:              TES_PECCAP.c
*  Letras identificadoras:      TPCA
*
*  Nome da base de software:    Jogo de Gamao
*
*  Projeto: INF 1301 Jogo de Gamao
*  Autores: lsm - Lucas Silva de Medeiros
*			ea  - Eduardo Abramoff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       02  	ea    19/10/2015  adaptações na insere e retira
*	01	   ea	  10/10		Início do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include	"GENERICO.H"
#include	"LERPARM.H"

#include	"PECCAP.H"


#define     CRIAR_PECASCAPTURADAS_CMD       "=criarpecascapturadas"
#define     DESTRUIR_PECASCAPTURADAS_CMD    "=destruirpecascapturadas"
#define     INSERIR_PECACAPTURADA_CMD		  "=inserirpecacapturada"
#define     RETIRAR_PECACAPTURADA_CMD		  "=retirarpecacapturada"


static int pecas[2];

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPCA &Testar pecas capturadas
*
*  $ED Descrição da função
*     a funçao tem objetivo de testar o modulo PECCAP.C
*
*     Comandos disponíveis:
*
*     =criarpecascapturadas				condret  
*     =destruirpecascapturadas			condret     
*	  =inserirpecacapturada				int		int		condret
*	  =retirarpecacapturada				int		int		condret
*
***********************************************************************/
static PCA_tppPecasCapturadas pPecasCapturadas = NULL;
      

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

	  int indice,
		  numLidos = -1,
		  CondRetEsp = -1,
		  cor,
		  coresp,
		  jogador;
		  
	  PCA_tpCondRet CondRet ;
	  TST_tpCondRet Ret;
	  int *pPeca;
	  pecas[0]=0;
	  pecas[1]=1;

	  
	  /* testar criar estrutura de pecas capturadas */

         if ( strcmp( ComandoTeste , CRIAR_PECASCAPTURADAS_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if  ( numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PCA_CriarPecasCapturadas(&pPecasCapturadas);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao criar estrutura de pecas capturadas.");

         } /* Fim ativa: Testar criar estrutura de pecas capturadas */

      /* Testar destruir estrutura de pecas capturadas */

         else if ( strcmp( ComandoTeste , DESTRUIR_PECASCAPTURADAS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if (  numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = PCA_DestruirPecasCapturadas(&pPecasCapturadas);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao destruir estrutura de pecas capturadas.");

         } /* Fim ativa: Testar destruir estrutura de pecas capturadas  */

	  /* Testar inserir peca na estrutura de pecas capturadas*/

		 else if (strcmp(ComandoTeste, INSERIR_PECACAPTURADA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				  &jogador, &cor, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 CondRet = PCA_InserirPecaCapturada (pPecasCapturadas,jogador, &pecas[cor]);


			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao inserir peca na estrutura de pecas capturadas.");

		 } /* Fim ativa: Testar inserir peca na estrutura de pecas capturadas */

	  /* Testar retirar peca da estrutura de pecas capturadas */

		 else if (strcmp(ComandoTeste, RETIRAR_PECACAPTURADA_CMD) == 0)
		 {

			 numLidos = LER_LerParametros("iii",
				 &jogador, &coresp, &CondRetEsp);

			 if (numLidos != 3) {
				 return TST_CondRetParm;
			 } /* if */

			 pPeca = NULL;
			 CondRet = PCA_RetirarPecaCapturada(pPecasCapturadas,jogador, &pPeca);

			 if( CondRet == PCA_CondRetOK)
			 {
				 cor = *pPeca;
				 if (cor != coresp)
					 CondRet = PCA_PecaErrada;
			 }

			 return TST_CompararInt(CondRetEsp, CondRet,
				 "Condicao de retorno errada ao retirar peca da estrutura de pecas capturadas.");

		 } /* Fim ativa: Testar retirar peca da estrutura de pecas capturadas */

	 

      return TST_CondRetNaoConhec ;

   } /* Fim função: TPCA &Testar pecas capturadas */


/*****  Código das funções encapsuladas no módulo  *****/


/********** Fim do módulo de implementação: TPCA Teste pecas capturadas **********/
