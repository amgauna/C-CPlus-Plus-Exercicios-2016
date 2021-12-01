// Account.cpp
// Defini��es de fun��o membro para a classe Account.
#include "Account.h" // Defini��o da classe Account

// O construtor Account inicializa os atributos
Account::Account( int theAccountNumber, int thePIN, 
   double theAvailableBalance, double theTotalBalance )
   : accountNumber( theAccountNumber ),
     pin( thePIN ),
     availableBalance( theAvailableBalance ),
     totalBalance( theTotalBalance )
{
   // corpo vazio
} // fim do construtor Account

// determina se um PIN especificado pelo usu�rio corresponde ao PIN em Account
bool Account::validatePIN( int userPIN ) const
{ 
   if ( userPIN == pin )
      return true;
   else
      return false;
} // fim da fun��o validatePIN

// retorna o saldo dispon�vel
double Account::getAvailableBalance() const
{
   return availableBalance;
} // fim da fun��o getAvailableBalance

// retorna o saldo total
double Account::getTotalBalance() const
{
   return totalBalance;
} // fim da fun��o getTotalBalance

// credita uma quantia � conta
void Account::credit( double amount )
{
   totalBalance += amount; // adiciona ao saldo total
} // fim da fun��o credit

// debita uma quantia da conta
void Account::debit( double amount )
{
   availableBalance -= amount; // subtrai do saldo dispon�vel
   totalBalance -= amount; // subtrai do saldo total
} // fim da fun��o debit

// retorna o n�mero da conta
int Account::getAccountNumber() const
{
   return accountNumber;  
} // fim da fun��o getAccountNumber


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
