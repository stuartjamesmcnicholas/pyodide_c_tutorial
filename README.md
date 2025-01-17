# Build C extension into Pyodide

This is mainly a set of notes for myself when learning how to build a C extension
for Pyodide. In due course I would probably like to investigate if I can incorporate
nanobind into this.

```
  python3.12 -m venv pyodide_env/
  source pyodide_env/bin/activate
  python3 -m pip install pyodide-build
  pyodide config get emscripten_version
  git clone https://github.com/emscripten-core/emsdk.git
  cd emsdk/
  ./emsdk install 3.1.58
  ./emsdk activate 3.1.58
  source emsdk_env.sh
  emcc -v #Check we have 3.1.58
  cd ..
  git clone https://github.com/stuartjamesmcnicholas/pyodide_c_tutorial.git
  cd pyodide_c_tutorial/aproject
  pyodide build #This builds the emscripten wheel!
  cp dist/mypackage-0.0.1-cp312-cp312-pyodide_2024_0_wasm32.whl ../serve_example
  cd ..
  python -m http.server --directory serve_example
```

Other useful commands:
```
  pyodide xbuildenv search --all #shows available configurations
```

```
  python3 -m pip install #This builds for the native pyenv python rather than Pyodide, useful for testing
```
