#ifndef JOGOX1_H_
#define JOGOX1_H_

#include "Jogo.h"

template <typename T>
class JogoX1 : public Jogo <T> {
private:

public:
	//CONSTRUTOR
	JogoX1(const int &qtd, const T &n);
	//METODOS JOGATINA
	virtual void jogar_com_cores_repetidas(int intervalo, int tam, Lista <string> &l1) override;	//polimorfismo
	virtual void jogar_sem_cores_repetidas(int intervalo, int tam, Lista <string> &l1) override;
	//DESTRUTOR
	~JogoX1();
};

//FUNCOES AUXILIARES
void imprimeResposta(void); //LE RESPOSTA DO JOGADOR DE UM ARQUIVO, PARA GARANTIR QUE NAO ESTA MENTINDO

#endif /* JOGOX1_H_ */
