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
2. Run `./inverted_pendulum_motion.exe (optional parameters)` (See examples)
The parameters are `theta_0 v_theta_0 omega nSteps totalTime a g l`

3. You can open output.dat in any data plotting software. To see it in Octave, run `octave-cli -q`
4. To generate the graph, run `showMotion('output.dat')` within Octave.