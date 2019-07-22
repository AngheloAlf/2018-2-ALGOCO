/**
 * @file  counter.cc
 * @brief Code for counter
 */

#include <iostream>
#include <iomanip>
#include <algorithm>

#include "counter.hh"

counter::counter()
{
	m = -1;
	for (int i = 0; i < SIZE; i++)
		a[i] = 0;
}

void counter::inc()
{
	if (m == -1) {
		a[0] = 1;
		m = 0;
		return;
	}
	int i;
	for (i = 0; a[i] == 1; i++)
		a[i] = 0;
	a[i] = (a[i] == 0);
	if (a[i] == 0 && m == i){
		m = -1;
	}
	else {
		m = std::max(m, i);
	}
}

void counter::dec()
{
	if (m == -1){
		a[0] = -1;
		m = 0;
		return;
	}

	int i;
	for (i = 0; a[i] == -1; i++){
		a[i] = 0;
	}

	a[i] = a[i] == 0 ? -1 : 0;
	if (a[i] == 0 && m == i) {
		m = -1;
	}
	else {
		m = std::max(m, i);
	}
}

int counter::val()
{
	int result = 0;
	for (int i = 0; i <= m; i++)
		result += a[i] * (1 << i);
	return result;
}

std::ostream &operator<<(std::ostream &os, const counter &ctr)
{
	os << "[" << std::setw(2) << ctr.m << ": ";
	for(int i = SIZE - 1; i >= 0; i--) {
		char c;
		if (ctr.a[i] < 0)
			c = '-';
		else if (ctr.a[i] == 0)
			c = '0';
		else
			c = '1';
		std::cout << c;
	}
	os << "]";
	return os;
}
