#include <vector>
#include <string>
#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <fstream>

#include "./MD5.hh"

std::mutex mtx;

void test_string(const std::string &to_test, std::vector<std::string> hashes, std::ofstream *file)
{
    std::string hash = md5(to_test);
    for (int index = 0; index < hashes.size(); index++)
    {
#ifdef DEBUG
            mtx.lock();
            std::clog << "\033[32m {" << to_test << "} => [" << hash << "]" << "\033[0m" << std::endl;
            mtx.unlock();
#endif
        if (hash == hashes[index])
        {
            mtx.lock();
            std::clog << "\033[35m[Found] `" << to_test << "` = [" << hashes[index] << "]\033[0m" << std::endl;
            *file << hashes[index] << " = " << to_test << std::endl;
            hashes.erase(hashes.begin() + index);
            mtx.unlock();
        }
    }
}

/**
** Info: Lit le fichier `passwords.txt`, stocke chaque ligne dans un vector et le renvoie
**/
static std::vector<std::string> read_hases()
{
    std::vector<std::string> vect;
    std::fstream file("./passwords.txt", std::ios::in);
    if (file)
    {
        std::string line;
        while (getline(file, line))
        vect.push_back(line);
    }
    return (vect);
}

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
void generator(std::string alpha, std::string prefix, int length, char bound, std::ofstream *file, std::vector<std::string> hashes) {
    //std::string newPrefix;

    if (length == 0) {
        //*file << prefix << std::endl;
        test_string(prefix, hashes, file);
        return;
    }

    if (prefix == "") {
        //newPrefix = prefix + bound;
        generator(alpha, prefix + bound, length - 1, bound, file, hashes);
    } else {
        for (size_t i = 0; i < alpha.length(); i++) {
            //newPrefix = prefix + alpha[i];
            generator(alpha, prefix + alpha[i], length - 1, bound, file, hashes);
        }
    }
}

int main(int argc, char const *argv[]) {
    //Démarre un chrono
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    std::string alpha = "abcdefghijklmnopqrstuvwxyz0123456789!@#$%&*";  //Alphabet de référence
    std::thread t[alpha.length()];                                      //Tableau de thread = nombre de lettre dans l'alphabet
    std::ofstream fichier("./found_passwords.txt");                                //Le fichier dans lequel écrire

    std::vector<std::string> hashes = read_hases();

    for(int length = 1; length <= 8; length++)
    {
        //On lance un thread pour chaque lettre de l'alphabet
        for (size_t i = 0; i < alpha.length(); i++) {
            t[i] = std::thread(generator, alpha, "", length, alpha[i], &fichier, hashes);
        }

        //On attend la fin des threads
        for (size_t i = 0; i < alpha.length(); i++) {
            t[i].join();
        }
    }
    fichier.close();
    //Affiche le temps d'execution
    std::chrono::duration<double> sec = std::chrono::system_clock::now() - start;
    std::cout << "took " << sec.count() << " seconds\n";
    return 0;
}
