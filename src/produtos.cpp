#include "produtos.hpp"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iostream>

using namespace std;

Produtos::Produtos(){
	//Construtor
}

Produtos::Produtos(int id, string categoria, string nome, float preco, int quantidade){
	this->id = id;
	this->categoria = categoria;
	this->nome = nome;
	this->preco = preco;
	this->quantidade = quantidade;

}

void Produtos::Criar_Produtos(string categoria, string nome, float preco, int quantidade){
	// Atribuindo ID ao novo produto
	fstream contadorid;
	int id_contador;
	int id_final;
	contadorid.open("./db/etc/contadorid.txt");
	if (contadorid.is_open()){
		while (contadorid >> id_contador){

		}
		id_final = id_contador +1;
		ofstream atualizarcontador;
		atualizarcontador.open("./db/etc/contadorid.txt");
		if(atualizarcontador.is_open()){
			atualizarcontador << id_final;
		}
	}

	// Fim de atribuição de ID ao novo produto

		this->id = id_contador;
		this->categoria = categoria;
		this->nome = nome;
		this->preco = preco;
		this->quantidade = quantidade;

		escrever_dados();
	
}

Produtos::~Produtos(){
	// Destrutor
}

void Produtos::set_id(int id){
	this->id = id;
}

int Produtos::get_id(){
	return id;
}

void Produtos::set_nome(string nome){
	this->nome = nome;
}

void Produtos::set_preco(float preco){
	this->preco = preco;
}

void Produtos::set_quantidade(int quantidade){
	this->quantidade = quantidade;
}

void Produtos::set_categoria(string categoria){
	this->categoria = categoria;
}

string Produtos::get_nome(){
	return nome;
} 

float Produtos::get_preco(){
	return preco;
}

int Produtos::get_quantidade(){
	return quantidade;
}

string Produtos::get_categoria(){
	return categoria;
}

void Produtos::escrever_dados(){
	ofstream produto;
	string end = "./db/produtos/";
	end.append(to_string(id));
	end.append(".txt");
	produto.open(end);

	if(produto.is_open()){
		produto << get_id() << endl;
    	produto << get_categoria() << endl;
    	produto << get_nome() << endl;
    	produto << fixed << setprecision(2) << get_preco() << endl;
    	produto << get_quantidade() << endl;
    	produto.close();
  }


}