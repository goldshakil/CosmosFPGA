# CosmosFPGA
This project and research is directed towards accelerating data bases by using a Cosmos FPGA (XC7Z045-3FFG900 Zynq-7000).


## Goals of this project:
1) Connecting COSMOS FPGA to a host PC using Xillybus and then Implementing data transfer over PCIe.
2) Accelerating SQLite by implementing an enhanced version of the merge sort algorithm on the FPGA.

### Pre-Requirements:
Download Vivado HLS/Design Suite and SDK from [Here](https://www.xilinx.com/support/download/index.html/content/xilinx/en/downloadNav/vivado-design-tools/2019-2.html).

## Part 1: Connecting COSMOS FPGA to a host PC over PCIe.
### Requirements: 
1) Cosmos+ board (can be obtained [Here](http://www.openssd.io/)).
2) Xillybus bundle (can be obtained [Here](http://xillybus.com/downloads/xillybus-eval-zynq-pcie-2.0d.zip)).

### Documentation and Tutorials:
1) Documentation (can be obtained [Here](http://xillybus.com/doc)).
2) Tutorials (can be obtained [Here](http://xillybus.com/tutorials)).

## Part 2: Implementing Enhanced Merge Sort on Cosmos+ FPGA:
## Requirements:
1) HLS Code in the src directory.
2) Block Diagram (can be obtained by following the tutorial [Here](https://github.com/Cosmos-OpenSSD/Cosmos-plus-OpenSSD/blob/master/doc/Cosmos%2B%20OpenSSD%202017%20Tutorial.pdf)).
3) SDK Code in the src directory.



