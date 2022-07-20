unset label
clear
set terminal jpeg
set output "graficovvst.jpg"
set title "vvst"
set xlabel "velocidad"
set ylabel "tiempo"
set grid
set style data point
plot "cohetedattvsv"