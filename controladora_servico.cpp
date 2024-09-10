#include "controladora_servico.h"



bool ControladoraServicoTitulo::cadastrarTitulo(const Titulo& titulo) {
    return containerTitulo->incluir(titulo);
}

bool ControladoraServicoTitulo::descadastrarTitulo(const Codigo_de_titulo& codigo) {
    return containerTitulo->remover(codigo);
}

bool ControladoraServicoTitulo::consultarTitulo(Titulo& titulo) {
    return containerTitulo->pesquisar(&titulo);
}

bool ControladoraServicoTitulo::atualizarTitulo(const Titulo& titulo) {
    return containerTitulo->atualizar(titulo);
}

bool ControladoraServicoTitulo::retornaTituloPeloEmissor(const Cpf& cpf, list<Titulo>& titulos) {
    return containerTitulo->pesquisar(cpf, &titulos);
}

// Implementação dos métodos da ControladoraServicoPagamento.

bool ControladoraServicoPagamento::cadastrarPagamento(const Pagamento& pagamento) {
    return containerPagamento->incluir(pagamento);
}

bool ControladoraServicoPagamento::descadastrarPagamento(const CodigoPagamento& codigo) {
    return containerPagamento->remover(codigo);
}

bool ControladoraServicoPagamento::consultarPagamento(Pagamento& pagamento) {
    return containerPagamento->pesquisar(&pagamento);
}

bool ControladoraServicoPagamento::atualizarPagamento(const Pagamento& pagamento) {
    return containerPagamento->atualizar(pagamento);
}

bool ControladoraServicoPagamento::retornaPedidoPeloCodigoTitulo(const Codigo_de_titulo& codigoTitulo, list<Pagamento>& pagamentos) {
    return containerPagamento->pesquisar(codigoTitulo, &pagamentos);
}

// Implementação dos métodos da ControladoraServicoConta.


bool ControladoraServicoConta::cadastrarConta(const Conta& conta) {
    return containerConta->incluir(conta);
}

bool ControladoraServicoConta::descadastrarConta(const Cpf& cpf) {
    return containerConta->remover(cpf);
}

bool ControladoraServicoConta::consultarConta(Conta& conta) {
    return containerConta->pesquisar(&conta);
}

bool ControladoraServicoConta::atualizarConta(const Conta& conta) {
    return containerConta->atualizar(conta);
}

bool ControladoraServicoConta::autenticarConta(const Cpf& cpf, const Senha& senha) {
    return containerConta->autenticar(cpf, senha);
}


