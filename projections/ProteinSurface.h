/*////////////////////////////////////////////////////////////////
Permission to use, copy, modify, and distribute this program for
any purpose, with or without fee, is hereby granted, provided that
the notices on the head, the reference information, and this
copyright notice appear in all copies or substantial portions of
the Software. It is provided "as is" without express or implied
warranty.
*////////////////////////////////////////////////////////////////
// ProteinSurface.h: interface for the ProteinSurface class.
//
//////////////////////////////////////////////////////////////////////
//    7  6  6
//   7     5
//  4  4  5
//    11   10
//  8    9
//    3  2  2
//   3     1
//  0  0  1 
static const char vcmcoffset[8][3] =
{
	{0, 0, 0},{1, 0, 0},{0, 1, 0},{1, 1, 0},
	{0,0, 1},{1, 0, 1},{0, 1, 1},{1, 1, 1}
};
static const char vcmctable[256][10]=
{
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 0 0 0 0   0 oka
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 0 0 0 1   1 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 0 0 0 1   2 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 0 0 0 2   3 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 0 0 0 1   4 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 0 0 0 2   5 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 0 0 0 2   6 oke
1, 2, 0, 1,-1,-1,-1,-1,-1,-1,//1 1 1 0 0 0 0 0 3   7 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 0 0 0 1   8 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 0 0 0 2   9 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 1 0 0 0 0 2  10 okd
1, 0, 1, 3,-1,-1,-1,-1,-1,-1,//1 1 0 1 0 0 0 0 3  11 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 1 0 0 0 0 2  12 okd
1, 3, 2, 0,-1,-1,-1,-1,-1,-1,//1 0 1 1 0 0 0 0 3  13 okf
1, 1, 3, 2,-1,-1,-1,-1,-1,-1,//0 1 1 1 0 0 0 0 3  14 okf
2, 0, 1, 3, 3, 2, 0,-1,-1,-1,//1 1 1 1 0 0 0 0 4  15 oki
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 0 0 0 1  16 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 1 0 0 0 2  17 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 0 0 0 2  18 oke
1, 1, 0, 4,-1,-1,-1,-1,-1,-1,//1 1 0 0 1 0 0 0 3  19 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 0 0 0 2  20 oke
1, 4, 0, 2,-1,-1,-1,-1,-1,-1,//1 0 1 0 1 0 0 0 3  21 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 0 0 0 3  22 okh
1, 2, 4, 1,-1,-1,-1,-1,-1,-1,//1 1 1 0 1 0 0 0 4  23 okj
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 1 0 0 0 2  24 okc
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 1 0 0 0 3  25 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 1 1 0 0 0 3  26 okg
2, 0, 4, 1, 1, 3, 0,-1,-1,-1,//1 1 0 1 1 0 0 0 4  27 okk
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 1 1 0 0 0 3  28 okg
2, 2, 4, 0, 0, 3, 2,-1,-1,-1,//1 0 1 1 1 0 0 0 4  29 okm
1, 1, 3, 2,-1,-1,-1,-1,-1,-1,//0 1 1 1 1 0 0 0 4  30 okl
2, 4, 1, 3, 3, 2, 4,-1,-1,-1,//1 1 1 1 1 0 0 0 5  31 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 1 0 0 1  32 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 1 0 0 2  33 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 1 0 0 2  34 okd
1, 5, 1, 0,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 1 0 0 3  35 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 1 0 0 2  36 okc
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 1 0 0 3  37 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 1 0 0 3  38 okg
2, 0, 5, 1, 1, 2, 0,-1,-1,-1,//1 1 1 0 0 1 0 0 4  39 okm
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 1 0 0 2  40 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 1 0 0 3  41 okh
1, 3, 1, 5,-1,-1,-1,-1,-1,-1,//0 1 0 1 0 1 0 0 3  42 okf
1, 0, 5, 3,-1,-1,-1,-1,-1,-1,//1 1 0 1 0 1 0 0 4  43 okj
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 1 0 1 0 0 3  44 okg
1, 3, 2, 0,-1,-1,-1,-1,-1,-1,//1 0 1 1 0 1 0 0 4  45 okl
2, 1, 5, 3, 3, 2, 1,-1,-1,-1,//0 1 1 1 0 1 0 0 4  46 okk
2, 5, 3, 2, 2, 0, 5,-1,-1,-1,//1 1 1 1 0 1 0 0 5  47 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 1 0 0 2  48 okd
1, 0, 4, 5,-1,-1,-1,-1,-1,-1,//1 0 0 0 1 1 0 0 3  49 okf
1, 4, 5, 1,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 1 0 0 3  50 okf
2, 4, 5, 1, 1, 0, 4,-1,-1,-1,//1 1 0 0 1 1 0 0 4  51 oki
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 1 0 0 3  52 okg
2, 4, 5, 0, 0, 2, 4,-1,-1,-1,//1 0 1 0 1 1 0 0 4  53 okk
1, 4, 5, 1,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 1 0 0 4  54 okl
2, 2, 4, 5, 5, 1, 2,-1,-1,-1,//1 1 1 0 1 1 0 0 5  55 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 1 1 0 0 3  56 okg
1, 0, 4, 5,-1,-1,-1,-1,-1,-1,//1 0 0 1 1 1 0 0 4  57 okl
2, 5, 3, 1, 1, 4, 5,-1,-1,-1,//0 1 0 1 1 1 0 0 4  58 okm
2, 3, 0, 4, 4, 5, 3,-1,-1,-1,//1 1 0 1 1 1 0 0 5  59 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 1 1 1 0 0 4  60 okn
3, 5, 0, 3, 5, 3, 2, 5, 2, 4,//1 0 1 1 1 1 0 0 5  61 okq
3, 2, 1, 4, 2, 4, 5, 2, 5, 3,//0 1 1 1 1 1 0 0 5  62 okq
2, 4, 5, 3, 3, 2, 4,-1,-1,-1,//1 1 1 1 1 1 0 0 6  63 okt
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 0 1 0 1  64 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 0 1 0 2  65 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 0 1 0 2  66 okc
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 0 1 0 3  67 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 0 1 0 2  68 oke
1, 0, 2, 6,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 0 1 0 3  69 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 0 1 0 3  70 okg
2, 2, 6, 0, 0, 1, 2,-1,-1,-1,//1 1 1 0 0 0 1 0 4  71 okk
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 0 1 0 2  72 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 0 1 0 3  73 okh
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 1 0 0 1 0 3  74 okg
1, 0, 1, 3,-1,-1,-1,-1,-1,-1,//1 1 0 1 0 0 1 0 4  75 okl
1, 6, 2, 3,-1,-1,-1,-1,-1,-1,//0 0 1 1 0 0 1 0 3  76 okf
1, 3, 6, 0,-1,-1,-1,-1,-1,-1,//1 0 1 1 0 0 1 0 4  77 okj
2, 3, 6, 2, 2, 1, 3,-1,-1,-1,//0 1 1 1 0 0 1 0 4  78 okm
2, 6, 0, 1, 1, 3, 6,-1,-1,-1,//1 1 1 1 0 0 1 0 5  79 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 0 1 0 2  80 oke
1, 6, 4, 0,-1,-1,-1,-1,-1,-1,//1 0 0 0 1 0 1 0 3  81 okf
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 0 1 0 3  82 okg
2, 4, 1, 0, 0, 6, 4,-1,-1,-1,//1 1 0 0 1 0 1 0 4  83 okm
1, 2, 6, 4,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 0 1 0 3  84 okf
2, 0, 2, 6, 6, 4, 0,-1,-1,-1,//1 0 1 0 1 0 1 0 4  85 oki
1, 2, 6, 4,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 0 1 0 4  86 okl
2, 1, 2, 6, 6, 4, 1,-1,-1,-1,//1 1 1 0 1 0 1 0 5  87 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 1 0 1 0 3  88 okg
1, 6, 4, 0,-1,-1,-1,-1,-1,-1,//1 0 0 1 1 0 1 0 4  89 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 1 1 0 1 0 4  90 okn
3, 3, 0, 6, 3, 6, 4, 3, 4, 1,//1 1 0 1 1 0 1 0 5  91 okq
2, 6, 4, 2, 2, 3, 6,-1,-1,-1,//0 0 1 1 1 0 1 0 4  92 okk
2, 3, 6, 4, 4, 0, 3,-1,-1,-1,//1 0 1 1 1 0 1 0 5  93 okr
3, 4, 2, 1, 4, 1, 3, 4, 3, 6,//0 1 1 1 1 0 1 0 5  94 okq
2, 1, 3, 6, 6, 4, 1,-1,-1,-1,//1 1 1 1 1 0 1 0 6  95 okt
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 1 1 0 2  96 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 1 1 0 3  97 okh
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 1 1 0 3  98 okg
1, 5, 1, 0,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 1 1 0 4  99 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 1 1 0 3 100 okg
1, 0, 2, 6,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 1 1 0 4 101 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 1 1 0 4 102 okn
3, 6, 0, 5, 6, 5, 1, 6, 1, 2,//1 1 1 0 0 1 1 0 5 103 okq
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 1 1 0 3 104 okh
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 1 1 0 4 105 oko
1, 3, 1, 5,-1,-1,-1,-1,-1,-1,//0 1 0 1 0 1 1 0 4 106 okl
1, 0, 5, 3,-1,-1,-1,-1,-1,-1,//1 1 0 1 0 1 1 0 5 107 okp
1, 6, 2, 3,-1,-1,-1,-1,-1,-1,//0 0 1 1 0 1 1 0 4 108 okl
1, 3, 6, 0,-1,-1,-1,-1,-1,-1,//1 0 1 1 0 1 1 0 5 109 okp
3, 5, 3, 6, 5, 6, 2, 5, 2, 1,//0 1 1 1 0 1 1 0 5 110 okq
2, 6, 0, 5, 6, 5, 3,-1,-1,-1,//1 1 1 1 0 1 1 0 6 111 oks
1, 5, 4, 6,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 1 1 0 3 112 okf
1, 5, 0, 6,-1,-1,-1,-1,-1,-1,//1 0 0 0 1 1 1 0 4 113 okj
2, 4, 6, 5, 5, 1, 4,-1,-1,-1,//0 1 0 0 1 1 1 0 4 114 okk
2, 6, 5, 1, 1, 0, 6,-1,-1,-1,//1 1 0 0 1 1 1 0 5 115 okr
2, 6, 5, 4, 4, 2, 6,-1,-1,-1,//0 0 1 0 1 1 1 0 4 116 okm
2, 5, 0, 2, 2, 6, 5,-1,-1,-1,//1 0 1 0 1 1 1 0 5 117 okr
3, 1, 4, 2, 1, 2, 6, 1, 6, 5,//0 1 1 0 1 1 1 0 5 118 okq
2, 5, 1, 2, 2, 6, 5,-1,-1,-1,//1 1 1 0 1 1 1 0 6 119 okt
1, 5, 4, 6,-1,-1,-1,-1,-1,-1,//0 0 0 1 1 1 1 0 4 120 okl
1, 5, 0, 6,-1,-1,-1,-1,-1,-1,//1 0 0 1 1 1 1 0 5 121 okp
3, 6, 5, 3, 6, 3, 1, 6, 1, 4,//0 1 0 1 1 1 1 0 5 122 okq
2, 6, 5, 3, 6, 3, 0,-1,-1,-1,//1 1 0 1 1 1 1 0 6 123 oks
3, 3, 6, 5, 3, 5, 4, 3, 4, 2,//0 0 1 1 1 1 1 0 5 124 okq
2, 5, 0, 3, 5, 3, 6,-1,-1,-1,//1 0 1 1 1 1 1 0 6 125 oks
2, 1, 4, 2, 5, 3, 6,-1,-1,-1,//0 1 1 1 1 1 1 0 6 126 oku
1, 6, 5, 3,-1,-1,-1,-1,-1,-1,//1 1 1 1 1 1 1 0 7 127 okv
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 0 0 1 1 128 okb
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 0 0 1 2 129 okc
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 0 0 1 2 130 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 0 0 1 3 131 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 0 0 1 2 132 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 0 0 1 3 133 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 0 0 1 3 134 okh
1, 2, 0, 1,-1,-1,-1,-1,-1,-1,//1 1 1 0 0 0 0 1 4 135 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 0 0 1 2 136 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 0 0 1 3 137 okg
1, 7, 3, 1,-1,-1,-1,-1,-1,-1,//0 1 0 1 0 0 0 1 3 138 okf
2, 1, 7, 3, 3, 0, 1,-1,-1,-1,//1 1 0 1 0 0 0 1 4 139 okm
1, 2, 3, 7,-1,-1,-1,-1,-1,-1,//0 0 1 1 0 0 0 1 3 140 okf
2, 3, 7, 2, 2, 0, 3,-1,-1,-1,//1 0 1 1 0 0 0 1 4 141 okk
1, 1, 7, 2,-1,-1,-1,-1,-1,-1,//0 1 1 1 0 0 0 1 4 142 okj
2, 7, 2, 0, 0, 1, 7,-1,-1,-1,//1 1 1 1 0 0 0 1 5 143 okr
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 0 0 1 2 144 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 1 0 0 1 3 145 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 0 0 1 3 146 okh
1, 1, 0, 4,-1,-1,-1,-1,-1,-1,//1 1 0 0 1 0 0 1 4 147 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 0 0 1 3 148 okh
1, 4, 0, 2,-1,-1,-1,-1,-1,-1,//1 0 1 0 1 0 0 1 4 149 okl
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 0 0 1 4 150 oko
1, 2, 4, 1,-1,-1,-1,-1,-1,-1,//1 1 1 0 1 0 0 1 5 151 okp
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 1 1 0 0 1 3 152 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 1 1 0 0 1 4 153 okn
1, 7, 3, 1,-1,-1,-1,-1,-1,-1,//0 1 0 1 1 0 0 1 4 154 okl
3, 4, 1, 7, 4, 7, 3, 4, 3, 0,//1 1 0 1 1 0 0 1 5 155 okq
1, 2, 3, 7,-1,-1,-1,-1,-1,-1,//0 0 1 1 1 0 0 1 4 156 okl
3, 7, 2, 4, 7, 4, 0, 7, 0, 3,//1 0 1 1 1 0 0 1 5 157 okq
1, 1, 7, 2,-1,-1,-1,-1,-1,-1,//0 1 1 1 1 0 0 1 5 158 okp
2, 7, 2, 4, 7, 4, 1,-1,-1,-1,//1 1 1 1 1 0 0 1 6 159 oks
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 1 0 1 2 160 oke
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 1 0 1 3 161 okg
1, 1, 5, 7,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 1 0 1 3 162 okf
2, 5, 7, 1, 1, 0, 5,-1,-1,-1,//1 1 0 0 0 1 0 1 4 163 okk
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 1 0 1 3 164 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 1 0 0 1 0 1 4 165 okn
1, 1, 5, 7,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 1 0 1 4 166 okl
3, 7, 1, 2, 7, 2, 0, 7, 0, 5,//1 1 1 0 0 1 0 1 5 167 okq
1, 5, 7, 3,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 1 0 1 3 168 okf
1, 5, 7, 3,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 1 0 1 4 169 okl
2, 1, 5, 7, 7, 3, 1,-1,-1,-1,//0 1 0 1 0 1 0 1 4 170 oki
2, 0, 5, 7, 7, 3, 0,-1,-1,-1,//1 1 0 1 0 1 0 1 5 171 okr
2, 7, 2, 3, 3, 5, 7,-1,-1,-1,//0 0 1 1 0 1 0 1 4 172 okm
3, 0, 3, 5, 0, 5, 7, 0, 7, 2,//1 0 1 1 0 1 0 1 5 173 okq
2, 2, 1, 5, 5, 7, 2,-1,-1,-1,//0 1 1 1 0 1 0 1 5 174 okr
2, 0, 5, 7, 7, 2, 0,-1,-1,-1,//1 1 1 1 0 1 0 1 6 175 okt
1, 7, 5, 4,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 1 0 1 3 176 okf
2, 4, 7, 5, 5, 0, 4,-1,-1,-1,//1 0 0 0 1 1 0 1 4 177 okm
1, 7, 1, 4,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 1 0 1 4 178 okj
2, 7, 1, 0, 0, 4, 7,-1,-1,-1,//1 1 0 0 1 1 0 1 5 179 okr
1, 7, 5, 4,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 1 0 1 4 180 okl
3, 2, 4, 7, 2, 7, 5, 2, 5, 0,//1 0 1 0 1 1 0 1 5 181 okq
1, 7, 1, 4,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 1 0 1 5 182 okp
2, 7, 1, 2, 7, 2, 4,-1,-1,-1,//1 1 1 0 1 1 0 1 6 183 oks
2, 5, 4, 7, 7, 3, 5,-1,-1,-1,//0 0 0 1 1 1 0 1 4 184 okk
3, 3, 5, 0, 3, 0, 4, 3, 4, 7,//1 0 0 1 1 1 0 1 5 185 okq
2, 4, 7, 3, 3, 1, 4,-1,-1,-1,//0 1 0 1 1 1 0 1 5 186 okr
2, 0, 4, 7, 7, 3, 0,-1,-1,-1,//1 1 0 1 1 1 0 1 6 187 okt
3, 4, 7, 2, 4, 2, 3, 4, 3, 5,//0 0 1 1 1 1 0 1 5 188 okq
2, 5, 0, 3, 4, 7, 2,-1,-1,-1,//1 0 1 1 1 1 0 1 6 189 oku
2, 2, 1, 4, 2, 4, 7,-1,-1,-1,//0 1 1 1 1 1 0 1 6 190 oks
1, 4, 7, 2,-1,-1,-1,-1,-1,-1,//1 1 1 1 1 1 0 1 7 191 okv
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 0 1 1 2 192 okd
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 0 1 1 3 193 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//0 1 0 0 0 0 1 1 3 194 okg
0,-1,-1,-1,-1,-1,-1,-1,-1,-1,//1 1 0 0 0 0 1 1 4 195 okn
1, 7, 6, 2,-1,-1,-1,-1,-1,-1,//0 0 1 0 0 0 1 1 3 196 okf
2, 6, 0, 2, 2, 7, 6,-1,-1,-1,//1 0 1 0 0 0 1 1 4 197 okm
1, 7, 6, 2,-1,-1,-1,-1,-1,-1,//0 1 1 0 0 0 1 1 4 198 okl
3, 1, 2, 7, 1, 7, 6, 1, 6, 0,//1 1 1 0 0 0 1 1 5 199 okq
1, 3, 7, 6,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 0 1 1 3 200 okf
1, 3, 7, 6,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 0 1 1 4 201 okl
2, 7, 6, 3, 3, 1, 7,-1,-1,-1,//0 1 0 1 0 0 1 1 4 202 okk
3, 6, 3, 0, 6, 0, 1, 6, 1, 7,//1 1 0 1 0 0 1 1 5 203 okq
2, 3, 7, 6, 6, 2, 3,-1,-1,-1,//0 0 1 1 0 0 1 1 4 204 oki
2, 0, 3, 7, 7, 6, 0,-1,-1,-1,//1 0 1 1 0 0 1 1 5 205 okr
2, 1, 7, 6, 6, 2, 1,-1,-1,-1,//0 1 1 1 0 0 1 1 5 206 okr
2, 0, 1, 7, 7, 6, 0,-1,-1,-1,//1 1 1 1 0 0 1 1 6 207 okt
1, 4, 6, 7,-1,-1,-1,-1,-1,-1,//0 0 0 0 1 0 1 1 3 208 okf
2, 6, 7, 4, 4, 0, 6,-1,-1,-1,//1 0 0 0 1 0 1 1 4 209 okk
1, 4, 6, 7,-1,-1,-1,-1,-1,-1,//0 1 0 0 1 0 1 1 4 210 okl
3, 7, 4, 1, 7, 1, 0, 7, 0, 6,//1 1 0 0 1 0 1 1 5 211 okq
1, 4, 2, 7,-1,-1,-1,-1,-1,-1,//0 0 1 0 1 0 1 1 4 212 okj
2, 7, 4, 0, 0, 2, 7,-1,-1,-1,//1 0 1 0 1 0 1 1 5 213 okr
1, 4, 2, 7,-1,-1,-1,-1,-1,-1,//0 1 1 0 1 0 1 1 5 214 okp
2, 1, 2, 7, 1, 7, 4,-1,-1,-1,//1 1 1 0 1 0 1 1 6 215 oks
2, 7, 4, 6, 6, 3, 7,-1,-1,-1,//0 0 0 1 1 0 1 1 4 216 okm
3, 0, 6, 3, 0, 3, 7, 0, 7, 4,//1 0 0 1 1 0 1 1 5 217 okq
3, 1, 7, 4, 1, 4, 6, 1, 6, 3,//0 1 0 1 1 0 1 1 5 218 okq
2, 1, 7, 4, 6, 3, 0,-1,-1,-1,//1 1 0 1 1 0 1 1 6 219 oku
2, 4, 2, 3, 3, 7, 4,-1,-1,-1,//0 0 1 1 1 0 1 1 5 220 okr
2, 4, 0, 3, 3, 7, 4,-1,-1,-1,//1 0 1 1 1 0 1 1 6 221 okt
2, 1, 7, 4, 1, 4, 2,-1,-1,-1,//0 1 1 1 1 0 1 1 6 222 oks
1, 7, 4, 1,-1,-1,-1,-1,-1,-1,//1 1 1 1 1 0 1 1 7 223 okv
1, 6, 7, 5,-1,-1,-1,-1,-1,-1,//0 0 0 0 0 1 1 1 3 224 okf
1, 6, 7, 5,-1,-1,-1,-1,-1,-1,//1 0 0 0 0 1 1 1 4 225 okl
2, 5, 6, 7, 7, 1, 5,-1,-1,-1,//0 1 0 0 0 1 1 1 4 226 okm
3, 0, 5, 6, 0, 6, 7, 0, 7, 1,//1 1 0 0 0 1 1 1 5 227 okq
2, 7, 5, 6, 6, 2, 7,-1,-1,-1,//0 0 1 0 0 1 1 1 4 228 okk
3, 5, 6, 0, 5, 0, 2, 5, 2, 7,//1 0 1 0 0 1 1 1 5 229 okq
3, 2, 7, 1, 2, 1, 5, 2, 5, 6,//0 1 1 0 0 1 1 1 5 230 okq
2, 5, 6, 0, 2, 7, 1,-1,-1,-1,//1 1 1 0 0 1 1 1 6 231 oku
1, 6, 3, 5,-1,-1,-1,-1,-1,-1,//0 0 0 1 0 1 1 1 4 232 okj
1, 6, 3, 5,-1,-1,-1,-1,-1,-1,//1 0 0 1 0 1 1 1 5 233 okp
2, 6, 3, 1, 1, 5, 6,-1,-1,-1,//0 1 0 1 0 1 1 1 5 234 okr
2, 6, 3, 0, 6, 0, 5,-1,-1,-1,//1 1 0 1 0 1 1 1 6 235 oks
2, 5, 6, 2, 2, 3, 5,-1,-1,-1,//0 0 1 1 0 1 1 1 5 236 okr
2, 0, 3, 5, 0, 5, 6,-1,-1,-1,//1 0 1 1 0 1 1 1 6 237 oks
2, 1, 5, 6, 6, 2, 1,-1,-1,-1,//0 1 1 1 0 1 1 1 6 238 okt
1, 5, 6, 0,-1,-1,-1,-1,-1,-1,//1 1 1 1 0 1 1 1 7 239 okv
2, 4, 6, 7, 7, 5, 4,-1,-1,-1,//0 0 0 0 1 1 1 1 4 240 oki
2, 0, 6, 7, 7, 5, 0,-1,-1,-1,//1 0 0 0 1 1 1 1 5 241 okr
2, 1, 4, 6, 6, 7, 1,-1,-1,-1,//0 1 0 0 1 1 1 1 5 242 okr
2, 1, 0, 6, 6, 7, 1,-1,-1,-1,//1 1 0 0 1 1 1 1 6 243 okt
2, 2, 7, 5, 5, 4, 2,-1,-1,-1,//0 0 1 0 1 1 1 1 5 244 okr
2, 5, 0, 2, 2, 7, 5,-1,-1,-1,//1 0 1 0 1 1 1 1 6 245 okt
2, 2, 7, 1, 2, 1, 4,-1,-1,-1,//0 1 1 0 1 1 1 1 6 246 oks
1, 1, 2, 7,-1,-1,-1,-1,-1,-1,//1 1 1 0 1 1 1 1 7 247 okv
2, 3, 5, 4, 4, 6, 3,-1,-1,-1,//0 0 0 1 1 1 1 1 5 248 okr
2, 0, 6, 3, 0, 3, 5,-1,-1,-1,//1 0 0 1 1 1 1 1 6 249 oks
2, 3, 1, 4, 4, 6, 3,-1,-1,-1,//0 1 0 1 1 1 1 1 6 250 okt
1, 3, 0, 6,-1,-1,-1,-1,-1,-1,//1 1 0 1 1 1 1 1 7 251 okv
2, 5, 4, 2, 2, 3, 5,-1,-1,-1,//0 0 1 1 1 1 1 1 6 252 okt
1, 0, 3, 5,-1,-1,-1,-1,-1,-1,//1 0 1 1 1 1 1 1 7 253 okv
1, 2, 1, 4,-1,-1,-1,-1,-1,-1,//0 1 1 1 1 1 1 1 7 254 okv
0,-1,-1,-1,-1,-1,-1,-1,-1,-1//1 1 1 1 1 1 1 1 8 255 okw
};
static const char a2fVertexOffset[8][3] =
{
	{0, 0, 0},{1, 0, 0},{1, 1, 0},{0, 1, 0},
	{0,0, 1},{1, 0, 1},{1, 1, 1},{0, 1, 1}
};

static const char a2iEdgeConnection[12][2] = 
{
	{0,1}, {1,2}, {2,3}, {3,0},
	{4,5}, {5,6}, {6,7}, {7,4},
	{0,4}, {1,5}, {2,6}, {3,7}
};
static const int aiCubeEdgeFlags[256]=
{
	0x000, 0x109, 0x203, 0x30a, 0x406, 0x50f, 0x605, 0x70c, 0x80c, 0x905, 0xa0f, 0xb06, 0xc0a, 0xd03, 0xe09, 0xf00, 
    0x190, 0x099, 0x393, 0x29a, 0x596, 0x49f, 0x795, 0x69c, 0x99c, 0x895, 0xb9f, 0xa96, 0xd9a, 0xc93, 0xf99, 0xe90, 
    0x230, 0x339, 0x033, 0x13a, 0x636, 0x73f, 0x435, 0x53c, 0xa3c, 0xb35, 0x83f, 0x936, 0xe3a, 0xf33, 0xc39, 0xd30, 
    0x3a0, 0x2a9, 0x1a3, 0x0aa, 0x7a6, 0x6af, 0x5a5, 0x4ac, 0xbac, 0xaa5, 0x9af, 0x8a6, 0xfaa, 0xea3, 0xda9, 0xca0, 
    0x460, 0x569, 0x663, 0x76a, 0x066, 0x16f, 0x265, 0x36c, 0xc6c, 0xd65, 0xe6f, 0xf66, 0x86a, 0x963, 0xa69, 0xb60, 
    0x5f0, 0x4f9, 0x7f3, 0x6fa, 0x1f6, 0x0ff, 0x3f5, 0x2fc, 0xdfc, 0xcf5, 0xfff, 0xef6, 0x9fa, 0x8f3, 0xbf9, 0xaf0, 
    0x650, 0x759, 0x453, 0x55a, 0x256, 0x35f, 0x055, 0x15c, 0xe5c, 0xf55, 0xc5f, 0xd56, 0xa5a, 0xb53, 0x859, 0x950, 
    0x7c0, 0x6c9, 0x5c3, 0x4ca, 0x3c6, 0x2cf, 0x1c5, 0x0cc, 0xfcc, 0xec5, 0xdcf, 0xcc6, 0xbca, 0xac3, 0x9c9, 0x8c0, 
    0x8c0, 0x9c9, 0xac3, 0xbca, 0xcc6, 0xdcf, 0xec5, 0xfcc, 0x0cc, 0x1c5, 0x2cf, 0x3c6, 0x4ca, 0x5c3, 0x6c9, 0x7c0, 
    0x950, 0x859, 0xb53, 0xa5a, 0xd56, 0xc5f, 0xf55, 0xe5c, 0x15c, 0x055, 0x35f, 0x256, 0x55a, 0x453, 0x759, 0x650, 
    0xaf0, 0xbf9, 0x8f3, 0x9fa, 0xef6, 0xfff, 0xcf5, 0xdfc, 0x2fc, 0x3f5, 0x0ff, 0x1f6, 0x6fa, 0x7f3, 0x4f9, 0x5f0, 
    0xb60, 0xa69, 0x963, 0x86a, 0xf66, 0xe6f, 0xd65, 0xc6c, 0x36c, 0x265, 0x16f, 0x066, 0x76a, 0x663, 0x569, 0x460, 
    0xca0, 0xda9, 0xea3, 0xfaa, 0x8a6, 0x9af, 0xaa5, 0xbac, 0x4ac, 0x5a5, 0x6af, 0x7a6, 0x0aa, 0x1a3, 0x2a9, 0x3a0, 
    0xd30, 0xc39, 0xf33, 0xe3a, 0x936, 0x83f, 0xb35, 0xa3c, 0x53c, 0x435, 0x73f, 0x636, 0x13a, 0x033, 0x339, 0x230, 
    0xe90, 0xf99, 0xc93, 0xd9a, 0xa96, 0xb9f, 0x895, 0x99c, 0x69c, 0x795, 0x49f, 0x596, 0x29a, 0x393, 0x099, 0x190, 
    0xf00, 0xe09, 0xd03, 0xc0a, 0xb06, 0xa0f, 0x905, 0x80c, 0x70c, 0x605, 0x50f, 0x406, 0x30a, 0x203, 0x109, 0x000
};
static const char a2iTriangleConnectionTable[256][16] =  
{
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 8, 3, 9, 8, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 2, 10, 0, 2, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {2, 8, 3, 2, 10, 8, 10, 9, 8, -1, -1, -1, -1, -1, -1, -1},
        {3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 11, 2, 8, 11, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 9, 0, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 11, 2, 1, 9, 11, 9, 8, 11, -1, -1, -1, -1, -1, -1, -1},
        {3, 10, 1, 11, 10, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 10, 1, 0, 8, 10, 8, 11, 10, -1, -1, -1, -1, -1, -1, -1},
        {3, 9, 0, 3, 11, 9, 11, 10, 9, -1, -1, -1, -1, -1, -1, -1},
        {9, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 3, 0, 7, 3, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 9, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 1, 9, 4, 7, 1, 7, 3, 1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 4, 7, 3, 0, 4, 1, 2, 10, -1, -1, -1, -1, -1, -1, -1},
        {9, 2, 10, 9, 0, 2, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
        {2, 10, 9, 2, 9, 7, 2, 7, 3, 7, 9, 4, -1, -1, -1, -1},
        {8, 4, 7, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {11, 4, 7, 11, 2, 4, 2, 0, 4, -1, -1, -1, -1, -1, -1, -1},
        {9, 0, 1, 8, 4, 7, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
        {4, 7, 11, 9, 4, 11, 9, 11, 2, 9, 2, 1, -1, -1, -1, -1},
        {3, 10, 1, 3, 11, 10, 7, 8, 4, -1, -1, -1, -1, -1, -1, -1},
        {1, 11, 10, 1, 4, 11, 1, 0, 4, 7, 11, 4, -1, -1, -1, -1},
        {4, 7, 8, 9, 0, 11, 9, 11, 10, 11, 0, 3, -1, -1, -1, -1},
        {4, 7, 11, 4, 11, 9, 9, 11, 10, -1, -1, -1, -1, -1, -1, -1},
        {9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 5, 4, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 5, 4, 1, 5, 0, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {8, 5, 4, 8, 3, 5, 3, 1, 5, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 0, 8, 1, 2, 10, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
        {5, 2, 10, 5, 4, 2, 4, 0, 2, -1, -1, -1, -1, -1, -1, -1},
        {2, 10, 5, 3, 2, 5, 3, 5, 4, 3, 4, 8, -1, -1, -1, -1},
        {9, 5, 4, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 11, 2, 0, 8, 11, 4, 9, 5, -1, -1, -1, -1, -1, -1, -1},
        {0, 5, 4, 0, 1, 5, 2, 3, 11, -1, -1, -1, -1, -1, -1, -1},
        {2, 1, 5, 2, 5, 8, 2, 8, 11, 4, 8, 5, -1, -1, -1, -1},
        {10, 3, 11, 10, 1, 3, 9, 5, 4, -1, -1, -1, -1, -1, -1, -1},
        {4, 9, 5, 0, 8, 1, 8, 10, 1, 8, 11, 10, -1, -1, -1, -1},
        {5, 4, 0, 5, 0, 11, 5, 11, 10, 11, 0, 3, -1, -1, -1, -1},
        {5, 4, 8, 5, 8, 10, 10, 8, 11, -1, -1, -1, -1, -1, -1, -1},
        {9, 7, 8, 5, 7, 9, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 3, 0, 9, 5, 3, 5, 7, 3, -1, -1, -1, -1, -1, -1, -1},
        {0, 7, 8, 0, 1, 7, 1, 5, 7, -1, -1, -1, -1, -1, -1, -1},
        {1, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 7, 8, 9, 5, 7, 10, 1, 2, -1, -1, -1, -1, -1, -1, -1},
        {10, 1, 2, 9, 5, 0, 5, 3, 0, 5, 7, 3, -1, -1, -1, -1},
        {8, 0, 2, 8, 2, 5, 8, 5, 7, 10, 5, 2, -1, -1, -1, -1},
        {2, 10, 5, 2, 5, 3, 3, 5, 7, -1, -1, -1, -1, -1, -1, -1},
        {7, 9, 5, 7, 8, 9, 3, 11, 2, -1, -1, -1, -1, -1, -1, -1},
        {9, 5, 7, 9, 7, 2, 9, 2, 0, 2, 7, 11, -1, -1, -1, -1},
        {2, 3, 11, 0, 1, 8, 1, 7, 8, 1, 5, 7, -1, -1, -1, -1},
        {11, 2, 1, 11, 1, 7, 7, 1, 5, -1, -1, -1, -1, -1, -1, -1},
        {9, 5, 8, 8, 5, 7, 10, 1, 3, 10, 3, 11, -1, -1, -1, -1},
        {5, 7, 0, 5, 0, 9, 7, 11, 0, 1, 0, 10, 11, 10, 0, -1},
        {11, 10, 0, 11, 0, 3, 10, 5, 0, 8, 0, 7, 5, 7, 0, -1},
        {11, 10, 5, 7, 11, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 0, 1, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 8, 3, 1, 9, 8, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
        {1, 6, 5, 2, 6, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 6, 5, 1, 2, 6, 3, 0, 8, -1, -1, -1, -1, -1, -1, -1},
        {9, 6, 5, 9, 0, 6, 0, 2, 6, -1, -1, -1, -1, -1, -1, -1},
        {5, 9, 8, 5, 8, 2, 5, 2, 6, 3, 2, 8, -1, -1, -1, -1},
        {2, 3, 11, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {11, 0, 8, 11, 2, 0, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 9, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1, -1, -1, -1},
        {5, 10, 6, 1, 9, 2, 9, 11, 2, 9, 8, 11, -1, -1, -1, -1},
        {6, 3, 11, 6, 5, 3, 5, 1, 3, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 11, 0, 11, 5, 0, 5, 1, 5, 11, 6, -1, -1, -1, -1},
        {3, 11, 6, 0, 3, 6, 0, 6, 5, 0, 5, 9, -1, -1, -1, -1},
        {6, 5, 9, 6, 9, 11, 11, 9, 8, -1, -1, -1, -1, -1, -1, -1},
        {5, 10, 6, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 3, 0, 4, 7, 3, 6, 5, 10, -1, -1, -1, -1, -1, -1, -1},
        {1, 9, 0, 5, 10, 6, 8, 4, 7, -1, -1, -1, -1, -1, -1, -1},
        {10, 6, 5, 1, 9, 7, 1, 7, 3, 7, 9, 4, -1, -1, -1, -1},
        {6, 1, 2, 6, 5, 1, 4, 7, 8, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 5, 5, 2, 6, 3, 0, 4, 3, 4, 7, -1, -1, -1, -1},
        {8, 4, 7, 9, 0, 5, 0, 6, 5, 0, 2, 6, -1, -1, -1, -1},
        {7, 3, 9, 7, 9, 4, 3, 2, 9, 5, 9, 6, 2, 6, 9, -1},
        {3, 11, 2, 7, 8, 4, 10, 6, 5, -1, -1, -1, -1, -1, -1, -1},
        {5, 10, 6, 4, 7, 2, 4, 2, 0, 2, 7, 11, -1, -1, -1, -1},
        {0, 1, 9, 4, 7, 8, 2, 3, 11, 5, 10, 6, -1, -1, -1, -1},
        {9, 2, 1, 9, 11, 2, 9, 4, 11, 7, 11, 4, 5, 10, 6, -1},
        {8, 4, 7, 3, 11, 5, 3, 5, 1, 5, 11, 6, -1, -1, -1, -1},
        {5, 1, 11, 5, 11, 6, 1, 0, 11, 7, 11, 4, 0, 4, 11, -1},
        {0, 5, 9, 0, 6, 5, 0, 3, 6, 11, 6, 3, 8, 4, 7, -1},
        {6, 5, 9, 6, 9, 11, 4, 7, 9, 7, 11, 9, -1, -1, -1, -1},
        {10, 4, 9, 6, 4, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 10, 6, 4, 9, 10, 0, 8, 3, -1, -1, -1, -1, -1, -1, -1},
        {10, 0, 1, 10, 6, 0, 6, 4, 0, -1, -1, -1, -1, -1, -1, -1},
        {8, 3, 1, 8, 1, 6, 8, 6, 4, 6, 1, 10, -1, -1, -1, -1},
        {1, 4, 9, 1, 2, 4, 2, 6, 4, -1, -1, -1, -1, -1, -1, -1},
        {3, 0, 8, 1, 2, 9, 2, 4, 9, 2, 6, 4, -1, -1, -1, -1},
        {0, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {8, 3, 2, 8, 2, 4, 4, 2, 6, -1, -1, -1, -1, -1, -1, -1},
        {10, 4, 9, 10, 6, 4, 11, 2, 3, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 2, 2, 8, 11, 4, 9, 10, 4, 10, 6, -1, -1, -1, -1},
        {3, 11, 2, 0, 1, 6, 0, 6, 4, 6, 1, 10, -1, -1, -1, -1},
        {6, 4, 1, 6, 1, 10, 4, 8, 1, 2, 1, 11, 8, 11, 1, -1},
        {9, 6, 4, 9, 3, 6, 9, 1, 3, 11, 6, 3, -1, -1, -1, -1},
        {8, 11, 1, 8, 1, 0, 11, 6, 1, 9, 1, 4, 6, 4, 1, -1},
        {3, 11, 6, 3, 6, 0, 0, 6, 4, -1, -1, -1, -1, -1, -1, -1},
        {6, 4, 8, 11, 6, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {7, 10, 6, 7, 8, 10, 8, 9, 10, -1, -1, -1, -1, -1, -1, -1},
        {0, 7, 3, 0, 10, 7, 0, 9, 10, 6, 7, 10, -1, -1, -1, -1},
        {10, 6, 7, 1, 10, 7, 1, 7, 8, 1, 8, 0, -1, -1, -1, -1},
        {10, 6, 7, 10, 7, 1, 1, 7, 3, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 6, 1, 6, 8, 1, 8, 9, 8, 6, 7, -1, -1, -1, -1},
        {2, 6, 9, 2, 9, 1, 6, 7, 9, 0, 9, 3, 7, 3, 9, -1},
        {7, 8, 0, 7, 0, 6, 6, 0, 2, -1, -1, -1, -1, -1, -1, -1},
        {7, 3, 2, 6, 7, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {2, 3, 11, 10, 6, 8, 10, 8, 9, 8, 6, 7, -1, -1, -1, -1},
        {2, 0, 7, 2, 7, 11, 0, 9, 7, 6, 7, 10, 9, 10, 7, -1},
        {1, 8, 0, 1, 7, 8, 1, 10, 7, 6, 7, 10, 2, 3, 11, -1},
        {11, 2, 1, 11, 1, 7, 10, 6, 1, 6, 7, 1, -1, -1, -1, -1},
        {8, 9, 6, 8, 6, 7, 9, 1, 6, 11, 6, 3, 1, 3, 6, -1},
        {0, 9, 1, 11, 6, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {7, 8, 0, 7, 0, 6, 3, 11, 0, 11, 6, 0, -1, -1, -1, -1},
        {7, 11, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 0, 8, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 9, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {8, 1, 9, 8, 3, 1, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
        {10, 1, 2, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, 3, 0, 8, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
        {2, 9, 0, 2, 10, 9, 6, 11, 7, -1, -1, -1, -1, -1, -1, -1},
        {6, 11, 7, 2, 10, 3, 10, 8, 3, 10, 9, 8, -1, -1, -1, -1},
        {7, 2, 3, 6, 2, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {7, 0, 8, 7, 6, 0, 6, 2, 0, -1, -1, -1, -1, -1, -1, -1},
        {2, 7, 6, 2, 3, 7, 0, 1, 9, -1, -1, -1, -1, -1, -1, -1},
        {1, 6, 2, 1, 8, 6, 1, 9, 8, 8, 7, 6, -1, -1, -1, -1},
        {10, 7, 6, 10, 1, 7, 1, 3, 7, -1, -1, -1, -1, -1, -1, -1},
        {10, 7, 6, 1, 7, 10, 1, 8, 7, 1, 0, 8, -1, -1, -1, -1},
        {0, 3, 7, 0, 7, 10, 0, 10, 9, 6, 10, 7, -1, -1, -1, -1},
        {7, 6, 10, 7, 10, 8, 8, 10, 9, -1, -1, -1, -1, -1, -1, -1},
        {6, 8, 4, 11, 8, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 6, 11, 3, 0, 6, 0, 4, 6, -1, -1, -1, -1, -1, -1, -1},
        {8, 6, 11, 8, 4, 6, 9, 0, 1, -1, -1, -1, -1, -1, -1, -1},
        {9, 4, 6, 9, 6, 3, 9, 3, 1, 11, 3, 6, -1, -1, -1, -1},
        {6, 8, 4, 6, 11, 8, 2, 10, 1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, 3, 0, 11, 0, 6, 11, 0, 4, 6, -1, -1, -1, -1},
        {4, 11, 8, 4, 6, 11, 0, 2, 9, 2, 10, 9, -1, -1, -1, -1},
        {10, 9, 3, 10, 3, 2, 9, 4, 3, 11, 3, 6, 4, 6, 3, -1},
        {8, 2, 3, 8, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1},
        {0, 4, 2, 4, 6, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 9, 0, 2, 3, 4, 2, 4, 6, 4, 3, 8, -1, -1, -1, -1},
        {1, 9, 4, 1, 4, 2, 2, 4, 6, -1, -1, -1, -1, -1, -1, -1},
        {8, 1, 3, 8, 6, 1, 8, 4, 6, 6, 10, 1, -1, -1, -1, -1},
        {10, 1, 0, 10, 0, 6, 6, 0, 4, -1, -1, -1, -1, -1, -1, -1},
        {4, 6, 3, 4, 3, 8, 6, 10, 3, 0, 3, 9, 10, 9, 3, -1},
        {10, 9, 4, 6, 10, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 9, 5, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, 4, 9, 5, 11, 7, 6, -1, -1, -1, -1, -1, -1, -1},
        {5, 0, 1, 5, 4, 0, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
        {11, 7, 6, 8, 3, 4, 3, 5, 4, 3, 1, 5, -1, -1, -1, -1},
        {9, 5, 4, 10, 1, 2, 7, 6, 11, -1, -1, -1, -1, -1, -1, -1},
        {6, 11, 7, 1, 2, 10, 0, 8, 3, 4, 9, 5, -1, -1, -1, -1},
        {7, 6, 11, 5, 4, 10, 4, 2, 10, 4, 0, 2, -1, -1, -1, -1},
        {3, 4, 8, 3, 5, 4, 3, 2, 5, 10, 5, 2, 11, 7, 6, -1},
        {7, 2, 3, 7, 6, 2, 5, 4, 9, -1, -1, -1, -1, -1, -1, -1},
        {9, 5, 4, 0, 8, 6, 0, 6, 2, 6, 8, 7, -1, -1, -1, -1},
        {3, 6, 2, 3, 7, 6, 1, 5, 0, 5, 4, 0, -1, -1, -1, -1},
        {6, 2, 8, 6, 8, 7, 2, 1, 8, 4, 8, 5, 1, 5, 8, -1},
        {9, 5, 4, 10, 1, 6, 1, 7, 6, 1, 3, 7, -1, -1, -1, -1},
        {1, 6, 10, 1, 7, 6, 1, 0, 7, 8, 7, 0, 9, 5, 4, -1},
        {4, 0, 10, 4, 10, 5, 0, 3, 10, 6, 10, 7, 3, 7, 10, -1},
        {7, 6, 10, 7, 10, 8, 5, 4, 10, 4, 8, 10, -1, -1, -1, -1},
        {6, 9, 5, 6, 11, 9, 11, 8, 9, -1, -1, -1, -1, -1, -1, -1},
        {3, 6, 11, 0, 6, 3, 0, 5, 6, 0, 9, 5, -1, -1, -1, -1},
        {0, 11, 8, 0, 5, 11, 0, 1, 5, 5, 6, 11, -1, -1, -1, -1},
        {6, 11, 3, 6, 3, 5, 5, 3, 1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 10, 9, 5, 11, 9, 11, 8, 11, 5, 6, -1, -1, -1, -1},
        {0, 11, 3, 0, 6, 11, 0, 9, 6, 5, 6, 9, 1, 2, 10, -1},
        {11, 8, 5, 11, 5, 6, 8, 0, 5, 10, 5, 2, 0, 2, 5, -1},
        {6, 11, 3, 6, 3, 5, 2, 10, 3, 10, 5, 3, -1, -1, -1, -1},
        {5, 8, 9, 5, 2, 8, 5, 6, 2, 3, 8, 2, -1, -1, -1, -1},
        {9, 5, 6, 9, 6, 0, 0, 6, 2, -1, -1, -1, -1, -1, -1, -1},
        {1, 5, 8, 1, 8, 0, 5, 6, 8, 3, 8, 2, 6, 2, 8, -1},
        {1, 5, 6, 2, 1, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 3, 6, 1, 6, 10, 3, 8, 6, 5, 6, 9, 8, 9, 6, -1},
        {10, 1, 0, 10, 0, 6, 9, 5, 0, 5, 6, 0, -1, -1, -1, -1},
        {0, 3, 8, 5, 6, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {10, 5, 6, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {11, 5, 10, 7, 5, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {11, 5, 10, 11, 7, 5, 8, 3, 0, -1, -1, -1, -1, -1, -1, -1},
        {5, 11, 7, 5, 10, 11, 1, 9, 0, -1, -1, -1, -1, -1, -1, -1},
        {10, 7, 5, 10, 11, 7, 9, 8, 1, 8, 3, 1, -1, -1, -1, -1},
        {11, 1, 2, 11, 7, 1, 7, 5, 1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, 1, 2, 7, 1, 7, 5, 7, 2, 11, -1, -1, -1, -1},
        {9, 7, 5, 9, 2, 7, 9, 0, 2, 2, 11, 7, -1, -1, -1, -1},
        {7, 5, 2, 7, 2, 11, 5, 9, 2, 3, 2, 8, 9, 8, 2, -1},
        {2, 5, 10, 2, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1},
        {8, 2, 0, 8, 5, 2, 8, 7, 5, 10, 2, 5, -1, -1, -1, -1},
        {9, 0, 1, 5, 10, 3, 5, 3, 7, 3, 10, 2, -1, -1, -1, -1},
        {9, 8, 2, 9, 2, 1, 8, 7, 2, 10, 2, 5, 7, 5, 2, -1},
        {1, 3, 5, 3, 7, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 7, 0, 7, 1, 1, 7, 5, -1, -1, -1, -1, -1, -1, -1},
        {9, 0, 3, 9, 3, 5, 5, 3, 7, -1, -1, -1, -1, -1, -1, -1},
        {9, 8, 7, 5, 9, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {5, 8, 4, 5, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1},
        {5, 0, 4, 5, 11, 0, 5, 10, 11, 11, 3, 0, -1, -1, -1, -1},
        {0, 1, 9, 8, 4, 10, 8, 10, 11, 10, 4, 5, -1, -1, -1, -1},
        {10, 11, 4, 10, 4, 5, 11, 3, 4, 9, 4, 1, 3, 1, 4, -1},
        {2, 5, 1, 2, 8, 5, 2, 11, 8, 4, 5, 8, -1, -1, -1, -1},
        {0, 4, 11, 0, 11, 3, 4, 5, 11, 2, 11, 1, 5, 1, 11, -1},
        {0, 2, 5, 0, 5, 9, 2, 11, 5, 4, 5, 8, 11, 8, 5, -1},
        {9, 4, 5, 2, 11, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {2, 5, 10, 3, 5, 2, 3, 4, 5, 3, 8, 4, -1, -1, -1, -1},
        {5, 10, 2, 5, 2, 4, 4, 2, 0, -1, -1, -1, -1, -1, -1, -1},
        {3, 10, 2, 3, 5, 10, 3, 8, 5, 4, 5, 8, 0, 1, 9, -1},
        {5, 10, 2, 5, 2, 4, 1, 9, 2, 9, 4, 2, -1, -1, -1, -1},
        {8, 4, 5, 8, 5, 3, 3, 5, 1, -1, -1, -1, -1, -1, -1, -1},
        {0, 4, 5, 1, 0, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {8, 4, 5, 8, 5, 3, 9, 0, 5, 0, 3, 5, -1, -1, -1, -1},
        {9, 4, 5, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 11, 7, 4, 9, 11, 9, 10, 11, -1, -1, -1, -1, -1, -1, -1},
        {0, 8, 3, 4, 9, 7, 9, 11, 7, 9, 10, 11, -1, -1, -1, -1},
        {1, 10, 11, 1, 11, 4, 1, 4, 0, 7, 4, 11, -1, -1, -1, -1},
        {3, 1, 4, 3, 4, 8, 1, 10, 4, 7, 4, 11, 10, 11, 4, -1},
        {4, 11, 7, 9, 11, 4, 9, 2, 11, 9, 1, 2, -1, -1, -1, -1},
        {9, 7, 4, 9, 11, 7, 9, 1, 11, 2, 11, 1, 0, 8, 3, -1},
        {11, 7, 4, 11, 4, 2, 2, 4, 0, -1, -1, -1, -1, -1, -1, -1},
        {11, 7, 4, 11, 4, 2, 8, 3, 4, 3, 2, 4, -1, -1, -1, -1},
        {2, 9, 10, 2, 7, 9, 2, 3, 7, 7, 4, 9, -1, -1, -1, -1},
        {9, 10, 7, 9, 7, 4, 10, 2, 7, 8, 7, 0, 2, 0, 7, -1},
        {3, 7, 10, 3, 10, 2, 7, 4, 10, 1, 10, 0, 4, 0, 10, -1},
        {1, 10, 2, 8, 7, 4, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 9, 1, 4, 1, 7, 7, 1, 3, -1, -1, -1, -1, -1, -1, -1},
        {4, 9, 1, 4, 1, 7, 0, 8, 1, 8, 7, 1, -1, -1, -1, -1},
        {4, 0, 3, 7, 4, 3, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {4, 8, 7, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {9, 10, 8, 10, 11, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 0, 9, 3, 9, 11, 11, 9, 10, -1, -1, -1, -1, -1, -1, -1},
        {0, 1, 10, 0, 10, 8, 8, 10, 11, -1, -1, -1, -1, -1, -1, -1},
        {3, 1, 10, 11, 3, 10, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 2, 11, 1, 11, 9, 9, 11, 8, -1, -1, -1, -1, -1, -1, -1},
        {3, 0, 9, 3, 9, 11, 1, 2, 9, 2, 11, 9, -1, -1, -1, -1},
        {0, 2, 11, 8, 0, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {3, 2, 11, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {2, 3, 8, 2, 8, 10, 10, 8, 9, -1, -1, -1, -1, -1, -1, -1},
        {9, 10, 2, 0, 9, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {2, 3, 8, 2, 8, 10, 0, 1, 8, 1, 10, 8, -1, -1, -1, -1},
        {1, 10, 2, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {1, 3, 8, 9, 1, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 9, 1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {0, 3, 8, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
        {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1}
};
#if !defined(AFX_PROTEINSURFACE_H__0413A5ED_33E6_4E18_A96C_CFF9B940C2CB__INCLUDED_)
#define AFX_PROTEINSURFACE_H__0413A5ED_33E6_4E18_A96C_CFF9B940C2CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ProteinSurface  
{
public:
	ProteinSurface();
	void boundbox(int seqinit,int seqterm,atom *proseq,bool atomtype,point3d *minp,point3d *maxp);
	point3d ptran;
	int boxlength;
	bool flagradius;
	double proberadius;
	double fixsf;
	double scalefactor;
	point3d pmin,pmax;
	int pheight,pwidth,plength;
	int widxz[13];
	int *depty[13];
	double cutradis;
	void boundingatom(bool btype);
	volumepixel ***vp;
	void initpara(int seqinit,int seqterm,atom* proseq,bool atomtype,bool btype);
	void fillvoxels(int seqinit,int seqterm,bool atomtype,atom* proseq,bool bcolor);
	void fillatom(int indx,atom* proseq,bool bcolor);
	void fillatomwaals(int indx,atom* proseq,bool bcolor);
	void fillvoxelswaals(int seqinit,int seqterm,bool atomtype,atom* proseq,bool bcolor);
	void fastoneshell(int* innum,int *allocout,voxel2 ***boundpoint,int* outnum, int *elimi);
	void fastdistancemap(int type);
	voxel2* inarray;
	voxel2* outarray;
	int	totalsurfacevox;
	int totalinnervox;
	faceinfo *faces;
	vertinfo *verts;
	int facenumber,vertnumber;
	void buildboundary();
	void marchingcubeinit(int stype);
	void marchingcubeorigin(int stype);
	void marchingcubeorigin2(int stype);
	void marchingcube(int stype);
	double carea,cvolume;
	double sarea,svolume;
	void calcareavolume();
	void computenorm();
	int ncav;
	double *eachcavityvolume;
	void cavitynumbers();
	void cavitiesareavolume();
	void outputcavityatoms(int seqinit,int seqterm,atom* proseq,char *filename);
	void surfaceinterior();
	void atomsinout(int seqinit,int seqterm,atom* proseq);
	void outputoff(char *filename);
	void outputply(char *filename,atom* proseq,int ncolor,int tinout);
	void outsas(int numbb,boneinfo *bb,atom* proseq,char *filename);
	void laplaciansmooth(int numiter);
	void checkEuler();
	void checkinoutpropa();
	double *depval;
	int numdep;
	void calcdepth(int numbb,int seqinit,int seqterm,atom* proseq,boneinfo *bb,bool type);//edt
	virtual ~ProteinSurface();

};

#endif // !defined(AFX_PROTEINSURFACE_H__0413A5ED_33E6_4E18_A96C_CFF9B940C2CB__INCLUDED_)
