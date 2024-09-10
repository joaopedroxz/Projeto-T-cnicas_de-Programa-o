#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED

#pragma once

#include <string>
#include "dominios.h"
#include "entidades.h"

// Interface para serviço de títulos.
class IServicoTitulo {
public:
    virtual bool cadastrarTitulo(const Titulo&) = 0;
    virtual bool descadastrarTitulo(const Codigo_de_titulo&) = 0;
    virtual bool consultarTitulo(Titulo&) = 0;
    virtual bool atualizarTitulo(const Titulo&) = 0;
    virtual ~IServicoTitulo() = default;
};

// Interface para serviço de pagamentos.
class IServicoPagamento {
public:
    virtual bool cadastrarPagamento(const Pagamento&) = 0;
    virtual bool descadastrarPagamento(const CodigoPagamento&) = 0;
    virtual bool consultarPagamento(Pagamento&) = 0;
    virtual bool atualizarPagamento(const Pagamento&) = 0;
    virtual ~IServicoPagamento() = default;
};

// Interface para serviço de contas.
class IServicoConta {
public:
    virtual bool cadastrarConta(const Conta&) = 0;
    virtual bool descadastrarConta(const Cpf&) = 0;
    virtual bool consultarConta(Conta&) = 0;
    virtual bool atualizarConta(const Conta&) = 0;
    virtual bool autenticarConta(const Cpf&, const Senha&) = 0;
    virtual ~IServicoConta() = default;
};

#endif // INTERFACES_H_INCLUDED
