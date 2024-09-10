#ifndef TESTES_ENTIDADES_H_INCLUDED
#define TESTES_ENTIDADES_H_INCLUDED

#include <string>
#include <stdexcept>

#include "entidades.h"

using namespace std;

class TUConta
{
private:
    string CPF_VALIDO = "342.158.410-97";
    string NOME_VALIDO = "Daniel Filipe";
    string SENHA_VALIDA = "356872";

    Conta *conta;

    int estado;
    void testeSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA = -1;
    int run();
};

inline int TUConta::run ()
{
    testeSucesso();
    return estado;
}


class TUTitulo
{
private:
    string CODIGO_TITULO_VALIDO = "CRI00000000";
    string NOME_VALIDO = "Daniel Filipe";
    string SETOR_VALIDO = "Agricultura";
    string DATA_EMISSAO_VALIDO = "7-5-2001";
    string DATA_VENCIMENTO_VALIDO = "15-5-2005";
    double VALOR_VALIDO = 1000.0;

    Titulo *titulo;

    int estado;
    void testeSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

inline int TUTitulo::run ()
{
    testeSucesso();
    return estado;
}


class TUPagamento
{
private:
    string CODIGO_PAGAMENTO_VALIDO = "12345678";
    string DATA_VALIDO = "7-5-2000";
    int PERCENTUAL_VALIDO = 50;
    string ESTADO_VALIDO = "Liquidado";

    Pagamento *pagamento;

    int estado;
    void testeSucesso();
public:
    const static int SUCESSO =  0;
    const static int FALHA   = -1;
    int run();
};

inline int TUPagamento::run ()
{
    testeSucesso();
    return estado;
}

#endif // TESTES_ENTIDADES_H_INCLUDED
