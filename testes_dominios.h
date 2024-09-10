#ifndef TESTES_DOMINIOS_H_INCLUDED
#define TESTES_DOMINIOS_H_INCLUDED

#include <string>
#include <stdexcept>

#include "dominios.h"

using namespace std;

///
/// classe de teste usado para verificar se o dominio Codigo de titulo implementado esta funcionando corretamente;
///
/// Regras de formato:
/// - 3 primeiros prefixos dos tipos; CDB,CRA,CRI,LCA,LCI,DEB;
/// - 9 caracteres com letras maiusculas (A-Z) ou numeros inteiros entre (0-9).
///
class TUCodigo
{
private:
///
/// Variavel responsavel por fornecer um valor valido para ser usado no teste de sucesso
///
    string VALOR_VALIDO = "CRI00000000";
///
/// Variavel responsavel por fornecer um valor invalido para ser usado no teste de erro.
///
    string VALOR_INVALIDO = "LLL00000000";
///
/// Metodo com a logica para o teste. Verificara como o dominio se comporta recebendo um valor valido.
///
    void testeSucesso();
///
/// Metodo com a logica para o teste. Verificara como o dominio se comporta recebendo um valor invalido.
///
    void testeErro();
///
/// Variavel responsavel por armazenar o resultado dos testes feitos
///
    int estado;
public:
///
/// Variavel que indica o resultado dos testes feitos, em caso do dominio funcionando perfeitamente a variavel sera utilizada
///
    const static int SUCESSO = 0;
///
/// Variavel que indica o resultado dos testes feitos, em caso do dominio com defeito a variavel sera utilizada
///
    const static int FALHA = -1;

///
/// Metodo responsavel por fazer todos os testes funcionarem, tratasse start para todo o teste
///
    int run();
};


///
/// classe de teste usado para verificar se o dominio Percentual implementado esta funcionando corretamente;
///
/// Regras de formato:
/// - valor inteiro de 0 a 100.
///
class TUPercentual
{
private:
///
/// Variavel responsavel por fornecer um valor valido para ser usado no teste de sucesso
///
    int VALOR_VALIDO = 95;
///
/// Variavel responsavel por fornecer um valor invalido para ser usado no teste de erro.
///
    int VALOR_INVALIDO = -1;
///
/// Metodo com a logica para o teste. Verificara como o dominio se comporta recebendo um valor valido.
///
    void testeSucesso();
///
/// Metodo com a logica para o teste. Verificara como o dominio se comporta recebendo um valor invalido.
///
    void testeErro();
///
/// Variavel responsavel por armazenar o resultado dos testes feitos
///
    int estado;
public:
///
/// Variavel que indica o resultado dos testes feitos, em caso do dominio funcionando perfeitamente a variavel sera utilizada
///
    const static int SUCESSO = 0;
///
/// Variavel que indica o resultado dos testes feitos, em caso do dominio com defeito a variavel sera utilizada
///
    const static int FALHA = -1;
    int run();
};


class TUNome {
private:
    string VALOR_VALIDO = "Daniel Filipe";
    string VALOR_INVALIDO = "D4aniel F1ilip3";

    void testeSucesso();
    void testeErro();

    int estado;

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


class TUSenha {
private:
    string VALOR_VALIDO = "657438";
    string VALOR_INVALIDO = "123456";

    void testeSucesso();
    void testeErro();

    int estado;

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


class TUData{
public:
    private:
    string VALOR_VALIDO = "29-05-2005";
    string VALOR_INVALIDO = "29/05/2005";

    void testeSucesso();
    void testeErro();

    int estado;

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


///
/// Teste de unidade referente a classe Estado
///
class TUEstado{
private:
    string VALOR_VALIDO = "Liquidado";
    string VALOR_INVALIDO = "INDISPONIVEL";

    void testeSucesso();
    void testeErro();

    int estado;

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


class TUCodigoPagamento {
private:
    string VALOR_VALIDO = "12345678";
    string VALOR_INVALIDO = "01234567";

    void testeSucesso();
    void testeErro();

    int estado;

public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


class TUSetor {
private:
    string VALOR_VALIDO = "Agricultura";
    string VALOR_INVALIDO = "Buritis";

    void testeSucesso();
    void testeErro();

    int estado;
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};


class TUCpf {
private:
    const string VALOR_VALIDO = "342.158.410-97";
    const string VALOR_INVALIDO = "111.111.111-12";

    void testeSucesso();
    void testeFalha();

    int estado;
public:
    static const int SUCESSO = 0;
    static const int FALHA = -1;

    int run();
};


class TUDinheiro {
private:
    static constexpr double VALOR_VALIDO = 1000.0;
    static constexpr double VALOR_INVALIDO = 2000000.0;

    void testeSucesso();
    void testeFalha();

    int estado;
public:
    const static int SUCESSO = 0;
    const static int FALHA = -1;

    int run();
};

#endif // TESTES_DOMINIOS_H_INCLUDED
