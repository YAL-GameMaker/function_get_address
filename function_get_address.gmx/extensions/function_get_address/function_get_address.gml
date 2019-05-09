#define function_get_closure
/// (name)->ptr
var name = argument0, cc;
if (variable_global_exists(name)) {
	cc = variable_global_get(name);
} else {
	variable_global_set(name, variable_global_get(name));
	cc = variable_global_get(name);
	variable_global_set(name, cc);
}
return ptr(cc);
