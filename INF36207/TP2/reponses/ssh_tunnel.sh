#!/bin/sh

#ssh_tunnel.sh -local_port 2080 -h[ostname] localhost -distant_port 80 -u utilisateur -host serveurweb.org
#ssh_tunnel.sh --help

help () {
    echo "AIDE"
}

local_port=0
hostname="null"
distant_port=0
user="null"
host="null"

if [ $# -eq 1 ]; then
    help
    exit 0
elif [ $# -eq 10 ]; then
    count=`expr $# - $#`
    while [ $count -le $# ]; do
        if [ $1 = "--local_port" ]; then
            shift
            local_port=$1
            count=`expr $count + 1`
        elif [ $1 = "-h" ] || [ $1 = "--hostname" ]; then
            shift
            hostname=$1
            count=`expr $count + 1`
        elif [ $1 = "--distant_port" ]; then
            shift
            distant_port=$1
            count=`expr $count + 1`
        elif [ $1 == "--user" ]; then
            shift
            user=$1
            count=`expr $count + 1`
        elif [ $1 = "--host" ]; then
            shift
            host=$1
            count=`expr $count + 1`
        fi
        shift
        count=`expr $count + 1`
    done

    echo "ssh -L $local_port:$hostname:$distant_port $user@$host"
    ssh -L $local_port:$hostname:$distant_port $user@$host

else
    echo "Erreur : pas assez de parametres..."
    echo "Tapez 'ssh_tunnel.sh --help pour plus d'informations"
    exit 1
fi
