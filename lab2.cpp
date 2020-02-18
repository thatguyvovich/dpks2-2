// DPKS2 lab by Rusinov Volodymyr IO-91mn

#include <stdio.h>
#include <unistd.h> // supports getopt, but not getopt_long
#include <iostream>
#include <string>
#include <getopt.h>

extern char* optarg;

void help();
void version();
void list(char* opts);
void value(char* opts);

static struct option ops[] = {
	{"help", no_argument, 0, 'h'},
	{"list", no_argument, 0, 'l'},
	{"version", optional_argument, 0, 'v'},
	{"value", required_argument, 0 , 'V'}
};

int main(int argc, char* argv[]){
	int param, param_index;
	bool list = false;
	bool value = false;
	bool version = false;
	bool help = false;

	while((param = getopt_long(argc, argv, "hvl::V:", ops, &param_index)) != 1){
		switch(param){
			case 'h' : if(!help)   {help(); help = true;         } break;
			case 'v' : if(!version){version(); version = true;   } break;
			case 'l' : if(!list)   {list(optarg); list = true;   } break;
			case 'V' : if(!value)  {value(optarg); value = true; } break;

		}
	}

	return 0;
}


void help(){
	std::cout << "This command includes following flags: -l --list, -v --version, -h --help." << std::endl;
}

void version(){
	std::cout << "LAB2_DPKS v1.0" << std::endl;
}

void list(char* opts){
	std::cout << "Listing all of the options..." << std::endl;
	printf(opts);
	std::cout << "End list." << std::endl;
}

void value(char* opts){
	if (atoi(opts) != 0)
	{
        	printf("Error: value can't contain non-numerical symbols.");
		return;
	}
	std::cout << "Entered value: ";
	printf(opts);
	printf("\n");
}

