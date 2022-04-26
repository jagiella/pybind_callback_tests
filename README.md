## build example module


```bash
%%bash
cmake -S . -B build && cmake --build build
```

    -- The C compiler identification is GNU 11.2.0
    -- The CXX compiler identification is GNU 11.2.0
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working C compiler: /usr/bin/cc - skipped
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Detecting CXX compiler ABI info
    -- Detecting CXX compiler ABI info - done
    -- Check for working CXX compiler: /usr/bin/c++ - skipped
    -- Detecting CXX compile features
    -- Detecting CXX compile features - done
    -- Found PythonInterp: /usr/bin/python3.10 (found version "3.10.4") 
    -- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython3.10.so
    -- Performing Test HAS_FLTO
    -- Performing Test HAS_FLTO - Success
    -- Found pybind11: /usr/include (found version "2.9.1")
    -- Configuring done
    -- Generating done
    -- Build files have been written to: /home/nick/Dokumente/GitHub/pybind_callback_tests/build
    [ 50%] Building CXX object CMakeFiles/example.dir/pybind.cpp.o
    [100%] Linking CXX shared module example.cpython-310-x86_64-linux-gnu.so
    [100%] Built target example


## extend PYTHONPATH to find example module


```python
import sys
sys.path.append('build')
```

## import test function and callbacks 


```python
from example import equal, cpp_callback1, cpp_callback2

def py_callback1():
    print('py_callback1 called')

def py_callback2():
    print('py_callback2 called')
```


```python
# execute callbacks
py_callback1()
py_callback2()
cpp_callback1()
cpp_callback2()
```

    py_callback1 called
    py_callback2 called
    cpp_callback1 called
    cpp_callback2 called



```python
# compare cpp functions
print(equal(cpp_callback1, cpp_callback1))
print(equal(cpp_callback1, cpp_callback2))
```

    True
    False
    f1 and f2 of same type: PFvvE
    f1 and f2 of same type: PFvvE



```python
# compare python functions
print(equal(py_callback1, py_callback1))
print(equal(py_callback1, py_callback2))
```

    False
    False
    f1 and f2 of same type: ZN8pybind116detail11type_casterISt8functionIFvvEEvE4loadENS_6handleEbE12func_wrapper
    f1 can not be cast to : void(*)()
    f1 and f2 of same type: ZN8pybind116detail11type_casterISt8functionIFvvEEvE4loadENS_6handleEbE12func_wrapper
    f1 can not be cast to : void(*)()



```python

```
