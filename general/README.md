# Défis généraux

Cette section contient de défis de programmation qui ne sont pas liés à une catégorie en particulier. Ils reflètent plutôt des aptitudes et connaissances qui seront généralement utiles peu importe les compétitions auxquelles vous participerez.

De plus, les épreuves de cette catégorie se veulent plus accessibles afin de donner une chance à celleux qui sont moins expérimentées de montrer leur motivation et leurs capacités.

## Contraintes

Vous **devez** utiliser un des langages suivant (il n'est pas obligatoire d'utiliser le même pour chacun de défis): shell/bash, C, C++, Java, Python ou Ruby.

Vous **devez** fournir une liste des dépendances pour vos programmes ainsi qu'une documentation de la procédure pour les exécuter.

Vous **pouvez** fournir un environnement Docker configuré pour exécuter votre programme (surtout si vous avez des dépendances ou configurations complexes).

## Épreuve 1 - Le classique

Écrivez un programme qui fait le fameux Fizz-Buzz.

On compte de 1 à 100 inclusivement, si le nombre est un multiple de 3, on affiche 'Fizz', si c'est un multiple de 5, affichez 'Buzz'. Si c'est les deux, affichez 'FizzBuzz'. Si le nombre ne répond à aucune des deux conditions précédentes, on affiche le nombre. Il doit y avoir un retour de ligne après l'affichage de chacun des nombres.

## Épreuve 2 - Ouin PI Chudnovsky

Écrivez un programme qui, recevant un nombre entier positif `x` en argument, affiche la `x`è décimale de PI. Doit être capable d'afficher au moins jusqu'à la 200è décimale correctement.

## Épreuve 0v3 - Base 0v10

Écrivez un programme qui, recevant deux entiers en base 7 en argument, affiche le résultat de leur addition, de leur multiplication et et de leur soustraction (1er_nombre - 2e_nombre); le tout en base 7.

Évidemment (non pas vraiment), les nombres en base 7 sont identifiés par le préfixe `0v`. Les 10 premiers nombres sont donc `0v0, 0v1, 0v2, 0v3, 0v4, 0v5, 0v6, 0v10, 0v11 et 0v12`

## Épreuve 4 - Le jeu du pélican (règles simplifiés pour joueur à 2).

*Volé sans aucune honte d'une épreuve des* [CSGames 2016](https://github.com/R4PaSs/csgames2016_xp)

Écrivez un programme qui simule une partie du jeu du pélican entre 2 joueurs. À chaque lancer de dé, votre programme doit afficher le nombre roulé pour chacun des joueurs, ainsi que le résultat du lancer (nombre d'artichauts gagnés, fin de la partie, etc.). Lorsque la partie se termine, votre programme doit afficher le joueur gagnant ainsi que le nombre d'artichaut de chacun des joueurs.

### Règles

Chaque joueur jette un dès à 6 faces:

 - Si les deux joueurs ont la même valeur, le jeu s'arrête et celui qui a le plus d'artichauts gagne.
 - Autrement celui qui à la plus grande valeur gagne autant d'artichaut que la différence.
 - En plus, s'il a fait un 6, il vole 17% des artichauts que son adversaire a présentement (arrondi à l'entier supérieur).
 - Toutefois, si un joueur fait 1 et l'autre fait six, le nombre d'artichauts des deux joueurs et remis à zéro, trois parties sont rejouées et le gagnant de la partie est celui qui gagne une majorité de ces 3 nouvelles parties.

## Épreuve 5 - Dromepalins

Un dromepalin est un mot qui, lorsqu'on inverse la première partie du mot avec sa deuxième partie, donne un autre mot existant. Si le mot à un nombre de lettres impair, on considère que la lettre supplémentaire fait partie de la deuxième partie du mot. (Ex: par -> arp)

Écrivez un programme qui prend en entrée une liste de mots et détermine lesquels sont des dromepalins. Afin de vérifier si le mot résultant est valide, vérifiez s'il existe dans [le dictionnaire fourni dans ce dossier](./dictionnaire_francais)

## Épreuve 6 - Hexanombres

Écrivez un programme qui prend un nombre entier positif en argument et vérifie s'il est un [nombre hexagonal](https://fr.wikipedia.org/wiki/Nombre_hexagonal).
Si c'est le cas, on affiche un bel hexagone en ascii art:

```
 __
/  \
\__/
```

Sinon, on affiche ce même hexagone, mais traversé par une barre

```
 __
/\ \
\_\/

```

## Épreuve 7 - Arbre Binaire de Recherche Anarcho-Communiste

Écrivez un programme qui reçoit une liste de nombre entiers et les insère dans un [arbre rouge-noir](https://fr.wikipedia.org/wiki/Arbre_bicolore) inversé dans l'ordre dans lequel ils sont donnés. Par `arbre rouge-noir inversé`, on entend un arbre-rouge noir trié en ordre décroissant plutôt que croissant. Donc:

 - L'enfant gauche d'un noeud doit avoir une valeur supérieure ou égale à celle du noeud.
 - L'enfant droit d'un noeud doit avoir une valeur inférieure à celle du noeud.

Une fois que celà est fait, affichez le résultat du [parcours préfixe](https://fr.wikipedia.org/wiki/Arbre_binaire#Parcours_pr%C3%A9fixe,_infixe_et_postfixe) de l'arbre résultant. Les nombres doivent être affichés séparés par une virgule seulement `,`
