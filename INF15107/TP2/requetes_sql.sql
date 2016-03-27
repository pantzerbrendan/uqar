
-- # 1. Les IDs de tous les ruchers de la ville de « Rimouski ».
SELECT rucher.id
FROM rucher LEFT JOIN adresse ON rucher.idAdresse = adresse.id
WHERE adresse.ville LIKE "Rimouski";

-- # 2. La liste des ruches actives et qui sont issues d’essaims naturels.
SELECT *
FROM ruche
WHERE ruche.estActive == 1 AND ruche.estUnEssaimNaturel == 1;

-- # 3. Les noms des produits fournis par le fournisseur ayant l’ID «10 ».
SELECT produit.nom FROM fournisseurproduit FULL OUTER JOIN produit ON fournisseurproduit.idProduit = produit.id WHERE fournisseurproduit.id == 10;

-- # 4. Les noms des produits fournis par le fournisseur ayant l’ID «10 » et dont le prix de détail est inférieur à 100$.
SELECT produit.nom FROM fournisseurproduit FULL OUTER JOIN produit ON fournisseurproduit.idProduit = produit.id WHERE fournisseurproduit.id == 10 AND fournisseurproduit.prixDetail < 100.00;

-- # 5. Les IDs des ruchers composés de moins de 100 ruches.
SELECT DISTINCT ruche.idRucher FROM ruche INNER JOIN (
  SELECT ruche.idRucher, COUNT(ruche.idRucher) AS count FROM ruche GROUP BY ruche.idRucher
) AS C ON ruche.idRucher = C.idRucher WHERE C.cnt < 100;

-- # 6. Les IDs des ruchers composés de moins de 100 ruches et qui sont situés dans la ville de « Rimouski ».
SELECT DISTINCT ruche.idRucher FROM ruche INNER JOIN (
  SELECT ruche.idRucher, COUNT(ruche.idRucher) AS count FROM ruche GROUP BY ruche.idRucher
) AS C ON ruche.idRucher = C.idRucher LEFT JOIN (
  SELECT * FROM rucher FULL JOIN adresse ON rucher.idAdresse = adresse.id
) AS A ON ruche.idRucher = A.idRucher
WHERE C.cnt < 100 AND A.ville LIKE "Rimouski";

-- # 7. Les IDs des ruchers comportant le plus grand nombre de ruches.
CREATE VIEW nombre_ruches AS
SELECT DISTINCT C.count FROM ruche INNER JOIN (
  SELECT ruche.idRucher, COUNT(ruche.idRucher) AS count FROM ruche GROUP BY ruche.idRucher
) AS C on ruche.idRucher = C.idRucher; -- creation d'une vue contenant le nombre de nombre de ruches

SELECT ruche.idRucher FROM ruche INNER JOIN (
  SELECT ruche.idRucher, COUNT(ruche.idRucher) AS count FROM ruche GROUP BY ruche.idRucher
) AS C ON ruche.idRucher = C.idRucher
WHERE C.count = (
  SELECT IFNULL(MAX(nombre_ruches.count), 0) FROM nombre_ruches
);

-- # 8. Les IDs des ruchers où travaillent moins de 5 employés.
;

-- # 9. Les IDs des ruchers où travaille le plus grand nombre d’employés.
;

-- # 10. Le nombre moyen de visites par employé.
SELECT AVG(nb_visites.nombre_visites) FROM (
  SELECT visite.idEmploye, COUNT(visite.id) AS nombre_visites FROM visite GROUP BY visite.idEmploye
) AS nb_visites;

-- # 11. Le nombre moyen de visites par employé pour le rucher avec ID égal à « 10 ».
SELECT AVG(nb_visites.nombre_visites) FROM (
  SELECT visite.idEmploye, COUNT(visite.id) AS nombre_visites FROM visite
  INNER JOIN ruche ON visite.idRuche = ruche.id INNER JOIN rucher ON ruche.idRucher = rucher.id
  GROUP BY visite.idEmploye WHERE rucher.id = 10
) AS nb_visites;

-- # 12. Les IDs des ruches qui n’ont jamais été visitées.
SELECT ruche.id FROM ruche INNER JOIN (
  SELECT DISTINCT visiteruche.idRuche FROM visiteruche
) AS ruches_visitees WHERE ruche.id NOT IN(ruches_visitees.idRuche);

-- # 13. Les IDs des ruchers qui contiennent au moins une ruche qui n’a jamais été visitée.
SELECT DISTINCT ruche.idRucher FROM ruche INNER JOIN (
  SELECT DISTINCT visiteruche.idRuche FROM visiteruche
) AS ruches_visitees WHERE ruche.id NOT IN(ruches_visitees.idRuche);

-- # 14. Les IDs des ruches dont les reines sont bridées et qui sont marquées par la couleur « bleue ».
SELECT ruche.id FROM ruche WHERE ruche.idReine IN (
  SELECT reine.id FROM reine INNER JOIN marquagereine ON reine.idMarquage = marquagereine.id
  WHERE reine.estBridee == 1 AND marquagereine.couleur LIKE "bleue"
);

-- # 15. Les IDs des ruchers ayant des ruches dont les reines sont bridées et qui sont marquées par la couleur « bleue ».
SELECT DISTINCT ruche.idRucher FROM ruche WHERE ruche.idReine IN (
  SELECT reine.id FROM reine INNER JOIN marquagereine ON reine.idMarquage = marquagereine.id
  WHERE reine.estBridee == 1 AND marquagereine.couleur LIKE "bleue"
);
