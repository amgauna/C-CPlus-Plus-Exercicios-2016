// Keypad.cpp
// Defini��o da fun��o membro da classe Keypad (o teclado do ATM).
#include <iostream>
using std::cin;

#include "Keypad.h" // Defini��o da classe Keypad

// retorna um valor de inteiro inserido pelo usu�rio
int Keypad::getInput() const
{
   int input; // vari�vel para armazenar a entrada
   cin >> input; // supomos que o usu�rio insira um inteiro
   return input; // retorna o valor inserido pelo usu�rio
} // fim da fun��o getInput


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
