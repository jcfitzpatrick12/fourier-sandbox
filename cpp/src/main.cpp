// Tinkering around.
#include <cmath>
#include <iostream>
#include <memory>

#include "signal_factory.h"
#include "base_periodic_signal.h"
#include "fourier.h"

// Adapt the `fourier.h` code to work with the smart pointer instead.
// Write a function which numerically computes the fourier series.

int main()
{
	// Defining the periodic signal
	const double period { 3 };
	const int num_samples { 30 };
	const SignalType signal_type { SignalType::rect };
	
	// Fourier coefficient parameters
	const int N { 20 }; 

	std::unique_ptr<const BasePeriodicSignal> signal {  make_periodic_signal(signal_type,
								                 period,
								                 num_samples) };		
	
	// print_signal(signal);
	complex_vector reconstructed_signal { get_fourier_series(N, *signal)  };

	for (complex_double z : reconstructed_signal ) 
	{
		std::cout << z << std::endl;
	}	
		
	return 0;
}

