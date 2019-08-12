#include "__test__.hpp"

void UnitTest::show_success_msg()
{
	cout << KGRN << "[SUCCESS] " << KNRM;
	cout << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

void UnitTest::show_fail_msg()
{
	cout << KRED << "[FAILED] " << KNRM;
	cout << KYEL << name;
	cout << " (" << subject << ")" << KNRM << endl;
}

void UnitTest::set_subject(string arg_subject)
{
	subject = arg_subject;
}
