#ifndef JOGO_H_
#define JOGO_H_

#include "Bola.h"
#include "Tabuleiro.h"
#include "pino.h"
#include "lista.h"

template <typename T>
class Jogo : public Tabuleiro <T>{	//heranca
private:

public:
	//CONSTRUTOR
	Jogo(const int &qtd, const T &n);
	//METODOS JOGATINA
	virtual void jogar_com_cores_repetidas(int intervalo, int tam, Lista <string> &l1);
	virtual void jogar_sem_cores_repetidas(int intervalo, int tam, Lista <string> &l1);
	int compara(string resposta[], int tam, int linha, Tabuleiro <T> &respostaPinos);
	//SOBRECARGA DE OPERADOR
        template <typename T1>
	friend std::ostream &operator << (std::ostream &output, const Jogo <T1> &jogo);
	//DESTRUTOR
	~Jogo();
};

//FUNCOES AUXILIARES
bool Existe(int valores[], int tam, int valor);

#endif /* JOGO_H_ */
