## Libraries
Care to __clone__ these (and any new libraries) into /Applications/Arduino.app/Contents/Java/libraries and use as git submodules as necessary. The C/C++ intellisense also needs to be updated manually in c_cpp_properties.json

### Libraries currently used
[MPU9250](https://github.com/bolderflight/MPU9250)
[Adafruit_BMP280_Library](https://github.com/adafruit/Adafruit_BMP280_Library)

### .cpp, .c and .ino files
__.ino files__ : during compile time, the compiler joins all the .ino files together, in alphabetical order (except the 'main' .ino) and compiles as one big file. 
__.cpp / .h files__ : each file is compiled independently, this is standard c++ behaviour

Big multifile projects - use .cpp, small projects use .ino

Something to be aware of when deconstructing other peoples code made of multiple .ino files as they appear to be missing a heap of imports and variable declarations etc.

Don't mix and match


# Design decisions
- VS Code / Arduino plugin + Arduino IDE
- Use __.ino__ files for main program and its functions. __.cpp__ if you need to create a library