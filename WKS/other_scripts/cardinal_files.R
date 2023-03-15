#!/usr/bin/env Rscript



print(args)

tabTmp = read.table("SHREC19_proteins_final_out/5_wks.txt")
matTmp = as.matrix(tabTmp)
vecL = c(matTmp)

quantile(unlist(vecL), probs = seq(.1, .9, by = .1))

hist(unlist(vecL), breaks=59)


