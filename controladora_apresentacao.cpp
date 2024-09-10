#include <string>
#include <iostream>
#include <stdexcept>
#include <map>
#include "controladora_apresentacao.h"

using namespace std;

char TelaInicial::mostrarMenu() {
    string opcao;
    bool continuar = true;

    while (continuar) {
        cout << "<--------------------------------------------------------->" << endl;
        cout << "|  Bem-vindo ao Sistema! Selecione uma das opcoes abaixo: |" << endl;
        cout << "<--------------------------------------------------------->" << endl;
        cout << "|  1 - Entrar no sistema                                  |" << endl;
        cout << "|  2 - Cadastrar conta                                    |" << endl;
        cout << "|  3 - Encerrar                                           |" << endl;
        cout << "<--------------------------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            return '1';
        } else if (opcao == "2") {
            return '2';
        } else if (opcao == "3") {
            return '3';
            continuar = false;
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}

bool TelaCadastro::cadastro(ControladoraServicoConta& controladoraConta) {
    bool continuar = true;

    Nome nome;
    Cpf cpf;
    Senha senha;

    while (continuar) {

        while (true) {
            string stringNome;

            cout << "Digite seu nome (Nome e sobrenome): " << endl;
            getline(cin, stringNome);

            try {
                nome.setNome(stringNome);
                break;
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        while (true) {
            string stringCPF;

            cout << "Digite o CPF da conta (XXX.XXX.XXX-XX): " << endl;
            cin >> stringCPF;

            try {
                cpf.setNumero(stringCPF);
                break;
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        while (true) {
            string stringSenha;

            cout << "Digite sua senha: " << endl;
            cin >> stringSenha;

            try {
                senha.setSenha(stringSenha);
                break;
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
            }
        }

        continuar = false;
    }

    try {
        Conta conta;

        conta.setCpf(cpf);
        conta.setNome(nome);
        conta.setSenha(senha);

        if (controladoraConta.consultarConta(conta)) {
            throw invalid_argument("CPF ja esta cadastrado no sistema!");
        } else {
            controladoraConta.cadastrarConta(conta);
        }

        return true;
    } catch (invalid_argument& e) {
        cout << "\033[2J\033[1;1H";
        cout << "<------------------------------------->" << endl;
        cout << " Alerta: " << e.what() << endl;
        cout << "<------------------------------------->" << endl;

        return false;
    }
}

bool TelaLogin::entrar(ControladoraServicoConta& controladoraConta, Conta& conta) {
    bool continuar = true;

    while (continuar) {
        string stringCPF;
        string stringSenha;

        while (true) {
            cout << "Digite seu CPF (XXX.XXX.XXX-XX): ";
            getline(cin, stringCPF);
            break;
        }

        while (true) {
            cout << "Digite sua senha: ";
            getline(cin, stringSenha);
            break;
        }

        try {
            Cpf cpf;
            Senha senha;

            cpf.setNumero(stringCPF);
            senha.setSenha(stringSenha);

            conta.setCpf(cpf);
            conta.setSenha(senha);

            if (controladoraConta.autenticarConta(cpf, senha)) {
                return controladoraConta.consultarConta(conta);
            };

            return false;
        } catch (invalid_argument& e) {
            cout << e.what() << endl;

            return false;
        }
    }

    return false;
}

string TelaMenuServicos::mostrarMenu() {
    string opcao;

    while (true) {
        cout << "<------------------------------------->" << endl;
        cout << "|  Selecione um de nossos servicos:   |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "|  1 - Minha conta                    |" << endl;
        cout << "|  2 - Meus titulos                   |" << endl;
        cout << "|  3 - Meus pagamentos                |" << endl;
        cout << "|  4 - Encerrar sistema               |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "SERVICOS_CONTA";
        } else if (opcao == "2") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "SERVICOS_TITULO";
        } else if (opcao == "3") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "SERVICOS_PAGAMENTOS";
        } else if (opcao == "4") {
            return "ENCERRAR";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
            cin.get();
        }
    }

    return 0;
}

string TelaServicosConta::mostrarMenu(ControladoraServicoConta& controladoraConta, Conta& conta) {
    string opcao;

    while(true) {
        cout << "<------------------------------------->" << endl;
        cout << "| Minha Conta:                        |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "| 1 - Informacoes da Conta            |" << endl;
        cout << "| 2 - Editar informacoes da Conta     |" << endl;
        cout << "| 3 - Excluir conta                   |" << endl;
        cout << "| 4 - Sair da conta                   |" << endl;
        cout << "| 5 - Voltar para tela anterior       |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            return this->infoConta(controladoraConta, conta);
        } else if (opcao == "2") {
            return this->editarConta(controladoraConta, conta);
        } else if (opcao == "3") {
            return this->excluirConta(controladoraConta, conta);
        } else if (opcao == "4") {
            cout << "\033[2J\033[1;1H";

            Conta resetContaAuth;

            conta = resetContaAuth;

            return "MAIN";
        } else if (opcao == "5") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "MENU_SERVICOS";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }
    }

    return 0;
}

string TelaServicosConta::infoConta(ControladoraServicoConta& controladoraConta, Conta& conta) {
    string opcao;

    controladoraConta.consultarConta(conta);

    cout << "\033[2J\033[1;1H";
    cin.ignore();

    while(true) {
        cout << "<---------------------------------------------->" << endl;
        cout << "| Minha Conta:                                 |" << endl;
        cout << "<---------------------------------------------->" << endl;
        cout << " Nome: " << conta.getNome().getNome() << endl;
        cout << " CPF: " << conta.getCpf().getNumero() << endl;
        cout << " Senha: " << conta.getSenha().getSenha() << endl;
        cout << "<---------------------------------------------->" << endl;
        cout << "| Opcoes:                                      |" << endl;
        cout << "| 1 - Voltar para tela anterior                |" << endl;
        cout << "<---------------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "SERVICOS_CONTA";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }
    }

    return 0;
}

string TelaServicosConta::editarConta(ControladoraServicoConta& controladoraConta, Conta& conta) {
    string opcao;

    while(true) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<------------------------------------->" << endl;
        cout << "| Editar informacoes da Conta:        |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "| 1 - Editar Nome                     |" << endl;
        cout << "| 2 - Editar Senha                    |" << endl;
        cout << "| 3 - Voltar para tela anterior       |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            string stringNome;
            Nome nome;

            cout << "\033[2J\033[1;1H";
            cin.ignore();

            cout << "Editar nome da Conta:" << endl;
            cout << "Novo nome: ";
            getline(cin, stringNome);

            try {
                nome.setNome(stringNome);
                conta.setNome(nome);

                if (controladoraConta.atualizarConta(conta)) {
                    controladoraConta.consultarConta(conta);
                };

                cout << "\033[2J\033[1;1H";

                cout << "Nome editado com sucesso!" << endl;

                return "MENU_SERVICOS";
            } catch (invalid_argument& e) {
                cout << e.what() << endl;
                cin.ignore();
            }
        } else if (opcao == "2") {
            string stringSenha;
            Senha senha;

            cout << "\033[2J\033[1;1H";
            cin.ignore();

            cout << "<------------------------>" << endl;
            cout << "| Editar senha da Conta: |" << endl;
            cout << "<------------------------>" << endl;
            cout << "Nova senha: ";
            cin >> stringSenha;

            try {
                senha.setSenha(stringSenha);
                conta.setSenha(senha);

                if (controladoraConta.atualizarConta(conta)) {
                    controladoraConta.consultarConta(conta);
                };

                cout << "\033[2J\033[1;1H";

                cout << "Senha editada com sucesso!" << endl;

                return "MENU_SERVICOS";
            } catch (invalid_argument& e) {
                cout << "<------------------------------------->" << endl;
                cout << " Alerta: " << e.what() << endl;
                cout << "<------------------------------------->" << endl;
                cin.ignore();
            }
        } else if (opcao == "3") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "MENU_SERVICOS";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }
    }

    return 0;
}

string TelaServicosConta::excluirConta(ControladoraServicoConta& controladoraConta, Conta& conta) {
    string opcao;

    while(true) {
        cout << "VOCE TEM CERTEZA QUE DESEJA EXCLUIR A SUA CONTA?:" << endl;
        cout << "1 - SIM, QUERO EXCLUIR MINHA CONTA. " << endl;
        cout << "2 - NAO, NAO QUERO EXCLUIR MINHA CONTA. " << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            controladoraConta.descadastrarConta(conta.getCpf());

            cout << "Conta excluida com sucesso." << endl;

            return "MAIN";
        } else if (opcao == "2") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "SERVICOS_CONTA";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }
    }

    return 0;
}

string TelaServicoTitulo::mostrarMenu(ControladoraServicoTitulo& controladoraTitulo, Conta& conta) {
    string opcao;

    while(true) {
        cout << "<------------------------------------->" << endl;
        cout << "| Titulos:                            |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "| 1 - Listar Titulos                  |" << endl;
        cout << "| 2 - Cadastrar novo titulo           |" << endl;
        cout << "| 3 - Editar Titulo                   |" << endl;
        cout << "| 4 - Excluir Titulo                  |" << endl;
        cout << "| 5 - Voltar                          |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            return infoTitulo(controladoraTitulo, conta);
        } else if (opcao == "2") {
            return incluirTitulo(controladoraTitulo, conta);
        } else if (opcao == "3") {
            return editarTitulo(controladoraTitulo, conta);
        } else if (opcao == "4") {
            return excluirTitulo(controladoraTitulo, conta);
        } else if (opcao == "5") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "MENU_SERVICOS";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }

    }

}

string TelaServicoTitulo::infoTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta) {
    list<Titulo> result;

    string opcao;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "Seus Titulos: " << endl;
        cout << "<------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            cout << "Titulo -- " << (index + 1) << endl;
            cout << "Codigo do Titulo: " << titulo.getCodigo().getCodigo() << endl;
            cout << "Emissor: " << titulo.getEmissor().getNome() << endl;
            cout << "Setor: " << titulo.getSetor().getSetor() << endl;
            cout << "Data de emissao: " << titulo.getEmissao().getData() << endl;
            cout << "Data de Vencimento: " << titulo.getVencimento().getData() << endl;
            cout << "Valor: R$" << titulo.getValor().getValor() << endl;
            cout << "<------------------------------------->" << endl;
        }

        cout << "1 - Voltar para tela anterior" << endl;
        cin >> opcao;

        cout << "\033[2J\033[1;1H";

        return "SERVICOS_TITULO";

        cout << "\033[2J\033[1;1H";
        cin.ignore();
    } else {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<--------------------------------------------->" << endl;
        cout << "| Alerta: Ainda nao ha Titulos cadastrados!   |" << endl;
        cout << "<--------------------------------------------->" << endl;

        return "SERVICOS_TITULO";
    };

    return 0;
}

string TelaServicoTitulo::incluirTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta) {
    string stringCodigoTitulo;
    string stringSetor;
    string stringEmissao;
    string stringVencimento;
    string stringValor;

    Codigo_de_titulo codigoTitulo;
    Setor setor;
    Data emissao;
    Data vencimento;
    Dinheiro valor;

    cout << "\033[2J\033[1;1H";
    cin.ignore();

    cout << "Cadastre um novo Titulo:" << endl;

    while(true) {
        cout << "Digite o codigo de Titulo (Exemplo de formato: CDBXXXXXXXX):" << endl;
        cin >> stringCodigoTitulo;

        try {
            codigoTitulo.setCodigo(stringCodigoTitulo);
            cin.ignore();
            break;
        } catch (invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    while(true) {
        cout << "<--------------------------------------------------------------->" << endl;
        cout << "Setores validos:" << endl;
        for (const std::string& setor : setor.getSetoresValidos()) {
            cout << setor << std::endl;
        }
        cout << "<--------------------------------------------------------------->" << endl;
        cout << "Digite o setor do Titulo:" << endl;
        getline(cin, stringSetor);

        try {
            setor.setSetor(stringSetor);
            break;
        } catch (invalid_argument& e) {
            cout << "<------------------------------------->" << endl;
            cout << " Alerta: " << e.what() << endl;
            cout << "<------------------------------------->" << endl;
        }
    }

    while(true) {
        cout << "Digite a data de Emissao do Titulo (Formato: dd-mm-aaaa):" << endl;
        cin >> stringEmissao;

        try {
            emissao.setData(stringEmissao);
            break;
        } catch (invalid_argument& e) {
            cout << "<------------------------------------->" << endl;
            cout << " Alerta: " << e.what() << endl;
            cout << "<------------------------------------->" << endl;
        }
    }

    while(true) {
        cout << "Digite a data de Vencimento do Titulo (Formato: dd-mm-aaaa):" << endl;
        cin >> stringVencimento;

        try {
            vencimento.setData(stringVencimento);
            break;
        } catch (invalid_argument& e) {
            cout << "<------------------------------------->" << endl;
            cout << " Alerta: " << e.what() << endl;
            cout << "<------------------------------------->" << endl;
        }
    }

    while(true) {
        cout << "Digite o valor do Titulo (Formato: apenas numero de 0 a 1.000.000,00):" << endl;
        cin >> stringValor;

        try {
            valor.setValor(stod(stringValor));
            break;
        } catch (invalid_argument& e) {
            cout << "<------------------------------------->" << endl;
            cout << " Alerta: " << e.what() << endl;
            cout << "<------------------------------------->" << endl;
        }
    }

    try {
        Titulo titulo;
        titulo.setCodigo(codigoTitulo);
        titulo.setSetor(setor);
        titulo.setEmissao(emissao);
        titulo.setVencimento(vencimento);
        titulo.setValor(valor);

        titulo.setEmissor(conta.getNome());
        titulo.setCpfEmissor(conta.getCpf());

        controladoraTitulo.cadastrarTitulo(titulo);

        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "Titulo cadastrado com sucesso!" << endl;
        return "SERVICOS_TITULO";
    } catch (invalid_argument& e) {
        cout << "<------------------------------------->" << endl;
        cout << " Alerta: " << e.what() << endl;
        cout << "<------------------------------------->" << endl;
        cin.ignore();
    }

    return 0;
}

string TelaServicoTitulo::editarTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta) {
    list<Titulo> result;

    string opcao;

    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "Seus Titulos: " << endl;
        cout << "<------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();

            cout << "<------------------------------------->" << endl;
            cout << "| Titulo -- " << (index + 1) << endl;
            cout << "| Codigo do Titulo: " << titulo.getCodigo().getCodigo() << endl;
            cout << "| Emissor: " << titulo.getEmissor().getNome() << endl;
            cout << "| Setor: " << titulo.getSetor().getSetor() << endl;
            cout << "| Data de emissao: " << titulo.getEmissao().getData() << endl;
            cout << "| Data de Vencimento: " << titulo.getVencimento().getData() << endl;
            cout << "| Valor: R$" << titulo.getValor().getValor() << endl;
            cout << "<------------------------------------->" << endl;
        }

        cout << "| Opcoes:                            |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "0 - Voltar para tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Editar Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";

                return "SERVICOS_TITULO";
            }

            if (mapTitulos.find(stoi(opcao)) != mapTitulos.end()) {
                string labelEdit;

                Codigo_de_titulo codigo;

                codigo.setCodigo(mapTitulos[stoi(opcao)]);

                cout << "\033[2J\033[1;1H";

                cout << "<---------------------------------------------------------->" << endl;
                cout << "  Titulo de codigo:" << mapTitulos[stoi(opcao)] << " selecionado.  " << endl;
                cout << "<---------------------------------------------------------->" << endl;
                cout << "| 1 - Editar Setor                                         |" << endl;
                cout << "| 2 - Editar Data de Emissao                               |" << endl;
                cout << "| 3 - Editar Data de Vencimento                            |" << endl;
                cout << "| 4 - Editar valor                                         |" << endl;
                cout << "| 5 - Voltar para a tela anterior                          |" << endl;
                cout << "<---------------------------------------------------------->" << endl;

                while (true) {
                    cout << "Opcao:";
                    cin >> labelEdit;

                    if (labelEdit == "1") {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();
                        string stringSetor;

                        Setor newSetor;

                        cout << "<--------------------------------------------------------------->" << endl;
                        cout << "Setores validos:" << endl;
                        for (const std::string& setor : newSetor.getSetoresValidos()) {
                            cout << setor << std::endl;
                        }
                        cout << "<--------------------------------------------------------------->" << endl;
                        cout << "Digite o novo setor do Titulo:" << endl;
                        getline(cin, stringSetor);

                        try {
                            newSetor.setSetor(stringSetor);

                            Titulo newTitulo;

                            newTitulo.setCodigo(codigo);

                            if (controladoraTitulo.consultarTitulo(newTitulo)) {
                                newTitulo.setSetor(newSetor);

                                controladoraTitulo.atualizarTitulo(newTitulo);
                            } else {
                                throw invalid_argument("Titulo nao encontrado!");
                            }

                            cout << "\033[2J\033[1;1H";
                            cout << "<------------------------------------->" << endl;
                            cout << "| Alerta: Titulo editado com sucesso! |" << endl;
                            cout << "<------------------------------------->" << endl;

                            return "SERVICOS_TITULO";
                        } catch (invalid_argument& e) {
                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: " << e.what() << endl;
                            cout << "<------------------------------------->" << endl;
                        }
                    } else if (labelEdit == "2") {
                        cout << "\033[2J\033[1;1H";
                        Data newEmissao;
                        string stringEmissao;

                        cout << "Digite a nova Data de Emissao:" << endl;
                        cin >> stringEmissao;

                        try {
                            newEmissao.setData(stringEmissao);

                            Titulo newTitulo;

                            newTitulo.setCodigo(codigo);

                            if (controladoraTitulo.consultarTitulo(newTitulo)) {
                                newTitulo.setEmissao(newEmissao);

                                controladoraTitulo.atualizarTitulo(newTitulo);
                            } else {
                                throw invalid_argument("Titulo nao encontrado!");
                            }

                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: Titulo editado com sucesso!   " << endl;
                            cout << "<------------------------------------->" << endl;

                            return "SERVICOS_TITULO";
                        } catch (invalid_argument& e) {
                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: " << e.what() << endl;
                            cout << "<------------------------------------->" << endl;
                        }
                    } else if (labelEdit == "3") {
                        cout << "\033[2J\033[1;1H";
                        Data newVencimento;
                        string stringVencimento;

                        cout << "<--------------------------------------------------------------->" << endl;
                        cout << "Digite a nova data de Vencimento:" << endl;
                        cin >> stringVencimento;

                        try {
                            newVencimento.setData(stringVencimento);

                            Titulo newTitulo;

                            newTitulo.setCodigo(codigo);

                            if (controladoraTitulo.consultarTitulo(newTitulo)) {
                                newTitulo.setVencimento(newVencimento);

                                controladoraTitulo.atualizarTitulo(newTitulo);
                            } else {
                                throw invalid_argument("Titulo nao encontrado!");
                            }

                            cout << "\033[2J\033[1;1H";

                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: Titulo editado com sucesso!   " << endl;
                            cout << "<------------------------------------->" << endl;

                            return "SERVICOS_TITULO";
                        } catch (invalid_argument& e) {
                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: " << e.what() << endl;
                            cout << "<------------------------------------->" << endl;
                        }
                    } else if (labelEdit == "4") {
                        cout << "\033[2J\033[1;1H";
                        Dinheiro newValor;
                        string stringValor;

                        cout << "<--------------------------------------------------------------->" << endl;
                        cout << "Digite o novo valor:" << endl;
                        cin >> stringValor;

                        try {
                            newValor.setValor(stod(stringValor));

                            Titulo newTitulo;

                            newTitulo.setCodigo(codigo);

                            if (controladoraTitulo.consultarTitulo(newTitulo)) {
                                newTitulo.setValor(newValor);

                                controladoraTitulo.atualizarTitulo(newTitulo);
                            } else {
                                throw invalid_argument("Titulo nao encontrado!");
                            }

                            cout << "\033[2J\033[1;1H";

                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: Titulo editado com sucesso!   " << endl;
                            cout << "<------------------------------------->" << endl;

                            return "SERVICOS_TITULO";
                        } catch (invalid_argument& e) {
                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: " << e.what() << endl;
                            cout << "<------------------------------------->" << endl;
                        }
                    } else if (labelEdit == "5") {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();

                        return "SERVICOS_TITULO";
                    } else {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();

                        cout << "<------------------------------------->" << endl;
                        cout << "| Alerta: Opcao invalida.              |" << endl;
                        cout << "<------------------------------------->" << endl;
                    }
                }
            } else {
               cout << "<------------------------------------------------------>" << endl;
               cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
               cout << "<------------------------------------------------------>" << endl;
            }
        }

        cout << "\033[2J\033[1;1H";

        return "SERVICOS_TITULO";

        cout << "\033[2J\033[1;1H";
        cin.ignore();
    } else {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<-------------------------------------------->" << endl;
        cout << "  Alerta: Ainda nao ha Titulos cadastrados!" << endl;
        cout << "<-------------------------------------------->" << endl;

        return "SERVICOS_TITULO";
    };

    return 0;
}

string TelaServicoTitulo::excluirTitulo(ControladoraServicoTitulo& controladoraTitulo, Conta& conta) {
    list<Titulo> result;

    string opcao;

    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "Seus Titulos: " << endl;
        cout << "<------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();

            cout << "<------------------------------------->" << endl;
            cout << "| Titulo -- " << (index + 1) << endl;
            cout << "| Codigo do Titulo: " << titulo.getCodigo().getCodigo() << endl;
            cout << "| Emissor: " << titulo.getEmissor().getNome() << endl;
            cout << "| Setor: " << titulo.getSetor().getSetor() << endl;
            cout << "| Data de emissao: " << titulo.getEmissao().getData() << endl;
            cout << "| Data de Vencimento: " << titulo.getVencimento().getData() << endl;
            cout << "| Valor: R$" << titulo.getValor().getValor() << endl;
            cout << "<------------------------------------->" << endl;
        }

        cout << "| Opcoes:                            |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "0 - Voltar para tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Excluir Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";

                return "SERVICOS_TITULO";
            }

            if (mapTitulos.find(stoi(opcao)) != mapTitulos.end()) {
                string labelEdit;

                Codigo_de_titulo codigo;

                codigo.setCodigo(mapTitulos[stoi(opcao)]);

                cout << "\033[2J\033[1;1H";

                cout << "<---------------------------------------------------------->" << endl;
                cout << "  Titulo de codigo:" << mapTitulos[stoi(opcao)] << " selecionado.  " << endl;
                cout << "<---------------------------------------------------------->" << endl;
                cout << "| TEM CERTEZA QUE DESEJA EXCLUIR O TITULO?                 |" << endl;
                cout << "|                                                          |" << endl;
                cout << "| 1 - SIM, QUERO EXCLUIR O TITULO.                         |" << endl;
                cout << "| 2 - NAO, NAO QUERO EXCLUIR O TITULO.                     |" << endl;
                cout << "|                                                          |" << endl;
                cout << "<---------------------------------------------------------->" << endl;

                while (true) {
                    cout << "Opcao:";
                    cin >> labelEdit;

                    if (labelEdit == "1") {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();

                        try {
                            controladoraTitulo.descadastrarTitulo(codigo);

                            cout << "<------------------------------------->" << endl;
                            cout << "| Alerta: Titulo excluido com sucesso |" << endl;
                            cout << "<------------------------------------->" << endl;

                            return "SERVICOS_TITULO";
                        } catch (invalid_argument& e) {
                            cout << "<------------------------------------->" << endl;
                            cout << " Alerta: " << e.what() << endl;
                            cout << "<------------------------------------->" << endl;
                        }
                    } else if (labelEdit == "2") {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();

                        cout << "<------------------------------------->" << endl;
                        cout << "| Alerta: Operacao cancelada.          |" << endl;
                        cout << "<------------------------------------->" << endl;

                        return "SERVICOS_TITULO";
                    } else {
                        cout << "\033[2J\033[1;1H";
                        cin.ignore();

                        cout << "<------------------------------------->" << endl;
                        cout << "| Alerta: Opcao invalida.              |" << endl;
                        cout << "<------------------------------------->" << endl;
                    }
                }
            } else {
               cout << "<------------------------------------------------------>" << endl;
               cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
               cout << "<------------------------------------------------------>" << endl;
            }
        }

        cout << "\033[2J\033[1;1H";

        return "SERVICOS_TITULO";

        cout << "\033[2J\033[1;1H";
        cin.ignore();
    } else {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<-------------------------------------------->" << endl;
        cout << "  Alerta: Ainda nao ha Titulos cadastrados!" << endl;
        cout << "<-------------------------------------------->" << endl;

        return "SERVICOS_TITULO";
    };

    return 0;
}

string TelaServicoPagamentos::mostrarMenu(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta) {
    string opcao;

    while(true) {
        cout << "<------------------------------------->" << endl;
        cout << "| Meus Pagamentos:                    |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "| 1 - Listar Pagamentos               |" << endl;
        cout << "| 2 - Cadastrar Novo Pagamento        |" << endl;
        cout << "| 3 - Editar Pagamento                |" << endl;
        cout << "| 4 - Excluir Pagamento               |" << endl;
        cout << "| 5 - Voltar                          |" << endl;
        cout << "<------------------------------------->" << endl;
        cout << "Opcao: ";
        cin >> opcao;

        if (opcao == "1") {
            return infoPagamento(controladoraTitulo, controladoraPagamento, conta);
        } else if (opcao == "2") {
            return incluirPagamento(controladoraTitulo, controladoraPagamento, conta);
        } else if (opcao == "3") {
            return editarPagamento(controladoraTitulo, controladoraPagamento, conta);
        } else if (opcao == "4") {
            return excluirPagamento(controladoraTitulo, controladoraPagamento, conta);
        } else if (opcao == "5") {
            cout << "\033[2J\033[1;1H";
            cin.ignore();

            return "MENU_SERVICOS";
        } else {
            cout << "Opcao invalida! Pressione Enter para tentar novamente." << endl;
            cin.ignore();
        }

    }
}

string TelaServicoPagamentos::infoPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta) {
    list<Titulo> result;

    string opcao;

    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<------------------------------------------------------------->" << endl;
        cout << "| Selecione o Titulo para listar os Pagamentos:               |" << endl;
        cout << "<------------------------------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();
        }

        cout << "0 - Voltar para a tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Listar Pagamentos para o Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<------------------------------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";

                return "SERVICOS_PAGAMENTOS";
            }

            cout << "\033[2J\033[1;1H";

            Codigo_de_titulo codigoTitulo;
            codigoTitulo.setCodigo(mapTitulos[stoi(opcao)]);

            list<Pagamento> pagamentos;

            if (controladoraPagamento.retornaPedidoPeloCodigoTitulo(codigoTitulo, pagamentos)) {

                if (pagamentos.empty()) {
                    cout << "\033[2J\033[1;1H";
                    cout << "<------------------------------------------------------------->" << endl;
                    cout << "| Alerta: Nao ha pagamentos para esse titulo                  |" << endl;
                    cout << "<------------------------------------------------------------->" << endl;
                    return "SERVICOS_PAGAMENTOS";
                }

                int indexPagamento = 0;

                cout << "<------------------------------------------------------>" << endl;
                cout << "| Pagamentos para o Titulo: " << codigoTitulo.getCodigo() << endl;

                for (list<Pagamento>::iterator elemento = pagamentos.begin(); elemento != pagamentos.end(); ++elemento, ++indexPagamento) {
                    Pagamento& pagamento = *elemento;

                    cout << "<------------------------------------->" << endl;
                    cout << "| Pagamento -- " << (indexPagamento + 1) << endl;
                    cout << "| Codigo do Pagamento: " << pagamento.getCodigo().getCodigo() << endl;
                    cout << "| Data: " << pagamento.getData().getData() << endl;
                    cout << "| Estado: " << pagamento.getEstado().getEstado() << endl;
                    cout << "| Percentual: " << pagamento.getPercentual().getvalor() << endl;
                    cout << "<------------------------------------->" << endl;
                }

                cout << "<------------------------------------->" << endl;
                cout << "| Opcoes:                              " << endl;
                cout << "|                                      " << endl;
                cout << "| 1 - Voltar                           " << endl;
                cout << "<------------------------------------->" << endl;

                while (true) {
                    string opcao;

                    cout << "Opcao:" << endl;
                    cin >> opcao;

                    if (opcao == "1") {
                        cout << "\033[2J\033[1;1H";

                        return "SERVICOS_PAGAMENTOS";
                    } else {
                        cout << "Opcao invalida, escolha outra!" << endl;
                    }
                }

            } else {
                if (pagamentos.empty()) {
                    cout << "\033[2J\033[1;1H";
                    cout << "<------------------------------------------------------------->" << endl;
                    cout << "| Alerta: Nao ha pagamentos para esse titulo                  |" << endl;
                    cout << "<------------------------------------------------------------->" << endl;
                    return "SERVICOS_PAGAMENTOS";
                }
            }
        }
    }

    return 0;
}

string TelaServicoPagamentos::incluirPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta) {
    list<Titulo> result;

    string opcao;

    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<-------------------------------------------------------------->" << endl;
        cout << "| Selecione o Titulo para lancar um Pagamento:                 |" << endl;
        cout << "<-------------------------------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();
        }

        cout << "0 - Voltar para a tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Incluir Pagamento para o Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<--------------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";

                return "SERVICOS_PAGAMENTOS";
            }

            if (mapTitulos.find(stoi(opcao)) != mapTitulos.end()) {
                cout << "\033[2J\033[1;1H";

                Codigo_de_titulo codigoTitulo;
                codigoTitulo.setCodigo(mapTitulos[stoi(opcao)]);

                while (true) {
                    CodigoPagamento codigoPagamento;
                    Data dataPagamento;
                    Percentual percentualPagamento;
                    Estado estadoPagamento;

                    string stringData;
                    string stringCodigoPagamento;
                    string stringPercentual;
                    string stringEstado;

                    cout << "Digite o codigo do pagamento (8 digitos):" << endl;
                    cin >> stringCodigoPagamento;

                    cout << "Digite a data do pagamento (dd-mm-aaaa):" << endl;
                    cin >> stringData;

                    cout << "Digite o percentual (0 a 100):" << endl;
                    cin >> stringPercentual;

                    cout << "Digite o Estado (Previsto, Liquidado ou Inadimplente):" << endl;
                    cin >> stringEstado;

                    codigoPagamento.setCodigo(stringCodigoPagamento);
                    dataPagamento.setData(stringData);
                    percentualPagamento.setValor(stoi(stringPercentual));
                    estadoPagamento.setEstado(stringEstado);

                    try {
                        Pagamento pagamento;
                        pagamento.setCodigo(codigoPagamento);
                        pagamento.setCodigoTitulo(codigoTitulo);
                        pagamento.setData(dataPagamento);
                        pagamento.setEstado(estadoPagamento);

                        controladoraPagamento.cadastrarPagamento(pagamento);

                        cout << "\033[2J\033[1;1H";

                        cout << "Pagamento incluido com sucesso!" << endl;

                        return "SERVICOS_PAGAMENTOS";
                    } catch (invalid_argument& e) {
                        cout << "<------------------------------------->" << endl;
                        cout << " Alerta: " << e.what() << endl;
                        cout << "<------------------------------------->" << endl;
                    }
                }

            } else {
                cout << "<------------------------------------------------------>" << endl;
                cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
                cout << "<------------------------------------------------------>" << endl;
            }
        }
    }

    return 0;
}

string TelaServicoPagamentos::editarPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta) {
    list<Titulo> result;
    string opcao;
    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "<-------------------------------------------------------------->" << endl;
        cout << "| Selecione o Titulo para editar um Pagamento:                 |" << endl;
        cout << "<-------------------------------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;
            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();
        }

        cout << "0 - Voltar para a tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Editar Pagamento para o Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<-------------------------------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";
                return "SERVICOS_PAGAMENTOS";
            }

            if (mapTitulos.find(stoi(opcao)) != mapTitulos.end()) {
                cout << "\033[2J\033[1;1H";

                Codigo_de_titulo codigoTitulo;
                codigoTitulo.setCodigo(mapTitulos[stoi(opcao)]);

                list<Pagamento> pagamentos;

                if (controladoraPagamento.retornaPedidoPeloCodigoTitulo(codigoTitulo, pagamentos)) {
                    if (pagamentos.empty()) {
                        cout << "\033[2J\033[1;1H";
                        cout << "Nao ha pagamentos para esse pedido!" << endl;
                        return "SERVICOS_PAGAMENTOS";
                    }

                    int indexPagamento = 0;
                    map<int, string> mapPagamentos;

                    cout << "<--------------------------------------------->" << endl;
                    cout << "| Pagamentos para o Titulo: " << codigoTitulo.getCodigo() << endl;

                    for (list<Pagamento>::iterator elemento = pagamentos.begin(); elemento != pagamentos.end(); ++elemento, ++indexPagamento) {
                        Pagamento& pagamento = *elemento;
                        mapPagamentos[(indexPagamento + 1)] = pagamento.getCodigo().getCodigo();

                        cout << "<--------------------------------------------->" << endl;
                        cout << "| Pagamento -- " << (indexPagamento + 1) << endl;
                        cout << "| Codigo do Pagamento: " << pagamento.getCodigo().getCodigo() << endl;
                        cout << "| Data: " << pagamento.getData().getData() << endl;
                        cout << "| Estado: " << pagamento.getEstado().getEstado() << endl;
                        cout << "| Percentual: " << pagamento.getPercentual().getvalor() << endl;
                        cout << "<--------------------------------------------->" << endl;
                    }

                    cout << "0 - Voltar para a tela anterior" << endl;
                    for (const auto& par : mapPagamentos) {
                        cout << par.first << " - Editar Pagamento de Codigo -> " << par.second << endl;
                    }

                    cout << "<--------------------------------------------->" << endl;

                    while (true) {
                        cout << "Opcao:" << endl;
                        cin >> opcao;

                        if (opcao == "0") {
                            cout << "\033[2J\033[1;1H";
                            return "SERVICOS_PAGAMENTOS";
                        }

                        if (mapPagamentos.find(stoi(opcao)) != mapPagamentos.end()) {
                            cout << "\033[2J\033[1;1H";
                            Pagamento newPagamento;

                            // Localiza o pagamento selecionado
                            for (list<Pagamento>::iterator elemento = pagamentos.begin(); elemento != pagamentos.end(); ++elemento) {
                                if (elemento->getCodigo().getCodigo() == mapPagamentos[stoi(opcao)]) {
                                    newPagamento = *elemento;
                                    break;
                                }
                            }

                            // Menu de edição
                            while (true) {
                                cout << "<------------------------------------->" << endl;
                                cout << "| Pagamento Selecionado: " << newPagamento.getCodigo().getCodigo() << endl;
                                cout << "<------------------------------------->" << endl;
                                cout << "| 1 - Editar Data                     |" << endl;
                                cout << "| 2 - Editar Estado                   |" << endl;
                                cout << "| 3 - Editar Percentual               |" << endl;
                                cout << "| 0 - Voltar                          |" << endl;
                                cout << "<------------------------------------->" << endl;
                                cout << "Opcao: ";
                                cin >> opcao;

                                string opcaoEdicao;
                                cout << "Opcao:" << endl;
                                cin >> opcaoEdicao;

                                if (opcaoEdicao == "0") {
                                    cout << "\033[2J\033[1;1H";
                                    return "SERVICOS_PAGAMENTOS";
                                }

                                if (opcaoEdicao == "1") {
                                    string novaData;
                                    cout << "Digite a nova Data do Pagamento (dd-mm-aaaa):" << endl;
                                    cin >> novaData;

                                    Data data;
                                    data.setData(novaData);

                                    newPagamento.setData(data);
                                } else if (opcaoEdicao == "2") {
                                    string novoEstado;
                                    cout << "Digite o novo Estado do Pagamento (Previsto, Liquidado ou Inadimplente):" << endl;
                                    cin >> novoEstado;

                                    Estado estado;
                                    estado.setEstado(novoEstado);

                                    newPagamento.setEstado(estado);
                                } else if (opcaoEdicao == "3") {
                                    string novoPercentual;
                                    cout << "Digite o novo Percentual (0 a 100):" << endl;
                                    cin >> novoPercentual;

                                    Percentual percentual;
                                    percentual.setValor(stoi(novoPercentual));

                                    newPagamento.setPercentual(percentual);
                                } else {
                                    cout << "Opcao invalida, por favor escolha novamente." << endl;
                                    continue;
                                }

                                try {
                                    controladoraPagamento.atualizarPagamento(newPagamento);
                                    cout << "\033[2J\033[1;1H";
                                    cout << "Pagamento atualizado com sucesso!" << endl;
                                    return "SERVICOS_PAGAMENTOS";
                                } catch (invalid_argument& e) {
                                    cout << "<------------------------------------->" << endl;
                                    cout << " Alerta: " << e.what() << endl;
                                    cout << "<------------------------------------->" << endl;
                                }
                            }

                        } else {
                            cout << "<------------------------------------------------------>" << endl;
                            cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
                            cout << "<------------------------------------------------------>" << endl;
                        }
                    }
                } else {
                    if (pagamentos.empty()) {
                        cout << "\033[2J\033[1;1H";
                        cout << "<------------------------------------------------------------->" << endl;
                        cout << "| Alerta: Nao ha pagamentos para esse titulo                  |" << endl;
                        cout << "<------------------------------------------------------------->" << endl;
                        cout << "Nao ha pagamentos para esse pedido!" << endl;
                        return "SERVICOS_PAGAMENTOS";
                    }
                }
            } else {
                cout << "<------------------------------------------------------>" << endl;
                cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
                cout << "<------------------------------------------------------>" << endl;
            }
        }
    }

    return 0;
}

string TelaServicoPagamentos::excluirPagamento(ControladoraServicoTitulo& controladoraTitulo, ControladoraServicoPagamento& controladoraPagamento, Conta& conta) {
    list<Titulo> result;

    string opcao;

    map<int, string> mapTitulos;

    if (controladoraTitulo.retornaTituloPeloEmissor(conta.getCpf(), result)) {
        cout << "\033[2J\033[1;1H";
        cin.ignore();

        cout << "Selecione o Titulo para listar e remover os Pagamentos: " << endl;
        cout << "<--------------------------------------------->" << endl;

        int index = 0;

        for (list<Titulo>::iterator elemento = result.begin(); elemento != result.end(); ++elemento, ++index) {
            Titulo& titulo = *elemento;

            mapTitulos[(index + 1)] = titulo.getCodigo().getCodigo();
        }

        cout << "0 - Voltar para a tela anterior" << endl;

        for (const auto& par : mapTitulos) {
            cout << par.first << " - Listar e Remover Pagamentos para o Titulo de Codigo -> " << par.second << endl;
        }

        cout << "<--------------------------------------------->" << endl;

        while (true) {
            cout << "Opcao:" << endl;
            cin >> opcao;

            if (opcao == "0") {
                cout << "\033[2J\033[1;1H";
                return "SERVICOS_PAGAMENTOS";
            }

            if (mapTitulos.find(stoi(opcao)) != mapTitulos.end()) {
                cout << "\033[2J\033[1;1H";

                Codigo_de_titulo codigoTitulo;
                codigoTitulo.setCodigo(mapTitulos[stoi(opcao)]);

                list<Pagamento> pagamentos;

                if (controladoraPagamento.retornaPedidoPeloCodigoTitulo(codigoTitulo, pagamentos)) {
                    if (pagamentos.empty()) {
                        cout << "\033[2J\033[1;1H";
                        cout << "Nao ha pagamentos para esse pedido!" << endl;
                        return "SERVICOS_PAGAMENTOS";
                    }

                    int indexPagamento = 0;
                    map<int, string> mapPagamentos;

                    cout << "<------------------------------------->" << endl;
                    cout << "| Pagamentos para o Titulo: " << codigoTitulo.getCodigo() << endl;

                    for (list<Pagamento>::iterator elemento = pagamentos.begin(); elemento != pagamentos.end(); ++elemento, ++indexPagamento) {
                        Pagamento& pagamento = *elemento;

                        mapPagamentos[(indexPagamento + 1)] = pagamento.getCodigo().getCodigo();

                        cout << "<------------------------------------->" << endl;
                        cout << "| Pagamento -- " << (indexPagamento + 1) << endl;
                        cout << "| Codigo do Pagamento: " << pagamento.getCodigo().getCodigo() << endl;
                        cout << "| Data: " << pagamento.getData().getData() << endl;
                        cout << "| Estado: " << pagamento.getEstado().getEstado() << endl;
                        cout << "| Percentual: " << pagamento.getPercentual().getvalor() << endl;
                        cout << "<------------------------------------->" << endl;
                    }

                    cout << "0 - Voltar para a tela anterior" << endl;
                    for (const auto& par : mapPagamentos) {
                        cout << par.first << " - Remover Pagamento de Codigo -> " << par.second << endl;
                    }

                    cout << "<--------------------------------------------->" << endl;

                    while (true) {
                        cout << "Opcao:" << endl;
                        cin >> opcao;

                        if (opcao == "0") {
                            cout << "\033[2J\033[1;1H";
                            return "SERVICOS_PAGAMENTOS";
                        }

                        if (mapPagamentos.find(stoi(opcao)) != mapPagamentos.end()) {
                            cout << "\033[2J\033[1;1H";
                            Pagamento pagamento;

                            // Localiza o pagamento selecionado
                            for (list<Pagamento>::iterator elemento = pagamentos.begin(); elemento != pagamentos.end(); ++elemento) {
                                if (elemento->getCodigo().getCodigo() == mapPagamentos[stoi(opcao)]) {
                                    pagamento = *elemento;
                                    break;
                                }
                            }

                            cout << "Tem certeza que deseja remover o pagamento de codigo " << pagamento.getCodigo().getCodigo() << "?" << endl;
                            cout << "1 - SIM, TENHO CERTEZA. " << endl;
                            cout << "2 - NAO, CANCELAR OPERACAO " << endl;
                            string confirmacao;
                            cin >> confirmacao;

                            if (confirmacao == "1") {
                                try {
                                    controladoraPagamento.descadastrarPagamento(pagamento.getCodigo());
                                    cout << "\033[2J\033[1;1H";
                                    cout << "Pagamento removido com sucesso!" << endl;
                                    return "SERVICOS_PAGAMENTOS";
                                } catch (invalid_argument& e) {
                                    cout << "<------------------------------------->" << endl;
                                    cout << " Alerta: " << e.what() << endl;
                                    cout << "<------------------------------------->" << endl;
                                }
                            } else {
                                cout << "\033[2J\033[1;1H";
                                cout << "<------------------------------------------------------>" << endl;
                                cout << "| Alerta: Operacao cancelada                           |" << endl;
                                cout << "<------------------------------------------------------>" << endl;
                                return "SERVICOS_PAGAMENTOS";
                            }
                        } else {
                            cout << "<------------------------------------------------------>" << endl;
                            cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
                            cout << "<------------------------------------------------------>" << endl;
                        }
                    }
                } else {
                    if (pagamentos.empty()) {
                        cout << "\033[2J\033[1;1H";
                        cout << "<------------------------------------------------------------->" << endl;
                        cout << "| Alerta: Nao ha pagamentos para esse titulo                  |" << endl;
                        cout << "<------------------------------------------------------------->" << endl;
                        return "SERVICOS_PAGAMENTOS";
                    }
                }
            } else {
                cout << "<------------------------------------------------------>" << endl;
                cout << "| Alerta: Opcao nao existe, por favor, escolha outra   |" << endl;
                cout << "<------------------------------------------------------>" << endl;
            }
        }
    }

    return 0;
}

