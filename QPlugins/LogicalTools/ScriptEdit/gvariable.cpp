#include "gvariable.h"

//����ȫ�ֱ����ṹ��
gVariable::Global_Var gVariable::GlobalVar;
QMap<QString, gVariable::Global_Var> gVariable::global_variable_link = QMap<QString, gVariable::Global_Var>();
