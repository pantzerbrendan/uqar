
#include "utils.h"

namespace utils
{

	int 		pgcd(int a, int b)
	{
		// b != 0 == true : return PGCD(b, a%b)
		// else 		  : return a
		return ((b) ? (pgcd(b, a % b)) : (a));
	}

}