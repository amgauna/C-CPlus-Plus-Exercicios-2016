// Withdrawal.h
// Defini��o da classe Withdrawal. Representa uma transa��o de retirada.
#ifndef WITHDRAWAL_H
#define WITHDRAWAL_H

#include "Transaction.h" // Defini��o da classe Transaction
class Keypad; // declara��o antecipada da classe Keypad
class CashDispenser; // declara��o antecipada da classe CashDispenser

class Withdrawal : public Transaction
{
public:
   Withdrawal( int, Screen &, BankDatabase &, Keypad &, CashDispenser & );
   virtual void execute(); // realiza a transa��o
private:
   int amount; // quantia a sacar
   Keypad &keypad; // refer�ncia ao teclado do ATM
   CashDispenser &cashDispenser; // refer�ncia ao dispensador de notas do ATM
   int displayMenuOfAmounts() const; // exibe o menu de retirada
}; // fim da classe Withdrawal

#endif // WITHDRAWAL_H


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
