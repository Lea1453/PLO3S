#!/usr/bin/env Rscript



print(args)

tabTmp = read.table("out/SHREC19_proteins/5_0_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = unlist(vecLtmp)

tabTmp = read.table("out/SHREC19_proteins/5_1_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = c(vecL,unlist(vecLtmp))

tabTmp = read.table("out/SHREC19_proteins/5_2_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = c(vecL,unlist(vecLtmp))

tabTmp = read.table("out/SHREC19_proteins/5_3_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = c(vecL,unlist(vecLtmp))

tabTmp = read.table("out/SHREC19_proteins/5_4_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = c(vecL,unlist(vecLtmp))

tabTmp = read.table("out/SHREC19_proteins/5_5_curveElev_NoSmoothering.asc", skip=1)
matTmp = as.matrix(tabTmp)
vecLtmp = c(matTmp)

vecL = c(vecL,unlist(vecLtmp))

vecF=vecL[which(vecL[]<5)]

quantile(vecF, probs = seq(.1, .9, by = .1))

hist(vecF, breaks=59)


