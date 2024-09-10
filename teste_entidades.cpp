#include "testes_entidades.h"


void TUConta::testeSucesso ()
{
    estado = SUCESSO;
    Conta conta;

    try
    {
        conta.setCpf(CPF_VALIDO);
        conta.setNome(NOME_VALIDO);
        conta.setSenha(SENHA_VALIDA);

        if (conta.getCpf() != CPF_VALIDO)
            estado = FALHA;


        if (conta.getNome() != NOME_VALIDO)
            estado = FALHA;


        if (conta.getSenha() != SENHA_VALIDA)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUTitulo::testeSucesso ()
{
    estado = SUCESSO;
    Titulo titulo;

    try
    {
        titulo.setCodigo(CODIGO_TITULO_VALIDO);
        titulo.setEmissor(NOME_VALIDO);
        titulo.setEmissao(DATA_EMISSAO_VALIDO);
        titulo.setVencimento(DATA_VENCIMENTO_VALIDO);
        titulo.setSetor(SETOR_VALIDO);
        titulo.setValor(VALOR_VALIDO);

        if (titulo.getCodigo() != CODIGO_TITULO_VALIDO)
            estado = FALHA;

        if (titulo.getEmissor() != NOME_VALIDO)
            estado = FALHA;

        if (titulo.getEmissao() != DATA_EMISSAO_VALIDO)
            estado = FALHA;

        if (titulo.getVencimento() != DATA_VENCIMENTO_VALIDO)
            estado = FALHA;

        if (titulo.getSetor() != SETOR_VALIDO)
            estado = FALHA;

        if (titulo.getValor() != VALOR_VALIDO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}

void TUPagamento::testeSucesso ()
{
    estado = SUCESSO;
    Pagamento pagamento;

    try
    {
        pagamento.setCodigo(CODIGO_PAGAMENTO_VALIDO);
        pagamento.setData(DATA_VALIDO);
        pagamento.setEstado(ESTADO_VALIDO);
        pagamento.setPercentual(PERCENTUAL_VALIDO);

        if (pagamento.getCodigo() != CODIGO_PAGAMENTO_VALIDO)
            estado = FALHA;

        if (pagamento.getData() != DATA_VALIDO)
            estado = FALHA;

        if (pagamento.getEstado() != ESTADO_VALIDO)
            estado = FALHA;

        if (pagamento.getPercentual() != PERCENTUAL_VALIDO)
            estado = FALHA;
    }

    catch(invalid_argument &excecao)
    {
        estado = FALHA;
    }
}
