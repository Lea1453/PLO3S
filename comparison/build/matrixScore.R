#!/usr/bin/env Rscript
library(fields)
library(RColorBrewer)
library("viridis")

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))
print(args)
print(n)


print(read.table(args[2])$V1)

names_obj = read.table(args[(n%/%2)+1])$V1
names_obj = sub("^([^.]*).*", "\\1", names_obj) 

#permet d'elimienr les objets 67 et 68 (car outliers)
#names_obj = names_obj[-67:-68]

normalit<-function(m){
     255*(m - min(m))/(max(m)-min(m))
}

for(i in 1:(n%/%2))
{
	tX <- read.table(args[i])
	mX <- as.matrix(tX)

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
	mX = 255 - mX

	#permet un meilleur contraste en rapprochant les valeurs = à 0 des autres
	#mX[mX < 190] = 190
	#normalit(mX)

	png(filename=args[(n%/%2)+1+i], width = 2000, height = 2000, units="px")
	par(mar=c(1,5,5,7))
	image(t(mX[nrow(mX):1,]),axes=FALSE, col=plasma(256))
	axis(3, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj, las = 2)
	axis(2, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj[length(names_obj):1], las = 2)
	image.plot(t(mX[nrow(mX):1,]),axes=FALSE, col=plasma(256), legend.only=TRUE)
	#image.plot(t(mX[nrow(mX):1,]),axes=FALSE, col=heat.colors(256), legend.only=TRUE)
	dev.off()


}


