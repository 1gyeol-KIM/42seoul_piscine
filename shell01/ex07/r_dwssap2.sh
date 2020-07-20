#!/bin/bash
cat /etc/passwd | sed '/#/d' | sed '1d'| awk 'NR%2' | sed 's/:.*$//g' | rev | sort -r | awk ''$FT_LINE1' <= NR && NR <= '$FT_LINE2'' |tr '\n' ',' | sed -e 's/,/, /g' -e 's/, $/./g' | sed 's/,$/./g' | tr -d '\n'
