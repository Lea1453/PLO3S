#!/usr/bin/env Rscript
library(fields)

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))
print(args)
print(n)

names_obj_t = read.table(args[(n%/%2)+1])$V1
names_obj_t = sub("^([^.]*).*", "\\1", names_obj_t) 


names_obj <- names_obj_t
for(i in 31:120) {
names_obj[31:40] <- names_obj_t[91:100]
names_obj[41:60] <- names_obj_t[31:50]
names_obj[71:80] <-  names_obj_t[111:120]
names_obj[81:90] <-  names_obj_t[51:60]
names_obj[91:110] <-names_obj_t[71:90]
names_obj[111:120] <- names_obj_t[101:110]
}

#permet d'elimienr les objets 67 et 68 (car outliers)
#names_obj = names_obj[-67:-68]

normalit<-function(m){
     255*(m - min(m))/(max(m)-min(m))
}


for(ti in 1:(n%/%2))
{
	tX <- read.table(args[ti])

	tX_tmp <- tX

	for(i in 1:120) {
		for(j in 1:120) {

		if(i > 30 && i < 41)
			tX[i,j] = tX_tmp[(i+60-1)%%120+1,(j+60-1)%%120+1]
		if(j > 30 && j < 41)
			tX[i,j] <- tX_tmp[(i+60-1)%%120+1,(j+60-1)%%120+1]

		if(i > 40 && i < 61)
			tX[i,j] = tX_tmp[(i+110-1)%%120+1,(j+110-1)%%120+1]
		if(j > 40 && j < 61)
			tX[i,j] <- tX_tmp[(i+110-1)%%120+1,(j+110-1)%%120+1]

		if(i > 70 && i < 81)
			tX[i,j] = tX_tmp[(i+40-1)%%120+1,(j+40-1)%%120+1]
		if(j > 70 && j < 81)
			tX[i,j] <- tX_tmp[(i+40-1)%%120+1,(j+40-1)%%120+1]

		if(i > 80 && i < 91)
			tX[i,j] = tX_tmp[(i+90-1)%%120+1,(j+90-1)%%120+1]
		if(j > 80 && j < 91)
			tX[i,j] <- tX_tmp[(i+90-1)%%120+1,(j+90-1)%%120+1]

		if(i > 90 && i < 111)
			tX[i,j] = tX_tmp[(i+100-1)%%120+1,(j+100-1)%%120+1]
		if(j > 90 && j < 111)
			tX[i,j] <- tX_tmp[(i+100-1)%%120+1,(j+100-1)%%120+1]

		if(i > 110 && i < 121)
			tX[i,j] = tX_tmp[(i+110-1)%%120+1,(j+110-1)%%120+1]
		if(j > 100 && j < 121)
			tX[i,j] <- tX_tmp[(i+110-1)%%120+1,(j+110-1)%%120+1]
			}
		}
	print("test")
	mX <- as.matrix(tX)

#print(mX)
	#pour rajouter les deux outliers
	#vec_minus <- c(366,511)
	#new_mX <- matrix(1,nrow=nrow(mX)+2,ncol=ncol(mX)+2)  
	#new_mX[-vec_minus,-vec_minus] <- mX

	#write.table(new_mX, file="matrix_withOutlier.txt", row.names=FALSE, col.names=FALSE)
	#FIN ajout des outliers

	#print(which(mX > 0.9, arr.ind = TRUE))
	#mX[mX > 20] <- 20
	#mX[mX > 60000] <- 60000 
			

	#permet d'elimienr les objets 67 et 68 (car outliers)
	#mX <- mX[-(67:68),-(67:68)]
	
	normalit(mX)

	#permet un meilleur contraste en rapprochant les valeurs = à 0 des autres
	#mX[mX < 190] = 190
	#normalit(mX)

	png(filename=args[(n%/%2)+1+ti], width = 2000, height = 2000, units="px")
	par(mar=c(1,5,5,7))
	image(t(mX[nrow(mX):1,]),axes=FALSE, col=heat.colors(256))
	axis(3, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj, las = 2)
	axis(2, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj[length(names_obj):1], las = 2)
	image.plot(t(mX[nrow(mX):1,]),axes=FALSE, col=heat.colors(256), legend.only=TRUE)
	dev.off()


}


