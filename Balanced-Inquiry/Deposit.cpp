// Deposit.cpp
// Defini��es de fun��o membro para a classe Deposit.
#include "Deposit.h" // Defini��o da classe Deposit
#include "Screen.h" // Defini��o da classe Screen
#include "BankDatabase.h" // Defini��o da classe BankDatabase
#include "Keypad.h" // Defini��o da classe Keypad
#include "DepositSlot.h" // Defini��o da classe DepositSlot

const static int CANCELED = 0; // constante representando a op��o de cancelamento

// o construtor Deposit inicializa os membros de dados da classe
Deposit::Deposit( int userAccountNumber, Screen &atmScreen, 
   BankDatabase &atmBankDatabase, Keypad &atmKeypad, 
   DepositSlot &atmDepositSlot )
   : Transaction( userAccountNumber, atmScreen, atmBankDatabase ),
     keypad( atmKeypad ), depositSlot( atmDepositSlot )
{
   // corpo vazio
} // fim do construtor de Deposit

// realiza transa��o; sobrescreve a fun��o virtual pura da Transaction
void Deposit::execute()
{
   BankDatabase &bankDatabase = getBankDatabase(); // obt�m a refer�ncia
   Screen &screen = getScreen(); // obt�m a refer�ncia

   amount = promptForDepositAmount(); // obt�m a quantia de dep�sito do usu�rio

   // verifica se o usu�rio inseriu uma quantia de dep�sito ou cancelou
   if ( amount != CANCELED )
   {
      // solicita o envelope de dep�sito contendo a quantia especificada
      screen.displayMessage( 
         "\nPlease insert a deposit envelope containing " );
      screen.displayDollarAmount( amount );
      screen.displayMessageLine( " in the deposit slot." );

      // recebe o envelope de dep�sito
      bool envelopeReceived = depositSlot.isEnvelopeReceived();

      // verifica se envelope de dep�sito foi recebido
      if ( envelopeReceived )
      {  
         screen.displayMessageLine( "\nYour envelope has been received."
            "\nNOTE: The money just will not be available until we"
            "\nverify the amount of any enclosed cash, and any enclosed "
            "checks clear." );
         
         // credita na conta para refletir o dep�sito
         bankDatabase.credit( getAccountNumber(), amount ); 
      } // fim do if
      else // envelope de dep�sito n�o foi recebido
      {
         screen.displayMessageLine( "\nYou did not insert an "
            "envelope, so the ATM has canceled your transaction." );
      } // fim de else
   } // fim do if
   else // o usu�rio cancelou em vez de inserir uma quantia
   {
      screen.displayMessageLine( "\nCanceling transaction..." );
   } // fim de else
} // fim da fun��o execute

// solicita que o usu�rio insira uma quantia de dep�sito em centavos
double Deposit::promptForDepositAmount() const
{
   Screen &screen = getScreen(); // obt�m a refer�ncia � tela

   // exibe o prompt e recebe a entrada
   screen.displayMessage( "\nPlease enter a deposit amount in " 
      "CENTS (or 0 to cancel): " );
   int input = keypad.getInput(); // recebe a entrada da quantia do dep�sito
   
   // verifica se o usu�rio cancelou ou inseriu uma quantia v�lida
   if ( input == CANCELED ) 
      return CANCELED;
   else
   {
      return static_cast< double >( input ) / 100; // retorna a quantia em d�lares
   } // fim de else
} // fim da fun��o promptForDepositAmount


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
