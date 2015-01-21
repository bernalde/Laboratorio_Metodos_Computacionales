wget https://raw.githubusercontent.com/forero/ComputationalLab/master/2014-2/Talleres/notas_fisicaII_201320.dat


echo "Cuántos estudiantes pasaron el primer parcial?"
awk '{if ($1>=60) print $1}' notas_fisicaII_201320.dat | wc -l
echo "Cuántos estudiantes pasaron el primer parcial, perdieron el final y pasaron la materia?"
awk '{if ($1>=60 && $5<60 && $6>=60) print $1}' notas_fisicaII_201320.dat | wc -l
echo "Cuántos estudiantes perdieron al menos un parcial y pasaron la materia?"
awk '{if (($1<60 || $2 <60 || $3 <60) && $6>=60) print $1}' notas_fisicaII_201320.dat | wc -l
echo "Cuántos estudiantes pasaron solamente dos parciales y pasaron la materia?"
awk '{if ((($1>=60 && $2>=60 && $3<60) || ($1>=60 && $2<60 && $3>=60) || ($1<60 && $2>=60 && $3>=60)) && $6>=60) print $1}' notas_fisicaII_201320.dat | wc -l
