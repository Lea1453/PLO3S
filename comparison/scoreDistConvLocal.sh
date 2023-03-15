#! /bin/bash

filesIn=""
filesR=""

fdb="dataSet_PPI4DOCK_100"



for fmkdir in out/${fdb}; do
    echo "${fmkdir}"
    mkdir -p "${fmkdir}"
done
mkdir -p "out/${fdb}"


#dog2 = 27

listPathMat=`ls in/${fdb}/1_curveElev_NoSmoothering.asc | sort -V`

echo "${listPathMat}"
listMat=${listPathMat//in\/${fdb}\/1/}
echo "${listMat}"


#permet de reperer les differentes matrices a faire
for fMat in $listMat; do
    filesIn=""
    
    for fin in `ls in/${fdb}/*${fMat} | sort -V` ; do
	
	echo "${fin}"
	filesIn="${filesIn} ${fin}"

	
    done

    fout=${fin//\.txt/}
    fout=${fout//in\//out\/}
    #si 2 chiffres pour le plus grand : [[:digit:]][[:digit:]]
    fout=${fout//[[:digit:]][[:digit:]]_/}



    echo "fout : ${fout}"

    ./scoreDistCvxLocal ${filesIn} "${fout}"
    
done


filesRin=""
filesRout=""
fileREADME="out/${fdb}/README.txt"
 
for finR in `ls out/${fdb}/*Elev_*score.txt | sort -V`; do 
   # echo "${finR}"
    filesRin="${filesRin} ${finR}"
    foutR=${finR//\.txt/\.png}
    filesRout="${filesRout} ${foutR}"
done



./matrixScore.R ${filesRin} ${fileREADME} ${filesRout} 


