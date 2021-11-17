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
g++ -o myprogram class1.cpp class2.cpp class3.cpp main.cpp
./main
```

## Rules

### DON'Ts

* use `using namespace ...` in header file
* `using namespace std`

### DOs

```
using std::cout;
using std::endl;
```

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

* clang format setup in VS code https://clang.llvm.org/docs/ClangFormat.html
* Google CPP style guide https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
