#ifndef TABULEIRO_H_
#define TABULEIRO_H_

#include <iostream>
#include "Bola.h"

template <typename T>
class Tabuleiro{
private:
	T numero_jogadas;
	int quantidade_bolas;
	Bola <string> *bolas;	//composicao
	Bola <string> **matriz; //mostra as jogadas anteriores
public:
	//CONSTRUTOR
	Tabuleiro(const int &qtd, const T &n);
	//SETTERS
	void setNumeroJogadas(T n);
	void setQtdadeBolas(int qtd);
	//GETTERS
	T getNumeroJogadas() const;
	int getQtdadeBolas() const;
	Bola <string> *getBolas() const;
	Bola <string> **getMatriz() const;
	//OUTROS METODOS
	void preenche(string jogada, int posicao);
	void preenche_matriz(string jogada, int linha, int coluna);
	void printa_Pinos();
	//DESTRUTOR
	virtual ~Tabuleiro();
};

#endif /* TABULEIRO_H_ */
