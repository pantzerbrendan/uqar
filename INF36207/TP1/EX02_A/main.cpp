#include "./include/DictAttack.hh"
#include <iostream>

int main() {
  DictAttack dictAttack("ressource/passwords.txt",
  "ressource/mots-8-et-moins.txt");
  dictAttack.decryptPswds();
  dictAttack.saveDecrypt();
  // std::list<Password*> *pswds = dictAttack.getPasswords();
  //
  // for (std::list<Password*>::iterator it = pswds->begin();
  // it != pswds->end(); it++) {
  //   std::cout << (*it)->getEncryptPsw() << std::endl;
  // }
  // std::cout << md5("plop") << std::endl;

  return (0);
}
