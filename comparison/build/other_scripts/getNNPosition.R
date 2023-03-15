#!/usr/bin/env Rscript
library(fields)

args <- commandArgs(trailingOnly = TRUE)

n = (length(args))

nameOut = args[2]



tX <- read.table(args[1])
mX <- as.matrix(tX)

#mX = t(mX[nrow(mX):1,])


vecBestScore = apply(mX, 1, function(x) (sort(x))[2])
vecBestPos = apply(mX, 1, function(x) (order(x))[2])

print(as.vector(t(vecBestPos)))
test=as.vector(t(vecBestPos))

write.table(vecBestPos, file = nameOut, sep = "\n",
            row.names = FALSE, col.names = FALSE)

