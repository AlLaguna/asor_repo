#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

int main() 
{
   
   int error = setuid(0);
   
   if(error == -1) //Hay error
   {
        cout << "ERROR";
   }

   return 1;
}
