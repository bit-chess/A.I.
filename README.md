# A.I.
Inteligencia artificial do Jogo. Utiliza de uma abordagem heuristica para a tomada de decisão.

## Bitboard Mágicos
A ideia consiste em armazenar os movimentos da torre, bispo e rainha em tabelas pré-computadas. O índice será feita por meio de uma função:
(O & Mov) * Mag >> Número  
O - Casas ocupadas  
Mov - Movimentos possíveis a partir daquela casa  
Mag - Número mágico, específico para a casa  
