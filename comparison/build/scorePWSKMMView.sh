#! /bin/bash


#COMPARISON-------------------------------------------

filesIn=""
filesR=""


listPathMat=`ls in/1_0_curveElev_NoSmoothering.asc | sort -V`

listMat=${listPathMat//in\/1_0/}
echo "List Mat : ${listMat}"


#permet de reperer les differentes matrices a faire
for fMat in $listMat; do
    filesIn=""
    filesInSec=""

   for fin in `ls in/*${listMat} | sort -V` ; do

	filesIn="${filesIn} ${fin}"
	
    done


    #fout=${fin//\.asc/}
    fout=${fin//\.txt/}
    fout=${fout//in\//out\/}
    #si 2 chiffres pour le plus grand : [[:digit:]][[:digit:]]
    fout=${fout//[[:digit:]][[:digit:]][[:digit:]]_[[:digit:]][[:digit:]]_/}

   
    for fin in `ls in/*${listMat} | sort -V` ; do

	filesInSec="${filesInWKS} a"
	
    done
 


    echo "fout : ${fout}"

    #valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
    ./scoreDistCvxLocal ${filesIn} ${filesInWKS} "${fout}"

done



#MATRIX IMAGE-------------------------------------------


filesRin=""
filesRout=""
#this file is needed for displaying names of object on the matrix generated with R
fileNAMES="NAMES_OBJECT.txt"
 
for finR in `ls out/*Elev_score.txt | sort -V`; do 
    echo "${finR}"
    filesRin="${filesRin} ${finR}"
    foutR=${finR//\.txt/\.png}
    filesRout="${filesRout} ${foutR}"
done


./matrixScore.R ${filesRin} ${fileNAMES} ${filesRout} 

