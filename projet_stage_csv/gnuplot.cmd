set title "Evolution de la taille des nodules en fonction du temps"
set xlabel "jours"
set ylabel "taille du nodule"
set grid
plot "./data_of_patients/1.dat" using 1:2 with lines notitle
plot "./data_of_patients/1.dat" using 1:3 with lines notitle
plot "./data_of_patients/1.dat" using 1:4 with lines notitle
replot "./data_of_patients/2.dat" using 1:2 with lines notitle
replot "./data_of_patients/2.dat" using 1:3 with lines notitle
replot "./data_of_patients/2.dat" using 1:4 with lines notitle
replot "./data_of_patients/3.dat" using 1:2 with lines notitle
replot "./data_of_patients/3.dat" using 1:3 with lines notitle
replot "./data_of_patients/3.dat" using 1:4 with lines notitle
replot "./data_of_patients/4.dat" using 1:2 with lines notitle
replot "./data_of_patients/4.dat" using 1:3 with lines notitle
replot "./data_of_patients/4.dat" using 1:4 with lines notitle
replot "./data_of_patients/5.dat" using 1:2 with lines notitle
replot "./data_of_patients/5.dat" using 1:3 with lines notitle
replot "./data_of_patients/5.dat" using 1:4 with lines notitle
replot "./data_of_patients/6.dat" using 1:2 with lines notitle
replot "./data_of_patients/6.dat" using 1:3 with lines notitle
replot "./data_of_patients/6.dat" using 1:4 with lines notitle
replot "./data_of_patients/7.dat" using 1:2 with lines notitle
replot "./data_of_patients/7.dat" using 1:3 with lines notitle
replot "./data_of_patients/7.dat" using 1:4 with lines notitle
replot "./data_of_patients/8.dat" using 1:2 with lines notitle
replot "./data_of_patients/8.dat" using 1:3 with lines notitle
replot "./data_of_patients/8.dat" using 1:4 with lines notitle
replot "./data_of_patients/9.dat" using 1:2 with lines notitle
replot "./data_of_patients/9.dat" using 1:3 with lines notitle
replot "./data_of_patients/9.dat" using 1:4 with lines notitle
replot "./data_of_patients/10.dat" using 1:2 with lines notitle
replot "./data_of_patients/10.dat" using 1:3 with lines notitle
replot "./data_of_patients/10.dat" using 1:4 with lines notitle
replot "./data_of_patients/11.dat" using 1:2 with lines notitle
replot "./data_of_patients/11.dat" using 1:3 with lines notitle
replot "./data_of_patients/11.dat" using 1:4 with lines notitle
replot "./data_of_patients/12.dat" using 1:2 with lines notitle
replot "./data_of_patients/12.dat" using 1:3 with lines notitle
replot "./data_of_patients/12.dat" using 1:4 with lines notitle
replot "./data_of_patients/13.dat" using 1:2 with lines notitle
replot "./data_of_patients/13.dat" using 1:3 with lines notitle
replot "./data_of_patients/13.dat" using 1:4 with lines notitle
replot "./data_of_patients/14.dat" using 1:2 with lines notitle
replot "./data_of_patients/14.dat" using 1:3 with lines notitle
replot "./data_of_patients/14.dat" using 1:4 with lines notitle
set terminal png
set output "test.png"
replot
set terminal x11
pause -1 "appuyez sur une touche pour continuer"
