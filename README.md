# Toy Cpp

This project is mainly used as a test of the following dependencies, but can also be used as a starting point for a new c++ project :

-  [Nael utils](https://github.com/KobNael/nael_utils) : a small C++ library with some useful tools
-  [Nael Cpp Action](https://github.com/KobNael/nael_cpp_action) : a reusable github pipeline for full C++ CI process

## Notations
- `path_to_repo` corresponds to the root directory of this git repository
- `build_directory` corresponds to the build directory (automagically created by conan).
It should be something like `path_to_repo/builds/Linux/gcc/13/x86_64/(Debug|Release)/`
- `path_to_bin` corresponds to the path to the binary.
It should be something like `path_to_repo/builds/Linux/gcc/13/x86_64/(Debug|Release)/src/app/ps_scheduling`

## Installation

### Environnement

Tested on Ubuntu 24.04.1 LTS (native or through wsl2).

1. Update your system

    > $ sudo apt-get update && sudo apt-get upgrade

1. Install c++ tools

    > $ sudo apt-get install -y git cmake make doxygen gcc gcovr lcov libncurses5-dev cppcheck valgrind

1. Install python3/pip3/venv
    > $ sudo apt-get install python3 python3-pip python3-venv

    > $ pip3 install --upgrade pip

### Get source code

1. Clone the main repository
    > $ git clone git@github.com:KobNael/nael_toy_cpp.git

### Before first compilation

1. Create a new dedicated virtual environnement
    > $ python -m venv ps_venv

1. Activate the virtual environnement
    > $ source path_to_ps_venv/bin/activate

1. Install the Python requirements (conan)
    > $ pip3 install -r path_to_repo/requirements.txt

1. Set up the conan profiles
    > $ conan config install https://github.com/KobNael/nael_cpp_action.git --args="-b main"

1. Update gcc to at least gcc 13. To check:
   > $ gcc --version

1. Update cmake to at least 3.28. To check:
   > $ cmake --version


### First compilation

1. **Debug**
    > $ cd path_to_repo && conan build . -sbuild_type=Debug -o '&:coverage=ON' -o '&:cppcheck=ON' -o '&:valgrind=ON'  -pr:a=Linux-latest  --build missing

1. **Release**
    > $ cd path_to_repo && conan build . -sbuild_type=Release  -pr:a=Linux-latest  --build missing

### Launch tests
:warning: All the results can be found in the directory `path_to_repo/compilation-databases/(Debug|Release)`.
1. **Unit tests**
    > $ cd build_directory/ && make run_unit_tests

1. **Valgrind Memcheck**
    :warning:  Only available if the option `-o '&:valgrind=ON'` has been given to the `conan build` command.

    > $ cd build_directory/ && make run_memcheck

1. **GCov|LCov Coverage**
    :warning:  Only available in Debug, and if the option `-o '&:coverage=ON'` has been given to the `conan build` command.
    > $ cd build_directory/ && make run_coverage

1. **CppCheck Linter**
    :warning:  Only available if the option `-o '&:cppcheck=ON'` has been given to the `conan build` command.
    > $ cd build_directory/ && make run_cppcheck

