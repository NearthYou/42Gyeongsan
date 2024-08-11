#!/bin/bash
x=$(echo $FT_NBR1 | tr "'" "0" | sed -r 's"[\]"1"g' | tr '"' '2' | tr "?" "3" | tr "!" "4")
y=$(echo $FT_NBR2 | tr "mrdoc" "01234")
echo $x+$y | xargs echo "obase=13; ibase=5;" | bc | tr "0123456789ABC" "gtaio luSnemf"
