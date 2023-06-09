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
fdb="nonBinaireEx"


for fmkdir in out/${fdb}; do
    echo "${fmkdir}"
    mkdir -p "${fmkdir}"
done
mkdir -p "out/${fdb}"

#long chemin pour SHREC21 sinon "in/$fdb/*curve..."
#for fin in `ls ../../mesh_curvatureDEM_multiview_triangle_WKS/out/${fdb}/*curveElev.asc | sort -V` ; do
for fin in `ls in/$fdb/*curveElev.asc | sort -V` ; do
    filesInCurvElev="${filesInCurvElev}${fin} "
done


echo "calcul de la convexité"
while [ -n "$filesInCurvElev" ]; do

    headCurvElev=`echo "$filesInCurvElev" | cut -d ' ' -f 1`
    filesInCurvElev=`echo "$filesInCurvElev" | sed 's/[^ ]* *\(.*\)$/\1/'`

    fout=${headCurvElev//\.asc/}
    fout=${fout//in\//out\/} #decommenter si on Ctrl-C Ctrl-V
    #fout=${fout//..\/..\/mesh_curvatureDEM_multiview_triangle_WKS\/out\//out\/}
    echo "${fout}"
    echo "${headCurvElev}"
    echo " "
    #  echo "${headCurvElev}"
    ./convex ${headCurvElev} ${fout}

done



echo "recuperation des fichier pour la heatmap"
for finR in `ls out/${fdb}/*.asc | sort -V`; do
#for finR in  out/${fdb}/{1001..1500}_*.txt ; do 
 #   echo "${finR}"
  
	filesCurveIn="${filesCurveIn} ${finR}"
	foutCurve=${finR//\.asc/\.png}
	filesCurveOut="${filesCurveOut} ${foutCurve}"
   

done


#soit on choisit la version "mapConvexity, avec des info
#soit la version saveMat_png qui est brut (sans info, juste la matrice)
echo "calcul des heatmap"
#./mapConvexity.R ${filesRin} ${filesRout} 
#./curvature.R ${filesCurveIn} ${filesCurveOut} 
#./saveMat_png.R  ${filesCurveIn} ${filesCurveOut} 

