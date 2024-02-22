# Leitor RFID - Comunicação entre Arduino e NodeMCU

Este projeto consiste em uma solução completa para leitura de tags RFID e envio dos dados para um banco de dados Firebase em tempo real, utilizando um microcontrolador Arduino e um dispositivo ESP8266 (NodeMCU).

## Descrição Geral

Este projeto integra dois componentes principais: um leitor RFID conectado a um Arduino e um dispositivo ESP8266 responsável por se comunicar com o Firebase para armazenar os dados lidos. O Arduino é responsável por ler as tags RFID e enviar os dados para o NodeMCU através da comunicação serial, enquanto o NodeMCU se conecta à rede Wi-Fi e ao Firebase para armazenar os dados.

## Configuração do Hardware

- Um microcontrolador Arduino (ou compatível) com suporte a comunicação serial
- Um módulo RFID RC522
- Um dispositivo ESP8266 (NodeMCU) para se comunicar com o Firebase
- Conexão serial entre o Arduino e o NodeMCU

## Configuração do Firebase

Antes de utilizar este código, é necessário configurar um banco de dados Firebase e obter as credenciais de autenticação. Siga os passos abaixo para configurar o Firebase:

1. Acesse [Firebase Console](https://console.firebase.google.com/) e crie um novo projeto.
2. Clique em "Adicionar projeto" e siga as instruções para configurar o projeto.
3. Após configurar o projeto, clique em "Realtime Database" no menu lateral esquerdo.
4. Crie um novo banco de dados ou utilize um existente.
5. No menu superior, clique em "Regras" e ajuste as regras de segurança do banco de dados conforme necessário. Por padrão, o acesso é restrito apenas aos usuários autenticados.
6. No menu lateral esquerdo, clique em "Configuração do projeto" (ícone de engrenagem) e selecione "Geral".
7. Role para baixo até encontrar as configurações do aplicativo e copie o URL do banco de dados e a chave de autenticação.

## Configuração do Código

### No código do Arduino (leitor RFID):

Antes de carregar o código para o Arduino, é necessário incluir as bibliotecas necessárias e configurar os pinos do módulo RFID RC522:

- `SPI.h`: Biblioteca para comunicação SPI.
- `RFID.h`: Biblioteca para controlar o módulo RFID RC522.
- `SoftwareSerial.h`: Biblioteca para comunicação serial com o NodeMCU.

Além disso, os pinos `SDA_DIO` e `RESET_DIO` devem ser configurados de acordo com a conexão física do módulo RFID RC522.

### No código do NodeMCU (ESP8266):

Antes de carregar o código para o NodeMCU, é necessário configurar as seguintes constantes:

- `FIREBASE_HOST`: URL do banco de dados Firebase.
- `FIREBASE_AUTH`: Chave de autenticação do Firebase.
- `_SSID`: Nome da rede Wi-Fi.
- `_PASSWORD`: Senha da rede Wi-Fi.

Certifique-se de que o NodeMCU está conectado à mesma rede Wi-Fi configurada no Firebase.

## Funcionamento

1. O código no Arduino lê os números de série das tags RFID detectadas pelo módulo RC522 e envia os dados para o NodeMCU através da comunicação serial.
2. O código no NodeMCU recebe os dados do Arduino, se conecta à rede Wi-Fi e ao Firebase e armazena os dados recebidos em tempo real no banco de dados Firebase.

## Dependências

### No código do Arduino:

- SPI
- RFID
- SoftwareSerial

### No código do NodeMCU:

- FirebaseESP8266
- ESP8266WiFi

Certifique-se de instalar todas as bibliotecas necessárias antes de compilar os códigos.
