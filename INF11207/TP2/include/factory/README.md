Factories
========

# Non fonctionnel pour le moment

### Informations

Afin d'utiliser les `Factory` pour instancier dynamiquement des objets, utiliser la méthode statique :
```c++
template<typename ReturnType, typename EnumType>
ReturnType	*newObject(EnumType type, const std::string &param = "");
```

Cette méthode, en fonction de l'enum, appelle une autre méthode d'une classe Factory. Cette autre méthode peut également être appelée sans passer par celle-ci.

### Utilisation

```c++
// Data.hpp

/* on définit un enum à utiliser. */
typedef enum { A, B, C } MyEnum;

/* on définit la classe mère. */
class MyClass { ... };

/* on définit la classe fille. */
class MySecondClass : public MyClass { ... };
```

```c++
#include "factory/Factory.hpp"
#include "Data.hpp"

int main()
{
	/*
    ** on instancie un objet de type MySecondClass, héritant de MyClass à
	** l'aide de la Factory en ne passant que l'enum en paramètre.
    */
	MyClass *obj1 = Factories::Factory::newObject<MySecondClass, MyEnum>(B);

	/*
    ** on instancie un objet de type MySecondClass, héritant de MyClass à
	** l'aide de la Factory en passant l'enum en paramètre et une chaine
	** permettant d'initialiser l'objet.
    */
	MyClass *obj2 = Factories::Factory::newObject<MySecondClass, MyEnum>(B, "str");

	return (0);
}

```
Ce qui équivaut à :
```c++
#include "factory/SecondFactory.hpp"
#include "Data.hpp"

/** Les classes sont les mêmes que précédemment. */
int main()
{
	// On instancie un objet de type MySecondClass sans paramètre que le type  créer.
	MyClass *obj1 = Factories::MySecondFactory::newObject(B);

	/*
    ** On instancie un objet de type MySecondClass avec un paramètre,
	** en plus du type, permettant de l'initialiser.
    */
    MyClass *obj2 = Factories::MySecondFactory::newObject(B , "str");

	return (0);
}
```
