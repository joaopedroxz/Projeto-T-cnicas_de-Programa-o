#ifndef CONTROLADORA_SERVICO_H_INCLUDED
#define CONTROLADORA_SERVICO_H_INCLUDED
#include "interfaces.h"
#include "Containers.cpp"

using namespace std;
/**
 * @class ControladoraServicoTitulo
 * @brief Implementa a interface de servi�o de t�tulos.
 */
/// Controladora para servi�o de t�tulos.
class ControladoraServicoTitulo : public IServicoTitulo {
private:
    ContainerTitulo* containerTitulo;
public:
    /// Construtor que inicializa o container de t�tulos.
    ControladoraServicoTitulo(ContainerTitulo* container) : containerTitulo(container) {}

    /// Cadastra um novo t�tulo no container.
    bool cadastrarTitulo(const Titulo&) override;

    /// Remove um t�tulo do container usando o c�digo do t�tulo.
    bool descadastrarTitulo(const Codigo_de_titulo&) override;

    /// Consulta os detalhes de um t�tulo no container.
    bool consultarTitulo(Titulo&) override;

    /// Atualiza os detalhes de um t�tulo no container.
    bool atualizarTitulo(const Titulo&) override;

    /// Retorna uma lista de t�tulos emitidos por um CPF espec�fico.
    bool retornaTituloPeloEmissor(const Cpf&, list<Titulo>&);
};

/**
 * @class ControladoraServicoPagamento
 * @brief Implementa a interface de servi�o de pagamentos.
 */

/// Controladora para servi�o de pagamentos.
class ControladoraServicoPagamento : public IServicoPagamento {
private:
    ContainerPagamento* containerPagamento;
public:
    /// Construtor que inicializa o container de pagamentos.
    ControladoraServicoPagamento(ContainerPagamento* container) : containerPagamento(container) {}

    /// Cadastra um novo pagamento no container.
    bool cadastrarPagamento(const Pagamento&) override;

    /// Remove um pagamento do container usando o c�digo do pagamento.
    bool descadastrarPagamento(const CodigoPagamento&) override;

    /// Consulta os detalhes de um pagamento no container.
    bool consultarPagamento(Pagamento&) override;

    /// Atualiza os detalhes de um pagamento no container.
    bool atualizarPagamento(const Pagamento&) override;

    /// Retorna uma lista de pagamentos associados a um c�digo de t�tulo espec�fico.
    bool retornaPedidoPeloCodigoTitulo(const Codigo_de_titulo&, list<Pagamento>&);
};

/**
 * @class ControladoraServicoConta
 * @brief Implementa a interface de servi�o de contas.
 */

/// Controladora para servi�o de conta.
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

