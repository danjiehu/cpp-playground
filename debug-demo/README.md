This repo is created to document how to set up and utilize debugging for C++ in Visual Studio Code.

# debug

* `Run and Debug` button on left side menu
* setting: `g++ - build and bebug active file`
* click `the green Play button` to start a debugging session
* break points (the red dot): where you want to the program to pause - the debugger will execute code until the line **BEFORE** where you set the debugger
* the yellow arrow: points to the line that is ABOUT TO be executed, but NOT yet
* set WATCH variables
* **view address**
* menu buttons
  * `Continue/Pause`
  * `Step Over`
  * `Step Into`
  * `Step Out`
  * `Restart`
  * `Stop`
* MAKE SURE
  * the active file is the one you want to run and debug

# config

* compile header files and multiple cpp class files with same `ctrl + opt + n` commands
  * add to Code Runner executor map json settings
    `"code-runner.executorMap": { "cpp": "cd $dir && g++ -std=c++14 *.cpp  -o $fileNameWithoutExt && $dir$fileNameWithoutExt", }, `
  * in tasks.json under the .vscode folder
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
* https://www.youtube.com/watch?v=0ebzPwixrJA
