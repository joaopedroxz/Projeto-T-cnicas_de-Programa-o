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
     * @brief Inclui um novo t�tulo no container.
     * @param T�tulo a ser inclu�do.
     * @return true se o t�tulo for inclu�do com sucesso, false se o t�tulo j� existir.
     */
    bool incluir(Titulo titulo);

    /**
     * @brief Remove um t�tulo do container.
     * @param codigo do t�tulo a ser removido.
     * @return true se o t�tulo for removido com sucesso, false se o t�tulo n�o for encontrado.
     */
    bool remover(Codigo_de_titulo codigo);

    /**
     * @brief Pesquisa um t�tulo no container.
     * @param Ponteiro para o t�tulo a ser pesquisado.
     * @return true se o t�tulo for encontrado, false caso contr�rio.
     */
    bool pesquisar(Titulo* titulo);

    /**
     * @brief Atualiza um t�tulo no container.
     * @param T�tulo com as informa��es atualizadas.
     * @return true se o t�tulo for atualizado com sucesso, false caso contr�rio.
     */
    bool atualizar(Titulo titulo);

    /**
     * @brief Pesquisa t�tulos de um determinado emissor.
     * @param cpf CPF do emissor.
     * @param Lista onde os t�tulos encontrados ser�o armazenados.
     * @return true se t�tulos forem encontrados, false caso contr�rio.
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
     * @param Pagamento a ser inclu�do.
     * @return true se o pagamento for inclu�do com sucesso, false se o pagamento j� existir.
     */
    bool incluir(Pagamento pagamento);

    /**
     * @brief Remove um pagamento do container.
     * @param codigo C�digo do pagamento a ser removido.
     * @return true se o pagamento for removido com sucesso, false se o pagamento n�o for encontrado.
     */
    bool remover(CodigoPagamento codigo);

    /**
     * @brief Pesquisa um pagamento no container.
     * @param pagamento Ponteiro para o pagamento a ser pesquisado.
     * @return true se o pagamento for encontrado, false caso contr�rio.
     */
    bool pesquisar(Pagamento* pagamento);

    /**
     * @brief Atualiza um pagamento no container.
     * @param pagamento Pagamento com as informa��es atualizadas.
     * @return true se o pagamento for atualizado com sucesso, false caso contr�rio.
     */
    bool atualizar(Pagamento pagamento);

    /**
     * @brief Pesquisa pagamentos associados a um t�tulo espec�fico.
     * @param codigoTitulo C�digo do t�tulo associado.
     * @param pagamentos Lista onde os pagamentos encontrados ser�o armazenados.
     * @return true se pagamentos forem encontrados, false caso contr�rio.
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
     * @param Conta a ser inclu�da.
     * @return true se a conta for inclu�da com sucesso, false se a conta j� existir.
     */
    bool incluir(Conta conta);

    /**
     * @brief Remove uma conta do container.
     * @param CPF da conta a ser removida.
     * @return true se a conta for removida com sucesso, false se a conta n�o for encontrada.
     */
    bool remover(Cpf cpf);

    /**
     * @brief Pesquisa uma conta no container.
     * @param Ponteiro para a conta a ser pesquisada.
     * @return true se a conta for encontrada, false caso contr�rio.
     */
    bool pesquisar(Conta* conta);

    /**
     * @brief Atualiza uma conta no container.
     * @param Conta com as informa��es atualizadas.
     * @return true se a conta for atualizada com sucesso, false caso contr�rio.
     */
    bool atualizar(Conta conta);

    /**
     * @brief Autentica uma conta com CPF e senha.
     * @param CPF da conta.
     * @param Senha da conta.
     * @return true se a conta for autenticada com sucesso, false caso contr�rio.
     */
    bool autenticar(Cpf cpf, Senha senha);
};

#endif // CONTAINERS_H_INCLUDED
