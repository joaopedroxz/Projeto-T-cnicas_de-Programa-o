#include <iostream>

#include "dominios.h"
#include "entidades.cpp"
#include "testes_dominios.cpp"
#include "testes_entidades.cpp"
#include "controladora_servico.cpp"
#include "controladora_apresentacao.cpp"

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

int main()
{
    ContainerConta containerConta;
    ContainerPagamento containerPagamento;
    ContainerTitulo containerTitulo;

    ControladoraServicoConta controladoraConta(&containerConta);
    ControladoraServicoPagamento controladoraPagamento(&containerPagamento);
    ControladoraServicoTitulo controladoraTitulo(&containerTitulo);

    bool exec = true;

    string screen = "MAIN";

    Conta contaAuth;

    // Cria automaticamente dados para teste:

    Conta createAccount;

    Cpf createCpf;
    Nome createNome;
    Senha createSenha;

    createCpf.setNumero("123.456.789-09");
    createNome.setNome("ADMIN");
    createSenha.setSenha("567821");

    createAccount.setCpf(createCpf);
    createAccount.setNome(createNome);
    createAccount.setSenha(createSenha);

    controladoraConta.cadastrarConta(createAccount);

    Titulo createTitulo;

    Codigo_de_titulo createCodigo;
    Nome createEmissor;
    Setor createSetor;
    Data createEmissao;
    Data createVencimento;
    Dinheiro createValor;

    createCodigo.setCodigo("CRA45673456");
    createEmissor.setNome(createAccount.getNome().getNome());
    createSetor.setSetor("Agricultura");
    createEmissao.setData("12-05-2024");
    createVencimento.setData("12-05-2025");
    createValor.setValor(15000.00);

    createTitulo.setCodigo(createCodigo);
    createTitulo.setEmissor(createEmissor);
    createTitulo.setSetor(createSetor);
    createTitulo.setEmissao(createEmissao);
    createTitulo.setVencimento(createVencimento);
    createTitulo.setValor(createValor);
    createTitulo.setCpfEmissor(createAccount.getCpf());

    controladoraTitulo.cadastrarTitulo(createTitulo);

    Pagamento createPagamento;

    Data dataPagamento;
    CodigoPagamento codigoPagamento;
    Percentual percentualPagamento;
    Estado estadoPagamento;
    Codigo_de_titulo tituloAssociadoPagamento;

    tituloAssociadoPagamento.setCodigo("CRA45673456");
    dataPagamento.setData("12-05-2024");
    codigoPagamento.setCodigo("12345678");
    percentualPagamento.setValor(10);
    estadoPagamento.setEstado("Previsto");

    createPagamento.setCodigo(codigoPagamento);
    createPagamento.setData(dataPagamento);
    createPagamento.setPercentual(percentualPagamento);
    createPagamento.setEstado(estadoPagamento);
    createPagamento.setCodigoTitulo(tituloAssociadoPagamento);

    controladoraPagamento.cadastrarPagamento(createPagamento);

    while (exec) {

        if (screen == "ENCERRAR") {
            exec = false;
        }

        if (screen == "MAIN") {
            TelaInicial telaInicial;

            char opcao = telaInicial.mostrarMenu();

            if (opcao == '1') {
                cout << "\033[2J\033[1;1H";
                cin.ignore();

                screen = "LOGIN";
            };

            if (opcao == '2') {
                cout << "\033[2J\033[1;1H";
                cin.ignore();

                screen = "CADASTRO";
            };

            if (opcao == '3') {
                exec = false;
            };
        };

        if (screen == "CADASTRO") {
            TelaCadastro telaCadastro;

            bool sucesso = telaCadastro.cadastro(controladoraConta);

            if (sucesso) {
                cout << "\033[2J\033[1;1H";
                cin.get();

                cout << "Conta cadastrada com sucesso! Agora faca o login." << endl;
                screen = "LOGIN";
            } else {
                cout << "Falha ao cadastrar a conta." << endl;
                screen = "MAIN";
            };
        };

        if (screen == "LOGIN") {
            TelaLogin telaLogin;

            bool sucesso = telaLogin.entrar(controladoraConta, contaAuth);

            if (sucesso) {
                cout << "\033[2J\033[1;1H";

                cout << "Login realizado com sucesso! Seja bem-vindo, " << contaAuth.getNome().getNome() << "!" << endl;
                screen = "MENU_SERVICOS";
            } else {
                cout << "Falha ao entrar na conta. CPF/Senha invalidos." << endl;
                screen = "MAIN";
            };
        }

        if (screen == "MENU_SERVICOS") {
            TelaMenuServicos telaServicos;

            screen = telaServicos.mostrarMenu();
        }

        if (screen == "SERVICOS_CONTA") {
            TelaServicosConta telaConta;

            screen = telaConta.mostrarMenu(controladoraConta, contaAuth);
        }

        if (screen == "SERVICOS_TITULO") {
            TelaServicoTitulo telaTitulo;

            screen = telaTitulo.mostrarMenu(controladoraTitulo, contaAuth);
        }

        if (screen == "SERVICOS_PAGAMENTOS") {
            TelaServicoPagamentos telaPagamento;

            screen = telaPagamento.mostrarMenu(controladoraTitulo, controladoraPagamento, contaAuth);
        }
    };

    cout << "Encerrando sistema..." << endl;

    return 0;
}
