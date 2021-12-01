// Screen.h
// Defini��o da classe Screen. Representa a tela do ATM.
#ifndef SCREEN_H
#define SCREEN_H

#include <string>
using std::string;

class Screen
{
public:
   void displayMessage( string ) const; // gera sa�da de uma mensagem
   void displayMessageLine( string ) const; // gera sa�da da mensagem com nova linha
   void displayDollarAmount( double ) const; // gera sa�da de um valor em d�lar
}; // fim da classe Screen

#endif // SCREEN_H


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
