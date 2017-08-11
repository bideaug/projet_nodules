set title "Evolution de la taille des nodules en fonction du temps"
set xlabel "jours"
set ylabel "taille du nodule"
set grid

plot   "../data_of_patients/11.dat" using 1:2 with lines title "patient 11 DCT"
replot "../data_of_patients/11.dat" using 1:4 with lines title "patient 11 DCVD"
replot "../data_of_patients/11.dat" using 1:3 with lines title "patient 11 DSOL"

set terminal png
set output "data_of_patient_11.png"
replot
set terminal x11
pause -1 "appuyez sur une touche pour continuer"
