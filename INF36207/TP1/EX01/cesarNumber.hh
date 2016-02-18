#ifndef CESARNUMBER_HH
#define CESARNUMBER_HH

#include <cstdlib>
#include <iostream>
#include <map>

#define NB_ALPHA 26

class			CesarNumber {

private:
  std::string		_pswd;
  std::string		*_pswdDecrypt;
  std::map<char, int>	*_freq;
  std::map<char, char>	*_keyMap;

  /* Fonctions */
  void			calcStat(); //Calcule la frequence d'appartition des lettres
  void			calcDict(char ref); //Calcule le nouveau dictionnaire
  void			decrypt(); //Decrypte le message

  template<typename T, typename V>
  void			printMap(std::map<T, V> *map); //Affiche une map

public:
  /* Constructeur / Destructeur */
  CesarNumber(std::string pswd, char ref = 'E');
  ~CesarNumber();

  /* Getter / Setter */
  std::string		getPswd();
  void			setPswd(std::string pswd, char ref = 'E');
  std::string		getPswdDecrypt();

  /* Fonctions */
};

#endif /* CESARNUMBER_HH */
