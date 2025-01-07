# Usar uma imagem base com GCC
FROM gcc:latest

# Definir o diretório de trabalho
WORKDIR /usr/src/app

# Copiar os arquivos do projeto para o contêiner
COPY ./src/ ./src/

# Compilar múltiplos arquivos C em um único executável
RUN gcc ./src/main.c ./src/funcoes.c -o a.out

# Comando padrão ao iniciar o contêiner
CMD ["./a.out"]