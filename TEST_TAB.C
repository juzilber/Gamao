***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:              TestLIS.c
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     4       avs   01/fev/2006 criar linguagem script simbólica
*     3       avs   08/dez/2004 uniformização dos exemplos
*     2       avs   07/jul/2003 unificação de todos os módulos em um só projeto
*     1       avs   16/abr/2003 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "tabuleiro.h"


static const char CRIAR_TABULEIRO_CMD            [ ] = "=criartabuleiro" ;
static const char DESTRUIR_TABULEIRO_CMD         [ ] = "=destruirtabuleiro";
static const char MOVER_PECA_CMF				 [ ] = "=moverpeca";
static const char RETIRAR_PECA_CMD				 [ ] = "=retirarpeca";
static const char INSERIR_PECA_CMD				 [ ] = "=inserirpeca";
static const char DISTRIBUIR_PECAS_CMD			 [ ] = "=distribuirpecas";


/*#define TRUE  1
#define FALSE 0

#define VAZIO     0
#define NAO_VAZIO 1

#define DIM_VT_LISTA   10
#define DIM_VALOR     100

LIS_tppLista   vtListas[ DIM_VT_LISTA ] ;
*/
/***** Protótipos das funções encapuladas no módulo *****/

   static void DestruirValor( void * pValor ) ;

 //  static int ValidarInxLista( int inxLista , int Modo ) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS &Testar lista
*
*  $ED Descrição da função
*     Podem ser criadas até 10 listas, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de memória
*     =criarlista                   inxLista
*     =destruirlista                inxLista
*     =esvaziarlista                inxLista
*     =inselemantes                 inxLista  string  CondRetEsp
*     =inselemapos                  inxLista  string  CondRetEsp
*     =obtervalorelem               inxLista  string  CondretPonteiro
*     =excluirelem                  inxLista  CondRetEsp
*     =irinicio                     inxLista
*     =irfinal                      inxLista
*     =avancarelem                  inxLista  numElem CondRetEsp
*
***********************************************************************/

   TST_tpCondRet TST_EfetuarComando( char * ComandoTeste )
   {

      int //inxLista  = -1 ,
          numLidos   = -1 ,
          CondRetEsp = -1  ;

      TST_tpCondRet CondRet ;

      char   StringDado[  DIM_VALOR ] ;
      char * pDado ;

      int ValEsp = -1 ;

      int i ;

      int numElem = -1 ;

      StringDado[ 0 ] = 0 ;

      /* Efetuar reset de criar um tabuleiro */

         if ( strcmp( ComandoTeste , CRIAR_TABULEIRO_CMD ) == 0 )
         {
			 numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if  ( numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_CriarTabuleiro() ;

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao criar tabuleiro.");

         } /* fim  */

      /* Testar destruir um tabuleiro */

         else if ( strcmp( ComandoTeste , DESTRUIR_TABULEIRO_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "i" ,
                       &CondRetEsp) ;

            if ( ( numLidos != 1 ) {
               return TST_CondRetParm ;
            } /* if */

			CondRet = TAB_DestruirTabuleiro() ;

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao destruir tabuleiro.");

         } /* fim  */

      /* Testar movimentar peça */

         else if ( strcmp( ComandoTeste , MOVER_PECA_CMF ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,
                      &CasaOrigem, &passos, &CondRetEsp) ;

            if ( ( numLidos != 3 ) {
               return TST_CondRetParm ;
            } /* if */

		   CondRet = TAB_MovimentarPeca(CasaOrigem, passos);

           return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao movimentar peça no tabuleiro.");

         } /* fim */

      /* Testar retirar peça de uma casa */

         else if ( strcmp( ComandoTeste , RETIRAR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "ii" ,
                               &casa, &CondRetEsp ) ;

            if (numLidos != 2 ) {
               return TST_CondRetParm ;
            } /* if */

            CondRet = TAB_RetirarPeca(casa);
            

        return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao retirar peça do tabuleiro.");

         } /* fim */

      /* Testar inserir peça */

         else if ( strcmp( ComandoTeste , INSERIR_PECA_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,
                               &casa, &tpPeca, &CondRetEsp ) ;

            if (numLidos != 3 ) {
               return TST_CondRetParm ;
            } /* if */

            CondRet = TAB_InserirPeca(casa, tpPeca);
            

        return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao inserir peça no tabuleiro.");
         } /* fim */

      /* Testar inserir elemento apos */
		else if ( strcmp( ComandoTeste , DISTRIBUIR_PECAS_CMD ) == 0 )
         {

            numLidos = LER_LerParametros( "iii" ,
                               &tpPeca, &tpPeca, &CondRetEsp ) ;

            if (numLidos != 3 ) {
               return TST_CondRetParm ;
            } /* if */

            CondRet = TAB_DistribuirPecas(tpPeca, tpPeca);
            

        return TST_CompararInt( CondRetEsp , CondRet ,
                     "Condicao de retorno errada ao distribuir peças no tabuleiro.");
         } /* fim */

      return TST_CondRetNaoConhec ;

   } /* Fim função: TLIS &Testar lista */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

   void DestruirValor( void * pValor )
   {

      free( pValor ) ;

   } /* Fim função: TLIS -Destruir valor */


/***********************************************************************
*
*  $FC Função: TLIS -Validar indice de lista
*
***********************************************************************/

   int ValidarInxLista( int inxLista , int Modo )
   {

      if ( ( inxLista <  0 )
        || ( inxLista >= DIM_VT_LISTA ))
      {
         return FALSE ;
      } /* if */
         
      if ( Modo == VAZIO )
      {
         if ( vtListas[ inxLista ] != 0 )
         {
            return FALSE ;
         } /* if */
      } else
      {
         if ( vtListas[ inxLista ] == 0 )
         {
            return FALSE ;
         } /* if */
      } /* if */
         
      return TRUE ;

   } /* Fim função: TLIS -Validar indice de lista */

/********** Fim do módulo de implementação: TLIS Teste lista de símbolos **********/

