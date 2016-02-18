#ifndef DICTATTACK_HH
#define DICTATTACK_HH

#include <iostream>
#include <list>
#include <fstream>
#include "./data/Password.hh"
#include "./MD5.hh"

class                       DictAttack {
private:
  const std::string         _resPath = "./decrypt.txt";

  std::string               _pswPath;
  std::string               _dictPath;
  std::list<Password*>      *_passwords;
  std::list<std::string>    *_dict;

  // std::string               decryptMD5(const std::string psw);
  void                      feedDict();
  void                      feedPsw();

public:
  DictAttack (const std::string pswPath, const std::string dictPath);
  ~DictAttack ();

  void                      decryptPswds();
  void                      saveDecrypt();

  std::list<Password*>      *getPasswords() const;
};

#endif /* DictAttack */
