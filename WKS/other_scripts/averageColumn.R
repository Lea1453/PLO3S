#!/usr/bin/env Rscript

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))

#cree le vecteur final composé de 0
resFinal = numeric(100)

png(filename=args[n], width = 3000, height = 2000, units="px")

for(i in 1:(n-1))
{
	ta <- read.table(args[i], sep=" ")
	mx <- as.matrix(ta)
	me <- colMeans(mx)
	resFinal = resFinal + me

	if(i == 4)
	{
		plot(resFinal, main="Average value per position in descriptor", xlab="Position in descriptor", ylab="Average value", col="blue")
		resFinal = numeric(100)
	}
	else if (i == 8)
	{
		lines(resFinal, col="red")
		resFinal = numeric(100)
		print(resFinal)
	}
	else if (i == 12)
	{
		print(resFinal)
		lines(resFinal, col="green")
		resFinal = numeric(100)
	}
	else if (i == 16)
	{
		print(resFinal)
		lines(resFinal, col="black")
		resFinal = numeric(100)
	}



}




dev.off()



