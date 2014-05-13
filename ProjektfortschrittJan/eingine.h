#include <stdio.h>
#include <iostream>

namespace controller {

	class Engine {

	public:
		virtual void init(int argc, char* argv[]) {};
		virtual void run() {};
	};

}