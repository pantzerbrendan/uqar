INF11207 - TP3
===============

Date d'énoncé : 22/09/2016
Date de rendu : 05/04/2016 à 23h59

### Informations en rapport avec le [Makefile](./Makefile)

Il n'y a rien de plus a ajouter dans les regles comprenant les sources.
Si des main de tests sont ajoutes, les inserer comme suit:

Lignes a ajouter
``` Makefile
$(CXX) $(LDFLAGS) -c $(TESTS)/main_de_tests.cpp -o $(TESTS)/main_de_tests.o
$(GXX) $(D_OBJS) $(TESTS)/main_de_tests.o -o $(NOM_TEST)
```
Il faudra egalement creer une nouvelle regle qui correspondra au nom du binaire de test `(NOM_TEST) ci-dessus`.
```Makefile
$(NAME):	$(OBJS)
				$(CXX) $(OBJS) -o $(NAME)

$(TEST):	$(D_OBJS)
				$(CXX) $(LDFLAGS) -c $(TESTS)/main_compilation.cpp -o $(TESTS)/main_compilation.o
				$(GXX) $(D_OBJS) $(TESTS)/main_compilation.o -o $(TEST_COMP)
				## Add test compilation here
```

### Sujet :
[![pdf_icon](http://www.chambery-tourisme.com/wp-content/uploads/cache//noeStarter/images/50__50__auto__~wp-content~themes~chambery~images~icons~pdf.png) Sujet_TP3_INF11207.pdf](./sujet.pdf)

----
#### Barême
----
> 15 points : Implementation de la classe `fraction`

* 3 points : implementation des operateurs unaires
	* le plus unaire : `operator+()`
	* le moins unaire : `operator-()`
	* l'inverse multiplicatif : `operator~()`
* 12 points : implementation des operateurs de base `operator+(...)`, `operator-(...)`, `operator*(...)`, `operator/(...)` :
	* entier avec fraction
	* fraction avec entier
	* fraction avec fraction

> 2 points : Effectuer la simplification des fractions

----
#### Informations
----

* Pour la partie a 12 points, seulement les deux derniers points sont implementes !
* D'autres operateurs sont implementes :
	* `operator++()` : pre-inecrementation
	* `operator--()` : pre-decrementation
	* `operator++(int)` : post-incrementation
	* `operator--(int)` : post-decrementation
	* `operator+=(int)`
	* `operator-=(int)`
	* `operator*=(int)`
	* `operator/=(int)`
	* `operator+=(fraction)`
	* `operator-=(fraction)`
	* `operator*=(fraction)`
	* `operator/=(fraction)`
	* `operator==(fraction)`
	* `operator!=(fraction)`

### Répartition du travail :

| Qui? | Partie | Etat |
| :----: | :----: | :----: |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |## Heading ##
| | | |
| | | |
| | | |


