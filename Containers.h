#ifndef CONTAINERS_H_INCLUDED
#define CONTAINERS_H_INCLUDED

#include "dominios.h"
#include "entidades.h"

#include <list>

using namespace std;

/**
 * @class ContainerTitulo
 * @brief Container para gerenciar objetos da classe Titulo.
 */
class ContainerTitulo {
private:
    list<Titulo> container; ///< Lista de objetos Titulo.
public:
    /**
     * @brief Inclui um novo título no container.
     * @param Título a ser incluído.
     * @return true se o título for incluído com sucesso, false se o título já existir.
     */
    bool incluir(Titulo titulo);

    /**
     * @brief Remove um título do container.
     * @param codigo do título a ser removido.
     * @return true se o título for removido com sucesso, false se o título não for encontrado.
     */
    bool remover(Codigo_de_titulo codigo);

    /**
     * @brief Pesquisa um título no container.
     * @param Ponteiro para o título a ser pesquisado.
     * @return true se o título for encontrado, false caso contrário.
     */
    bool pesquisar(Titulo* titulo);

    /**
     * @brief Atualiza um título no container.
     * @param Título com as informações atualizadas.
     * @return true se o título for atualizado com sucesso, false caso contrário.
     */
    bool atualizar(Titulo titulo);

    /**
     * @brief Pesquisa títulos de um determinado emissor.
     * @param cpf CPF do emissor.
     * @param Lista onde os títulos encontrados serão armazenados.
     * @return true se títulos forem encontrados, false caso contrário.
     */
    bool pesquisar(Cpf cpf, list<Titulo>* titulos);
};

/**
 * @class ContainerPagamento
 * @brief Container para gerenciar objetos da classe Pagamento.
 */
class ContainerPagamento {
private:
    list<Pagamento> container; ///< Lista de objetos Pagamento.
public:
    /**
     * @brief Inclui um novo pagamento no container.
     * @param Pagamento a ser incluído.
     * @return true se o pagamento for incluído com sucesso, false se o pagamento já existir.
     */
    bool incluir(Pagamento pagamento);

    /**
     * @brief Remove um pagamento do container.
     * @param codigo Código do pagamento a ser removido.
     * @return true se o pagamento for removido com sucesso, false se o pagamento não for encontrado.
     */
    bool remover(CodigoPagamento codigo);

    /**
     * @brief Pesquisa um pagamento no container.
     * @param pagamento Ponteiro para o pagamento a ser pesquisado.
     * @return true se o pagamento for encontrado, false caso contrário.
     */
    bool pesquisar(Pagamento* pagamento);

    /**
     * @brief Atualiza um pagamento no container.
     * @param pagamento Pagamento com as informações atualizadas.
     * @return true se o pagamento for atualizado com sucesso, false caso contrário.
     */
    bool atualizar(Pagamento pagamento);

    /**
     * @brief Pesquisa pagamentos associados a um título específico.
     * @param codigoTitulo Código do título associado.
     * @param pagamentos Lista onde os pagamentos encontrados serão armazenados.
     * @return true se pagamentos forem encontrados, false caso contrário.
     */
    bool pesquisar(Codigo_de_titulo codigoTitulo, list<Pagamento>* pagamentos);
};

/**
 * @class ContainerConta
 * @brief Container para gerenciar objetos da classe Conta.
 */
class ContainerConta {
private:
    list<Conta> container; ///< Lista de objetos Conta.
public:
    /**
     * @brief Inclui uma nova conta no container.
     * @param Conta a ser incluída.
     * @return true se a conta for incluída com sucesso, false se a conta já existir.
     */
    bool incluir(Conta conta);

    /**
     * @brief Remove uma conta do container.
     * @param CPF da conta a ser removida.
     * @return true se a conta for removida com sucesso, false se a conta não for encontrada.
     */
    bool remover(Cpf cpf);

    /**
     * @brief Pesquisa uma conta no container.
     * @param Ponteiro para a conta a ser pesquisada.
     * @return true se a conta for encontrada, false caso contrário.
     */
    bool pesquisar(Conta* conta);

    /**
     * @brief Atualiza uma conta no container.
     * @param Conta com as informações atualizadas.
     * @return true se a conta for atualizada com sucesso, false caso contrário.
     */
    bool atualizar(Conta conta);

    /**
     * @brief Autentica uma conta com CPF e senha.
     * @param CPF da conta.
     * @param Senha da conta.
     * @return true se a conta for autenticada com sucesso, false caso contrário.
     */
    bool autenticar(Cpf cpf, Senha senha);
};

#endif // CONTAINERS_H_INCLUDED
