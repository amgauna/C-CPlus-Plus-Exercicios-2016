// BankDatabase.h
// Defini��o da classe BankDatabase. Representa o banco de dados do banco.
#ifndef BANK_DATABASE_H
#define BANK_DATABASE_H

#include <vector> // classe utiliza vector para armazenar objetos Account
using std::vector;

#include "Account.h" // Defini��o da classe Account

class BankDatabase
{
public:
   BankDatabase(); // o construtor inicializa as contas

   // determina se o n�mero de conta e o PIN correspondem aos de uma Account
   bool authenticateUser( int, int ); // retorna true se a Account for aut�ntica

   double getAvailableBalance( int ); // obt�m um saldo dispon�vel
   double getTotalBalance( int ); // obt�m o saldo total de uma Account
   void credit( int, double ); // adiciona o valor ao saldo de Account
   void debit( int, double ); // subtrai o valor do saldo de Account
private:
   vector< Account > accounts; // vector das Accounts do banco

   // fun��o utilit�ria private
   Account * getAccount( int ); // obt�m ponteiro para o objeto Account
}; // fim da classe BankDatabase

#endif // BANK_DATABASE_H


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
