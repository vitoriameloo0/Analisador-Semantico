# Análisador Semantico

## Descrição
Esse projeto foi criado para a disciplina de compiladores, em que se pede para fazer algumas definições de uma linguagem de programação, podendo criar uma nova ou se basear em uma ja existente, e assim implementar um software que simula um compilador capaz de fazer a análise semantica.

A linguagem C foi a escolhida para ser desenvolvida algumas de suas caracteristicas. 

## ✅ Status do Projeto
🚧 Projeto concluido  🚧

## 🔨 Funcionalidades do Projeto
- Foi criada algumas classes de tokens
- Ao ser executado, permite para o usuário digitar o nome do arquivo fonte
- O arquivo correto ("sem erros de linguagem") se chama fonte1.txt
- O arquivo incorreto ("com erros de linguagem") se chama fonte2.txt
- Reconhece classe de tokens no codigo fonte por meio da análise léxica e insere os mesmos em estrutura de dados apropriadas
    - Tabela de Palavras Reservadas
    - Tabela de Símbolos
- Realiza tratamento de erro lexicos, sintaticos e semanticos, mostrando na tela qual o tipo de erro e apontando a posição do erro


## 🛠️ Tecnologias Utilizadas
As ferramentas utilizadas para desenvolver o projeto:
* [Visual Studio Code](https://code.visualstudio.com/) 
* [Flex](https://sourceforge.net/projects/gnuwin32/files/flex/2.5.4a-1/)  
* [Bison](https://sourceforge.net/projects/gnuwin32/files/bison/2.4.1/) 

## ⚙️ Como executar
- Abra um prompt de comando ou no terminal do VSCode
- Esteja na pasta do arquivos do projeto
- Execute os seguintes comandos:
  - lex tokens.l
  - gcc *.c
  - a.exe
- Após isso é só escrever o nome do arquivo de entrada


## Colaborador

[<img loading="lazy" src="https://avatars.githubusercontent.com/u/80923400?v=4" width=115><br><sub> Matheus Prokopowiski </sub>](https://github.com/prokow) |
| :---: |

## ✒️ Autores

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/95388328?v=4" width=115><br><sub>Vitória Melo </sub>](https://github.com/vitoriameloo0) |  
| :---: | 


[![Linkedin Badge](https://img.shields.io/badge/-Vitória-blue?style=flat-square&logo=Linkedin&logoColor=white&link=https://www.linkedin.com/in/vitoriacmelo/)](https://www.linkedin.com/in/vitoriacmelo/) 


## Licença 
Este projeto possui [Lincença](LICENSE.md) nos termos da licença MIT. 
