Projeto Bilheteria:
Um teatro possui 600 lugares dispostos em 15 fileiras com 40 poltronas cada.

Deseja-se um sistema de controle de ocupação que ofereça as seguintes opções, através de um seletor:

0.	Finalizar
1.	Reservar poltrona
2.	Mapa de ocupação
3.	Faturamento
A opção 1 deverá solicitar a informação da fileira e da poltrona. Os dados devem ser consistidos no sentido da garantia de serem válidos. Caso o lugar esteja vago, efetuar a reserva e informar o usuário do sucesso da operação. Caso o lugar já se encontre ocupado, alertar o usuário com uma mensagem.

A opção 2 deverá gerar na tela um “mapa” de ocupação do teatro com uma legenda onde:

‘.’ representa lugar vago
‘#’ representa lugar ocupado
A opção 3 deverá apresentar na tela as seguintes informações:

Qtde de lugares ocupados: 	999
Valor da bilheteria: 		R$ 9999,99
Sabendo-se que:

Fileiras 1 a 5: R$ 50,00
Fileiras 6 a 10: R$ 30,00
Fileiras 11 a 15: R$ 15,00

Projeto Buraco:


Objetivo: 

Criar em memória uma representação para cada uma das 52 cartas de um baralho (x 2 baralhos) para serem utilizadas em um jogo de Buraco.

O programa deverá "distribuir" aleatoriamente as cartas (11 cartas para cada um dos 4 jogadores participantes). Encerra a proposta com a apresentação das "mãos" de cada jogador.

Notação para a identificação da carta:

N-99-B = Onde:
N  -> Naipe (1-Copas / 2-Paus / 3-Ouro / 4-Espada)
99 -> Número da carta (01-Ás / 13-Rei)
B  -> Baralho (1 ou 2)
Exemplo: 4-10-2  ->  10 de espada do baralho 2
baralho[n][c]
n = 0..1
c = 0..51
baralho[0][1] = "1021"
baralho[0][2] = "1031"
baralho[0][0] = "1011"
.
.
baralho[0][12] = "1131"
baralho[0][13] = "2011"
.
.
baralho[0][51] = "4131"
.
baralho[1][0] = "1012"
.
.
.
.
baralho[1][51] = "4132"
mao[j][c]
j = 0..3
c = 0..10

mao[0][0] = "1012"
mao[1][0] = "1011"
