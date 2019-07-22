/**
 * @file  main.cc
 * @brief Main program for counter
 */

#include <iostream>
#include <cctype>
#include <cstdlib>

#include "counter.hh"

int main()
{
	counter ctr;
	char ans;

	for(;;) {
		std::cout << "I(nc D(ec S(how Q(uit: ";
		do std::cin >> ans; while(!std::isalpha(ans));
		switch (ans) {
		case 'I':
		case 'i':
			ctr.inc();
			break;
		case 'D':
		case 'd':
			ctr.dec();
			break;
		case 'S':
		case 's':
			std::cout << ctr << ": " << ctr.val() << std::endl;
			break;
		case 'Q':
		case 'q':
			std::exit(EXIT_SUCCESS);
			break;
		default:
			std::cout << "One of IDSQ: ";
			break;
		}
	}
}
