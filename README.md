# Push_swap
Ce projet vous demande de trier des données sur une pile, avec un set d’instructions limité, en moins de coups possibles. Pour le réussir, vous devrez manipuler différents algorithmes de tri et choisir la (ou les ?) solution la plus appropriée pour un classement optimisé des données.

make -> push_swap

Dans tester: make -> checker

exemple utilistaion:
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker $ARG

ARG représente la stack, push_swap gener les instructions de tri, et checker vérifient que ces instructions trient bien la pile

bash test.sh -> génere des tests automatiques randoms pour des stacks contenant de 1 à 500 ints, et affiche le nombre d'instructions utilisées pour les trier
