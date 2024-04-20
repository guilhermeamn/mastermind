#ifndef BOLA_H_
#define BOLA_H_

#include <iostream>

using std::string;

template <typename T>
class Bola{
private:
	T m_cor; //Cor da bola
public:
	//CONSTRUTORES
	Bola();
	Bola(const T &cor);
	//SETTERS
	void setCor(T cor);
	//GETTERS
	T getCor() const;
	//DESTRUTOR
	~Bola();
};

#endif /* BOLA_H_ */
