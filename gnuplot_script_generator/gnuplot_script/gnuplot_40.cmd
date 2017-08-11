set title "Evolution de la taille des nodules en fonction du temps"
set xlabel "jours"
set ylabel "taille du nodule"
set grid

plot   "../data_of_patients/40.dat" using 1:2 with lines title "patient 40 DCT"
replot "../data_of_patients/40.dat" using 1:4 with lines title "patient 40 DCVD"
replot "../data_of_patients/40.dat" using 1:3 with lines title "patient 40 DSOL"

set terminal png
set output "data_of_patient_40.png"
replot
set terminal x11
pause -1 "appuyez sur une touche pour continuer"
