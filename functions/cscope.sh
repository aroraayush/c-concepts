#!/bin/bash 
find .  \( -name "*.[chlyCHLY]" -o -name "*.ll" -o -name "*.yy"  -o -name "*.cxx" -o -name "*.cpp" -o -name "*.go" \) -print > cscope.files