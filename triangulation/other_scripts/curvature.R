#!/usr/bin/env Rscript
library(fields)

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))
print(args)
print(n)

for(i in 1:(n%/%2))
{
	tX <- read.table(args[i])
	mX <- as.matrix(tX)

	#print(i)	
	#print(args[i])
	#print(args[(n%/%2)+i])

	png(filename=args[(n%/%2)+i], width=ncol(mX)*1.5, height=nrow(mX)*1.5)


	#par(mar=c(1,5,5,1))
	#pin est en inch, qui sur mon ecran est environ 72 pixel
	par(pin=c(ncol(mX)/72,nrow(mX)/72))
	image.plot(t(mX[nrow(mX):1,]), xlab="", ylab="", axes=FALSE, main="Carte de courbure")
	#image(1:ncol(mX), 1:nrow(mX),t(mX[nrow(mX):1,]), xlab="", ylab="", axes=FALSE, main="Carte de convexite")
	#axis(3, at=seq(0,1,by=1.05/nrow(mX)), labels=names_obj, las = 2)
	#axis(2, at=seq(0,1,by=1.05/nrow(mX)), labels=names_obj[length(names_obj):1], las = 2)
	dev.off()
	#png(filename=args[5])
	#par(mar=c(1,5,5,1))
	#image(t(mY[nrow(mY):1,]),axes=FALSE)
	#axis(3, at=seq(0,1,by=1.05/nrow(mY)), labels=names_obj, las = 2)
	#axis(2, at=seq(0,1,by=1.05/nrow(mY)), labels=names_obj[length(names_obj):1], las = 2)
	#dev.off()
	
}
