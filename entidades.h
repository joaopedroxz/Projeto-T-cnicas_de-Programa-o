#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

/**
 * @brief Classe que representa uma conta - Implementado por Daniel Filipe Silva Miguel - 231006112
 */
class Conta {
private:
    Cpf cpf; /**< CPF associado à conta. */
    Nome nome; /**< Nome do titular da conta. */
    Senha senha; /**< Senha de acesso à conta. */

public:
    /**
     * @brief Define o CPF da conta.
     * @param cpf CPF a ser definido.
     */
    void setCpf(const Cpf& cpf);

    /**
     * @brief Obtém o CPF associado à conta.
     * @return CPF da conta.
     */
    Cpf getCpf();

    /**
     * @brief Define o nome do titular da conta.
     * @param nome Nome a ser definido.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Obtém o nome do titular da conta.
     * @return Nome do titular.
     */
    Nome getNome();

    /**
     * @brief Define a senha de acesso à conta.
     * @param senha Senha a ser definida.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Obtém a senha de acesso à conta.
     * @return Senha de acesso.
     */
    Senha getSenha();
};


/**
 * @brief Classe que representa um título - Implementado por Daniel Filipe Silva Miguel - 231006112
 */
class Titulo {
private:
    Codigo_de_titulo codigoTitulo; /**< Código do título. */
    Nome emissor; /**< Nome do emissor do título. */
    Cpf cpfEmissor;
    Setor setor; /**< Setor ao qual o título está associado. */
    Data emissao; /**< Data de emissão do título. */
    Data vencimento; /**< Data de vencimento do título. */
    Dinheiro valor; /**< Valor do título. */

public:
    /**
     * @brief Define o código do título.
     * @param codigo Código a ser definido.
     */
    void setCodigo(const Codigo_de_titulo& codigo);

    /**
     * @brief Obtém o código do título.
     * @return Código do título.
     */
    Codigo_de_titulo getCodigo();

    /**
     * @brief Define o emissor do título.
     * @param emissor Nome do emissor a ser definido.
     */
    void setEmissor(const Nome& emissor);

    /**
     * @brief Obtém o nome do emissor do título.
     * @return Nome do emissor.
     */
    Nome getEmissor();

    /**
     * @brief Define o setor associado ao título.
     * @param setor Setor a ser definido.
     */
    void setSetor(const Setor& setor);

    /**
     * @brief Obtém o setor associado ao título.
     * @return Setor do título.
     */
    Setor getSetor();

    /**
     * @brief Define a data de emissão do título.
     * @param emissao Data de emissão a ser definida.
     */
    void setEmissao(const Data& emissao);

    /**
     * @brief Obtém a data de emissão do título.
     * @return Data de emissão do título.
     */
    Data getEmissao();

    /**
     * @brief Define a data de vencimento do título.
     * @param vencimento Data de vencimento a ser definida.
     */
    void setVencimento(const Data& vencimento);

    /**
     * @brief Obtém a data de vencimento do título.
     * @return Data de vencimento do título.
     */
    Data getVencimento();

    /**
     * @brief Define o valor do título.
     * @param valor Valor a ser definido.
     */
    void setValor(const Dinheiro& valor);

    /**
     * @brief Obtém o valor do título.
     * @return Valor do título.
     */
    Dinheiro getValor();

    void setCpfEmissor(const Cpf& cpf);

    Cpf getCpfEmissor();
};


/**
 * @brief Classe que representa um pagamento - Implementado por Daniel Filipe Silva Miguel - 231006112
 */
class Pagamento {
private:
    CodigoPagamento codigo; /**< Código do pagamento. */
    Codigo_de_titulo codigoTituloAssociado;
    Data data; /**< Data do pagamento. */
    Percentual percentual; /**< Percentual do pagamento. */
    Estado estado; /**< Estado atual do pagamento. */

public:
    /**
     * @brief Define o código do pagamento.
     * @param codigo Código a ser definido.
     */
    void setCodigo(const CodigoPagamento& codigo);

    /**
     * @brief Obtém o código do pagamento.
     * @return Código do pagamento.
     */
    CodigoPagamento getCodigo();

    /**
     * @brief Define a data do pagamento.
     * @param data Data a ser definida.
     */
    void setData(const Data& data);

    /**
     * @brief Obtém a data do pagamento.
     * @return Data do pagamento.
     */
    Data getData();

    /**
     * @brief Define o percentual do pagamento.
     * @param percentual Percentual a ser definido.
     */
    void setPercentual(const Percentual& percentual);

    /**
     * @brief Obtém o percentual do pagamento.
     * @return Percentual do pagamento.
     */
    Percentual getPercentual();

    /**
     * @brief Define o estado atual do pagamento.
     * @param estado Estado a ser definido.
     */
    void setEstado(const Estado& estado);

    /**
     * @brief Obtém o estado atual do pagamento.
     * @return Estado do pagamento.
     */
    Estado getEstado();

    void setCodigoTitulo(const Codigo_de_titulo& codigoTitulo);

    Codigo_de_titulo getCodigoTitulo();
};

#endif // ENTIDADES_H_INCLUDED
