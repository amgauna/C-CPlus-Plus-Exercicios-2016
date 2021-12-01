// Transaction.cpp
// Defini��es de fun��o membro da classe Transaction.
#include "Transaction.h" // Defini��o da classe Transaction
#include "Screen.h" // Defini��o da classe Screen
#include "BankDatabase.h" // Defini��o da classe BankDatabase

// o construtor inicializa recursos comuns de todas as Transactions
Transaction::Transaction( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase )
   : accountNumber( userAccountNumber ),
     screen( atmScreen ),
     bankDatabase( atmBankDatabase )
{
   // corpo vazio
} // fim do construtor de Transaction

// retorna o n�mero da conta
int Transaction::getAccountNumber() const
{
   return accountNumber; 
} // fim da fun��o getAccountNumber

// retorna a refer�ncia � tela
Screen &Transaction::getScreen() const
{
   return screen;
} // fim da fun��o getScreen

// retorno a refer�ncia ao banco de dados de institui��o financeira
BankDatabase &Transaction::getBankDatabase() const
{
   return bankDatabase;
} // fim da fun��o getBankDatabase


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
