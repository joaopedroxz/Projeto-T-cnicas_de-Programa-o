#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"

/**
 * @brief Classe que representa uma conta - Implementado por Daniel Filipe Silva Miguel -�231006112
 */
class Conta {
private:
    Cpf cpf; /**< CPF associado � conta. */
    Nome nome; /**< Nome do titular da conta. */
    Senha senha; /**< Senha de acesso � conta. */

public:
    /**
     * @brief Define o CPF da conta.
     * @param cpf CPF a ser definido.
     */
    void setCpf(const Cpf& cpf);

    /**
     * @brief Obt�m o CPF associado � conta.
     * @return CPF da conta.
     */
    Cpf getCpf();

    /**
     * @brief Define o nome do titular da conta.
     * @param nome Nome a ser definido.
     */
    void setNome(const Nome& nome);

    /**
     * @brief Obt�m o nome do titular da conta.
     * @return Nome do titular.
     */
    Nome getNome();

    /**
     * @brief Define a senha de acesso � conta.
     * @param senha Senha a ser definida.
     */
    void setSenha(const Senha& senha);

    /**
     * @brief Obt�m a senha de acesso � conta.
     * @return Senha de acesso.
     */
    Senha getSenha();
};


/**
 * @brief Classe que representa um t�tulo - Implementado por Daniel Filipe Silva Miguel -�231006112
 */
class Titulo {
private:
    Codigo_de_titulo codigoTitulo; /**< C�digo do t�tulo. */
    Nome emissor; /**< Nome do emissor do t�tulo. */
    Cpf cpfEmissor;
    Setor setor; /**< Setor ao qual o t�tulo est� associado. */
    Data emissao; /**< Data de emiss�o do t�tulo. */
    Data vencimento; /**< Data de vencimento do t�tulo. */
    Dinheiro valor; /**< Valor do t�tulo. */

public:
    /**
     * @brief Define o c�digo do t�tulo.
     * @param codigo C�digo a ser definido.
     */
    void setCodigo(const Codigo_de_titulo& codigo);

    /**
     * @brief Obt�m o c�digo do t�tulo.
     * @return C�digo do t�tulo.
     */
    Codigo_de_titulo getCodigo();

    /**
     * @brief Define o emissor do t�tulo.
     * @param emissor Nome do emissor a ser definido.
     */
    void setEmissor(const Nome& emissor);

    /**
     * @brief Obt�m o nome do emissor do t�tulo.
     * @return Nome do emissor.
     */
    Nome getEmissor();

    /**
     * @brief Define o setor associado ao t�tulo.
     * @param setor Setor a ser definido.
     */
    void setSetor(const Setor& setor);

    /**
     * @brief Obt�m o setor associado ao t�tulo.
     * @return Setor do t�tulo.
     */
    Setor getSetor();

    /**
     * @brief Define a data de emiss�o do t�tulo.
     * @param emissao Data de emiss�o a ser definida.
     */
    void setEmissao(const Data& emissao);

    /**
     * @brief Obt�m a data de emiss�o do t�tulo.
     * @return Data de emiss�o do t�tulo.
     */
    Data getEmissao();

    /**
     * @brief Define a data de vencimento do t�tulo.
     * @param vencimento Data de vencimento a ser definida.
     */
    void setVencimento(const Data& vencimento);

    /**
     * @brief Obt�m a data de vencimento do t�tulo.
     * @return Data de vencimento do t�tulo.
     */
    Data getVencimento();

    /**
     * @brief Define o valor do t�tulo.
     * @param valor Valor a ser definido.
     */
    void setValor(const Dinheiro& valor);

    /**
     * @brief Obt�m o valor do t�tulo.
     * @return Valor do t�tulo.
     */
    Dinheiro getValor();

    void setCpfEmissor(const Cpf& cpf);

    Cpf getCpfEmissor();
};


/**
 * @brief Classe que representa um pagamento - Implementado por Daniel Filipe Silva Miguel -�231006112
 */
class Pagamento {
private:
    CodigoPagamento codigo; /**< C�digo do pagamento. */
    Codigo_de_titulo codigoTituloAssociado;
    Data data; /**< Data do pagamento. */
    Percentual percentual; /**< Percentual do pagamento. */
    Estado estado; /**< Estado atual do pagamento. */

public:
    /**
     * @brief Define o c�digo do pagamento.
     * @param codigo C�digo a ser definido.
     */
    void setCodigo(const CodigoPagamento& codigo);

    /**
     * @brief Obt�m o c�digo do pagamento.
     * @return C�digo do pagamento.
     */
    CodigoPagamento getCodigo();

    /**
     * @brief Define a data do pagamento.
     * @param data Data a ser definida.
     */
    void setData(const Data& data);

    /**
     * @brief Obt�m a data do pagamento.
     * @return Data do pagamento.
     */
    Data getData();

    /**
     * @brief Define o percentual do pagamento.
     * @param percentual Percentual a ser definido.
     */
    void setPercentual(const Percentual& percentual);

    /**
     * @brief Obt�m o percentual do pagamento.
     * @return Percentual do pagamento.
     */
    Percentual getPercentual();

    /**
     * @brief Define o estado atual do pagamento.
     * @param estado Estado a ser definido.
     */
    void setEstado(const Estado& estado);

    /**
     * @brief Obt�m o estado atual do pagamento.
     * @return Estado do pagamento.
     */
    Estado getEstado();

    void setCodigoTitulo(const Codigo_de_titulo& codigoTitulo);

    Codigo_de_titulo getCodigoTitulo();
};

#endif // ENTIDADES_H_INCLUDED
