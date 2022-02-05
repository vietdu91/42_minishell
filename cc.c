#include <signal.h>

int main(void)
{
	kill(0, SIGSEGV);
	return (0);
}
