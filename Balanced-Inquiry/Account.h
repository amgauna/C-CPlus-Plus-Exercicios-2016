// Account.h
// Defini��o da classe Account. // Representa uma conta banc�ria
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account
{
public:
   Account( int, int, double, double ); // o construtor configura atributos
   bool validatePIN( int ) const; // o PIN especificado pelo usu�rio � correto?
   double getAvailableBalance() const; // retorna o saldo dispon�vel
   double getTotalBalance() const; // retorna saldo total
   void credit( double ); // adiciona um valor ao  de Account
   void debit( double ); // subtrai uma quantia do saldo de Account
   int getAccountNumber() const; // retorna o n�mero da conta
private:
   int accountNumber; // n�mero da conta
   int pin; // PIN para autentica��o
   double availableBalance; // findos dispon�veis para retirada
   double totalBalance; // fundos dispon�veis + fundos esperando compensa��o
}; // fim da classe Account

#endif // ACCOUNT_H


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
