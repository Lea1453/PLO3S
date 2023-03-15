#!/usr/bin/env Rscript
library(fields)

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))
print(args)
print(n)

names_obj = read.table(args[(n%/%2)+1])$V1
names_obj = sub("^([^.]*).*", "\\1", names_obj) 

normalit<-function(m){
     255*(m - min(m))/(max(m)-min(m))
}


for(i in 1:(n%/%2))
{
	tX <- read.table(args[i])
	mX <- as.matrix(tX)

	mX[mX > 100] <- 100
	normalit(mX)
	png(filename=args[(n%/%2)+1+i], width = 1000, height = 1000, units="px")
	par(mar=c(1,5,5,7))
	image(t(mX[nrow(mX):1,]),axes=FALSE, col=heat.colors(256))
	axis(3, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj, las = 2)
	axis(2, at=seq(0,1,by=(1+(1/nrow(mX)))/nrow(mX)), labels=names_obj[length(names_obj):1], las = 2)
	image.plot(t(mX[nrow(mX):1,]),axes=FALSE, col=heat.colors(256), legend.only=TRUE)
	dev.off()


}


