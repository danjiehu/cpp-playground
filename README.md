# cpp-playground
This repo is used to document the learning of c++

## running c+
* with vscode Code Runner extension
 - Ctrl + Opt + N (to run)
 - Ctrl + Opt + M (to stop)
* alternatively,
```
g++ -std=c++11 hello.cpp -o hello
./hello
```

## rules
### DON'Ts
* use `using namespace ...` in header file
* `using namespace std`
### DOs
```
using std::cout;
using std::endl;
```
### naming
* file names `my-useful-class.ccp`
* namespace `cube`
* class & struct `class MyClass`
* variables & struct member variable `std::string table_name` `int num`
* class member variable (meaning *99%* it's private) `std::string table_name_` `int num_`
* function `void DoSometingImportant(){}`
* TODO comments
```
// TODO(Zeke) change this to use relations.
// TODO(bug 12345): remove the "Last visitors" feature.
```

## references
* clang format setup in VS code https://clang.llvm.org/docs/ClangFormat.html
* Google CPP style guide https://google.github.io/styleguide/cppguide.html#General_Naming_Rules
