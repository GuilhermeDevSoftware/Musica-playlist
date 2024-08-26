# Playlist de Músicas em C

Este projeto é um sistema de gerenciamento de playlists de músicas, desenvolvido em linguagem C. Ele permite que o usuário insira, pesquise, elimine, mostre e toque músicas em uma lista encadeada.

## Funcionalidades

- **Inserir Música**: Adicione novas músicas à playlist, incluindo informações como título, intérprete, ID e o caminho do arquivo.
- **Pesquisar Música**: Pesquise músicas na playlist através do ID.
- **Mostrar Músicas**: Exiba todas as músicas cadastradas na playlist.
- **Tocar Música**: Simule a execução de uma música da playlist (funcionalidade simples a ser implementada).

## Estrutura do Projeto

O projeto utiliza uma lista duplamente encadeada para armazenar as músicas. Cada música é representada por um nó na lista, contendo as seguintes informações:
- **Título**: Nome da música.
- **Intérprete**: Nome do intérprete da música.
- **ID**: Identificador único da música.
- **Path**: Caminho do arquivo da música no sistema.
