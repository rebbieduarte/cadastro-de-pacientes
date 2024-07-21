# Resumo Detalhado do Código

## Estruturas de Dados

### `struct Usuario`
- **Descrição**: Representa um usuário com login e senha.
- **Campos**:
  - `char login[50]`: Armazena o login do usuário.
  - `char senha[50]`: Armazena a senha do usuário.

### `struct Paciente`
- **Descrição**: Representa um paciente com informações detalhadas.
- **Campos**:
  - `char nome[100]`: Nome do paciente.
  - `int diaNascimento, mesNascimento, anoNascimento`: Data de nascimento do paciente.
  - `float peso`: Peso do paciente.
  - `char cpf[12]`: CPF do paciente.
  - `char endereco[200]`: Endereço completo do paciente.
  - `char bairro[50]`: Bairro do paciente.
  - `char cidade[50]`: Cidade do paciente.
  - `char estado[3]`: Estado do paciente (sigla).
  - `char telefone[15]`: Número de telefone do paciente.
  - `char comorbidade[100]`: Tipo de comorbidade do paciente.

## Funções

### `limparBuffer()`
- **Descrição**: Limpa o buffer de entrada para evitar problemas com entradas de usuário.
- **Implementação**: Lê e descarta caracteres do buffer até encontrar uma nova linha ou o fim do arquivo.

### `cadastrarUsuario(struct Usuario *usuario)`
- **Descrição**: Captura dados de login e senha e armazena na estrutura `Usuario`.
- **Implementação**: Utiliza `fgets` para ler strings e remove o caractere de nova linha do final com `strcspn`.

### `cadastrarPaciente(struct Paciente *paciente)`
- **Descrição**: Captura informações detalhadas de um novo paciente e armazena na estrutura `Paciente`.
- **Implementação**: Utiliza `fgets` para ler strings e `scanf` para capturar números e ponto flutuante, removendo o caractere de nova linha com `strcspn`.

### `salvarDados(struct Paciente paciente)`
- **Descrição**: Salva os dados de um paciente em um arquivo de texto (`pacientes.txt`).
- **Implementação**: Abre o arquivo em modo append (`"a"`), escreve os dados formatados e fecha o arquivo após a escrita.

### `limparTela()`
- **Descrição**: Limpa a tela do console, compatível com sistemas Windows e Linux/Mac.
- **Implementação**: Usa diretivas de pré-processador (`#ifdef`) para determinar o comando a ser executado (`"cls"` para Windows e `"clear"` para Linux/Mac).

## Função Principal (`main`)

- **Descrição**: Apresenta um menu interativo para o usuário interagir com o sistema de cadastro de usuários e pacientes.
- **Implementação**: 
  - Utiliza um loop `do-while` para exibir repetidamente o menu até que o usuário escolha sair.
  - Captura a escolha do usuário, executa a função correspondente ao menu escolhido (`cadastrarUsuario`, `cadastrarPaciente` ou saída do programa) e limpa a tela entre as operações.
  - Utiliza `getchar()` para esperar que o usuário pressione Enter antes de limpar a tela e exibir o menu novamente.

---

Este resumo detalhado cobre cada aspecto do código, desde a definição das estruturas de dados até a implementação das funções e da lógica principal do programa. Cada função desempenha um papel específico na interação com o usuário, captura de dados e gerenciamento de arquivos, proporcionando um sistema básico de cadastro de usuários e pacientes.
