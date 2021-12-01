// Deposit.h
// Defini��o da classe Deposit. Representa uma transa��o de dep�sito.
#ifndef DEPOSIT_H
#define DEPOSIT_H

#include "Transaction.h" // Defini��o da classe Transaction
class Keypad; // declara��o antecipada da classe Keypad
class DepositSlot; // declara��o antecipada da classe DepositSlot

class Deposit : public Transaction
{
public:
   Deposit( int, Screen &, BankDatabase &, Keypad &, DepositSlot & );
   virtual void execute(); // realiza a transa��o
private:
   double amount; // quantia a depositar
   Keypad &keypad; // refer�ncia ao teclado do ATM
   DepositSlot &depositSlot; // refer�ncia � abertura de dep�sito do ATM
   double promptForDepositAmount() const; // obt�m a quantia de dep�sito do usu�rio
}; // fim da classe Deposit

#endif // DEPOSIT_H


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
