// Withdrawal.cpp
// Defini��es de fun��o membro da classe Withdrawal.
#include "Withdrawal.h" // Defini��o da classe Withdrawal
#include "Screen.h" // Defini��o da classe Screen
#include "BankDatabase.h" // Defini��o da classe BankDatabase
#include "Keypad.h" // Defini��o da classe Keypad
#include "CashDispenser.h" // Defini��o da classe CashDispenser

// constante global que corresponde � op��o de menu para cancelar
const static int CANCELED = 6;

// construtor Withdrawal inicializa os membros de dados da classe
Withdrawal::Withdrawal( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase, Keypad &atmKeypad, 
   CashDispenser &atmCashDispenser )
   : Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
     keypad( atmKeypad ), cashDispenser( atmCashDispenser )
{
   // corpo vazio
} // fim do construtor de Withdrawal

// realiza transa��o; sobrescreve fun��o virtual da Transaction
void Withdrawal::execute()
{
   bool cashDispensed = false; // c�dulas ainda n�o foram entregues
   bool transactionCanceled = false; // transa��o ainda n�o foi cancelada 

   // obt�m as refer�ncias ao banco de dados e tela do banco
   BankDatabase &bankDatabase = getBankDatabase(); 
   Screen &screen = getScreen();

   // faz um loop at� as c�dulas serem entregues ou o usu�rio cancelar
   do
   {
      // obt�m a quantia de retirada escolhida pelo usu�rio
      int selection = displayMenuOfAmounts();
      
      // verifica se o usu�rio escolheu uma quantia de retirada ou cancelou
      if ( selection != CANCELED )
      {
         amount = selection; // configura quantia como o valor em d�lar selecionado

         // obt�m o saldo dispon�vel na conta envolvida
         double availableBalance = 
            bankDatabase.getAvailableBalance( getAccountNumber() );
   
         //  verifica se o usu�rio tem dinheiro suficiente na conta
         if ( amount <= availableBalance )
         {   
            // verifica se o dispensador de c�dulas tem c�dulas suficientes
            if ( cashDispenser.isSufficientCashAvailable( amount ) )
            {
               // atualiza a conta envolvida para refletir a retirada
               bankDatabase.debit( getAccountNumber(), amount );
               
               cashDispenser.dispenseCash( amount ); // entrega c�dulas
               cashDispensed = true; // c�dulas foram entregues

               // instrui o usu�rio a pegar as c�dulas
               screen.displayMessageLine( 
                  "\nPlease take your cash from the cash dispenser." );
            } // fim do if
            else // o dispensador de c�dulas n�o tem c�dulas suficientes
               screen.displayMessageLine( 
                  "\nInsufficient cash available in the ATM."
                  "\n\nPlease choose a smaller amount." );
         } // fim do if
         else // n�o h� dinheiro suficiente dispon�vel na conta do usu�rio
         {
            screen.displayMessageLine( 
               "\nInsufficient funds in your account."
               "\n\nPlease choose a smaller amount." );
         } // fim de else
      } // fim do if
      else // usu�rio escolheu a op��o de menu Cancel 
      {
         screen.displayMessageLine( "\nCanceling transaction..." );
         transactionCanceled = true; // usu�rio cancelou a transa��o
      } // fim de else
   } while ( !cashDispensed && !transactionCanceled ); // fim da instru��o do...while
} // fim da fun��o execute

// exibe um menu de quantias de saques e a op��o para cancelar;
// retorna a quantia escolhida ou 0 se o usu�rio escolher cancelar
int Withdrawal::displayMenuOfAmounts() const
{
   int userChoice = 0; // vari�vel local para armazenar o valor de retorno

   Screen &screen = getScreen(); // obt�m refer�ncia de tela
   
   // array de quantias que correspondem aos n�meros no menu
   int amounts[] = { 0, 20, 40, 60, 100, 200 };

   // faz um loop enquanto nenhuma escolha v�lida for feita
   while ( userChoice == 0 )
   {
      // exibe o menu
      screen.displayMessageLine( "\nWithdrawal options:" );
      screen.displayMessageLine( "1 - $20" );
      screen.displayMessageLine( "2 - $40" );
      screen.displayMessageLine( "3 - $60" );
      screen.displayMessageLine( "4 - $100" );
      screen.displayMessageLine( "5 - $200" );
      screen.displayMessageLine( "6 - Cancel transaction" );
      screen.displayMessage( "\nChoose a withdrawal option (1-6): " );

      int input = keypad.getInput(); // obt�m a entrada do usu�rio pelo teclado

      // determina como prosseguir com base no valor de entrada
      switch ( input )
      {
         case 1: // se o usu�rio escolheu uma quantia de retirada
         case 2: // (isto �, escolheu a op��o 1, 2, 3, 4 ou 5), retorna a
         case 3: // quantia correspondente do array de quantias
         case 4:
         case 5:
            userChoice = amounts[ input ]; // salva a escolha do usu�rio
            break;       
         case CANCELED: // o usu�rio escolheu cancelar
            userChoice = CANCELED; // salva a escolha do usu�rio
            break;
         default: // o usu�rio n�o inseriu um valor ente 1 e 6
            screen.displayMessageLine( 
               "\nIvalid selection. Try again." );
      } // fim do switch
   } // fim do while

   return userChoice; // retorna a quantia de retirada ou CANCELADA
} // fim da fun��o displayMenuOfAmounts


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
