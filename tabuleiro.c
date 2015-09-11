#include "tabuleiro.h"

static tpTabuleiro Tabuleiro;

void   ExcluirValorDaListaDeCasas ( void * pListaPecas )
// esta funcao � chamada na hora da liberacao de cada n� da lista de casas
// libera a memoria referente ao dado associado ao n� da lista de casas (lista de pe�as)
{
	// se existe lista de pe�as vinculada � casa
	if ( pListaPecas )
		LIS_DestruirLista( (LIS_tppLista)pListaPecas ) ;
}

void   ExcluirValorDaListaDePecas ( void * pPeca )
// esta funcao � chamada na hora da liberacao de cada n� da lista de pe�as
// libera a memoria referente ao dado associado ao n� da lista de pe�as
{
	// se existe pe�a vinculada ao elemento da lista de pe�as
	if ( pPeca )
		PEC_DestruirPeca( (tpPeca*) pPeca );
}

TAB_ConRet TAB_DestruirTabuleiro(void) {

	LIS_tpCondRet ret;

	/*	int i;

	LIS_tppLista pListaPecas;

	IrInicioLista( Tabuleiro->ListaCasas );

	for(i=0;i<24;i++){
		ret = LIS_AvancarElementoCorrente( pListaPecas , i );
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
		pListaPecas = LIS_ObterValor( Tabuleiro->ListaCasas );
		LIS_DestruirLista( pListaPecas ) ;
	}

	IrInicioLista( Tabuleiro->ListaCasas );
	*/

	ret = LIS_DestruirLista( Tabuleiro->ListaCasas );
	if(ret != LIS_CondRetOK)
		return TAB_CondRetTabuleiroNaoExiste;

	return TAB_CondRetOK;
}

TAB_tpCondRet TAB_CriarTabuleiro(void) {

	int i;
	LIS_tppLista pListaPecas; 
	LIS_tpCondRet ret;

	Tabuleiro->ListaCasas=LIS_CriarLista( ExcluirValorDaListaDeCasas );
	if (Tabuleiro->ListaCasas==NULL)
		return TAB_CondRetFaltouMemoria;

	// para cada casa
	for(i=24;i>0;i--){

		// criar lista para conter as pe�as de uma casa
		pListaPecas=LIS_CriarLista( ExcluirValorDaListaDePecas );
		if (pListaPecas==NULL)
			return TAB_CondRetFaltouMemoria;

		ret = LIS_InserirElementoAntes( Tabuleiro->ListaCasas , pListaPecas);
		if (ret == LIS_CondRetFaltouMemoria)
			return TAB_CondRetFaltouMemoria;
	}
	
	return TAB_CondRetOK;
}

TAB_tpCondRet TAB_InserirPecaEmCasa( int casa, tpPeca* pPeca ) {

	LIS_tpCondRet ret;
	LIS_tppLista pListaPecas;

	// posicionar na casa 1
	IrInicioLista( Tabuleiro->ListaCasas );

	// avan�ar para a casa determinada
	if ( casa > 1) {
		ret = LIS_AvancarElementoCorrente( Tabuleiro->ListaCasas , casa - 1 ) ;
		if(ret != LIS_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}

	// obter lista de pe�as desta casa
	pListaPecas = LIS_ObterValor( Tabuleiro->ListaCasas );

	// colocar pe�a do time nesta casa
	ret = LIS_InserirElementoAntes( pListaPecas , pPeca);
	if (ret == LIS_CondRetFaltouMemoria)
		return TAB_CondRetFaltouMemoria;

	return TAB_CondRetOK;
}

TAB_tpCondRet TAB_DistribuirPecas(tpPeca** timeA, tpPeca** timeB) {

	int i=0, iPecaA=0, iPecaB=0;
	TAB_tpCondRet ret;

	
	//Colocando 2 pe�as na primeira casa
	for(i=0;i<2;i++){
		ret = TAB_InserirPecaEmCasa( 1 , timeA[ iPecaB++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}

	// posicionar na casa 6
	for(i=0;i<5;i++){
		ret = TAB_InserirPecaEmCasa( 6 , timeB[ iPecaB++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}

	// posicionar na casa 8
	for(i=0;i<3;i++){
		ret = TAB_InserirPecaEmCasa( 8 , timeB[ iPecaB++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}
	
	// posicionar na casa 12

	for(i=0;i<5;i++){
		ret = TAB_InserirPecaEmCasa( 12 , timeA[ iPecaA++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}
	
	// posicionar na casa 13
	for(i=0;i<5;i++){
		ret = TAB_InserirPecaEmCasa( 13 , timeB[ iPecaB++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}
	
	// posicionar na casa 17
	for(i=0;i<3;i++){
		ret = TAB_InserirPecaEmCasa( 17 , timeA[ iPecaA++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}
	
	// posicionar na casa 19
	for(i=0;i<5;i++){
		ret = TAB_InserirPecaEmCasa( 19 , timeA[ iPecaA++ ] )
		if(ret != TAB_CondRetOK)
			return CondRetTabuleiroNaoExiste;
	}
	
	//posicionar na casa 24
	for(i=0;i<2;i++){
		ret = TAB_InserirPecaEmCasa( 24 , timeB[ iPecaB++ ] )
		if(ret != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;
	}

	return TAB_CondRetOK;
}

TAB_tpCondRet TAB_RetirarPeca( int Casa ) {

	LIS_tpCondRet ret;
	LIS_tppLista pListaPecas;

	IrInicioLista( Tabuleiro->ListaCasas );
	ret = LIS_AvancarElementoCorrente( Tabuleiro->ListaCasas , Casa );
	if(ret != TAB_CondRetOK)
		return TAB_CondRetTabuleiroNaoExiste;

	pListaPecas = LIS_ObterValor( Tabuleiro->ListaCasas );

	IrFinalLista( pListaPecas );
	ret = LIS_ExcluirElemento( pListaPecas );
	if(ret != LIS_CondRetOK)
		return TAB_CondRetListaNaoExiste;

	return TAB_CondRetOK;
}

TAB_tpCondRet TAB_MovimentarPeca (int CasaOrigem, int passos){

	LIS_tpCondRet ret;
	LIS_tppLista pListaPecas;
	tpPeca* PecaAndar;
	TAB_tpCondRet ret2;

	IrInicioLista( Tabuleiro->ListaCasas );
	ret = LIS_AvancarElementoCorrente( Tabuleiro->ListaCasas , CasaOrigem );
	if(ret != TAB_CondRetOK)
		return TAB_CondRetTabuleiroNaoExiste;

	pListaPecas = LIS_ObterValor( Tabuleiro->ListaCasas );

	IrFinalLista( pListaPecas );
	PecaAndar = LIS_ObterValor( pListaPecas ) ;

	ret = LIS_ExcluirElemento( pListaPecas );
	if(ret != LIS_CondRetOK)
		return TAB_CondRetListaNaoExiste;

	ret2 = TAB_InserirPecaEmCasa ( CasaOrigem + passos, PecaAndar);
	if(ret2 != TAB_CondRetOK)
			return TAB_CondRetTabuleiroNaoExiste;

return TAB_CondRetOK;
}