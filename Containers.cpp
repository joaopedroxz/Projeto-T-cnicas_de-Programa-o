#include "Containers.h"
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;
// ----------------------------------------------------------------------
// Implementações de métodos de classe container.

bool ContainerTitulo::incluir(Titulo titulo){
    for(list<Titulo>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == titulo.getCodigo().getCodigo()){
            return false;
        }
    }
    container.push_back(titulo);                               // Incluir objeto.
    return true;
}

bool ContainerTitulo::remover(Codigo_de_titulo codigo){
    for(list<Titulo>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerTitulo::pesquisar(Titulo* titulo){
    for(list<Titulo>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == titulo->getCodigo().getCodigo()){
            *titulo = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerTitulo::atualizar(Titulo titulo){
    for(list<Titulo>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == titulo.getCodigo().getCodigo()){
            *elemento = titulo;
            return true;
        }
    }
    return false;
}

bool ContainerTitulo::pesquisar(Cpf cpf, list<Titulo>* titulos) {
    for(list<Titulo>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCpfEmissor().getNumero() == cpf.getNumero()){
            titulos->push_back(*elemento);
        }
    }

    if (titulos->empty()) {
        return false;
    }

    return true;
}


bool ContainerPagamento::incluir(Pagamento pagamento){
    for(list<Pagamento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == pagamento.getCodigo().getCodigo()){
            return false;
        }
    }
    container.push_back(pagamento);                               // Incluir objeto.
    return true;
}

bool ContainerPagamento::remover(CodigoPagamento codigo){
    for(list<Pagamento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == codigo.getCodigo()){
            container.erase(elemento);                          // Remover objeto localizado.
            return true;
        }
    }
    return false;
}

bool ContainerPagamento::pesquisar(Pagamento* pagamento){
    for(list<Pagamento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == pagamento->getCodigo().getCodigo()){
            *pagamento = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerPagamento::atualizar(Pagamento pagamento){
    for(list<Pagamento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigo().getCodigo() == pagamento.getCodigo().getCodigo()){
            *elemento = pagamento;
            return true;
        }
    }
    return false;
}

bool ContainerPagamento::pesquisar(Codigo_de_titulo codigoTitulo, list<Pagamento>* pagamentos) {
    for(list<Pagamento>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCodigoTitulo().getCodigo() == codigoTitulo.getCodigo()){
            pagamentos->push_back(*elemento);
        }
    }

    if (pagamentos->empty()) {
        return false;
    }

    return true;
}



bool ContainerConta::incluir(Conta conta){
    for(list<Conta>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCpf().getNumero() == conta.getCpf().getNumero()) {
            return false;
        }
    }
    container.push_back(conta);                               // Incluir objeto.
    return true;
}

bool ContainerConta::remover(Cpf cpf){
    for(list<Conta>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCpf().getNumero() == cpf.getNumero()){
            container.erase(elemento);                          // Remover objeto localizado.
        return true;
}
    }
    return false;
}

bool ContainerConta::pesquisar(Conta* conta){
    for(list<Conta>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCpf().getNumero() == conta->getCpf().getNumero()){
            *conta = *elemento;
            return true;
        }
    }
    return false;
}

bool ContainerConta::atualizar(Conta conta){
    for(list<Conta>::iterator elemento = container.begin(); elemento != container.end(); elemento++){
        if (elemento->getCpf().getNumero() == conta.getCpf().getNumero()){
            *elemento = conta;
            return true;
        }
    }
    return false;
}

bool ContainerConta::autenticar(Cpf cpf, Senha senha)
{
    bool resultado = false;
    for (list<Conta>::iterator elemento = container.begin(); elemento != container.end(); ++elemento)
    {
        if (elemento->getCpf().getNumero() == cpf.getNumero())
        {
            if (elemento->getSenha().getSenha() == senha.getSenha())
            {
                resultado = true;
                break; // Sai do loop uma vez que a conta é autenticada
            }
        }
    }
    return resultado;
}
