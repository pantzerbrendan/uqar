INF11207 - TP2
===============

Date d'énoncé : 23/02/2016
Date de rendu : 08/03/2016 à 23h59

### Informations en rapport avec le [Makefile](./Makefile)

Tant qu'on ne fait pas les compilations pour la préparation au rendu, compiler avec `make debug`.
Les commandes `make`, `make all` et `make INF11207TP2` ne fonctionneront probablement pas à cause du flag de compilation `-Werror`.

Les sources compilées en mode DEBUG sont suffixées par `_debug.o` et les sources qui se sont pas pour le DEBUG sont simplement suffixées par `.o`.

> Lors de l'ajout de nouvelles sources, il faut ajouter le "lien" vers la source uniquement dans `SRC`, elles sont automatiquement ajoutées dans `D_SRC`. Des sources peuvent être ajoutées uniquement dans `D_SRC`. Exemple :

```Makefile
## Release
SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/monfichier.cpp

OBJS		=	$(SRC:.cpp=.o)
## end of Release section

## Debug
D_SRC		=	$(SRC) \
				$(SOURCE)/monfichierdebug.cpp

D_OBJS		=	$(D_SRC:.cpp=_debug.o)
## end of Debug section
```


### Sujet :
[![pdf_icon](http://www.chambery-tourisme.com/wp-content/uploads/cache//noeStarter/images/50__50__auto__~wp-content~themes~chambery~images~icons~pdf.png) Sujet_TP2_INF11207.pdf](./sujet.pdf)

----
#### Gestion de banque avec des comptes
----

> Caractéristiques des comptes bancaires

* Les comptes ont un numéro unique (utiliser des GUID ?)
* Les comptes sont assignés à un client
* Les comptes ont un solde, non négatif et n'a pas de limite positive
* Types de comptes : `compte normal`, `compte enfants` et `compte épargne-retraite`.

> Types de comptes

Tous les comptes permettent de savoir combien d'argent se trouve encore dessus.

* Les comptes normaux : possibilité de déposer de l'argent et d'en retirer sans contrainte (tant que le solde reste positif).
* Les comptes pour enfants :
	- Liés a un `compte normal`, celui du responsable.
	- Possibilité de déposer de l'argent.
	- Possibilité de retirer au maximum 10\$ par jour et au maximum 50\$ par mois.
	- Si on a un nouveau client de moins de 10 ans, il aura automatiquement un `compte pour enfants`.
* Les comptes épargne-retraite :
	- Possibilité de déposer autant d'argent que possible
	- Les retraits nécessitent une autorisation spéciale

----
#### Barême
----
> 13 points : Hiérarchie de classes, qui possède :

* menu, similaire à celui du [TP1](../INF11207/TP1)
* lister les informations d'un compte
* lister les informations de tous les comptes
* créer un compte (nom, date de naissance du client (si trop jeune, demander le numéro de compte d'un parent)
*  dépôt, retrait, affichage du solde
* gestion de persistance des données (sauvegarde a la fin du programme + lecture au démarrage)

> 2 points : Comment ferait-on pour passer la hiérarchie de classes par une seule classe paramétrisée (template) + donner squelette de la classe. Comparer les deux et dire ce qui paraît le plus adéquat : clarté, facilité de maintenance, ... Et dire pourquoi.

### Répartition du travail :

| Qui? | Partie | Etat |
| :----: | :----: | :----: |
| pantze_b | Factories (interface + factory spécifiques) | En cours |
| __ | Structure des classes de comptes bancaires |  |
| __ | Implémentation(retrait, dépôt) [compte normal] |  |
| __ | Implémentation(retrait, dépôt) [compte enfant] |  |
| __ | Implémentation(retrait, dépôt) [compte retraite] |  |
| __ | Génération du compte en fonction du client |  |
| __ | Lecture et sauvegarde des données |  |
| __ | Gestion du menu |  |
| | | |
| __ | Seconde partie (réponse aux questions) |  |
