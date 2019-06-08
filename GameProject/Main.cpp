#include "Vec2.h"

int main() {

	Vec2 vec(4, 6);
	Vec2 vec2(1, 1);

	Vec2 vec3 = 2 * vec;

	std::cout << vec3;

	return 0;
}