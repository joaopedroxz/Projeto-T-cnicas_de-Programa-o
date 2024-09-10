#ifndef CONTROLADORA_APRESENTACAO_H_INCLUDED
#define CONTROLADORA_APRESENTACAO_H_INCLUDED

#pragma once

#include "dominios.h"
#include "entidades.h"
#include "interfaces.h"
#include "controladora_servico.h"

class TelaInicial {
public:
    char mostrarMenu();
};

class TelaLogin {
public:
    bool entrar(ControladoraServicoConta& controladoraConta, Conta& conta);
};

class TelaCadastro {
public:
    bool cadastro(ControladoraServicoConta& controladoraConta);
};

class TelaMenuServicos {
public:
    string mostrarMenu();
};

class TelaServicosConta {
public:
    string mostrarMenu(ControladoraServicoConta& controladoraConta, Conta& conta);
    string infoConta(ControladoraServicoConta& controladoraConta, Conta& conta);
    string editarConta(ControladoraServicoConta& controladoraConta, Conta& conta);
    string excluirConta(ControladoraServicoConta& controladoraConta, Conta& conta);
};

class TelaServicoPagamentos {
public:
    string mostrarMenu(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta);
    string infoPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta);
    string incluirPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta);
    string editarPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta);
    string excluirPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta);
};

class TelaServicoTitulo {
public:
    string mostrarMenu(ControladoraServicoTitulo& controladoraTitulo, Conta& conta);
    string infoTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta);
    string incluirTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta);
    string editarTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta);
    string excluirTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta);
};

#endif // CONTROLADORA_APRESENTACAO_H_INCLUDED
