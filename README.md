# 🖥️ Sistema em C para Simulação de Portal de Serviços

Este projeto implementa um **portal de serviços interativo em linguagem C**, com módulos que reúnem operações matemáticas, verificações lógicas e classificações.  
O sistema foi desenvolvido como parte da disciplina de **Ciência da Computação (CESUPA)**, aplicando conceitos introdutórios de programação como entrada/saída de dados, condicionais, laços de repetição e modularização.

---

## 📌 Funcionalidades

### 🔑 Cadastro e Login
- Criação de conta com usuário e senha.
- Alteração de dados cadastrados.
- Exclusão de conta.
- Controle de acesso via arquivo `dadosdousuario.txt`.

### 👤 Módulo Pessoal
- Classificação de idade (menor, maior, situação eleitoral).  
- Cálculo de **IMC** a partir de peso e altura.  

### 💰 Módulo Financeiro
- Cálculo de salário anual.  
- Cálculo de salário por diária e dias trabalhados.  
- Conversão de moedas (R$ → US$, €).  

### 📚 Módulo Acadêmico
- Entrada de 4 notas.  
- Cálculo de soma, média e dobro da média.  
- Classificação: **Aprovado**, **Recuperação** ou **Reprovado**.  

### 🛠️ Módulo Utilidades
- Verificação de número par ou ímpar.  
- Checagem de número em intervalo [10, 50].  
- Cálculo de área e perímetro (círculo e retângulo).  
- Conversão de segundos em horas e minutos.  

---

## ⚙️ Estrutura e Fluxo do Sistema

- O programa é controlado por um **loop principal** que gerencia os menus.  
- Uso de **constantes de retorno** para controlar o fluxo:
  - `menuCriacao`  
  - `menuInicial`  
  - `menuPrincipal`  
  - `sair`  
- Implementado com **funções modulares** e **switch-case** para organização do código.

---

## 🛠️ Tecnologias Utilizadas
- **Linguagem C**
- **Bibliotecas padrão:** `stdio.h`, `stdlib.h`
- Manipulação de **arquivos** para persistência de dados.

---

## 📂 Estrutura do Projeto
