#!/bin/sh

## des erreurs surviennent a l'execution, ces erreurs sont aux differentes conditions :
## lignes 33, 38, 43, 48 et 53. Nous ne savons pas a quoi elles sont liees, ni comment les resoudre. 

help () {
    echo "Exemple"
    echo "./ssh_tunnel.sh [--local_port 2080] [--hostname localhost] [--distant_port 80] [--user utilisateur] [--host serveurweb.org]"
    echo "./ssh_tunnel.sh [--help]"
}

local_port=0
hostname="null"
distant_port=0
user="null"
host="null"

if [ $# -eq 1 ]
then
    if [ $1 = "--help" ]; then
        help
    else
        echo "Mauvais parametre..."
        echo "Tapez 'ssh_tunnel.sh --help pour plus d'informations"
    fi
    exit 0
elif [ $# -eq 10 ]
then
    count=`expr $# - $#`
    number=$#
    while [ $count -le $number ]
    do
        if [ $1 = "--local_port" ]
        then
            shift
            local_port=$1
            count=`expr $count + 1`
        elif [ $1 = "--hostname" ]
        then
            shift
            hostname=$1
            count=`expr $count + 1`
        elif [ $1 = "--distant_port" ]
        then
            shift
            distant_port=$1
            count=`expr $count + 1`
        elif [ $1 = "--user" ]
        then
            shift
            user=$1
            count=`expr $count + 1`
        elif [ $1 = "--host" ]
        then
            shift
            host=$1
            count=`expr $count + 1`
        fi
        if [ $count -lt $number ]
        then
            shift
        fi
        count=`expr $count + 1`
    done

    #echo "ssh -L $local_port:$hostname:$distant_port $user@$host"
    ssh -L $local_port:$hostname:$distant_port $user@$host

else
    echo "Erreur : pas assez de parametres..."
    echo "Tapez 'ssh_tunnel.sh --help pour plus d'informations"
    exit 1
fi
