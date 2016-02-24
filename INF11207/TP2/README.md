INF11207 - TP2
===============

Date d'énoncé : 23/02/2016
Date de rendu : 08/03/2016 à 23h59

### Informations en rapport avec le [Makefile](https://github.com/pantzerbrendan/uqar/tree/master/INF11207/TP2/Makefile)

Tant qu'on ne fait pas les compilations pour la préparation au rendu, compiler avec `make debug`.
Les commandes `make`, `make all` et `make INF11207TP2` ne fonctionneront probablement pas à cause du flag de compilation `-Werror`.

Les sources compilées en mode DEBUG sont suffixées par `_debug.o` et les sources qui se sont pas pour le DEBUG sont simplement suffixées par `.o`.

> Lors de l'ajout de nouvelles sources, il faut ajouter le "lien" vers la source dans `SRC` et dans `D_SRC`. Des sources peuvent également être ajoutées uniquement dans `D_SRC`. Exemple :
```Makefile
## Release
SRC			=	$(SOURCE)/main.cpp \
				$(SOURCE)/monfichier.cpp

OBJS		=	$(SRC:.cpp=.o)
## !Release

## Debug
D_SRC		=	$(SOURCE)/main.cpp \
				$(SOURCE)/monfichier.cpp \
				$(SOURCE)/mondebug.cpp

D_OBJS		=	$(D_SRC:.cpp=_debug.o)
## !Debug
```


### Sujet :
[![pdf_icon](http://www.chambery-tourisme.com/wp-content/uploads/cache//noeStarter/images/50__50__auto__~wp-content~themes~chambery~images~icons~pdf.png) Sujet_TP2_INF11207.pdf](https://github.com/pantzerbrendan/uqar/tree/master/INF11207/TP2/sujet.pdf)

> Gestion de banque avec des comptes

{copier coller sujet avec etapes}

### Répartition du travail :

| Qui? | Partie |
| :----: | :----: |
| pantze_b | Factories (interface + factory specifiques) |
| __ | __ |
