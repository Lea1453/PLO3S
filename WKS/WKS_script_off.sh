#!/bin/bash  

for file in ./in/*.off
do
    outputFile=${file/.off/_tmp.txt}
    echo $outputFile
    outputFile_vert=${file/.off/_vert.txt}
    echo $outputFile_vert
    outputFile_face=${file/.off/_face.txt}
    echo $outputFile_face
    #permet de commencer à la 3eme ligne
    tail -n +3 "$file" > "$outputFile"
    #prend les 3 premier colonnes
  #  awk 'NF{NF-=3};3' < ${outputFile} > ${outputFileTmp2}
    #sed 's/^\( + +\) * * *$/\1/g' "$outputFile" > ${outputFileTmp2} 

    #permet de separer les triangle (commentcent pas 3) et les vertices
    sed '/^3 /d' "$outputFile" > ${outputFile_vert} 
    sed -n 's/^3 //p' "$outputFile" > ${outputFile_face} 
done 



