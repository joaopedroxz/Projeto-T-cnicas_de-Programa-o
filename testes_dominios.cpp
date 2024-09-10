#include "testes_dominios.h"
#include "dominios.cpp"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void TUCodigo::testeSucesso()
{
    estado = SUCESSO;
    Codigo_de_titulo codi;
    try
    {
        codi.setCodigo(VALOR_VALIDO);
        if (codi.getCodigo() != VALOR_VALIDO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUCodigo::testeErro()
{
    estado = SUCESSO;
    Codigo_de_titulo codi;
    try
    {
        codi.setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(codi.getCodigo() == VALOR_INVALIDO)
            estado = FALHA;
    }
}


int TUCodigo::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUPercentual::testeSucesso()
{
    estado = SUCESSO;
    Percentual num;
    try
    {
        num.setValor(VALOR_VALIDO);
        if (num.getvalor()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUPercentual::testeErro()
{
    estado = SUCESSO;
    Percentual num;
    try
    {
        num.setValor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(num.getvalor() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUPercentual::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUNome::testeSucesso()
{
    estado = SUCESSO;
    Nome nome;
    try
    {
        nome.setNome(VALOR_INVALIDO);
        if (nome.getNome()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUNome::testeErro()
{
    estado = SUCESSO;
    Nome nome;
    try
    {
        nome.setNome(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(nome.getNome() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUNome::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUSenha::testeSucesso()
{
    estado = SUCESSO;
    Senha senha;
    try
    {
        senha.setSenha(VALOR_INVALIDO);
        if (senha.getSenha()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUSenha::testeErro()
{
    estado = SUCESSO;
    Senha senha;
    try
    {
        senha.setSenha(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(senha.getSenha() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUSenha::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUData::testeSucesso()
{
    estado = SUCESSO;
    Data data;
    try
    {
        data.setData(VALOR_INVALIDO);
        if (data.getData()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUData::testeErro()
{
    estado = SUCESSO;
    Data data;
    try
    {
        data.setData(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(data.getData() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUData::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUEstado::testeSucesso()
{
    estado = SUCESSO;
    Estado e;
    try
    {
        e.setEstado(VALOR_INVALIDO);
        if (e.getEstado()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUEstado::testeErro()
{
    estado = SUCESSO;
    Estado e;
    try
    {
        e.setEstado(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(e.getEstado() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUEstado::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUCodigoPagamento::testeSucesso()
{
    estado = SUCESSO;
    CodigoPagamento codigo;
    try
    {
        codigo.setCodigo(VALOR_INVALIDO);
        if (codigo.getCodigo()!= VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUCodigoPagamento::testeErro()
{
    estado = SUCESSO;
    CodigoPagamento codigo;
    try
    {
        codigo.setCodigo(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(codigo.getCodigo() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUCodigoPagamento::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUSetor::testeSucesso()
{
    estado = SUCESSO;
    Setor setor;
    try
    {
        setor.setSetor(VALOR_INVALIDO);
        if (setor.getSetor() != VALOR_VALIDO)
            estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}


void TUSetor::testeErro()
{
    estado = SUCESSO;
    Setor setor;
    try
    {
        setor.setSetor(VALOR_INVALIDO);
        estado = FALHA;
    }
    catch(invalid_argument &excecao)
    {
        if(setor.getSetor() == VALOR_INVALIDO){
            estado = FALHA;
        }
    }
}


int TUSetor::run()
{
    testeSucesso();
    testeErro();
    return estado;
}


void TUCpf::testeSucesso()
{
    Cpf cpf;
    estado = SUCESSO;
    estado = SUCESSO;
    try {
        cpf.setNumero(VALOR_VALIDO);
        if (!cpf.verificar_cpf(cpf.getNumero())) {
            estado = FALHA;
        }
    } catch (invalid_argument& e) {
        estado = FALHA;
    }
}

void TUCpf::testeFalha()
{
    Cpf cpf;
    estado = SUCESSO;
    try {
        cpf.setNumero(VALOR_INVALIDO);
        if (cpf.verificar_cpf(cpf.getNumero())) {
            estado = FALHA;
        }
    } catch (invalid_argument& e) {
        estado = SUCESSO;
    }
}

int TUCpf::run()
{
    testeSucesso();
    testeFalha();
    return estado;
}


void TUDinheiro::testeSucesso()
{
    estado = SUCESSO;
    Dinheiro dinheiro;

    try {
        dinheiro.setValor(VALOR_VALIDO);
        if (dinheiro.getValor() != VALOR_VALIDO) {
            estado = FALHA;
        }
    } catch (std::invalid_argument& excecao) {
        estado = FALHA;
    }
}


void TUDinheiro::testeFalha()
{
    estado = SUCESSO;
    Dinheiro dinheiro;

    try {
        dinheiro.setValor(VALOR_INVALIDO);
        estado = FALHA;
    } catch (std::invalid_argument& excecao) {
        if (dinheiro.getValor() == VALOR_INVALIDO) {
            estado = FALHA;
        }
    }
}


int TUDinheiro::run()
{
    testeSucesso();
    testeFalha();
    return estado;
}
