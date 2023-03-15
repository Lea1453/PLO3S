source("WKS.m")

n=404
timeEla=0

for ix= 1:n
    file_vert = strcat('./in/',int2str(ix),'_vert.txt'); 
    file_faces = strcat('./in/',int2str(ix),'_face.txt');
    outputName = strcat('./out/',int2str(ix),'_wks.txt');
   
    datVert=load(file_vert);
    datFaces=load(file_faces);
    datFaces=datFaces+1;

    t=cputime;
    tic
    [WKS,E,PHI,L] = compute_WKS(datVert,datFaces );
    toc
    timeEla=timeEla+(cputime-t)
    fprintf('Time spend for 1 WKS : %f \n', timeEla);
    dlmwrite(outputName,WKS,'delimiter',' ','precision',5);
      %save("-ascii", outputName, "WKS");
end

fprintf('Time spend for WKS : %f \n', timeEla);
