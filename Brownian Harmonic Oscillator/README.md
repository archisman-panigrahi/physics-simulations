## Dependencies
This is intended to be run in Unix based operating system.
`BLAS` is required to run this program. `GCC` is needed to compile
Use the following commands to install it in Debian based systems.
```bash
sudo apt install libopenblas-dev gcc
```

You can use GNU Octave to generate graphs

```bash
sudo apt install octave
```

## How to use

1. To compile, run `make`
2. Run `./dhosc.exe "optional parameters"` (without the quotes)
The parameters are `x_0 v_0 omega gamma squeeze nSteps totalTime`

3. You can open output.dat in any data plotting software. To see it in Octave, run `octave-cli -q`
4. To generate the graph, run `showMotion` within Octave.