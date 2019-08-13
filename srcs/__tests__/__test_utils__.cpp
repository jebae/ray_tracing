#include "__test_utils__.hpp"

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

string& UnitTest::set_subject(void)
{
	return (subject);
}
