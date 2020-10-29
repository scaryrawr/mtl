#include <memory>
#include <mtl/memory.hpp>

void custom_free(void *ptr)
{
	printf("%s\n", static_cast<char *>(ptr));
	free(ptr);
}

#define hello "Hello"
#define world "World"

int main(int argc, char *argv[])
{
	using free_deleter = mtl::custom_delete<decltype(custom_free), &custom_free>;
	using unique_malloc = std::unique_ptr<char, free_deleter>;

	using unique_malloc2 = mtl::unique_ptr<decltype(custom_free), &custom_free>;

	unique_malloc mem{static_cast<char *>(malloc(sizeof(world)))};
	sprintf(mem.get(), "%s", world);

	unique_malloc2 mem2{malloc(sizeof(hello))};
	sprintf(static_cast<char *>(mem2.get()), "%s", hello);

	return 0;
}
