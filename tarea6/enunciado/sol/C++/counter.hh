/**
 * @file  counter.hh
 * @brief Counter class declaration
 */

#ifndef COUNTER_HH
#define COUNTER_HH

#define SIZE 16

class counter {
	int m;
	signed char a[SIZE];
public:
	counter();

	void inc();
	void dec();
	int val();

	friend std::ostream & operator<<(std::ostream &, const counter &);
};

#endif
