#include "../../include/data/Password.hh"

Password::Password(const std::string &psw) {
  this->_encryptPsw = psw;
  this->_decryptPsw = "";
}

Password::~Password() {}

void        Password::setDecryptPsw(const std::string psw) {
  this->_decryptPsw = psw;
}

std::string Password::getEncryptPsw() const {
  return (this->_encryptPsw);
}

std::string Password::getDecryptPsw() const {
  return (this->_decryptPsw);
}
