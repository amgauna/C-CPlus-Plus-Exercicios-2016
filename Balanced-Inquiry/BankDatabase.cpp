// BankDatabase.cpp
// Defini��es da fun��o membro da classe BankDatabase.
#include "BankDatabase.h" // Defini��o da classe BankDatabase

// construtor padr�o BankDatabase inicializa contas
BankDatabase::BankDatabase()
{
   // cria dois objetos Account para testar
   Account account1( 12345, 54321, 1000.0, 1200.0 );
   Account account2( 98765, 56789, 200.0, 200.0 );

   // adiciona os objetos Account ao vector accounts
   accounts.push_back( account1 ); // adiciona account1 ao fim de vector
   accounts.push_back( account2 ); // adiciona account2 ao fim de vetcor
} // fim construtor padr�o BankDatabase 

// recupera o objeto Account que cont�m o n�mero de conta especificado
Account * BankDatabase::getAccount( int accountNumber )
{
   // faz um loop pelas contas procurando uma correspond�ncia com o n�mero de conta
   for ( size_t i = 0; i < accounts.size(); i++ )
   {
      // retorna a conta atual se uma correspond�ncia for localizada
      if ( accounts[ i ].getAccountNumber() == accountNumber )
         return &accounts[ i ];
   } // fim do for

   return NULL; // se nenhuma correspond�ncia com uma conta foi encontrada, retorna NULL
} // fim da fun��o getAccount

// determina se o n�mero da conta e o PIN especificados pelo usu�rio correspondem
// �queles de uma conta no banco de dados
bool BankDatabase::authenticateUser( int userAccountNumber, 
   int userPIN )
{
   // tenta recuperar a conta com o n�mero da conta
   Account * const userAccountPtr = getAccount( userAccountNumber );

   // se a conta existir, retorna o resultado da fun��o validatePIN de Account
   if ( userAccountPtr != NULL )
      return userAccountPtr->validatePIN( userPIN );
   else
      return false; // n�mero de conta n�o foi localizado, portanto retorna false
} // fim da fun��o authenticateUser

// retorna o saldo dispon�vel de Account com o n�mero da conta especificado
double BankDatabase::getAvailableBalance( int userAccountNumber )
{
   Account * const userAccountPtr = getAccount( userAccountNumber );
   return userAccountPtr->getAvailableBalance();
} // fim da fun��o getAvailableBalance

// retorna o saldo total de Account com o n�mero da conta especificado
double BankDatabase::getTotalBalance( int userAccountNumber )
{
   Account * const userAccountPtr = getAccount( userAccountNumber );
   return userAccountPtr->getTotalBalance();
} // fim da fun��o getTotalBalance

// credita uma quantia a Account com o n�mero da conta especificado
void BankDatabase::credit( int userAccountNumber, double amount )
{
   Account * const userAccountPtr = getAccount( userAccountNumber );
   userAccountPtr->credit( amount );
} // fim da fun��o credit

// debita uma quantidade da Account com o n�mero da conta especificado
void BankDatabase::debit( int userAccountNumber, double amount )
{
   Account * const userAccountPtr = getAccount( userAccountNumber );
   userAccountPtr->debit( amount );
} // fim da fun��o debit


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
