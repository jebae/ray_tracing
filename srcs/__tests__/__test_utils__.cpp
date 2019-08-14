#include "__test_utils__.hpp"

void UnitTest::show_success_msg(string func_name)
{
	cout << KGRN << "[SUCCESS] " << KNRM;
	cout << KYEL << "[" << func_name << "] " << KNRM;
	cout << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

void UnitTest::show_fail_msg(string func_name)
{
	cout << KRED << "[FAILED] " << KNRM;
	cout << KYEL << "[" << func_name << "] " << KNRM;
	cout << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

string& UnitTest::set_subject(void)
{
	return (subject);
}
