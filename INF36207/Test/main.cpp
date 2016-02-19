#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <fstream>

std::mutex mtx;

/**
 ** Info: Génère toutes les string de longueur fixe possible celon un alphabet
 ** Parametres:
 **   alpha: L'alphabet de référence
 **   prefix: La string qui se génère (doit être lancée vide depuis la fonction appelante)
 **   length: La longeur de la string à générée
 **   bound: La borne des strings à générer (EX: 'a' vas générer que les string qui commence par 'a')
 **   file: les fichier dans lequel on ecrit les résultats
 ** Reference: http://www.geeksforgeeks.org/print-all-combinations-of-given-length/
**/
void generator(std::string alpha, std::string prefix, int length, char bound, std::ofstream *file) {
  std::string newPrefix;

  if (length == 0) {
    mtx.lock();
    *file << prefix << std::endl;
    mtx.unlock();
    return;
  }

  if (prefix == "") {
    newPrefix = prefix + bound;
    generator(alpha, newPrefix, length - 1, bound, file);
  } else {
    for (size_t i = 0; i < alpha.length(); i++) {
      newPrefix = prefix + alpha[i];
      generator(alpha, newPrefix, length - 1, bound, file);
    }
  }
}

int main(int argc, char const *argv[]) {
  //Démarre un chrono
  std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

  std::string alpha = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";  //Alphabet de référence
  std::thread t[alpha.length()];                                      //Tableau de thread = nombre de lettre dans l'alphabet
  std::ofstream fichier("./test.txt");                                //Le fichier dans lequel écrire
  int length = 4;                                                     //La longueur des strings à générer

  //On lance un thread pour chaque lettre de l'alphabet
  for (size_t i = 0; i < alpha.length(); i++) {
    t[i] = std::thread(generator, alpha, "", length, alpha[i], &fichier);
  }

  //On attend la fin des threads
  for (size_t i = 0; i < alpha.length(); i++) {
    t[i].join();
  }

  //Affiche le temps d'execution
  std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
  std::cout << "took " << sec.count() << " seconds\n";
  return 0;
}
