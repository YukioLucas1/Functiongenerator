# Gerador de função
Este projeto foi desenvolvido utilizando uma CPU[Figura 1] baseada no microcontrolador ATmega328P, projetada e simulada no ambiente SimulIDE.

Para executar o projeto, é necessário utilizar o SimulIDE, um simulador gratuito voltado para circuitos eletrônicos e sistemas embarcados. Abra o arquivo CPU-Universal-Atmega328p.simu no SimulIDE, clique no microcontrolador com o botão direito do mouse clique em "carregar firmware" e selecione o arquivo .hex
Você pode baixar o simulador gratuitamente no site oficial: https://simulide.com/p/downloads/

O objetivo deste projeto é desenvolver um gerador de funções utilizando o microcontrolador ATmega328, produzindo os formas de onda dente de serra, triangular e senoidal. A seleção da forma de onda desejada é realizada por meio de três botões físicos:

    BT0: Gera a forma de onda dente de serra[Figura 2];
        Criada com valores crescentes de forma linear de 0 até aproximadamente 253,
        seguindo a lógica: 256 / 24 ≈ 10,67, então os valores são gerados na forma:
        0, 11, 22, 33, 44, ..., 253

    BT1: Gera a forma de onda triangular[Figura 3];
        Construída por meio de uma sequência crescente seguida de uma sequência decrescente,
        com valores aproximados: 0, 22, 44, ..., 220 (subida) e 220, 198, ..., 22 (descida).
        A onda possui um formato simétrico com um total de 22 amostras.

    BT2: Gera a forma de onda senoidal[Figura 4].
        Criada por meio da função: y = (sin(2πi / N) + 1) * 127.5, onde N é o número de amostras (24),
        e i representa o índice da amostra. Essa equação gera valores entre 0 e 255

A geração do sinal ocorre digitalmente através de uma tabela de valores em 8 bits (0 a 255), correspondente à amplitude do sinal. Esses valores são enviados para as saídas digitais do microcontrolador, conectadas a um R2R. A rede R2R converte o valor digital de cada ponto da forma de onda em uma tensão analógica proporcional, permitindo que o sinal seja visualizado em um osciloscópio ou analisado em circuitos externos.


Figura 1

![Sem título-1](https://github.com/user-attachments/assets/3d961b83-1f1e-4424-b1d4-4e2bc2262703)

Figura 2

![Sem título-1](https://github.com/user-attachments/assets/a685e367-c78b-4e54-bd46-f1602e2fa7ae)

Figura 3

![Sem título-1](https://github.com/user-attachments/assets/47388ceb-b033-45af-8c18-2acdeb5c1945)

Figura 4

![Sem título-1](https://github.com/user-attachments/assets/104abd0d-0522-4c45-bb97-8d97db78bcc8)


