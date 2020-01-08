CREATE TABLE publications (
	id INT PRIMARY KEY AUTO_INCREMENT,
	titre VARCHAR(100) CHECK (LENGTH(titre) >= 10),
	contenu TEXT NOT NULL,
	id_personnes INT NOT NULL UNIQUE,
    timestamp DATETIME,
    FOREIGN KEY(id_personnes) REFERENCES personnes(id)
);

-- Test de la contrainte titre
INSERT INTO publications (titre,contenu,id_personnes,timestamp) VALUES ("marchepas","blablablablablablabla",1,NOW());
INSERT INTO publications (titre,contenu,id_personnes,timestamp) VALUES ("EstFonctionelle","blablablablablablabla",1,NOW());