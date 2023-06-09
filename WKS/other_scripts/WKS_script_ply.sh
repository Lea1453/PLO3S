#!/bin/bash  

for file in ./in/*.ply
do
    outputFile=${file/.ply/_tmp.txt}
    echo $outputFile
    outputFileTmp2=${file/.ply/_tmp2.txt}
    echo $outputFileTmp2
    outputFile_vert=${file/.ply/_vert.txt}
    echo $outputFile_vert
    outputFile_face=${file/.ply/_face.txt}
    echo $outputFile_face

    #permet de commencer à la 11eme ligne
    tail -n +17 "$file" > "$outputFile"

    #prend les 3 premeire colonnes si il y a les couleurs dans le format du fichier
    awk 'NF{NF-=3};3' < ${outputFile} > ${outputFileTmp2}

    #Celui la inutile : sed 's/^\( + +\) * * *$/\1/g' "$outputFile" > ${outputFileTmp2} 

    #permet de separer les triangle (commentcent pas 3) et les vertices. Mettre "outputFileTmp2 si il y a les couleurs. Sinon outputFile
    sed '/^3 /d' "$outputFileTmp2" > ${outputFile_vert} 
    sed -n 's/^3 //p' "$outputFileTmp2" > ${outputFile_face} 
done 



