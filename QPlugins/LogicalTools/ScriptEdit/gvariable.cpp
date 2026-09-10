#include "gvariable.h"

//定义全局变量结构体
gVariable::Global_Var gVariable::GlobalVar;
QMap<QString, gVariable::Global_Var> gVariable::global_variable_link = QMap<QString, gVariable::Global_Var>();
