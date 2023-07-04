**Esse é o projeto Concordo da disciplina Linguagem de Programação 1 ministrada pelo professor Sidemar na UFRN para o curso de BTI.**

Autor: *Artur Revorêdo Pinto*

Horário da turma: *M56*

**Para compilar o código basta rodar os seguintes comandos**

* cmake -B build
* cmake --build build

**Para rodar o programa basta utilizar o comando**

* ./build/concordo

Nesse projeto existem alguns comandos possíveis, caso você não esteja logado os comandos são:

* create-user email senha nome

 Nesse comando email nem senha podem conter espaços, o nome no entanto pode.
* login email senha

 Entra com um usuário no sistema.
* quit

 Sai do programa.

Caso o login seja efetuado então outros comandos ficarão disponíveis para o usuário, esses são.

* disconnect

 Desconecta o usuário atual do sistema.
* create-server nome

  Em que nome é o nome do servidor.
* set-server-desc nome descrição

 Nesse o nome é o nome do servidor e descrição é a descrição que você deseja inserir no servidor.
* set-server-invite-code nome invite-code

 Nesse o nome é o nome do servidor o qual o invite code será mudado e invite code é um código sem espaços para ser inserido no servidor
* list-servers

 Apenas lista os servidores existentes
* remove-server

 Deleta um servidor do sistema.
* join-server nome invite code

 Nesse o usuário tentará ser adicionado no servidor de nome "nome" e digitará o código de convite.
* enter-server nome

 Nesse o usuário entra em um servidor do qual já é membro.
* leave-server

 Nesse o usuário sai do servidor, não deixando de ser um participante mas apenas para navegar por outros servidores.

* create-channel nome

 Nesse o usuário cria um canal no servidor em que está no momento com o nome dado no comando.

* enter-channel nome

 Nesse o usuário entrará no canal de nome informado no comando caso exista no servidor atual.

* leave-channel 

 Nesse o usuário sairá do canal atual.

* send-message mensagem

 Nesse o usuário envia uma mensagem nova no canal atual se estiver em um.

* list-messages

 Nesse o usuário lista as mensagens do canal atual.