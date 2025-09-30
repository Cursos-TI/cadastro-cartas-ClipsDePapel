# 🃏 Super Trunfo em C (Desafio Final)

Este projeto implementa uma versão simplificada do **Super Trunfo**, onde o usuário cadastra **duas cartas de cidades** e escolhe **dois atributos diferentes** para comparação.

## 🚀 Funcionalidades
- Cadastro de cartas pelo usuário (estado, código, nome, população, área, PIB, pontos turísticos).
- Cálculo automático de:
  - Densidade demográfica
  - PIB per capita
  - Super Poder
- Menu dinâmico para escolha de dois atributos diferentes.
- Comparação entre os atributos:
  - Regra geral: maior valor vence.
  - Exceção: **densidade demográfica**, onde o menor valor vence.
- Soma final dos dois atributos escolhidos para determinar o vencedor da rodada.
- Tratamento de empates.

## 🛠️ Compilação
Use o compilador `gcc`:

```bash
gcc super_trunfo_menu.c -o super_trunfo_menu
Após compilar, execute:
./super_trunfo_menu
