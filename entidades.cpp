#include "entidades.h"
#include "dominios.h"

using namespace std;

void Conta::setCpf (const Cpf& cpf) {
    this->cpf = cpf;
}

Cpf Conta::getCpf() {
    return this->cpf;
}

void Conta::setNome (const Nome& nome) {
    this->nome = nome;
}

Nome Conta::getNome() {
    return this->nome;
}

void Conta::setSenha (const Senha& senha) {
    this->senha = senha;
}

Senha Conta::getSenha() {
    return this->senha;
}

void Titulo::setCodigo(const Codigo_de_titulo& codigo) {
    this->codigoTitulo = codigo;
}

Codigo_de_titulo Titulo::getCodigo() {
    return this->codigoTitulo;
}

void Titulo::setEmissor(const Nome& emissor) {
    this->emissor = emissor;
}

Nome Titulo::getEmissor() {
    return this->emissor;
}

void Titulo::setSetor(const Setor& setor) {
    this->setor = setor;
}

Setor Titulo::getSetor() {
    return this->setor;
}

void Titulo::setEmissao(const Data& emissao) {
    this->emissao = emissao;
}

Data Titulo::getEmissao() {
    return this->emissao;
}

void Titulo::setVencimento(const Data& vencimento) {
    this->vencimento = vencimento;
}

Data Titulo::getVencimento() {
    return this->vencimento;
}

void Titulo::setValor(const Dinheiro& valor) {
    this->valor = valor;
}

Dinheiro Titulo::getValor() {
    return this->valor;
}

void Titulo::setCpfEmissor(const Cpf& cpf) {
    this->cpfEmissor = cpf;
}

Cpf Titulo::getCpfEmissor() {
    return this->cpfEmissor;
}

void Pagamento::setCodigo(const CodigoPagamento& codigo) {
    this->codigo = codigo;
}

CodigoPagamento Pagamento::getCodigo() {
    return this->codigo;
}

void Pagamento::setData(const Data& data) {
    this->data = data;
}

Data Pagamento::getData() {
    return this->data;
}

void Pagamento::setPercentual(const Percentual& percentual) {
    this->percentual = percentual;
}

Percentual Pagamento::getPercentual() {
    return this->percentual;
}

void Pagamento::setEstado(const Estado& estado) {
    this->estado = estado;
}

Estado Pagamento::getEstado() {
    return this->estado;
}

void Pagamento::setCodigoTitulo(const Codigo_de_titulo& codigoTitulo) {
    this->codigoTituloAssociado = codigoTitulo;
}

Codigo_de_titulo Pagamento::getCodigoTitulo() {
    return this->codigoTituloAssociado;
}
