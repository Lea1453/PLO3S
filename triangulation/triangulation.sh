#! /bin/bash

filesInCurvElev=""
fout=""
headCurvEle=""

for fin in `ls in/*curveElev.asc | sort -V` ; do
    filesInCurvElev="${filesInCurvElev}${fin} "
done


echo "triangulation..."
while [ -n "$filesInCurvElev" ]; do

    headCurvElev=`echo "$filesInCurvElev" | cut -d ' ' -f 1`
    filesInCurvElev=`echo "$filesInCurvElev" | sed 's/[^ ]* *\(.*\)$/\1/'`

    fout=${headCurvElev//\.asc/}
    fout=${fout//in\//out\/}
    echo "${fout}"
    echo "${headCurvElev}"
    echo " "
    ./convex ${headCurvElev} ${fout}

done

