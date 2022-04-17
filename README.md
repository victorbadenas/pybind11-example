# pybind11-example

## Prerequisites

* A compiler with C++11 support
* Pip 10+ or CMake >= 3.4 (or 3.8+ on Windows, which was the first version to support VS 2015)
* Ninja or Pip 10+

## Installation

Just clone this repository and pip install. Note the `--recursive` option which is
needed for the pybind11 submodule:

```bash
git clone --recursive https://github.com/victorbadenas/pybind11-example.git
cd pybind11-example
pip install .[test]
```

The `pip install` command will invoke CMake and build the pybind11 module as
specified in `CMakeLists.txt`.

## Building the documentation

Documentation for the example project is generated using Sphinx. Sphinx has the
ability to automatically inspect the signatures and documentation strings in
the extension module to generate beautiful documentation in a variety formats.
The following command generates HTML-based reference documentation; for other
formats please refer to the Sphinx manual:

```bash
cd ./docs
make html
```

## License

Pybind11 is provided under a BSD-style license that can be found in the LICENSE
file. By using, distributing, or contributing to this project, you agree to the
terms and conditions of this license.

## Test call

```python
import sample_package
sample_package.add(1, 2)
```

[`cibuildwheel`]:          https://cibuildwheel.readthedocs.io
[FAQ]: http://pybind11.rtfd.io/en/latest/faq.html#working-with-ancient-visual-studio-2009-builds-on-windows
[vs2015_runtime]: https://www.microsoft.com/en-us/download/details.aspx?id=48145
[scikit-build]: https://scikit-build.readthedocs.io/en/latest/

## Troubleshooting

* Anaconda: `version 'GLIBCXX_*' not found`. (Debian/apt based systems).
  * verify that the `gcc-4.9` library is installed. `apt list --installed | grep c++` in debian or systems that use `apt`.
  * Check that the version is available with: `strings /usr/lib/x86_64-linux-gnu/libstdc++.so.6 | grep GLIBCXX`.
  * If the version is available as shown by the previous command, backup the enviroment's `libstdc++.so.6` and link the one in your system:

    ```bash
    mv -vf ~/anaconda3/envs/${YOUR_ENV}/lib/libstdc++.so.6 ~/anaconda3/envs/${YOUR_ENV}/lib/libstdc++.so.6.old
    ln -s /usr/lib/x86_64-linux-gnu/libstdc++.so.6 ~/anaconda3/envs/${YOUR_ENV}/lib/libstdc++.so.6
    ```
