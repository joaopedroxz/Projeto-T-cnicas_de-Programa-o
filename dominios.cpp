#include "dominios.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>
#include <functional>
#include <algorithm>

using namespace std;

// Classes implementadas por Daniel Filipe Silva Miguel - 231006112
// Função split, retorna um array com todas as palavras separadas por espaços em branco
vector<string> Nome::split(string s)
{
    vector<string> strings_separadas;

    string string_atual;

    for (size_t j = 0; j < s.length(); j++)
    {

        if (s[j] == ' ')
        {
            strings_separadas.push_back(string_atual);
            string_atual = "";
            continue;
        }

        string_atual += s[j];

        if (j == (s.length() - 1))
        {
            strings_separadas.push_back(string_atual);
        }
    }

    return strings_separadas;
}


bool Nome::validar(string nome)
{
    vector<string> string_separada = split(nome);

    if (nome.empty()) throw invalid_argument("O nome nao pode estar vazio");

    for (size_t j = 0; j < nome.length(); j++)
    {
        if (isdigit(nome[j]))
        {
            throw invalid_argument("O nome deve ter apenas letras de A-Z ou a-z");
        }
    }

    if (string_separada.size() > 2) {
       throw invalid_argument("Escreva no maximo dois termos");
    }

    for (string termo : string_separada) {
        if (termo.length() < 3 || termo.length() > 10) {
            throw invalid_argument("Os termos devem ter no minimo 3 caracteres e no maximo 10");
        }

        if (!isupper(termo[0])) {
            throw invalid_argument("A inicial dos termos deve ser maiuscula");
        }
    }

    return true;
}


void Nome::setNome(string nome)
{
    validar(nome);
    this->nome = nome;
}


string Nome::getNome()
{
    return nome;
}


bool Senha::validar(string senha)
{
    if (senha.length() == 0) throw invalid_argument("A senha nao pode estar vazia");

    if (senha.length() != 6) throw invalid_argument("A senha deve ter 6 digitos");

    for (size_t j = 0; j < senha.length(); j++)
    {
        if (!isdigit(senha[j]))
        {
            throw invalid_argument("A senha deve conter apenas digitos de 0-9");
        }
    }

    if (senha[0] == '0') {
       throw invalid_argument("O primeiro digito pode ser diferente de zero");
    }

    for (size_t i = 0; i < senha.length(); i++)
    {
        char digito_atual = senha[i];

        for (size_t j = i + 1; j < senha.length(); j++)
        {
          if (digito_atual == senha[j])
          {
              throw invalid_argument("A senha nao pode ter digitos repetidos");
          }
        }
    }

    bool is_crescente = true;
    for (size_t i = 1; i < senha.length(); i++) {
        if (senha[i] < senha[i - 1]) {
            is_crescente = false;
            break;
        }
    }

    bool is_decrescente = true;
    for (size_t i = 1; i < senha.length(); i++) {
        if (senha[i] > senha[i - 1]) {
            is_decrescente = false;
            break;
        }
    }

    if (is_crescente || is_decrescente) throw invalid_argument("A senha nao pode ser sequência de digitos em ordem crescente ou decrescente");

    return true;
}


void Senha::setSenha(string senha)
{
    validar(senha);
    this->senha = senha;
}


string Senha::getSenha()
{
    return this->senha;
}


/// Classes implementadas por João Pedro Sousa Vasconcelos - 231021478
bool Data::AnoBissexto(int ano) const{
    return (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
}


bool Data::DataValida(int d, int m, int a) const{
    if (d < 1 || d > 31) {
        return false;
    }
    if (m < 1 || m > 12){
        return false;
    }
    if (a < 2000 || a > 2100){
        return false;
    }
    if (m == 2){
        if (AnoBissexto(a)) {
            return d <= 29;
        } else {
            return d <= 28;
        }
    } else if (m == 4 || m == 6 || m == 9 || m == 11) {
        return d <= 30;
    }
    return true;
}


bool Data::validarFormatoData(const string& data_string, int &d, int &m, int &a) const{
    if (sscanf(data_string.c_str(), "%d-%d-%d", &d, &m, &a) != 3) {
        return false;
    }
    return true;
}


void Data::setDia(int d) {
    if (d < 1 || d > 31) {
        throw invalid_argument("Dia invalido.");
    }
    dia = d;
}


void Data::setMes(int m) {
    if (DataValida(dia, m, ano)==false) {
        throw invalid_argument("Formato demmm data invalido.");
    }
    mes = m;
}


void Data::setAno(int a) {
    if (DataValida(dia, mes, a)==false)
        throw invalid_argument("Formato deaaa data invalido.");
    ano = a;
}


int Data::getDia() const {
    return dia;
}


int Data::getMes() const {
    return mes;
}


int Data::getAno() const {
    return ano;
}


void Data::setData(int d, int m, int a) {
    if (DataValida(d, m, a)==false) {
        if (d < 1 || d > 31) {
            throw invalid_argument("Dia invalido.");
        }
        if (m < 1 || m > 12) {
            throw invalid_argument("Mes invalido.");
        }
        if (a < 2000 || a > 2100) {
            throw invalid_argument("Ano invalido.");
        }
        throw invalid_argument("Data invalida.");
    }
    dia = d;
    mes = m;
    ano = a;
}


void Data::setData(const string& data_string) {
    int d, m, a;
    if (validarFormatoData(data_string, d , m, a) == false) {
        throw invalid_argument("Formato de data invalido.");
    }
    setData(d, m, a);
}


string Data::getData() {
    string dia = to_string(this->getDia());
    string mes = to_string(this->getMes());
    string ano = to_string(this->getAno());

    return dia + "-" + mes + "-" + ano;
}


void Estado::setEstado(const string& newEstado) {
    if (newEstado != "Previsto" && newEstado != "Liquidado" && newEstado != "Inadimplente")
        throw invalid_argument("Estado invalido.");
    estado = newEstado;
}


string Estado::getEstado() const {
    return estado;
}


void Estado::mostrarEstado() const {
    cout << "Estado: " << estado << endl;
}


/// Classes implementadas por Jonata Barbosa Severo - 231021342
void CodigoPagamento::validar(const string& codigo) {
    if (codigo.length() != 8) {
        throw invalid_argument("Codigo de pagamento invalido");
    }
    if (codigo[0] < '1' || codigo[0] > '9') {
        throw invalid_argument("Codigo de pagamento invalido");
    }
    for (size_t i = 1; i < codigo.length(); ++i) {
        if (codigo[i] < '0' || codigo[i] > '9') {
            throw invalid_argument("Codigo de pagamento invalido");
        }
    }
}


void CodigoPagamento::setCodigo(const string& codigo) {
    validar(codigo);
    this->codigo = codigo;
}


string CodigoPagamento::getCodigo() const {
    return codigo;
}


void Setor::setSetor(const string& nome) {
    if (find(secoes_validas.begin(), secoes_validas.end(), nome) == secoes_validas.end()) {
        throw invalid_argument("Secao invalida");
    }
    this->nome = nome;
}


string Setor::getSetor() const {
    return nome;
}


vector<string> Setor::getSetoresValidos() {
    return secoes_validas;
}


/// Classes implementadas por Roberth Nascimento de Jesus - Madricula 231021487
void Codigo_de_titulo::validar(string novoCodigo) // verifica_
{
    if (novoCodigo.length() != 11)
    {
        throw invalid_argument("Formato inválido: deve ter 11 caracteres");
    }

    string prefixo = novoCodigo.substr(0, 3);
    if (prefixo != "CDB" && prefixo != "CRA" && prefixo != "CRI" && prefixo != "LCA" && prefixo != "LCI" && prefixo != "DEB")
    {
        throw invalid_argument("Formato inválido: prefixo incorreto");
    }

    for (size_t i = 3; i < novoCodigo.length(); ++i)
    {
        if (!isupper(novoCodigo[i]) && !isdigit(novoCodigo[i]))
        {
            throw invalid_argument("Formato inválido: caracteres após o prefixo devem ser letras maiúsculas de A-Z ou números de 0-9");
        }
    }
}


void Codigo_de_titulo::setCodigo(string novoCodigo)
{
    validar(novoCodigo);
    this->codigo = novoCodigo;
}


string Codigo_de_titulo::getCodigo()
{
    return this->codigo;
}


int Percentual::validar(int num)
{
    for(int i = 0; i<=100; i++)
    {
        if (num == i)
        {
            return num;
        }
    }

    throw invalid_argument("Percentual errado fora do intervalo de 0 ate 100");
}


void Percentual::setValor(int num)
{
    validar(num);
    numero = num;
}


int Percentual::getvalor()
{
    return numero;
}


/// Classe implementada por Yuri Arruda Andrade Da SIlva - Matrícula 231006210
void Cpf::setNumero(string cpf){
    cpf.erase(remove(cpf.begin(), cpf.end(), '.'), cpf.end());
    cpf.erase(remove(cpf.begin(), cpf.end(), '-'), cpf.end());

    if (!verificar_cpf(cpf))
    {
        throw invalid_argument("CPF invalido!");
    };

    this->numero = cpf;
}


bool Cpf::verificar_cpf(string cpf) {
    if (cpf.length() != 11)
        return false;

    for (int i = 9; i <= 10; i++) {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += (cpf[j] - '0') * (i+1-j);
        int verifyingDigit = sum % 11;
        if (verifyingDigit < 2)
            verifyingDigit = 0;
        else
            verifyingDigit = 11 - verifyingDigit;

        if (cpf[i]- '0' != verifyingDigit)
            return false;
    }
    return true;
}


string Cpf::getNumero(){
    return this-> numero;
}


Dinheiro::Dinheiro() {
    valor = 0;
}


void Dinheiro::validar(double valor) {
    if (valor <= 0 || valor > 1000000) {
        throw std::invalid_argument("Valor fora dos padrões permitidos (fora do limite).");
    }
}


void Dinheiro::setValor(double novoValor) {
    validar(novoValor);
    valor = novoValor;
}


double Dinheiro::getValor() const {
    return valor;
}
