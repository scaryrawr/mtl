#include <mtl/memory.hpp>
#include <cerrno>
#include <cstdio>


error_t fopen_s(FILE** file, const char* filename, const char* mode)
{
	*file = nullptr;
	FILE* tmp{fopen(filename, mode)};
	if (!tmp)
	{
		goto Error;
	}

	*file = tmp;
	tmp = nullptr;

Error:
	if (tmp)
	{
		fclose(tmp);
	}

	return errno;
}

int main(int argc, char *argv[])
{
	using unique_file = mtl::unique_ptr<decltype(fclose), &fclose>;
	unique_file file;
	fopen_s(mtl::out_ptr(file), "hello world", "r");
	return 0;
}
