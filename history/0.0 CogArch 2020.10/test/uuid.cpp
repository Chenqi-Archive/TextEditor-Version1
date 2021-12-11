#include <rpc.h>
#pragma comment(lib, "Rpcrt4.lib")


int main() {
	UUID uuid;
	long ret = UuidCreate(&uuid);
	return ret;
}
