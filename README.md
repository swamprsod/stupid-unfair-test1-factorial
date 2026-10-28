# results
i5^3320m

1. ATS2
*580.1 µs*
2. C
*616.5 µs*
3. C (dumb)
*685.3 µs*
4. idris2 
*768.5 µs*
5. rust
*904.6 µs*
6. java*
*17200 µs*
7. python
*19500 µs*

... ATS2 , C , C (dumb) also have almost same amount of cycles  (1,248,655  1,245,556  1,243,295)

\*java: (- '-Xlog:startuptime' Time)

## c (not recursive) clang -O2

```
; coma< hyperfine ./f_dumb_c
Benchmark 1: ./f_dumb_c
  Time (mean ± σ):     685.3 µs ± 205.5 µs    [User: 570.3 µs, System: 135.9 µs]
  Range (min … max):   370.9 µs … 1723.7 µs    2024 runs

; coma< perf stat ./f_dumb_c
2432902008176640000

 Performance counter stats for './f_dumb_c':

              0.61 msec task-clock                       #    0.373 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
                59      page-faults                      #   96.784 K/sec
         1,243,295      cycles                           #    2.039 GHz
           902,850      stalled-cycles-frontend          #   72.62% frontend cycles idle
           648,082      instructions                     #    0.52  insn per cycle
                                                  #    1.39  stalled cycles per insn
           131,391      branches                         #  215.534 M/sec
             7,236      branch-misses                    #    5.51% of all branches

       0.001634847 seconds time elapsed

       0.001900000 seconds user
       0.000000000 seconds sys
```
## c clang -O2

```
; coma< hyperfine ./f_c
Benchmark 1: ./f_c
  Time (mean ± σ):     616.5 µs ± 218.1 µs    [User: 537.2 µs, System: 120.8 µs]
  Range (min … max):   332.9 µs … 1980.4 µs    2034 runs

; coma< perf stat ./f_c
2432902008176640000

 Performance counter stats for './f_c':

              0.61 msec task-clock                       #    0.384 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
                58      page-faults                      #   94.936 K/sec
         1,245,556      cycles                           #    2.039 GHz
           904,801      stalled-cycles-frontend          #   72.64% frontend cycles idle
           645,752      instructions                     #    0.52  insn per cycle
                                                  #    1.40  stalled cycles per insn
           130,318      branches                         #  213.307 M/sec
             7,270      branch-misses                    #    5.58% of all branches

       0.001591614 seconds time elapsed

       0.001866000 seconds user
       0.000000000 seconds sys

```
## java

```
( '[0.034s][info][startuptime] Create VM, 0.0324847 secs' => 49.7 - 32.5 \approx 17.2 ms )

; coma< hyperfine "java Main"
Benchmark 1: java Main
  Time (mean ± σ):      49.7 ms ±   1.3 ms    [User: 39.6 ms, System: 20.2 ms]
  Range (min … max):    46.5 ms …  53.4 ms    55 runs

; coma< perf stat java Main
2432902008176640000

 Performance counter stats for 'java Main':

             70.20 msec task-clock                       #    0.311 CPUs utilized
               117      context-switches                 #    1.667 K/sec
                10      cpu-migrations                   #  142.445 /sec
             4,951      page-faults                      #   70.525 K/sec
       178,039,604      cycles                           #    2.536 GHz
       122,344,484      stalled-cycles-frontend          #   68.72% frontend cycles idle
       116,563,975      instructions                     #    0.65  insn per cycle
                                                  #    1.05  stalled cycles per insn
        22,042,778      branches                         #  313.989 M/sec
         1,030,831      branch-misses                    #    4.68% of all branches

       0.225829545 seconds time elapsed

       0.055324000 seconds user
       0.020118000 seconds sys

```

## ats2 (patscc g++14 O0)

```
; coma< hyperfine ./f_ats
Benchmark 1: ./f_ats
  Time (mean ± σ):     580.1 µs ± 222.9 µs    [User: 489.4 µs, System: 134.2 µs]
  Range (min … max):   277.8 µs … 2019.6 µs    1944 runs

; coma< perf stat ./f_ats
2432902008176640000

 Performance counter stats for './f_ats':

              0.61 msec task-clock                       #    0.370 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
                58      page-faults                      #   94.809 K/sec
         1,248,655      cycles                           #    2.041 GHz
           907,184      stalled-cycles-frontend          #   72.65% frontend cycles idle
           644,398      instructions                     #    0.52  insn per cycle
                                                  #    1.41  stalled cycles per insn
           130,426      branches                         #  213.198 M/sec
             7,417      branch-misses                    #    5.69% of all branches

       0.001654625 seconds time elapsed

       0.001954000 seconds user
       0.000000000 seconds sys

```
## rust (rustc)

```
; coma< hyperfine ./f_rust
Benchmark 1: ./f_rust
  Time (mean ± σ):     904.6 µs ± 250.2 µs    [User: 770.0 µs, System: 180.7 µs]
  Range (min … max):   536.7 µs … 2350.0 µs    1364 runs

; coma< perf stat ./f_rust
2432902008176640000

 Performance counter stats for './f_rust':

              0.84 msec task-clock                       #    0.417 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
                73      page-faults                      #   87.157 K/sec
         1,993,427      cycles                           #    2.380 GHz
         1,464,478      stalled-cycles-frontend          #   73.47% frontend cycles idle
         1,052,259      instructions                     #    0.53  insn per cycle
                                                  #    1.39  stalled cycles per insn
           213,727      branches                         #  255.176 M/sec
            10,546      branch-misses                    #    4.93% of all branches

       0.002006178 seconds time elapsed

       0.002088000 seconds user
       0.000000000 seconds sys

```
## idris2 (refc)

```
; coma< hyperfine ./f_i2_refc
Benchmark 1: ./f_i2_refc
  Time (mean ± σ):     768.5 µs ± 225.2 µs    [User: 632.8 µs, System: 161.2 µs]
  Range (min … max):   440.1 µs … 2140.7 µs    1557 runs

; coma< perf stat ./f_i2_refc
2432902008176640000

 Performance counter stats for './f_i2_refc':

              0.82 msec task-clock                       #    0.437 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
                68      page-faults                      #   82.613 K/sec
         1,608,166      cycles                           #    1.954 GHz
         1,145,280      stalled-cycles-frontend          #   71.22% frontend cycles idle
           912,126      instructions                     #    0.57  insn per cycle
                                                  #    1.26  stalled cycles per insn
           183,042      branches                         #  222.378 M/sec
             9,088      branch-misses                    #    4.96% of all branches

       0.001881489 seconds time elapsed

       0.002023000 seconds user
       0.000000000 seconds sys

```
## python 

```
; coma< hyperfine py ./fac.py
Benchmark 1: py ./fac.py
  Time (mean ± σ):      19.5 ms ±   1.8 ms    [User: 15.3 ms, System: 4.1 ms]
  Range (min … max):    17.2 ms …  27.0 ms    151 runs

; coma< perf stat py ./fac.py
2432902008176640000

 Performance counter stats for 'py ./fac.py':

             25.96 msec task-clock                       #    0.931 CPUs utilized
                 0      context-switches                 #    0.000 /sec
                 0      cpu-migrations                   #    0.000 /sec
               876      page-faults                      #   33.745 K/sec
        57,807,619      cycles                           #    2.227 GHz
        34,752,814      stalled-cycles-frontend          #   60.12% frontend cycles idle
        47,783,238      instructions                     #    0.83  insn per cycle
                                                  #    0.73  stalled cycles per insn
        10,262,164      branches                         #  395.315 M/sec
           557,481      branch-misses                    #    5.43% of all branches

       0.027888110 seconds time elapsed

       0.024110000 seconds user
       0.004018000 seconds sys
```
