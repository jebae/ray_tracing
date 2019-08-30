#include "__test_utils__.hpp"
#include "trace_record.hpp"

class TestTraceRecord : public UnitTest
{
public:
	TestTraceRecord(bool print_success=false);
	void all(void);
};

TestTraceRecord::TestTraceRecord(bool print_success): UnitTest("TraceRecord", print_success)
{}

void TestTraceRecord::all(void)
{

}
