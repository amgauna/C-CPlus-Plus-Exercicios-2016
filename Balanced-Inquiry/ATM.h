// ATM.h
// Defini��o da classe ATM. Representa um caixa autom�tico.
#ifndef ATM_H
#define ATM_H

#include "Screen.h" // Defini��o da classe Screen
#include "Keypad.h" // Defini��o da classe Keypad
#include "CashDispenser.h" // Defini��o da classe CashDispenser
#include "DepositSlot.h" // Defini��o da classe DepositSlot
#include "BankDatabase.h" // Defini��o da classe BankDatabase
class Transaction; // declara��o forward da classe Transaction

class ATM
{
public:
   ATM(); // construtor inicializa membros de dados
   void run(); // inicia o ATM
private:
   bool userAuthenticated; // se usu�rio foi autenticado
   int currentAccountNumber; // n�mero atual da conta de usu�rio
   Screen screen; // Tela do ATM
   Keypad keypad; // Teclado do ATM
   CashDispenser cashDispenser; // dispensador de c�dulas do ATM
   DepositSlot depositSlot; // Abertura para dep�sito do ATM
   BankDatabase bankDatabase; // banco de dados com as informa��es sobre as contas

   // fun��es utilit�rias private 
   void authenticateUser(); // tenta autenticar o usu�rio
   void performTransactions(); // realiza transa��es
   int displayMainMenu() const; // exibe o menu principal

   // retorna o objeto da classe derivada Transaction especificada
   Transaction *createTransaction( int ); 
}; // fim da classe ATM

#endif // ATM_H


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
