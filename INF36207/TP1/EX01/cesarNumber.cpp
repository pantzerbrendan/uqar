#include "cesarNumber.hh"

/**
 ** Constructeur
**/
CesarNumber::CesarNumber(std::string pswd, char ref) {
  this->_pswd = pswd;
  this->_freq = new std::map<char, int>();
  this->_keyMap = new std::map<char, char>();
  this->_pswdDecrypt = new std::string();

  this->calcStat();
  this->calcDict(ref);
  this->decrypt();
}

/**
 ** Destructeur
**/
CesarNumber::~CesarNumber() {
  delete(this->_pswdDecrypt);
  delete(this->_freq);
  delete(this->_keyMap);
}

/**
 ** Info: Calcule la frequence d'appartition des lettres
 ** Param: La string à analyser
 ** Return: Une map contenant le nombre d'apparition de chaque lettre
**/
void		CesarNumber::calcStat() {
  this->_freq->clear();

  for(unsigned int i = 0; i < this->_pswd.length(); i++) {
    if (this->_freq->find(this->_pswd[i]) != this->_freq->end())
      (*this->_freq)[this->_pswd[i]] += 1;
    else
      (*this->_freq)[this->_pswd[i]] = 1;
  }

}

/**
 ** Info: Calculer décalage à partir d'un lettre de reference
 ** (La lettre E etant la lettre à sortir le plus souvent dans
 ** la langue fr
 ** Param: La lettre de reference
**/
void		CesarNumber::calcDict(char ref) {
  char		key;
  int		tmp;

  this->_keyMap->clear();

  tmp = 0;
  for (std::map<char, int>::iterator iter = this->_freq->begin(); iter != this->_freq->end(); iter++) {
    if (iter->second > tmp) {
      key = iter->first;
      tmp = iter->second;
    }
  }
  
  if ((tmp = key - ref) < 0)
    tmp *= -1;

  for (int i = 0, j = tmp; i < NB_ALPHA; i++, j++) 
    (*this->_keyMap)[(char)((j % NB_ALPHA) + 65)] = (char)(i + 65);
}

/**
 ** Info: Decrypte le message
**/
void		CesarNumber::decrypt() {

  for (unsigned int i = 0; i < this->_pswd.length(); i++) {
    this->_pswdDecrypt->push_back((*this->_keyMap)[this->_pswd[i]]);
  }
}

/**
 ** Info: Imprime une map
 ** Param: Le map à imprimer
**/
template<typename T, typename V>
void				CesarNumber::printMap(std::map<T, V> *map) {
  for (typename std::map<T, V>::iterator iter = map->begin(); iter != map->end(); iter++)
    std::cout << "Key: " << iter->first << " = " << iter->second << std::endl;
}

/**
 ** Getter
**/
std::string			CesarNumber::getPswd() {
  return (this->_pswd);
}

std::string			CesarNumber::getPswdDecrypt() {
  return (*this->_pswdDecrypt);
}

/**
 ** Setter
**/
void				CesarNumber::setPswd(std::string pswd, char ref) {
  this->_pswd = pswd;

  this->_pswdDecrypt->clear();
  this->calcStat();
  this->calcDict(ref);
  this->decrypt();
}
