## Installation
- `pip install pybind11`


## Naming structure ::
- module.cpp 
    - filename
    - content `PYBIND11_MODULE(module, m) {}`
- main.py
    - `module`
    - `module.add(x,y)`
- Makefile
    - `MODULE := module`

## Debug
- make info

## Usage
- make build (Compile dynamic library)
- make run (Run python code)
- make clean (Delete shared library)