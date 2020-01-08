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
	timestamp DATE,
	FOREIGN KEY(id_personnes) REFERENCES personnes(id)
);
