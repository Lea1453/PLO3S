n=403
timeEla=0



for ix= 1:n
  file_query= strcat('./SHREC19_proteins_final_out/',int2str(ix),'_wks.txt'); 
  datQ=load(file_query);
  nq = size(datQ,1);
  for iy=1:n
    
    file_target= strcat('./SHREC19_proteins_final_out/',int2str(iy),'_wks.txt');
    datT=load(file_target);
    nt = size(datT,1);

    t=cputime
    tic;
    score(ix,iy)=0.0;
    fprintf('Comparing shape %d and %d \n',ix, iy);
    for jx = 1:round(nq/50)
      for jy = 1:round(nt/50)
	vTmp = datQ(jx,:) - datT(jy,:);
	vTmp = abs(vTmp);
	
	res(jx,jy) = sum(vTmp);


      end
    end

    fprintf('Finding minimum \n');
    for jx = 1:min(round(nq/50),round(nt/50))

      if size(res)(1) > 1 && size(res)(2) > 1
	[resTmp,iMinTmp] = min(res);
	[scoreTmp,iMinCol] = min(res(iMinTmp));
	iMinRow = iMinTmp(iMinCol);
      elseif size(res)(1) > 1
	iMinCol = 1;
	[scoreTmp,iMinRow] = min(res);
      else
	iMinRow = 1;
	[scoreTmp,iMinCol] = min(res);
      end
	


      res(iMinRow,:) = []; 
      res(:,iMinCol) = [];
      

      score(ix,iy) = score(ix,iy) + scoreTmp;


    end
    toc
    timeEla=timeEla+(cputime-t)
    fprintf("Time spend for 1 comparison : %f \n", timeEla);
  end
  dlmwrite('./score_SHREC19_tmp.txt',score,'delimiter',' ','precision',5);                                                                                    
end

fprintf('Time spend for WKS : %f \n', timeEla);
outputName = strcat('./score_SHREC19_final.txt');
dlmwrite(outputName,score,'delimiter',' ','precision',5);
				%save("-ascii", outputName, "WKS");
