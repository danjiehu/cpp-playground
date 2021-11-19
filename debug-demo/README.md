This repo is created to demostrate how to set up and utilize debugging for C++ in Visual Studio Code.

# debug

* `Run and Debug` button on left side menu
* setting: `g++ - build and bebug active file`
* click the green play button to start a debugging session and view debug console for code execution result
* break points (the red dot): run all the code up until right BEFORE the line of breakpoint (the line of breakpoint is not executed)
* set WATCH variables
* **view address**
* **the yellow arrow points to the line that is about to be executed, but NOT YET**
* menu buttons (press Fn to activate function keys)
  * `Continue`***F5*** - execute a block of code: from the yellow-arrow line (included) to the line (included) right before the next break point
  * `Pause`*F6* - pause the running program, the yellow arrow will then pop up to indicate where the program is now
  * `Step Over`***F10*** - execute the yellow-arrow line and only that line
  * `Step Into`***F11*** - go into what's really being executed on the yellow-arrow line
  * `Step Out`*shift+F11* - go to what called the yellow-arrow line (can be used to go back to where you hit Step Into)
  * `Restart`
  * `Stop`
* MAKE SURE
  * the active file is the one you want to run and debug

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

# ref

* https://stackoverflow.com/questions/59474537/code-runner-configuration-for-running-multiple-cpp-classes-in-vscode
* https://stackoverflow.com/questions/47665886/vs-code-will-not-build-c-programs-with-multiple-ccp-source-files
* Cherno: https://www.youtube.com/watch?v=0ebzPwixrJA
