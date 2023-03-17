#include <iostream>
#include <string>

/**********************************
 *
 * checkError : verifie si une erreur à été declenché avec opencl
 * 
********************************/

void checkError_openCL(int nErr, const std::string mErr)
{
     if(nErr < 0) {
       std::cout << "error n° " << nErr << "\n" << mErr << "\n";
       exit(1);
     }
}
