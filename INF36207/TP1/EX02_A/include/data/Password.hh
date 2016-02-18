#ifndef PASSWORD_HH
#define PASSWORD_HH

#include <iostream>

class           Password {
private:
  std::string   _encryptPsw;
  std::string   _decryptPsw;

public:
  Password (const std::string &psw);
  ~Password ();

  void          setDecryptPsw(const std::string psw);

  std::string   getEncryptPsw() const;
  std::string   getDecryptPsw() const;
};

#endif /* Password */
