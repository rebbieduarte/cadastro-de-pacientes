# Projeto Integrador Multidisciplinar IV

* Projeto multidisciplinar iniciado no 2º semestre pela UNIP, onde consistia em um programa simples de cadastro de pacientes diagnosticados com COVID-19 para monitoramente das unidades de saúde básica da região. Projeto inteiramente feito na linguagem C, utilizando boas práticas de programação para que o código seja o mais semântico possível.

## Resumo do projeto

  * Estruturas de Dados

    `struct Usuario`
    - **Descrição**: Representa um usuário com login e senha.
    - **Campos**:
    - `char login[50]`: Armazena o login do usuário.
    - `char senha[50]`: Armazena a senha do usuário.

    - Cada usuário deveria conter um login e senha que seria usado para cadastrar os pacientes. Inicialmente, no projeto original (que já não tenho acesso), o login e senha eram pré-setados no código, ou seja, não havia possibilidade de criação de um novo usuário.

    ```
      printf("Login: ");
      fgets(usuario->login, sizeof(usuario->login), stdin);
      usuario->login[strcspn(usuario->login, "\n")] = 0; // Remove o \n do final de fgets

      printf("Senha: ");
      strncpy(usuario->senha, getpass(""), sizeof(usuario->senha)); // Captura a senha sem exibir no terminal

      printf("\nUsuário cadastrado com sucesso!\n\n"); 
    
    ```


    - Dessa forma, é possível criar diversos usuários com login e senha distintos.

---

### Principais Funções
   * `limparBuffer()`
    - **Descrição**: Limpa o buffer de entrada para evitar problemas com entradas de usuário.
    - **Implementação**: Lê e descarta caracteres do buffer até encontrar uma nova linha ou o fim do arquivo.

   * `cadastrarUsuario(struct Usuario *usuario)`
    - **Descrição**: Captura dados de login e senha e armazena na estrutura `Usuario`.
    - **Implementação**: Utiliza `fgets` para ler strings e remove o caractere de nova linha do final com `strcspn`.

   * `cadastrarPaciente(struct Paciente *paciente)`
    - **Descrição**: Captura informações detalhadas de um novo paciente e armazena na estrutura `Paciente`.
    - **Implementação**: Utiliza `fgets` para ler strings e `scanf` para capturar números e ponto flutuante, removendo o caractere de nova linha com `strcspn`.

   * `salvarDados(struct Paciente paciente)`
    - **Descrição**: Salva os dados de um paciente em um arquivo de texto (`pacientes.txt`).
    - **Implementação**: Abre o arquivo em modo append (`"a"`), escreve os dados formatados e fecha o arquivo após a escrita.

   * `limparTela()`
    - **Descrição**: Limpa a tela do console, compatível com sistemas Windows e Linux/Mac.
    - **Implementação**: Usa diretivas de pré-processador (`#ifdef`) para determinar o comando a ser executado (`"cls"` para Windows e `"clear"` para Linux/Mac).

---

Este resumo detalhado cobre cada aspecto do código, desde a definição das estruturas de dados até a implementação das funções e da lógica principal do programa. Cada função desempenha um papel específico na interação com o usuário, captura de dados e gerenciamento de arquivos, proporcionando um sistema básico de cadastro de usuários e pacientes.
