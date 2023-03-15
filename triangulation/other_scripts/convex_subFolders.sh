#! /bin/bash

filesInCurvElev=""
filesInderiv=""
fout=""
filesRin=""
filesCurve=""
filesCurveIn=""
foutCurve=""
filesCurveOut=""
filesRout=""
fdb="Shrec17_resDan_best4_MAD"
 



#for fin in ascii/${fdb}/${fcl}/"${ftype}"/*_deriv.asc; do 
for fin in `ls in/${fdb}/*/*_deriv.asc | sort -V` ; do
#for fin in  ascii/${fdb}/"${ftype}"/{3900..5494}*_deriv.asc  ; do
    #  echo "${fin}"
    
    fmkdir=`echo ${fin} | sed 's/\(.*\)\/.*/\1/'`
    fmkdir=${fmkdir//in/out}
    echo ${fmkdir}
    mkdir -p "${fmkdir}"
    
    filesInderiv="${filesInderiv}${fin} "
done

#for fin in ascii/${fdb}/${fcl}/"${ftype}"/*_deriv.asc; do 
for fin in `ls in/${fdb}/*/*.asc | sort -V` ; do
#for fin in  ascii/${fdb}/{3900..5494}*.asc  ; do
    if [[ "${fin}" != *deriv* ]]; then
	filesInCurvElev="${filesInCurvElev}${fin} "
    fi
done


echo "calcul de la convexité"
while [ -n "$filesInderiv" ]; do
    

    
    headderiv=`echo "$filesInderiv" | cut -d ' ' -f 1`
    filesInderiv=`echo "$filesInderiv" | sed 's/[^ ]* *\(.*\)$/\1/'`
    headCurvElev=`echo "$filesInCurvElev" | cut -d ' ' -f 1`
    filesInCurvElev=`echo "$filesInCurvElev" | sed 's/[^ ]* *\(.*\)$/\1/'`

    fout=${headderiv//_deriv\.asc/}
    fout=${fout//in/out}

    #echo "${fout}"
    #echo "${headderiv}"
    #echo "${headCurvElev}"
    ./convex ${headCurvElev} ${headderiv} ${fout}

done



echo "recuperation des fichier pour la heatmap"
for finR in `ls out/${fdb}/*/*.txt | sort -V`; do
#for finR in  out/${fdb}/"${ftype}"/{251..1000}_*.txt ; do 
    echo "${finR}"
    if [[ "${finR}" != *Curvature* ]]; then
	filesRin="${filesRin} ${finR}"
	foutR=${finR//\.txt/\.png}
	filesRout="${filesRout} ${foutR}"
    else
	filesCurveIn="${filesCurveIn} ${finR}"
	foutCurve=${finR//\.txt/\.png}
	filesCurveOut="${filesCurveOut} ${foutCurve}"
    fi
done
echo "calcul des heatmap"
./mapConvexity.R ${filesRin} ${filesRout} 
#./curvature.R ${filesCurveIn} ${filesCurveOut} 
#/./saveMat_png.R  ${filesRin} ${filesRout} 
