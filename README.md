# SIMPLE_NLP

## introduction

A simple library and command line program to calculate nlp problems.

## setup
`cmake` and `g++` is required.
```bash
$ cmake CMakeLists.txt
$ make
$ sudo make install
```

## usage
You can use `nlp_tool -h` to get help.
```
USAGE: 

   nlp_tool  -r <std::string> -y <std::string> [-x] [-c] [-d] [--]
             [--version] [-h]


Where: 

   -r <std::string>,  --ref <std::string>
     (required)  reference string

   -y <std::string>,  --hyp <std::string>
     (required)  hypnosis string

   -x,  --detailed
     show the detailed info of the calculate result.

   -c,  --CER
     calculate the CER of two strings.

   -d,  --edit_distance
     calculate the edit distance of two strings.

   --,  --ignore_rest
     Ignores the rest of the labeled arguments following this flag.

   --version
     Displays version information and exits.

   -h,  --help
     Displays usage information and exits.


   Simple NLP executable file. Able to calculate edit distance and CER.  

```
For example:
```bash
$ nlp_tool -d -r "horse" -y "ros"
edit distance: 3
$ nlp_tool -c -r "horse" -y "ros"
CER: 0.6
$ nlp_tool -x -r "horse" -y "ros"
hyp: ros                           
ref: horse                         
edit distance: 3                             
CER: 0.6                           
substitution characters: 1                             
deletion characters: 2                             
insertion characters: 0         
```