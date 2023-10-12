# ft_containers
The standard C++ containers have all a specific usage. To make sure you understand them, let’s re-implement them!
## Objectives
In this project, you will implement various container types from the C++ Standard Template Library (STL).

- For each container, create appropriately named class files.
- The namespace used will always be 'ft', and your containers will be tested using ft::\<container\>.
- It's essential to follow the structure of the reference container.
- If a part of the Coplien form is missing in the reference, do not implement it.
- Keep in mind that we are coding in C++98, so you must not implement any new features, but every old feature, even deprecated ones, is expected.

## Mandatory Part
- Implement the following containers (Vector and Stack) and turn in the necessary files <container>.hpp.
- You must also provide a main.cpp that tests everything for your evaluations.
- Member functions, non-member functions, and overloads are expected.
- You can use std::allocator if you don't implement the get_allocator member function.
- Justify your inner data structure for each container.
- If the container has an iterator system, you must reimplement it.
- You can refer to [cplusplus.com](https://cplusplus.com/) for what to implement, as it's easy to see the C++98 version.
- You cannot implement more public functions than the ones offered in the standard containers; everything else must be private or protected.
- Each public function/variable must be justified.
- For non-member overloads, the friend keyword is allowed, but each use of friend must be justified and will be checked during evaluation.
