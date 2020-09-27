#include <dlfcn.h>
#include <stdio.h>
#include "menuplugin.h"

typedef void (*func_t)();

int main(int argc, char*argv[])
{
	printf("This program uses a plugin.\n");
	void *hndl = 
		dlopen("../../plugin/bin/plugin.so", RTLD_NOW);
	if(hndl)
	{
		func_t func = (func_t)dlsym(hndl, "action");
		(*func)();
	}
	return 0;
}
