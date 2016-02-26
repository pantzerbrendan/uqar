Factories
========

### Informations

Afin d'utiliser les `Factory` pour instancier dynamiquement des objets, utiliser la méthode statique :
```c++
template<typename FactoryName, typename EnumType>
FactoryBaseType	*newObject(EnumType type, const std::string &params = "");
```

Cette méthode, en fonction du nom de la Factory (FactoryName), appelle la methode (statique elle aussi) de cette Factory permettant de créer une instance d'objet. Cette autre méthode peut également être appelée sans passer par celle-ci.
NB. Les objets crées au travers de la Factory doivent hériter de la classe `FactoryBaseType`. Toute Factory doit faire partie du namespace `Factories`.

Utiliser la méthode suivante permet de créer un nouvel objet de type `FactoryBaseType` [(FactoryBaseType.hpp)](./FactoryBaseType.hpp)
```c++
FactoryBaseType	*newObject();
```

### Utilisation

```{c++, count_lines}
// data.hpp
#include "factory/FactoryBaseType.hpp"

/* on définit un enum à utiliser. */
typedef enum { A, B, C } MyEnum;

/* on définit la classe  */
class MyClass : public Factories::FactoryBaseType { ... };
```

```{c++, count_lines}
// main.cpp
#include "factory/Factory.hpp"
#include "data.hpp" // code ci-dessus

int main()
{
	/* Création de l'objet sans autre paramètre que l'enum */
	MyClass *obj1 = Factories::Factory::newObject<Factories::MyClassFactory, MyEnum>(A);

	/* Création de l'objet avec un second paramètre pour l'initialiser */
	MyClass *obj2 = Factories::Factory::newObject<Factories::MyClassFactory, MyEnum>(A, "str");

	delete obj1;
	delete obj2;
	return (0);
}
```
