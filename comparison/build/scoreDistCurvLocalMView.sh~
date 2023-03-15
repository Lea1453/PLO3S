#! /bin/bash

filesIn=""
filesR=""

#fdb="sDB_f_mview_norRes_test_mini" 
fdb="SHREC19_proteins"


for fmkdir in out/${fdb}; do
    echo "${fmkdir}"
    mkdir -p "${fmkdir}"
done
mkdir -p "out/${fdb}"


#dog2 = 27

#MODIF POUR ne pas CP !!! a changer apres
listPathMat=`ls ../../curvature_descriptor_WKS/out/${fdb}/1_0_curveElev_NoSmoothering.asc | sort -V`
#listPathMat=`ls in/${fdb}/1_0_curveElev_NoSmoothering.asc | sort -V`
listPathWKS=`ls in/${fdb}/1_0_wks.txt | sort -V`

echo "${listPathMat}"
#MODIF pour ne pas CP
listMat=${listPathMat//..\/..\/curvature_descriptor_WKS\/out\/${fdb}\/1_0/}
#listMat=${listPathMat//in\/${fdb}\/1_0/}
listWKS=${listPathWKS//in\/${fdb}\/1_0/}
echo "List Mat : ${listMat}"

if [ -z "$listWKS" ]; then
    echo "List WKS empty, replacing it by \"a\" string"
    isWKSEmpty=true
fi

#permet de reperer les differentes matrices a faire
for fMat in $listMat; do
    filesIn=""
    filesInWKS=""

   #MODIF POUR ne pas CP
    for fin in `ls ../../curvature_descriptor_WKS/out/${fdb}/*${listMat} | sort -V` ; do
   #for fin in `ls in/${fdb}/*${listMat} | sort -V` ; do
	
	#echo "fin : ${fin}"
	filesIn="${filesIn} ${fin}"
	
    done


    #fout=${fin//\.asc/}
    fout=${fin//\.txt/}
    #fout=${fout//in\//out\/}
    #modif pour NE PAS CP avec SHREC19_proteins
    fout=${fout//..\/..\/curvature_descriptor_WKS\/out\//out\/}
    #si 2 chiffres pour le plus grand : [[:digit:]][[:digit:]]
    fout=${fout//[[:digit:]][[:digit:]][[:digit:]]_[[:digit:]][[:digit:]]_/}

    if $isWKSEmpty ; then
	#MODIF pour ne pas CP
	for fin in `ls ../../curvature_descriptor_WKS/out/${fdb}/*${listMat} | sort -V` ; do
	#for fin in `ls in/${fdb}/*${listMat} | sort -V` ; do

	    filesInWKS="${filesInWKS} a"
	    
	done
    else
	for fin in `ls in/${fdb}/*${listWKS} | sort -V` ; do
	    
	   # echo "fin WKS : ${fin}"
	    filesInWKS="${filesInWKS} ${fin}"
	    
	done
    fi
 



    echo "fout : ${fout}"

    #valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes
    ./scoreDistCvxLocal ${filesIn} ${filesInWKS} "${fout}"

done


filesRin=""
filesRout=""
fileREADME="out/${fdb}/README.txt"
 
for finR in `ls out/${fdb}/*Elev_score.txt | sort -V`; do 
    echo "${finR}"
    filesRin="${filesRin} ${finR}"
    foutR=${finR//\.txt/\.png}
    filesRout="${filesRout} ${foutR}"
done



./matrixScore.R ${filesRin} ${fileREADME} ${filesRout}
#Permet de reorganiser la matrice, cf le fichier R car c'est fait a la main selon les données
#./matrixScore_reorganise.R ${filesRin} ${fileREADME} ${filesRout} 

