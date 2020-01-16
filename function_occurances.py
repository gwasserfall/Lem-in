#!/homes/gwasserf/.brew/bin/python3
import sys
import os
import re

if len(sys.argv) != 3:
    if "focs" in __file__:
        print("Usage focs \"header_file\" \"source_folder\"")
    else:
        print("Usage {} \"header_file\" \"source_folder\"".format(__file__))
    quit(1)

header_file = sys.argv[1]
source_folder = sys.argv[2]

stats = []

def find_occurance_of_string(folder, string):

    counter = 0
    for file_name in os.listdir(source_folder):
        path = source_folder + '/' + file_name
        if path.endswith(".c"):
            with open(path, "r") as f:
                for line in f.readlines():
                    if string.lower() in line:
                        counter += 1
    return counter

with open(header_file, "r") as f:
    for line in f.readlines():
        if re.search(r"\(.*\);", line):
            func_line = re.sub(r"\(.*\);", "", line.strip()).replace(" ", "\t")
            func_name = func_line.split("\t")[-1]

            occurances = find_occurance_of_string("./src", func_name)

            stats.append({"function" : func_name, "occurances" : occurances)

stats.sort(key=lambda x: (-x["occurances"], x["function"].replace("*", "")))

for f in stats:
    print("{0: <25} :: {1}".format(f["function"], f["occurances"]))

