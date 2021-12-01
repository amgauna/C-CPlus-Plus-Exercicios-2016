// ATM.cpp
// Defini��es de fun��o membro para a classe ATM.
#include "ATM.h" // Defini��o da classe ATM
#include "Transaction.h" // Defini��o da classe Transaction
#include "BalanceInquiry.h" // Defini��o da classe BalanceInquiry
#include "Withdrawal.h" // Defini��o da classe Withdrawal
#include "Deposit.h" // Defini��o da classe Deposit

// constantes de enumera��o representam as principais op��es de menu
enum MenuOption { BALANCE_INQUIRY = 1, WITHDRAWAL, DEPOSIT, EXIT };

// o construtor padr�o ATM inicializa os membros de dados
ATM::ATM() 
   : userAuthenticated ( false ), // usu�rio n�o foi autenticado para iniciar
     currentAccountNumber( 0 ) // nenhum n�mero atual de conta para iniciar
{
   // corpo vazio
} // fim do construtor padr�o ATM 

// inicia o ATM
void ATM::run()
{
   // d� boas-vindas e autentica o usu�rio; realiza transa��es
   while ( true )
   {
      // faz um loop enquanto o usu�rio ainda n�o est� autenticado
      while ( !userAuthenticated ) 
      {
         screen.displayMessageLine( "\nWelcome!" );       
         authenticateUser(); // autentica o usu�rio
      } // fim do while
      
      performTransactions(); // o usu�rio agora est� autenticado
      userAuthenticated = false; // reinicializa antes da pr�xima sess�o do ATM
      currentAccountNumber = 0; // reinicializa antes da pr�xima sess�o do ATM
      screen.displayMessageLine( "\nThank you! Goodbye!" );
   } // fim do while
} // fim da fun��o run

// tenta autenticar o usu�rio contra o banco de dados
void ATM::authenticateUser() 
{
   screen.displayMessage( "\nPlease enter your account number: " );
   int accountNumber = keypad.getInput(); // insere o n�mero de conta
   screen.displayMessage( "\nEnter your PIN: " ); // solicita o PIN
   int pin = keypad.getInput(); // insere o PIN
   
   // configura userAuthenticated como um valor bool retornado pelo banco de dados
   userAuthenticated = 
      bankDatabase.authenticateUser( accountNumber, pin );
   
   // verifica se a autentica��o foi bem-sucedida
   if ( userAuthenticated )
   {
      currentAccountNumber = accountNumber; // salva a conta do usu�rio #
   } // fim do if
   else
      screen.displayMessageLine( 
         "Invalid account number or PIN. Please try again." );
} // fim da fun��o authenticateUser

// exibe o menu principal e realiza transa��es
void ATM::performTransactions() 
{
   // ponteiro local para armazenar a transa��o atualmente processada
   Transaction *currentTransactionPtr;
   
   bool userExited = false; // usu�rio optou por n�o sair

   // faz um loop enquanto o usu�rio n�o escolher a op��o para sair do sistema
   while ( !userExited )
   {     
      // mostra o menu principal e obt�m a sele��o de usu�rio
      int mainMenuSelection = displayMainMenu();

      // decide como prosseguir com base na sele��o de menu feita pelo usu�rio
      switch ( mainMenuSelection )
      {
         // o usu�rio optou por realizar um entre tr�s tipos de transa��es
         case BALANCE_INQUIRY: 
         case WITHDRAWAL: 
         case DEPOSIT:
            // inicializa como o novo objeto do tipo escolhido
            currentTransactionPtr = 
               createTransaction( mainMenuSelection );

            currentTransactionPtr->execute(); // executa a transa��o

            // libera o espa�o para a Transaction dinamicamente alocada
            delete currentTransactionPtr;

            break; 
         case EXIT: // usu�rio optou por terminar a sess�o
            screen.displayMessageLine( "\nExiting the system..." );
            userExited = true; // essa sess�o de ATM deve terminar
            break;
         default: // usu�rio n�o inseriu um inteiro de 1 a 4
            screen.displayMessageLine( 
               "\nYou did not enter a valid selection. Try again." );
            break;
      } // fim do switch
   } // fim do while
} // fim da fun��o performTransactions

// exibe o menu principal e retorna uma sele��o de entrada
int ATM::displayMainMenu() const
{
   screen.displayMessageLine( "\nMain menu:" );
   screen.displayMessageLine( "1 - View my balance" );
   screen.displayMessageLine( "2 - Withdraw cash" );
   screen.displayMessageLine( "3 - Deposit funds" );
   screen.displayMessageLine( "4 - Exit\n" );
   screen.displayMessage( "Enter a choice: " );
   return keypad.getInput(); // retorna a sele��o do usu�rio
} // fim da fun��o displayMainMenu
      
// retorna o objeto da classe derivada Transaction especificada
Transaction *ATM::createTransaction( int type )
{
   Transaction *tempPtr; // ponteiro Transaction tempor�rio
   
   // determina que tipo Transaction criar
   switch ( type )
   {
      case BALANCE_INQUIRY: // cria uma nova transa��o BalanceInquiry
         tempPtr = new BalanceInquiry( 
            currentAccountNumber, screen, bankDatabase );
         break;
      case WITHDRAWAL: // cria uma nova transa��o Withdrawal
         tempPtr = new Withdrawal( currentAccountNumber, screen, 
            bankDatabase, keypad, cashDispenser );
         break; 
      case DEPOSIT: // cria uma nova transa��o Deposit
         tempPtr = new Deposit( currentAccountNumber, screen, 
            bankDatabase, keypad, depositSlot );
         break;
   } // fim do switch

   return tempPtr; // retorna o objeto rec�m-criado
} // fim da fun��o createTransaction


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
