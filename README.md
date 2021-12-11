# cpp-playground

This repo is used to document the learning of c++

## Running c+

* with vscode Code Runner extension

  * `Ctrl + Opt + N` to run
  * `Ctrl + Opt + M` to stop
* alternatively,

```
g++ hello.cpp -o hello
./hello

g++ -std=c++11 hello.cpp -o hello
./hello

# compile with linked .cpp files
g++ -o main class1.cpp class2.cpp class3.cpp main.cpp
./main
```

## Rules

### DON'Ts

* use `using namespace ...` in header file
* `using namespace std`
* avoid using Linked Lists

### DOs

* std::cout & std::endl

```cpp
using std::cout;
using std::endl;
```

* Choosing collection type:

  * Use vector `<T>` by default
  * If want to avoid using the heap entirely and don't need to change the number of elements, use `std::array`
  * ref: https://www.youtube.com/watch?v=TJHgp1ugKGM&t=2948s

### Naming

* file names `my-useful-class.ccp`
* namespace `cube`
* class & struct `class MyClass`
* variables & struct member variable `std::string table_nameint num`
* class member variable (meaning *99%* it's private) `std::string table_name_int num_`
* function `void DoSometingImportant(){}`
* TODO comments

```
// TODO(Zeke) change this to use relations.
// TODO(bug 12345): remove the "Last visitors" feature.
```

## References

* how to use const in c++ https://www.sandordargo.com/blog/2020/11/04/when-use-const-1-functions-local-variables
* c++ best practices by jason turner https://www.sandordargo.com/blog/2021/06/05/cpp-best-practices-by-jason-turner
* clang format setup in VS code https://clang.llvm.org/docs/ClangFormat.html
* Google CPP style guide https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
* IMPORTANT - Mordern C++, list vs. vector performance: https://www.youtube.com/watch?v=TJHgp1ugKGM&t=2948s
* Why you should avoid Linked Lists: https://www.youtube.com/watch?v=YQs6IC-vgmo
