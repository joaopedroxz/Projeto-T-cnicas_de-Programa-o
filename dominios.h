#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED

#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

using namespace std;

/**
 * @class Nome
 * @brief Classe que representa um nome - Implementado por Daniel Filipe Silva Miguel - 231006112
 *
 * Esta classe encapsula o conceito de um nome, oferecendo métodos para validação
 * e obtenção do valor do nome.
 */
class Nome {
private:
    string nome; /**< O próprio nome armazenado como string. */

    /**
     * @brief Função privada para validar um nome.
     *
     * @param nome O nome a ser validado.
     * @return true se o nome é válido, false caso contrário.
     */
    bool validar(string nome);

    /**
     * @brief Função privada para dividir uma string em substrings.
     *
     * Esta função auxiliar divide uma string em substrings com base em espaços em branco.
     *
     * @param s A string a ser dividida.
     * @return Um vetor contendo as substrings.
     */
    vector<string> split(string s);

public:
    /**
     * @brief Define o valor do nome.
     *
     * Este método atribui um valor ao nome após validá-lo.
     *
     * @param nome O nome a ser atribuído.
     */
    void setNome(string nome);

    /**
     * @brief Obtém o valor atual do nome.
     *
     * @return O nome atual armazenado na instância.
     */
    string getNome();
};


/**
 * @class Senha
 * @brief Classe que representa uma senha - Implementado por Daniel Filipe Silva Miguel - 231006112
 *
 * Esta classe encapsula o conceito de uma senha, oferecendo métodos para validação
 * e obtenção do valor da senha.
 */
class Senha {
private:
    string senha; /**< A própria senha armazenada como string. */

    /**
     * @brief Função privada para validar uma senha.
     *
     * @param senha A senha a ser validada.
     * @return true se a senha é válida e uma excessão caso contrário.
     */
    bool validar(string senha);

public:
    /**
     * @brief Define o valor da senha.
     *
     * Este método atribui um valor à senha após validá-la.
     *
     * @param senha A senha a ser atribuída.
     */
    void setSenha(string senha);

    /**
     * @brief Obtém o valor atual da senha.
     *
     * @return A senha atual armazenada na instância.
     */
    string getSenha();
};


/// @class Data
/// @brief Classe que representa um Data - Implementado por João Pedro Sousa Vasconcelos - 231021478
///
/// Classe de validacao de data, verifica o dia, mes e ano se esta dentro dos formatos de data
/// Regras de formato:
///     - Formato DD-MM-AAAA
///     - DD - 00 a 31
///     - MM - 01 a 12
///     - AAAA - 2000 a 2100
///
class Data {
private:
    int dia, mes, ano;
    ///
    /// Funcao que verifica se o ano e bissexto
    /// @param ano
    ///
    bool AnoBissexto(int ano) const;
    ///
    /// Funcao que valida a data
    /// @param d @param m @param a
    ///
    bool DataValida(int d, int m, int a) const;
    ///
    /// Funcao que valida se a data esta no formato correto
    /// @param data_string @param d @param m @param a
    ///
    bool validarFormatoData(const string& data_string, int &d, int &m, int &a) const;
public:
    ///
    /// Recebe no parametro 'd' o dia e verifica se esta valido, caso contraio eh lancado execcao
    /// @param d
    ///
    void setDia(int d);
    ///
    /// Recebe no parametro 'm' o mes e verifica se esta valido, caso contraio eh lancado execcao
    /// @param m
    ///
    void setMes(int m);
    ///
    /// Recebe no parametro 'a' o ano e verifica se esta valido, caso contrario eh lancado execcao
    /// @param a
    ///
    void setAno(int a);
    ///
    /// Acessa o codigo referente ao dia e retorna
    /// @return dia
    ///
    int getDia() const;
    ///
    /// Acessa o codigo referente ao mes e retorna
    /// @return mes
    ///
    int getMes() const;
    ///
    /// Acessa o codigo referente ao ano e retorna
    /// @return ano
    ///
    int getAno() const;
    ///
    /// Recebe a data
    /// @param d @param m @param a
    ///
    void setData(int d, int m, int a);
    ///
    /// Recebe a data em seu formato de string
    /// @param data
    void setData(const string& data);
    ///
    /// Retorna a data completa
    ///
    string getData();
};


///
/// @brief Classe de validacao de estado, verifica se o estado informado esta dentro dos estados propostos - Implementado por João Pedro Sousa Vasconcelos - 231021478
/// Regras de validacao:
///    - Previsto
///    - Liquidado
///    - Inadimplente
class Estado {
private:
    string estado;
public:
    ///
    /// Recebe uma string que sera validada de acordo com as regras caso nao seja validada uma execcao eh lancada
    /// @param newEstado
    ///
    void setEstado(const string& newEstado);
    ///
    /// Metodo que retorna o estado informado apos a validacao
    /// @return estado
    ///
    string getEstado() const;
    ///
    /// Metodo que imprimi o estado apos validacao
    ///
    void mostrarEstado()const;
};


///
///@class CodigoPagamento - Implementado por Jonata Barbosa Severo - 231021342
///@brief Classe para representar um codigo de pagamento.
///
class CodigoPagamento {
private:
    string codigo;

    ///
    ///@brief Valida o codigo de pagamento.
    ///@param codigo Codigo de pagamento a ser validado.
    ///@throw std::invalid_argument Se o codigo for invalido.
    ///
    void validar(const string& codigo);

public:
    ///
    ///@brief Define o codigo de pagamento.
    ///
    void setCodigo(const string& codigo);

    ///
    ///@brief Obtém o codigo de pagamento.
    ///@return O codigo de pagamento.
    ///
    string getCodigo() const;
};


///
///@brief Classe para representar uma Setor - Implementado por Jonata Barbosa Severo - 231021342
///
///Define as varias secoes disponiveis para categorizacao.
///
class Setor {
private:
    string nome; /**< Nome da secao */

    vector<string> secoes_validas = { /**< Lista de secoes validas */
        "Agricultura", "Construcao civil", "Energia", "Financas", "Imobiliario",
        "Papel e celulose", "Pecuaria", "Quimica e petroquimica", "Metalurgia e siderurgia", "Mineracao"
    };

public:
    ///
    ///@brief Define o nome da secao.
    ///
    ///@param nome Novo nome da secao a ser definido.
    ///@throw std::invalid_argument Se o nome fornecido nao estiver na lista de secoes validas.
    ///
    void setSetor(const string& nome);

    ///
    ///@brief Obtem o nome da secao atual.
    ///
    ///@return std::string O nome da secao atual.
    ///
    string getSetor() const;

    vector<string> getSetoresValidos();
};


///
/// @brief Classe de validacao usado para verificar se o codigo de titulo fornecido esta dentro das regras - Implementada por Roberth Nascimento de Jesus - Madricula 231021487
///
/// Regras de formato:
/// - 3 primeiros prefixos dos tipos; CDB,CRA,CRI,LCA,LCI,DEB;
/// - 9 caracteres com letras maiusculas (A-Z) ou numeros inteiros entre (0-9).
///
class Codigo_de_titulo
{
private:
    string codigo;
public:
///
/// Recebe um valor de codigo pede a avaliacao do codigo de titulo, adiciona e atualiza o valor do parametro caso seja um valor valido
/// @param novoCodigo
///

    void setCodigo(string novoCodigo);

///
/// Acessa o codigo fornecido caso ele tenha sido armazenado devidamente
/// @return codigo
///

    string getCodigo();

///
/// Codigo responsavel pela validacao. Em caso de codigo invalido lanca excecoes de acordo com as regras da classe.
///

    void validar(string novoCodigo);
};



/// @brief Classe de validacao usado para verificar se o percentual de pagamento fornecido esta dentro das regras - Implementada por Roberth Nascimento de Jesus - Madricula 231021487
///
/// Regras de formato:
/// - valor inteiro de 0 a 100.
///
class Percentual
{
private:
    int numero;
public:

///
/// Pede a avaliacao do numero fornecido, adiciona e atualiza o valor do percentual
/// @param numero
///
    void setValor(int numero);

///
/// Acessa o numero fornecido
/// @return codigo
///
    int getvalor();

///
/// Valida ou lanca excecoes de acordo com as regras da classe, verifica se o percentual de pagamento e valido
///
    int validar(int numero);
};


///
///
///@brief CLasse que lê o CPF - Implementada por Yuri Arruda Andrade Da SIlva - Matrícula 231006210
///Classe para ler e verificar se o formato do cpf fornecido atende as regras oficiais ao mesmo tempo que verifica se o cpf realmente existe de acordo com os cálculos dos digitos verificadores
///
///regras:
///-Ter 11 digitos sendo os dois ultimos os digitos que serão usados para validação do cpf
///-São aceitos tanto escritos com "." e "-" quanto sem nenhuma pontuação
///-Não ser usadas letras ou outros pontos no meio do CPF
///
///
class Cpf{
private:
    string numero;

public:
    string getNumero();
    ///
    ///Registra o número do cpf, tirando os traços e pontos se forem fornecidos
    ///@param cpf Número do cpf como uma string
    ///
    ///
    void setNumero(string cpf);
    ///
    ///Faz a verificação se o número do cpf atende os requisitos das regfas
    ///@return True se for validado ou False se não passar nos testes de validação
    ///
    ///
    bool verificar_cpf(string cpf);
};


/// @brief Classe para ler e armazenar um valor monetário - Implementada por Yuri Arruda Andrade Da SIlva - Matrícula 231006210
///
/// A regra é:
///
/// -Adicionar um valor que esteja no intervalo de 0 a 1000000,00 de reais
///
///
class Dinheiro {
private:
    double valor;

public:
    ///
    ///
    ///  Construtor que inicializa com o valor 0
    ///
    ///
    Dinheiro();
    ///
    ///
    ///  @param novoValor Valor que vai ser atribuido pelo usuário
    ///
    ///  @throw std::invalid_argument Se o valor estiver fora dos limites impostos pelas regras.
    ///
    ///
    void setValor(double novoValor);
    ///
    ///
    /// Retorna o valor monetário
    ///
    /// @return Valor em reais
    ///
    ///
    double getValor() const;
    void validar(double valor);
};

#endif // DOMINIOS_H_INCLUDED

/*! \mainpage BIBLIOTECA DE CLASSES - TECNICAS DE PROGRAMACAO 1
 *
 *  Membros do grupo:
 *
 *      -> Daniel Filipe Silva Miguel - 231006112
 *
 *      -> Joao Pedro Sousa Vasconcelos - 231021478
 *
 *      -> Jonata Barbosa Severo - 231021342
 *
 *      -> Roberth Nascimento de Jesus - 231021487
 *
 *      -> Yuri Arruda Andrade Da Silva - 231006210
 */
