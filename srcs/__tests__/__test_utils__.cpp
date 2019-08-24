#include "__test_utils__.hpp"

void UnitTest::print_success_msg(string func_name)
{
	if (!print_success)
		return ;
	cout << KGRN << "[SUCCESS] " << KNRM;
	cout << KYEL << "[" << func_name << "] " << KNRM;
	cout << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

void UnitTest::print_fail_msg(string func_name)
{
	cout << KRED << "[FAILED] " << KNRM;
	cout << KYEL << "[" << func_name << "] " << KNRM;
	cout << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

void UnitTest::set_subject(string str)
{
	subject = str;
}
