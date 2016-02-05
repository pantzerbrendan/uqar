#include "cesarNumber.hh"

int				main() {
  std::string			pswd = "FYMYRNLUNYLLYMNLYMXYJYAUMYIHNOHZUCVFYJIOLFYWUGYGVYLNYNFYVLCY";
  CesarNumber			*cesarNumber = new CesarNumber(pswd);

  std::cout << cesarNumber->getPswd() << std::endl;
  std::cout << cesarNumber->getPswdDecrypt() << std::endl;

  delete(cesarNumber);
  return (0);
}
