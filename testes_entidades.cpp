#include "testes_entidades.h"
#include "dominios.h"

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

void TUConta::testeSucesso ()
{
    estado = SUCESSO;
    Conta conta;

    Cpf cpf;
    cpf.setNumero(CPF_VALIDO);

    Nome nome;
    nome.setNome(NOME_VALIDO);

    Senha senha;
    senha.setSenha(SENHA_VALIDA);

    try
    {
        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        if (conta.getNome().getNome() != NOME_VALIDO)
            estado = FALHA;

        if (conta.getSenha().getSenha() != SENHA_VALIDA)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUTitulo::testeSucesso ()
{
    estado = SUCESSO;
    Titulo titulo;

    Codigo_de_titulo codigoTitulo;
    codigoTitulo.setCodigo(CODIGO_TITULO_VALIDO);

    Nome emissor;
    emissor.setNome(NOME_VALIDO);

    Data emissao;
    emissao.setData(DATA_EMISSAO_VALIDO);

    Data vencimento;
    vencimento.setData(DATA_VENCIMENTO_VALIDO);

    Setor setor;
    setor.setSetor(SETOR_VALIDO);

    Dinheiro valor;
    valor.setValor(VALOR_VALIDO);

    try
    {
        titulo.setCodigo(codigoTitulo);
        titulo.setEmissor(emissor);
        titulo.setEmissao(emissao);
        titulo.setVencimento(vencimento);
        titulo.setSetor(setor);
        titulo.setValor(valor);

        if (titulo.getCodigo().getCodigo() != CODIGO_TITULO_VALIDO)
        {
            cout << titulo.getCodigo().getCodigo() << endl;
            estado = FALHA;
        }

        if (titulo.getEmissor().getNome() != NOME_VALIDO)
        {
            cout << titulo.getEmissor().getNome() << endl;
            estado = FALHA;
        }

        if (titulo.getEmissao().getData() != DATA_EMISSAO_VALIDO)
        {
            cout << titulo.getEmissao().getData() << endl;
            estado = FALHA;
        }

        if (titulo.getVencimento().getData() != DATA_VENCIMENTO_VALIDO)
        {
            cout << titulo.getVencimento().getData() << endl;
            estado = FALHA;
        }

        if (titulo.getSetor().getSetor() != SETOR_VALIDO)
        {
            cout << titulo.getSetor().getSetor() << endl;
            estado = FALHA;
        }

        if (titulo.getValor().getValor() != VALOR_VALIDO)
        {
            cout << titulo.getValor().getValor() << endl;
            estado = FALHA;
        }
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
        cout << excecao.what() << endl;
    }
}

void TUPagamento::testeSucesso ()
{
    estado = SUCESSO;
    Pagamento pagamento;

    CodigoPagamento codigo_pagamento;
    codigo_pagamento.setCodigo(CODIGO_PAGAMENTO_VALIDO);

    Data dataPagamento;
    dataPagamento.setData(DATA_VALIDO);

    Estado estadoPagamento;
    estadoPagamento.setEstado(ESTADO_VALIDO);

    Percentual percentual;
    percentual.setValor(PERCENTUAL_VALIDO);

    try
    {
        pagamento.setCodigo(codigo_pagamento);
        pagamento.setData(dataPagamento);
        pagamento.setEstado(estadoPagamento);
        pagamento.setPercentual(percentual);

        if (pagamento.getCodigo().getCodigo() != CODIGO_PAGAMENTO_VALIDO)
            estado = FALHA;

        if (pagamento.getData().getData() != DATA_VALIDO)
            estado = FALHA;

        if (pagamento.getEstado().getEstado() != ESTADO_VALIDO)
            estado = FALHA;

        if (pagamento.getPercentual().getvalor() != PERCENTUAL_VALIDO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
