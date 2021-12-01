// CashDispenser.h
// Defini��o da classe CashDispenser. Representa o ATM para o dispensador de c�dulas.
#ifndef CASH_DISPENSER_H
#define CASH_DISPENSER_H

class CashDispenser
{
public:
   CashDispenser(); // construtor inicializa contagem de conta para 500

   // simula a entrega da quantia especificada de c�dulas
   void dispenseCash( int ); 

   // indica se o dispensador de c�dulas pode entregar a quantia desejada
   bool isSufficientCashAvailable( int ) const;
private:
   const static int INITIAL_COUNT = 500;
   int count; // n�mero de c�dulas de US$ 20 remanescente
}; // fim da classe CashDispenser

#endif // CASH_DISPENSER_H


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
