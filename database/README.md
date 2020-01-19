# Database

## Épreuve 1

Soit le schéma de base de donnée suivant:

```
CREATE TABLE personnes (
	id INT PRIMARY KEY AUTO_INCREMENT,
	nom VARCHAR(50) NOT NULL UNIQUE,
	couleur ENUM('rouge', 'bleu', 'orange', 'turquoise'),
	poste VARCHAR(100) NOT NULL
);

CREATE TABLE photos_profil (
	id INT PRIMARY KEY AUTO_INCREMENT,
	id_personnes INT NOT NULL UNIQUE,
	photo BLOB NOT NULL,
	timestamp DATETIME,
	FOREIGN KEY(id_personnes) REFERENCES personnes(id)
);
```

*le schéma se trouve aussi dans le fichier* [schema_epreuve1.sql](schema_epreuve1.sql)

Dans les cas où le système de gestion de base de données (RDBMS) fait une différence sur les fonctions disponibles ou la syntaxe, considérez que nous utilisons **MariaBD**.

#### a) Écrivez une requête pour obtenir la `couleur` de toutes les personnes dont l'`id` se trouve entre 5 et 10 inclusivement.

#### b) Écrivez une requête pour obtenir le `nom` et la `photo` de toutes les personnes dont la `couleur` est orange et dont le timestamp est supérieur ou égal à la date d'il y a 10 jours (`maintenant - 10 jours`).

#### c) Écrivez une requête pour ajouter `mauve`, `vert` et `gris` comme couleurs possibles pour les personnes.

#### d) Créez une nouvelle table nommée `publications` qui contient un id, un titre, un contenu et un timestamp de publication (précis à la seconde près).

 - id, titre et timestamp doivent obligatoirement contenir une valeur.
 - Le titre doit contenir entre 10 et 100 caractères inclusivement.
 - Le contenu est du texte au format UTF-8 de longueur arbitraire (doit pouvoir contenir au moins 12 millions de caractères) et peut être vide.
 - Cette table de publications doit être liée aux personnes de cette manière: une publication n'est associée qu'à une seule personne et une personne peut avoir n'importe quel nombre de publications (incluant aucune).
