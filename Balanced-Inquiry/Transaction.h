// Transaction.h
// Defini��o da classe b�sica abstrata Transaction.
#ifndef TRANSACTION_H
#define TRANSACTION_H

class Screen; // declara��o antecipada da classe Screen
class BankDatabase; // declara��o antecipada da classe BankDatabase

class Transaction
{
public:
   // o construtor inicializa recursos comuns de todas as Transactions
   Transaction( int, Screen &, BankDatabase & );

   virtual ~Transaction() { } // destrutor virtual com corpo vazio

   int getAccountNumber() const; // retorna o n�mero da conta
   Screen &getScreen() const; // retorna a refer�ncia � tela
   BankDatabase &getBankDatabase() const; // retorna refer�ncia ao banco de dados

   // fun��o virtual pura para realizar a transa��o
   virtual void execute() = 0; // sobrescrita em classes derivadas
private:
   int accountNumber; // indica conta envolvida
   Screen &screen; // refer�ncia � tela ATM
   BankDatabase &bankDatabase; // refer�ncia ao banco de dados de informa��es de conta
}; // fim da classe Transaction

#endif // TRANSACTION_H


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
