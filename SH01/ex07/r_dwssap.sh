cat /etc/passwd | grep -v "^#" | sed -n 'n;p' | cut -f1 -d":" | rev | sort -r | awk 'NR >= ENVIRON["FT_LINE1"] && NR <= ENVIRON["FT_LINE2"]' | paste -s -d ',' - | sed 's/,/, /g' | tr '\n' '.'
