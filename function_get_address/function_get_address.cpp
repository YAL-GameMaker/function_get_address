/// @author YellowAfterlife
#include "stdafx.h"
#include "gml.h"

#define dllx extern "C" __declspec(dllexport)

dllx double test_message(GMLClosure* show_message) {
	GMLVar result = 0;
	GMLVar args[] = { "Hello from C++!" };
	show_message->ncall(result, sizeof(args), args);
	return result.getReal();
}

dllx double test_create(GMLClosure* script_execute, GMLClosure* variable_global_set, double obj) {
	GMLVar result = 0;
	//
	GMLVar args1[] = { "greet", "C++" };
	variable_global_set->ncall(result, sizeof(args1), args1);
	//
	GMLVar args2[] = { 0, 0, obj };
	script_execute->ncall(result, sizeof(args2), args2);
	//
	return result.getReal();
}