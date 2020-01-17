#!/homes/gwasserf/.brew/bin/python3
import sys
from termcolor import colored

previous = "'"

for line in sys.stdin:
    line = line.strip()
    if "Norm" in line and "Norm" in previous:        
        pass
    else:
        if "Norm" in previous:
            print(previous)
        print(colored(line, "red"))
    previous = line
