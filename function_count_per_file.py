#!/homes/gwasserf/.brew/bin/python3
import sys
import os
import re

if len(sys.argv) != 2:
    print("Usage {} \"source_directory\"".format(__file__))
    quit(1)

folder = sys.argv[1]

funcs = []

for fi in os.listdir(folder):
    path = folder + "/" + fi

    if path.endswith(".c"):
        with open(path, "r") as f:
            func_count = re.findall(r"\n\{", f.read())
            funcs.append({"f" : fi, "count" : len(func_count)})


funcs.sort(key=lambda x: -x["count"])

for f in funcs:
    print("{0: <25} :: {1}".format(f["f"], f["count"]))