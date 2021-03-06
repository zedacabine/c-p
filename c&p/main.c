/* 
 * File:   main.c
 * Author: ivo
 *
 * Created on January 27, 2015, 3:09 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "DataManagement.h"
#include "utilizador.h"
#include "tipo_utilizador.h"
#include "cliente.h"
#include "unidade.h"
#include "ingrediente.h"
#include "produto_final.h"
#include "linha_produto_final.h"
#include "encomenda.h"
#include "linha_encomenda.h"
#include "producao.h"

/*
 * 
 */
int main(int argc, char** argv) {

    //---------------------------------------------------------------------------------------------------------//

    unsigned short contadorTipoUtilizadores, contadorUtilizadores, contadorClientes, contadorUnidades, contadorIngredientes, contadorProdutosFinais, contadorLinhasProdutoFinal, contadorEncomenda, contadorLinhasEncomenda, contadorProducao;
    char NomeFicheiro[SHORT_STRING];

    //---------------------------------------------------------------------------------------------------------//
    //Tipo de Utilizadores

    const unsigned short MAX_TIPO_UTILIZADORES = 4;

    FieldAux estructAuxTipoUtilizadores[] = {
        {.fieldName = "id_tipo_utilizador", .alias = "Numero Tipo Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "descricao", .alias = "Descricao", .sizeBytes = SHORT_STRING, .type = STRING}
    };

    TipoUtilizador tipoUtilizadores[MAX_TIPO_UTILIZADORES];
    const unsigned int tamAuxTipoUtilizador = (sizeof (estructAuxTipoUtilizadores) / sizeof (estructAuxTipoUtilizadores[0]));
    const unsigned int tamTipoTipoUtilizador = sizeof (TipoUtilizador);

    Class tipoUtilizadorClass = {.name = "Tipo Utilizador", .primaryKeyField = ID_TIPO_UTILIZADOR, .StructTypeSize = tamTipoTipoUtilizador, .data = &tipoUtilizadores, .auxStruct = &estructAuxTipoUtilizadores, .elements = &contadorTipoUtilizadores, .fieldsNumber = tamAuxTipoUtilizador, .aliasField = DESCRICAO_TIPO_UTILIZADOR};

    strcpy(NomeFicheiro, "tipoUtilizadores.txt");
    readFile(NomeFicheiro, &tipoUtilizadorClass, MAX_TIPO_UTILIZADORES);

    //---------------------------------------------------------------------------------------------------------//
    //Utilizadores

    const unsigned short MAX_UTILIZADORES = 100;

    FieldAux estructAuxUtilizadores[] = {
        {.fieldName = "id_utilizador", .alias = "Numero Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true, .step = 1},
        {.fieldName = "id_tipo_utilizador", .alias = "Tipo de Utilizador", .sizeBytes = SHORT_SIZE, .type = SHORT, .required = true, .unique = false, .foreignKey = true, .parentPrimaryKey = ID_TIPO_UTILIZADOR, .parentClass = &tipoUtilizadorClass},
        {.fieldName = "username", .alias = "Username", . sizeBytes = SHORT_STRING, .type = STRING, .required = true},
        {.fieldName = "password", .alias = "Password", . sizeBytes = SHORT_STRING, .type = STRING, .required = true}
    };

    Utilizador utilizadores[MAX_UTILIZADORES];
    const unsigned int tamAuxUtilizador = (sizeof (estructAuxUtilizadores) / sizeof (estructAuxUtilizadores[0]));
    const unsigned int tamTipoUtilizador = sizeof (Utilizador);

    Class utilizadorClass = {.name = "Utilizador", .StructTypeSize = tamTipoUtilizador, .data = &utilizadores, .auxStruct = &estructAuxUtilizadores, .elements = &contadorUtilizadores, .fieldsNumber = tamAuxUtilizador, .aliasField = USERNAME};

    strcpy(NomeFicheiro, "utilizadores.txt");
    readFile(NomeFicheiro, &utilizadorClass, MAX_UTILIZADORES);

    //---------------------------------------------------------------------------------------------------------//
    //Clientes

    const unsigned short MAX_CLIENTES = 100;

    FieldAux estructAuxClientes[] = {
        {.fieldName = "id_cliente", .alias = "Numero de Cliente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "nome", .alias = "Nome", . sizeBytes = MEDIUM_STRING, .type = STRING, .required = true},
        {.fieldName = "id_utilizador", .alias = "Username", .sizeBytes = SHORT_SIZE, .type = SHORT, .required = true, .unique = true, .foreignKey = true, .parentPrimaryKey = ID_UTILIZADOR, .parentClass = &utilizadorClass}
    };

    Cliente clientes[MAX_CLIENTES];
    const unsigned int tamAuxCliente = (sizeof (estructAuxClientes) / sizeof (estructAuxClientes[0]));
    const unsigned int tamTipoCliente = sizeof (Cliente);

    Class clienteClass = {.name = "cliente", .StructTypeSize = tamTipoCliente, .data = &clientes, .auxStruct = &estructAuxClientes, .elements = &contadorClientes, .fieldsNumber = tamAuxCliente, .aliasField = NOME};

    strcpy(NomeFicheiro, "clientes.txt");
    readFile(NomeFicheiro, &clienteClass, MAX_CLIENTES);

    //---------------------------------------------------------------------------------------------------------//
    //Unidades

    const unsigned MAX_UNIDADES = 10;

    FieldAux estructAuxUnidades[] = {
        {.fieldName = "id_unidade", .alias = "Numero de Unidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "designacao_unidade", .alias = "Designacao", .sizeBytes = SHORT_STRING, .type = STRING, .unique = true, .required = true}
    };

    Unidade unidades[MAX_UNIDADES];
    const unsigned int tamAuxUnidade = (sizeof (estructAuxUnidades) / sizeof (estructAuxUnidades[0]));
    const unsigned int tamTipoUnidade = sizeof (Unidade);

    Class unidadeClass = {.name = "unidade", .StructTypeSize = tamTipoUnidade, .data = &unidades, .auxStruct = &estructAuxUnidades, .elements = &contadorUnidades, .fieldsNumber = tamAuxUnidade, .aliasField = DESCRICAO_UNIDADE};

    strcpy(NomeFicheiro, "unidades.txt");
    readFile(NomeFicheiro, &unidadeClass, MAX_UNIDADES);

    //---------------------------------------------------------------------------------------------------------//
    //Ingredientes

    const unsigned MAX_INGREDIENTES = 10;

    FieldAux estructAuxIngredientes[] = {
        {.fieldName = "id_ingrediente", .alias = "Numero de Ingrediente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "designacao_ingrediente", .alias = "Designacao", .sizeBytes = SHORT_STRING, .type = STRING, .unique = true, .required = true}
    };

    Ingrediente ingredientes[MAX_INGREDIENTES];
    const unsigned int tamAuxIngrediente = (sizeof (estructAuxIngredientes) / sizeof (estructAuxIngredientes[0]));
    const unsigned int tamTipoIngrediente = sizeof (Ingrediente);

    Class ingredienteClass = {.name = "ingrediente", .StructTypeSize = tamTipoIngrediente, .data = &ingredientes, .auxStruct = &estructAuxIngredientes, .elements = &contadorIngredientes, .fieldsNumber = tamAuxIngrediente, .aliasField = DESCRICAO_INGREDIENTE};

    strcpy(NomeFicheiro, "ingredientes.txt");
    readFile(NomeFicheiro, &ingredienteClass, MAX_INGREDIENTES);

    //---------------------------------------------------------------------------------------------------------//
    //ProdutoFinal

    const unsigned MAX_PRODUTO_FINAL = 10;

    FieldAux estructAuxProdutoFinal[] = {
        {.fieldName = "id_produto_final", .alias = "Numero de Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "designacao_produto_final", .alias = "Designacao", .sizeBytes = MEDIUM_STRING, .type = STRING, .unique = true, .required = true}
    };

    ProdutoFinal produtosFinais[MAX_PRODUTO_FINAL];
    const unsigned int tamAuxProdutoFinal = (sizeof (estructAuxProdutoFinal) / sizeof (estructAuxProdutoFinal[0]));
    const unsigned int tamTipoProdutoFinal = sizeof (ProdutoFinal);

    Class produtoFinalClass = {.name = "produto_final", .StructTypeSize = tamTipoProdutoFinal, .data = &produtosFinais, .auxStruct = &estructAuxProdutoFinal, .elements = &contadorProdutosFinais, .fieldsNumber = tamAuxProdutoFinal, .aliasField = DESCRICAO_PRODUTO_FINAL};

    strcpy(NomeFicheiro, "produtoFinal.txt");
    readFile(NomeFicheiro, &produtoFinalClass, MAX_PRODUTO_FINAL);

    //---------------------------------------------------------------------------------------------------------//
    //Linha do Produto Final

    const unsigned MAX_LINHA_PRODUTO_FINAL = 100;

    FieldAux estructAuxLinhaProdutoFinal[] = {
        {.fieldName = "id_linha_produto_final", .alias = "Numero da Linha do Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "id_produto_final", .alias = "Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &produtoFinalClass, .parentPrimaryKey = ID_PRODUTO_FINAL},
        {.fieldName = "id_ingrediente", .alias = "Ingrediente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &ingredienteClass, .parentPrimaryKey = ID_INGREDIENTE},
        {.fieldName = "id_unidade", .alias = "Unidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &unidadeClass, .parentPrimaryKey = ID_UNIDADE},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = FLOAT_SIZE, .type = FLOAT, .unique = false, .required = true, .autoIncrement = false},

    };

    LinhaProdutoFinal linhasProdutoFinal[MAX_LINHA_PRODUTO_FINAL];
    const unsigned int tamAuxLinhaProdutoFinal = (sizeof (estructAuxLinhaProdutoFinal) / sizeof (estructAuxLinhaProdutoFinal[0]));
    const unsigned int tamTipoLinhaProdutoFinal = sizeof (ProdutoFinal);

    Class linhaProdutoFinalClass = {.name = "linha_produto_final", .StructTypeSize = tamTipoLinhaProdutoFinal, .data = &linhasProdutoFinal, .auxStruct = &estructAuxLinhaProdutoFinal, .elements = &contadorLinhasProdutoFinal, .fieldsNumber = tamAuxLinhaProdutoFinal, .aliasField = ID_INGREDIENTE_LINHA_PRODUTO_FINAL};

    strcpy(NomeFicheiro, "linhaProdutoFinal.txt");
    readFile(NomeFicheiro, &linhaProdutoFinalClass, MAX_LINHA_PRODUTO_FINAL);

    //---------------------------------------------------------------------------------------------------------//
    //Encomenda

    const unsigned MAX_ENCOMENDA = 100;

    FieldAux estructAuxEncomenda[] = {
        {.fieldName = "id_encomenda", .alias = "Numero da Linha do Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "id_cliente", .alias = "Cliente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &clienteClass, .parentPrimaryKey = ID_CLIENTE},
        {.fieldName = "data_encomenda", .alias = "Data Encomenda", .sizeBytes = FLOAT_SIZE, .type = FLOAT, .unique = false, .required = true, .autoIncrement = false},
        {.fieldName = "data_entrega", .alias = "Data Entrega", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false},

    };

    Encomenda encomenda[MAX_ENCOMENDA];
    const unsigned int tamAuxEncomenda = (sizeof (estructAuxEncomenda) / sizeof (estructAuxEncomenda[0]));
    const unsigned int tamTipoEncomenda = sizeof (Encomenda);

    Class encomendaClass = {.name = "encomenda", .StructTypeSize = tamTipoEncomenda, .data = &encomenda, .auxStruct = &estructAuxEncomenda, .elements = &contadorEncomenda, .fieldsNumber = tamAuxEncomenda, .aliasField = ID_CLIENTE};

    strcpy(NomeFicheiro, "Encomenda.txt");
    readFile(NomeFicheiro, &encomendaClass, MAX_ENCOMENDA);

    //---------------------------------------------------------------------------------------------------------//
    //Linha da Encomenda

    const unsigned MAX_LINHA_ENCOMENDA = 100;

    FieldAux estructAuxLinhaEncomenda[] = {
        {.fieldName = "id_linha_encomenda", .alias = "Numero da Linha do Produto Final", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "id_encomenda", .alias = "Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &encomendaClass, .parentPrimaryKey = ID_ENCOMENDA},
        {.fieldName = "id_ingrediente", .alias = "Ingrediente", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &ingredienteClass, .parentPrimaryKey = ID_INGREDIENTE},
        {.fieldName = "id_unidade", .alias = "Unidade", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &unidadeClass, .parentPrimaryKey = ID_UNIDADE},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = FLOAT_SIZE, .type = FLOAT, .unique = false, .required = true, .autoIncrement = false},

    };

    linhaEncomenda linhasEncomenda[MAX_LINHA_ENCOMENDA];
    const unsigned int tamAuxLinhaEncomenda = (sizeof (estructAuxLinhaEncomenda) / sizeof (estructAuxLinhaEncomenda[0]));
    const unsigned int tamTipoLinhaEncomenda = sizeof (linhaEncomenda);

    Class linhaEncomendaClass = {.name = "linha_encomenda", .StructTypeSize = tamTipoLinhaEncomenda, .data = &linhasEncomenda, .auxStruct = &estructAuxLinhaEncomenda, .elements = &contadorLinhasEncomenda, .fieldsNumber = tamAuxLinhaEncomenda, .aliasField = ID_PRODUTO_FINAL_LINHA_ENCOMENDA};

    strcpy(NomeFicheiro, "linhaEncomenda.txt");
    readFile(NomeFicheiro, &linhaEncomendaClass, MAX_LINHA_ENCOMENDA);

    //---------------------------------------------------------------------------------------------------------//
    //Produção
    const unsigned MAX_PRODUCAO = 100;

    FieldAux estructAuxProducao[] = {
        {.fieldName = "id_producao", .alias = "Numero da Producao", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = true, .required = true, .autoIncrement = true},
        {.fieldName = "id_linha_encomenda", .alias = "Linha da Encomenda", .sizeBytes = SHORT_SIZE, .type = SHORT, .unique = false, .required = true, .autoIncrement = false, .foreignKey = true, .parentClass = &linhaEncomendaClass, .parentPrimaryKey = ID_LINHA_ENCOMENDA},
        {.fieldName = "quantidade", .alias = "Quantidade", .sizeBytes = FLOAT_SIZE, .type = FLOAT, .unique = false, .required = true, .autoIncrement = false},

    };

    Producao producoes[MAX_PRODUCAO];
    const unsigned int tamAuxProducao = (sizeof (estructAuxLinhaEncomenda) / sizeof (estructAuxLinhaEncomenda[0]));
    const unsigned int tamTipoProducao = sizeof (Producao);

    Class producaoClass = {.name = "producao", .StructTypeSize = tamTipoProducao, .data = &producoes, .auxStruct = &estructAuxProducao, .elements = &contadorProducao, .fieldsNumber = tamAuxProducao, .aliasField = ID_LINHA_ENCOMENDA_PRODUCAO};

    strcpy(NomeFicheiro, "producao.txt");
    readFile(NomeFicheiro, &producaoClass, MAX_PRODUCAO);

    //---------------------------------------------------------------------------------------------------------//

    typedef struct {
        Class * tipoUtilizadorClass;
        Class * utilizadorClass;

    } Classes;

    Classes classes;
    classes.tipoUtilizadorClass = &tipoUtilizadorClass;
    classes.utilizadorClass = &utilizadorClass;

    //---------------------------------------------------------------------------------------------------------//
    //Checks
    //inserirTipoUtilizador(classes.tipoUtilizadorClass);
    //listarTipoUtilizadores(classes.tipoUtilizadorClass);

    //listarTipoUtilizador(classes.tipoUtilizadorClass,0);
    int chaves[] = {0, 1};
    int campos[] = {ID_TIPO_UTILIZADOR, DESCRICAO_TIPO_UTILIZADOR};
    //filtrarTipoUtilizadores(classes.tipoUtilizadorClass, chaves, 2, campos, 2);
    //filtrarTipoUtilizador(classes.tipoUtilizadorClass,0,campos,2);
    //filtrarEditarTipoUtilizador(classes.tipoUtilizadorClass,0,campos,2);
    //editarTipoUtilizador(classes.tipoUtilizadorClass,1);
    //listar_editar_tipoUtilizadores(classes.tipoUtilizadorClass);
    //editarTipoUtilizadores(classes.tipoUtilizadorClass,chaves,2);
    //TipoUtilizador *tipoUtilizadorData = classes.tipoUtilizadorClass->data;
    //removerTipoUtilizador(classes.tipoUtilizadorClass, 2);
    //listarTipoUtilizadores(classes.tipoUtilizadorClass);
    
    //inserirUtilizador(classes.utilizadorClass);
    listarUtilizadores(classes.utilizadorClass);
   // (*classes.utilizadorClass->elements)=0;
    listarUtilizador(classes.utilizadorClass, 0);
    //printShort(classes.utilizadorClass->elements);
    return (EXIT_SUCCESS);
}

