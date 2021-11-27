This repo is created to demostrate how to set up and utilize debugging for C++ in Visual Studio Code.

# debug

* select on Run and Debug on left side menu
* select on DEBUG CONSOLE on bottom panel
* setting: `g++ - build and bebug active file`
* click the green play button to start a debugging session
* break points (the red dot): run all the code up until right BEFORE the line of breakpoint (the line of breakpoint is not executed)
* set WATCH variables
* **view memory address**
  * there's no way to dispay full program memory in HEX in VS Code mac like it could in Visual Studio, and Visual Studio mac doesn't support C++ yet
  * view variable value, simply type variable name `a` in BEBUG CONSOLE
  * view variable memory address, simply type `&a` in DEBUG CONSOLE
  * view variable memory in HEX, type `-exec x &a` in DEBUG CONSOLE
    * `-exec` is to indicate that what comes after is a GDB command
    * to track continuous changes, log `-exec x &a` to WATCH
* **the yellow arrow points to the line that is about to be executed, but NOT YET**
* menu buttons (press Fn to activate function keys)
  * `Continue`***F5*** - execute a block of code: from the yellow-arrow line (included) to the line (included) right before the next break point
  * `Pause`*F6* - pause the running program, the yellow arrow will then pop up to indicate where the program is now
  * `Step Over`***F10*** - execute the yellow-arrow line and only that line
  * `Step Into`***F11*** - go into what's really being executed on the yellow-arrow line
  * `Step Out`*shift+F11* - go to what called the yellow-arrow line
  * `Restart`
  * `Stop`
* MAKE SURE
  * the active file is the one you want to run and debug
  * launch debug session in `main.cpp` file, NOT `main` execution file

# terminal commands
## view processor file
``` bash
g++ main.cpp -E  #print pre-processor file to terminal
g++ main.cpp -E -o i.txt #outpute the pre-precessor file content to a txt file in the same folder
```

# GDB commands

```bash
-exec x &int_arr #display memory address starting from int_arr

-exec x/3xb &int_arr #display 3 bytes (specified by `b`) of memory, starting from int_arr, in hex (specified by `x`)

-exec x/50 &int_arr #display 50 repeat count of whatever display format and unit size last used

# for more information, see ref `GDB examining memory document`
# every byte has its own memory address

```

# config

* compile header files and multiple cpp class files with same `ctrl + opt + n` commands
  * add to Code Runner executor map json settings
    `"code-runner.executorMap": { "cpp": "cd $dir && g++ -std=c++14 *.cpp  -o $fileNameWithoutExt && $dir$fileNameWithoutExt", }, `
  * if need to use collect user input, set externalConsole to true in `launch.json` under the .vscode folder

    ```json
    "externalConsole": true,

    ```
  * in `tasks.json` under the .vscode folder, replace with the entirety of the code below

    ```json
    {
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "C/C++: g++ build active file",
            "command": "/usr/bin/g++",
            "args": [
                "-g",
                "${fileDirname}/*.cpp",
                "-o",
                "${fileDirname}/${fileBasenameNoExtension}"
            ],
            "options": {
                "cwd": "/usr/bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
      ]
    }
    ```

# other

```cpp
// checking data type
#include <typeinfo>
...
cout << typeid(variable).name() << endl;
```

# ref

* code runner config for building multiple files https://stackoverflow.com/questions/59474537/code-runner-configuration-for-running-multiple-cpp-classes-in-vscode
* build cpp with mutiple files https://stackoverflow.com/questions/47665886/vs-code-will-not-build-c-programs-with-multiple-ccp-source-files
* Cherno: https://www.youtube.com/watch?v=0ebzPwixrJA
* ASCII Table: https://www.sciencebuddies.org/science-fair-projects/references/ascii-table
* Hex Decimal converter https://www.binaryhexconverter.com/decimal-to-hex-converter
* Processor Register and CPU components https://www.bbc.co.uk/bitesize/guides/z7qqmsg/revision/4
* GDB: the GNU project debugger https://www.gnu.org/software/gdb/
* bit, byte, 32-bit vs. 64-bit CPU, register, clock cycle, data memory bit allocation explained https://www.youtube.com/watch?v=s2aB13sOBi8
* GDB examining memory document: https://web.mit.edu/gnu/doc/html/gdb_10.html#SEC57
* GDB x command https://visualgdb.com/gdbreference/commands/x
