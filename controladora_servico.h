#ifndef CONTROLADORA_SERVICO_H_INCLUDED
#define CONTROLADORA_SERVICO_H_INCLUDED
#include "interfaces.h"
#include "Containers.cpp"

using namespace std;
/**
 * @class ControladoraServicoTitulo
 * @brief Implementa a interface de serviço de títulos.
 */
/// Controladora para serviço de títulos.
class ControladoraServicoTitulo : public IServicoTitulo {
private:
    ContainerTitulo* containerTitulo;
public:
    /// Construtor que inicializa o container de títulos.
    ControladoraServicoTitulo(ContainerTitulo* container) : containerTitulo(container) {}

    /// Cadastra um novo título no container.
    bool cadastrarTitulo(const Titulo&) override;

    /// Remove um título do container usando o código do título.
    bool descadastrarTitulo(const Codigo_de_titulo&) override;

    /// Consulta os detalhes de um título no container.
    bool consultarTitulo(Titulo&) override;

    /// Atualiza os detalhes de um título no container.
    bool atualizarTitulo(const Titulo&) override;

    /// Retorna uma lista de títulos emitidos por um CPF específico.
    bool retornaTituloPeloEmissor(const Cpf&, list<Titulo>&);
};

/**
 * @class ControladoraServicoPagamento
 * @brief Implementa a interface de serviço de pagamentos.
 */

/// Controladora para serviço de pagamentos.
class ControladoraServicoPagamento : public IServicoPagamento {
private:
    ContainerPagamento* containerPagamento;
public:
    /// Construtor que inicializa o container de pagamentos.
    ControladoraServicoPagamento(ContainerPagamento* container) : containerPagamento(container) {}

    /// Cadastra um novo pagamento no container.
    bool cadastrarPagamento(const Pagamento&) override;

    /// Remove um pagamento do container usando o código do pagamento.
    bool descadastrarPagamento(const CodigoPagamento&) override;

    /// Consulta os detalhes de um pagamento no container.
    bool consultarPagamento(Pagamento&) override;

    /// Atualiza os detalhes de um pagamento no container.
    bool atualizarPagamento(const Pagamento&) override;

    /// Retorna uma lista de pagamentos associados a um código de título específico.
    bool retornaPedidoPeloCodigoTitulo(const Codigo_de_titulo&, list<Pagamento>&);
};

/**
 * @class ControladoraServicoConta
 * @brief Implementa a interface de serviço de contas.
 */

/// Controladora para serviço de conta.
class ControladoraServicoConta : public IServicoConta {
private:
    ContainerConta* containerConta;
public:
    /// Construtor que inicializa o container de contas.
    ControladoraServicoConta(ContainerConta* container) : containerConta(container) {}

    /// Cadastra uma nova conta no container.
    bool cadastrarConta(const Conta&) override;

    /// Remove uma conta do container usando o CPF.
    bool descadastrarConta(const Cpf&) override;

    /// Consulta os detalhes de uma conta no container.
    bool consultarConta(Conta&) override;

    /// Atualiza os detalhes de uma conta no container.
    bool atualizarConta(const Conta&) override;

    /// Autentica uma conta usando CPF e senha.
    bool autenticarConta (const Cpf&, const Senha&) override;
};

#endif // CONTROLADORA_SERVICO_H_INCLUDED

