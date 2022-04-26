#include <functional>
#include <iostream>
#include <pybind11/pybind11.h>
#include <pybind11/functional.h>

namespace py = pybind11;

void eval(std::function<void()> f) {
	f();
}

typedef void (fnType) ();

bool equal(std::function<void()> f1, std::function<void()> f2) {
	if (f1.target_type() != f2.target_type()){
		std::cout << "f1 and f2 of different types: " << f1.target_type().name() << " vs " << f2.target_type().name() << std::endl;
		return false;
	}else{
		std::cout << "f1 and f2 of same type: " << f1.target_type().name() << std::endl;
	}

	auto **p_f1 = f1.target<void(*)()>();
	auto **p_f2 = f2.target<void(*)()>();
	if(p_f1==0){
		std::cout << "f1 can not be cast to : void(*)()" << std::endl;
		return false;
	}
	if(p_f2==0){
		std::cout << "f2 can not be cast to : void(*)()" << std::endl;
		return false;
	}

	if (*p_f1 != *p_f2)
		return false;

	return true;
}

void cpp_callback1() {
	std::cout << "cpp_callback1 called" << std::endl;
}
void cpp_callback2() {
	std::cout << "cpp_callback2 called" << std::endl;
}

PYBIND11_MODULE(example, m) {
	m.doc() = "pybind11 example plugin"; // optional module docstring

	m.def("eval", &eval, "A function to evaluate other functions");
	m.def("equal", &equal, "A function that compares two functions");

	m.def("cpp_callback1", &cpp_callback1, "A test callback function");
	m.def("cpp_callback2", &cpp_callback2, "An other callback function");
}
