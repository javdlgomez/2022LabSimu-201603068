unset label
clear
set terminal jpeg
set output "graficoyvsv.jpg"
set title "Yvsv"
set xlabel "velocidad"
set ylabel "altura"
set grid
set style data point
plot "cohetedatyvsv" 