#include <iostream>
#include "myTraits.hpp"

//task 4: error
/*#define PRINT_TYPE_INFO(T) {
	if constexpr (my_traits::is_integral<T>::value) std::cout << "type is integral" << std::endl;
	else if constexpr (my_traits::is_floating_point<T>::value) std::cout << "type is floating point" << std::endl;
        else if constexpr (my_traits::is_pointer<T>::value) std::cout << "type is pointer" << std::endl;
        else if constexpr (my_traits::is_array<T>::value) std::cout << "type is array" << std::endl;
}*/
//task 1
template <typename T>
typename my_traits::enable_if<my_traits::is_integral<T>::value, T>::type sum(T a, T b) {
    return a + b;
}

//task 2
template <bool B,typename Truetype, typename Falsetype>
auto choose_type() {
    using type = typename my_traits::conditional<B, Truetype, Falsetype>::type; 
    return type();
}

//task3
template <typename T>
struct base_type {
	using type = typename my_traits::remove_const<typename my_traits::remove_reference<T>::type>::type;
}; 

//task5
template <typename T>
void reset_if_pointer(T& val) {
	if constexpr (my_traits::is_pointer<T>::value) {
		val = nullptr;
	}	
}
int main() {
	int a = 5, b = 4;
        double c = 8.2, d = 3.4;
	std::cout << sum(a,b) << std::endl;
	std::cout << sum(d,c) << std::endl;
	auto x = choose_type<my_traits::is_integral<int>::value, int, double>();
	std::cout << my_traits::is_same<decltype(x),int>::value;
	std::cout << my_traits::is_same<base_type<const int&>::type, int>::value;
//	PRINT_TYPE_INFO(int*);
//	PRINT_TYPE_INFO(int[]);
	

}
