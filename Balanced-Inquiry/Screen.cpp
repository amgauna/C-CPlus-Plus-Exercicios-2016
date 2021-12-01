// Screen.cpp
// Defini��es de fun��o membro para a classe Screen.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Screen.h" // Defini��o da classe Screen

// gera sa�da de uma mensagem sem uma nova linha
void Screen::displayMessage( string message ) const
{
   cout << message; 
} // fim da fun��o displayMessage

// gera sa�da de uma mensagem com uma nova linha
void Screen::displayMessageLine( string message ) const
{
   cout << message << endl;   
} // fim da fun��o displayMessageLine

// gera sa�da de um valor em d�lar
void Screen::displayDollarAmount( double amount ) const
{
   cout << fixed << setprecision( 2 ) << "$" << amount;
} // fim da fun��o displayDollarAmount


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
