// Refactor "BaseSignal"
// 	-> Seperate out the "continous" functionality, from the "sampling" functionality...
// 	-> Now, represents almost the "continous" f(t), in the sense that you give it a t, and it will compute the sample
// 	value. That's all...
// 	-> Change the responsibility of `compute_samples` - just evaluate the sample value at time `t`!
// 	-> Make `compute_samples` - or whatever it's new analogue is now called - public.
// Remove "sampling" from `BaseSignal`, and instead delegate this to a new function and return class.
// 	-> Perhaps the return is "SampledSignal"
// 	-> So we have seperated some concerns from our current `BaseSignal`...
// Refactor the rest of the code in line with these changes.
// Now, the `extend` functionality should be easier/clearer to implement.
// Write a function which computes the F.T. via the triangle trick.
// Compare F.T. to F.S. and plot, to make sure the code is working...

int main()
{
    return 0;
}
