# CirrusRT

## INTRODUCTION
CirrusRT is a physically-based volumetric renderer based on "Physically-Based Rendering: From Theory to Implementation." CirrusRT uses the Donut framework for the graphics API abstraction layer mechanism, and builds on this to present a photorealistic volumetric renderer.

After building the project and before running, enter this on the command line(powershell):
```
cd bin/Debug
./ShaderMake.exe -p DXIL --binary -c ../../shader/shader.cfg -o ../../build/Debug/shader/dxil --compiler <path/to/dxc.exe> --outputExt .bin
```

## ACKNOWLEDGEMENTS