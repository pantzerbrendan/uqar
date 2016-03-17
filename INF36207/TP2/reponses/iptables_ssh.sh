#!/bin/sh

iptables -F; iptables -X

iptables -t filter -A INPUT -p tcp --dport 49876 -j ACCEPT
iptables -t filter -A OUTPUT -p tcp --dport 49876 -j ACCEPT

iptables -t filter -A INPUT -j DROP
iptables -t filter -A OUTPUT -j DROP

iptables -L
