# Sistema de Gerenciamento de Tarefas em C

Este projeto é um sistema simples de gerenciamento de tarefas desenvolvido em C, executado dentro de um container Docker. Ele permite a persistência dos dados enquanto a aplicação for encerrada corretamente.

## Pré-requisitos

- Docker
- Docker Compose

## Como executar

1. **Construir a imagem Docker:**
   
   ```sh
   docker-compose build
   ```

2. **Subir o container em segundo plano:**
   
   ```sh
   docker-compose up -d
   ```
   > É necessário iniciar em segundo plano, pois a aplicação requer interatividade e o comando `-it` não é reconhecido diretamente.

3. **Acessar o container e executar a aplicação interativamente:**
   
   ```sh
   docker exec -it todo-list-container ./a.out
   ```

## Persistência de Dados

Para garantir a persistência dos dados, sempre finalize a aplicação utilizando a opção **"6"** no menu da aplicação.

## Encerrando o Container

Caso seja necessário parar o container:

```sh
docker-compose down
```

Isso removerá o container, mas os dados permanecerão se forem salvos corretamente antes da finalização da aplicação.
