unset label
clear
set terminal jpeg
set output "graficoyvst.jpg"
set title "Yvst"
set xlabel "altura"
set ylabel "tiempo"
set grid
set style data point
plot "cohetedattvsy" 