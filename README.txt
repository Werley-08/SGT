-- Nome: Francisco Werley da Silva
-- Matrícula: 553948

Eu já tinha um código de todo-list feito em C, então decidi usar o docker nela pra fazer a atividade

    -- Primeiro deve-se construir a imagem usando o comando:
    -- "docker-compose build"

    -- Depois subir o container em segundo plano, usando o comando:
    -- "docker-compose up -d"
    -- Deve-se primeiro subir em segundo plano, porque a aplicação precisa de interatividade e o comando -it não é
       reconhecido diretamente.

    -- Por fim, deve-se entrar no container interativamente, pelo comando:
    -- "docker exec -it todo-list-container ./a.out"

    -- Para a persistência funcionar, deve-se sempre encerrar a aplicação usando o comando "6" do menu