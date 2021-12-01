// BalanceInquiry.cpp
// Defini��es de fun��o membro da classe BalanceInquiry.
#include "BalanceInquiry.h" // Defini��o da classe BalanceInquiry
#include "Screen.h" // Defini��o da classe Screen
#include "BankDatabase.h" // Defini��o da classe BankDatabase

// o construtor BalanceInquiry inicializa os membros de dados de classe b�sica
BalanceInquiry:: BalanceInquiry( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase )
   : Transaction( userAccountNumber, atmScreen, atmBankDatabase )
{
   // corpo vazio
} // fim do construtor de BalanceInquiry

// realiza transa��o; sobrescreve a fun��o virtual pura da Transaction
void BalanceInquiry::execute()
{
   // obt�m as refer�ncias ao banco de dados e tela do banco
   BankDatabase &bankDatabase = getBankDatabase();
   Screen &screen = getScreen();

   // obt�m o saldo dispon�vel da Account do usu�rio atual
   double availableBalance = 
      bankDatabase.getAvailableBalance( getAccountNumber() );

   // obt�m o saldo total da Account do usu�rio atual
   double totalBalance = 
      bankDatabase.getTotalBalance( getAccountNumber() );
   
   // exibe as informa��es sobre o saldo na tela
   screen.displayMessageLine( "\nBalance Information:" );
   screen.displayMessage( " - Available balance: " ); 
   screen.displayDollarAmount( availableBalance );
   screen.displayMessage( "\n - Total balance:     " );
   screen.displayDollarAmount( totalBalance );
   screen.displayMessageLine( "" );
} // fim da fun��o execute


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
