#!/bin/bash

## Isole les mots de passe non crackés
## dans un fichier encrypt.txt
grep -v '=' decrypt.txt > encrypt.txt
