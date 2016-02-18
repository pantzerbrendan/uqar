#include "../include/DictAttack.hh"

DictAttack::DictAttack(const std::string pswPath, const std::string dictPath) {
  this->_pswPath = pswPath;
  this->_dictPath = dictPath;
  this->_passwords = new std::list<Password*>();
  this->_dict = new std::list<std::string>();

  feedDict();
  feedPsw();
}

DictAttack::~DictAttack() {
  delete(this->_passwords);
  delete(this->_dict);
}

void DictAttack::feedDict() {
  std::ifstream flux(_dictPath);
  std::string line;

  if (flux) {
    while (std::getline(flux, line))
    _dict->push_back(line);
  } else {
    std::cout << "Erreur: Impossible d'ouvrir le fichier "
    << _dictPath << std::endl;
  }
}

void DictAttack::feedPsw() {
  std::ifstream flux(_pswPath);
  Password *newPsw;
  std::string line;

  if (flux) {
    while (std::getline(flux, line)) {
      newPsw = new Password(line);
      _passwords->push_back(newPsw);
  }
  } else {
    std::cout << "Erreur: Impossible d'ouvrir le fichier "
    << _pswPath << std::endl;
  }
}

void DictAttack::decryptPswds() {
  std::string tmp;

  for (std::list<std::string>::iterator it1 = _dict->begin();
  it1 != _dict->end(); it1++) {
    tmp = md5((*it1));
    for (std::list<Password*>::iterator it2 = _passwords->begin();
    it2 != _passwords->end(); it2++) {
      if (tmp == (*it2)->getEncryptPsw()) {
        std::cout << "Trouvé: " << (*it2)->getEncryptPsw()
        << " = " << (*it1) << std::endl;
        (*it2)->setDecryptPsw(*it1);
      }
    }
  }
}

void DictAttack::saveDecrypt() {
  std::ofstream flux(_resPath);

  if (flux) {
    for (std::list<Password*>::iterator it = _passwords->begin();
    it != _passwords->end(); it++) {
      flux << (*it)->getEncryptPsw();
      if (!((*it)->getDecryptPsw()).empty())
        flux << " = " << (*it)->getDecryptPsw();
      flux << std::endl;
    }
  } else {
    std::cout << "Erreur: Impossible d'ouvrir le fichier" << std::endl;
  }
}

std::list<Password*> *DictAttack::getPasswords() const {
  return (_passwords);
}
