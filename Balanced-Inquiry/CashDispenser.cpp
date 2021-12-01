// CashDispenser.cpp
// Defini��es de fun��o membro da classe CashDispenser.
#include "CashDispenser.h" // Defini��o da classe CashDispenser

// o construtor padr�o CashDispenser inicializa a contagem como padr�o
CashDispenser::CashDispenser()
{
   count = INITIAL_COUNT; // configura atributo count como o padr�o
} // fim do construtor padr�o CashDispenser 

// simula a libera��o da quantia em dinheiro especificada; sup�e que h� dinheiro suficiente
// dispon�vel (chamada anterior para isSufficientCashAvailable retornou true)
void CashDispenser::dispenseCash( int amount )
{
   int billsRequired = amount / 20; // n�mero de c�dulas de US$ 20 requerido
   count -= billsRequired; // atualiza a contagem das c�dulas
} // fim da fun��o dispenseCash

// indica se o dispensador de c�dulas pode entregar a quantia desejada
bool CashDispenser::isSufficientCashAvailable( int amount ) const
{
   int billsRequired = amount / 20; // n�mero de c�dulas de US$ 20 requerido

   if ( count >= billsRequired )
      return true; // c�dulas suficientes est�o dispon�veis
   else 
      return false; // n�o h� c�dulas suficientes dispon�veis
} // fim da fun��o isSufficientCashAvailable


/**************************************************************************
 * (C) Copyright 1992-2005 Deitel & Associates, Inc. e                    *
 * Pearson Education, Inc. Todos os direitos reservados                   *
 *                                                                        *
 * NOTA DE ISEN��O DE RESPONSABILIDADES: Os autores e o editor deste      *
 * livro empregaram seus melhores esfor�os na prepara��o do livro. Esses  *
 * esfor�os incluem o desenvolvimento, pesquisa e teste das teorias e     *
 * programas para determinar sua efic�cia. Os autores e o editor n�o      *
 * oferecem nenhum tipo de garantia, expl�cita ou implicitamente, com     *
 * refer�ncia a esses programas ou � documenta��o contida nesses livros.  *
 * Os autores e o editor n�o ser�o respons�veis por quaisquer danos,      *
 * acidentais ou conseq�entes, relacionados com ou provenientes do        *
 * fornecimento, desempenho ou utiliza��o desses programas.               *
 **************************************************************************/
