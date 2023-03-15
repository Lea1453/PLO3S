#!/usr/bin/env Rscript

library(fields)
print("mapConvexity.R")
args <- commandArgs(trailingOnly = TRUE)

n = (length(args))
print(args)
print(n)

normalit<-function(m){
     255*(m - min(m))/(max(m)-min(m))
}



grays = rgb(red = 0:255/255, blue = 0:255/255, green = 0:255/255)
for(i in 1:(n%/%2))
{

	f <- file(args[i],"r")
	headTX <- readLines(f,n=1)
	close(f)
	print(headTX)
	sizeX <- as.numeric(strsplit(headTX, " ")[[1]][1])
	sizeY <- as.numeric(strsplit(headTX, " ")[[1]][2])

	tX <- read.table(args[i],skip=1)

	#print(tX)
	#mX <- matrix(tX$V63,nrow = sizeX,ncol = sizeY)
	#byrow permet de remplir la matrice ligne parlignee
	mX <- matrix(tX$V5,nrow = sizeY,ncol = sizeX, byrow=TRUE)
	print(args[i])

	#print(mX[,1:2])


	et = 4.0
	
	#mX[mX > 0.5] = 0.5
	#mX[mX < -0.5] = -0.5
	#mX[mX < (min(mX) + (et*(max(mX)-min(mX)))/(2*8) )] <- (min(mX) + (et*(max(mX)-min(mX)))/(2*8) )
	#mX[mX > (max(mX) - (et*(max(mX)-min(mX)))/(2*8) )] <- (max(mX) - (et*(max(mX)-min(mX)))/(2*8) )
	#print((min(mX) + (et*(max(mX)-min(mX)))/(2*8) ))
	#print( (max(mX) - (et*(max(mX)-min(mX)))/(2*8) ))

	#normalit(mX)
	#on doit faire ceci sinon l'image a une rotation de 90 deg
	 #mX <- t(mX[nrow(mX):1,,drop=FALSE])

	
	#png(filename=args[(n%/%2)+i],width = ncol(mX), height = nrow(mX))
	png(filename=args[(n%/%2)+i], width=ncol(mX)*1.5, height=nrow(mX)*1.5)
	#par(mar = rep(0, 4))
	#image(mX,axes=FALSE,frame.plot=FALSE, col=grays)
  	#par(pin=c(ncol(mX)/72,nrow(mX)/72))

	par(mar = rep(0,4))
	#image.plot(mX, xlab="", ylab="", axes=FALSE, main="Carte de courbure")
	#le transpose (t) et le nrow:1 sont OBLIGATOIRE pour avoir uen carte correct avec image / image plot
	image(t(mX[nrow(mX):1,]), axes=FALSE)
	
	dev.off()
	#heatmap(matrix(mX, nrow(mX), ncol(mX)), ,Rowv=NA,Colv=NA,col=grays, scale = "none")

	#dev.off()

	

}
