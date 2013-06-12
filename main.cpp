//Nicolas Silveira Kagami
//main.c

#include<stdio.h>
#include<stdlib.h>
#include "io.h"
#include "analysis.h"
#include "components.h"

int main(int argc, char** argv)
{
    if(argc == 2)
    {
        IO input;
        input.open_file(argv[1]);
        input.read();
        int a = 2;
        Node lala ((NodeType)1);
    }
    else
    {
        printf("No input file parameter\n");
    }
} 
