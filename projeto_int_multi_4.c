#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um usuário
struct Usuario {
    char login[50];
    char senha[50];
};

// Estrutura para representar um paciente
struct Paciente {
    char nome[100];
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    float peso;
    char cpf[12];
    char endereco[200];
    char bairro[50];
    char cidade[50];
    char estado[3];
    char telefone[15];
    char comorbidade[100];
};

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para limpar a tela (compatível com Windows e Linux/Mac)
void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função para cadastrar novo usuário
void cadastrarUsuario(struct Usuario *usuario) {
    limparTela();

    printf("==============================\n");
    printf("    Cadastro de Usuário\n");
    printf("==============================\n");

    printf("Login: ");
    fgets(usuario->login, sizeof(usuario->login), stdin);
    usuario->login[strcspn(usuario->login, "\n")] = 0; // Remove o \n do final de fgets

    printf("Senha: ");
    fgets(usuario->senha, sizeof(usuario->senha), stdin);
    usuario->senha[strcspn(usuario->senha, "\n")] = 0; // Remove o \n do final de fgets

    printf("\nUsuário cadastrado com sucesso!\n\n");
}

// Função para cadastrar novo paciente
void cadastrarPaciente(struct Paciente *paciente) {
    limparTela();

    printf("==============================\n");
    printf("    Cadastro de Paciente\n");
    printf("==============================\n");

    printf("Nome: ");
    fgets(paciente->nome, sizeof(paciente->nome), stdin);
    paciente->nome[strcspn(paciente->nome, "\n")] = 0; // Remove o \n do final de fgets

    printf("Data de Nascimento (dd mm aaaa): ");
    scanf("%d %d %d", &paciente->diaNascimento, &paciente->mesNascimento, &paciente->anoNascimento);
    limparBuffer();

    printf("Peso (kg): ");
    scanf("%f", &paciente->peso);
    limparBuffer();

    printf("CPF: ");
    fgets(paciente->cpf, sizeof(paciente->cpf), stdin);
    paciente->cpf[strcspn(paciente->cpf, "\n")] = 0; // Remove o \n do final de fgets

    printf("Endereço (com número): ");
    fgets(paciente->endereco, sizeof(paciente->endereco), stdin);
    paciente->endereco[strcspn(paciente->endereco, "\n")] = 0; // Remove o \n do final de fgets

    printf("Bairro: ");
    fgets(paciente->bairro, sizeof(paciente->bairro), stdin);
    paciente->bairro[strcspn(paciente->bairro, "\n")] = 0; // Remove o \n do final de fgets

    printf("Cidade: ");
    fgets(paciente->cidade, sizeof(paciente->cidade), stdin);
    paciente->cidade[strcspn(paciente->cidade, "\n")] = 0; // Remove o \n do final de fgets

    printf("Estado (sigla): ");
    fgets(paciente->estado, sizeof(paciente->estado), stdin);
    paciente->estado[strcspn(paciente->estado, "\n")] = 0; // Remove o \n do final de fgets

    printf("Número de Telefone: ");
    fgets(paciente->telefone, sizeof(paciente->telefone), stdin);
    paciente->telefone[strcspn(paciente->telefone, "\n")] = 0; // Remove o \n do final de fgets

    printf("Tipo de Comorbidade: ");
    fgets(paciente->comorbidade, sizeof(paciente->comorbidade), stdin);
    paciente->comorbidade[strcspn(paciente->comorbidade, "\n")] = 0; // Remove o \n do final de fgets

    printf("\nDados do paciente cadastrados com sucesso!\n\n");
}

// Função para salvar os dados do paciente em um arquivo txt
void salvarDadosPaciente(struct Paciente paciente) {
    FILE *arquivo;
    arquivo = fopen("pacientes.txt", "a"); // Abre o arquivo para escrita (append)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome: %s\n", paciente.nome);
    fprintf(arquivo, "Data de Nascimento: %02d/%02d/%d\n", paciente.diaNascimento, paciente.mesNascimento, paciente.anoNascimento);
    fprintf(arquivo, "Peso: %.2f kg\n", paciente.peso);
    fprintf(arquivo, "CPF: %s\n", paciente.cpf);
    fprintf(arquivo, "Endereço: %s\n", paciente.endereco);
    fprintf(arquivo, "Bairro: %s\n", paciente.bairro);
    fprintf(arquivo, "Cidade: %s\n", paciente.cidade);
    fprintf(arquivo, "Estado: %s\n", paciente.estado);
    fprintf(arquivo, "Telefone: %s\n", paciente.telefone);
    fprintf(arquivo, "Comorbidade: %s\n", paciente.comorbidade);
    fprintf(arquivo, "========================================\n");

    fclose(arquivo);
    printf("Dados salvos em pacientes.txt\n\n");
}

// Função para ler e exibir os dados dos pacientes cadastrados
void consultarPacientes() {
    FILE *arquivo;
    char linha[200];

    arquivo = fopen("pacientes.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Nenhum paciente cadastrado ainda.\n\n");
        return;
    }

    printf("==============================\n");
    printf("    Pacientes Cadastrados\n");
    printf("==============================\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
    printf("\n");
}

// Função para salvar os dados do usuário em um arquivo txt
void salvarDadosUsuario(struct Usuario usuario) {
    FILE *arquivo;
    arquivo = fopen("usuarios.txt", "a"); // Abre o arquivo para escrita (append)

    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Login: %s\n", usuario.login);
    fprintf(arquivo, "Senha: %s\n", usuario.senha);
    fprintf(arquivo, "========================================\n");

    fclose(arquivo);
    printf("Dados salvos em usuarios.txt\n\n");
}

// Função para ler e exibir os dados dos usuários cadastrados
void consultarUsuarios() {
    FILE *arquivo;
    char linha[200];

    arquivo = fopen("usuarios.txt", "r"); // Abre o arquivo para leitura

    if (arquivo == NULL) {
        printf("Nenhum usuário cadastrado ainda.\n\n");
        return;
    }

    printf("==============================\n");
    printf("    Usuários Cadastrados\n");
    printf("==============================\n");

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }

    fclose(arquivo);
    printf("\n");
}

int main() {
    struct Usuario usuario;
    struct Paciente paciente;

    int opcao;

    do {
        limparTela();

        printf("==============================\n");
        printf("    Menu Principal\n");
        printf("==============================\n");
        printf("1. Cadastrar novo usuário\n");
        printf("2. Cadastrar novo paciente\n");
        printf("3. Consultar usuários cadastrados\n");
        printf("4. Consultar pacientes cadastrados\n");
        printf("5. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBuffer();

        switch(opcao) {
            case 1:
                cadastrarUsuario(&usuario);
                salvarDadosUsuario(usuario);
                break;
            case 2:
                cadastrarPaciente(&paciente);
                salvarDadosPaciente(paciente);
                break;
            case 3:
                consultarUsuarios();
                break;
            case 4:
                consultarPacientes();
                break;
            case 5:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }

        printf("Pressione Enter para continuar...");
        getchar(); // Espera a tecla Enter ser pressionada
        limparTela();

    } while (opcao != 5);

    return 0;
}
