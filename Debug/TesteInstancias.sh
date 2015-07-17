#!/bin/bash

make clean

make 

./Git-Manne-Robson-1 Ins-V1-\*P-R\*.txt >> Prompt-Ins-V1-\*P-R\*.txt

sleep 180

./Git-Manne-Robson-1 Ins-V2-\*P-R\*.txt >> Prompt-Ins-V2-\*P-R\*.txt

sleep 180

./Git-Manne-Robson-1 Ins-V3-\*P-R\*.txt >> Prompt-Ins-V3-\*P-R\*.txt

sleep 180

./Git-Manne-Robson-1 Ins-V1-\*P-C\*.txt >> Prompt-Ins-V1-\*P-C\*.txt

sleep 180

./Git-Manne-Robson-1 Ins-V2-\*P-C\*.txt >> Prompt-Ins-V2-\*P-C\*.txt

sleep 180

./Git-Manne-Robson-1 Ins-V3-\*P-C\*.txt >> Prompt-Ins-V3-\*P-C\*.txt
