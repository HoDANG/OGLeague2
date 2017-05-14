import re
import json
import os

def readFile(file, dump):
    f = open(file, "r")
    count = 0
    for line in f:
        if count == 0 :
            m = re.search("^([a-zA-Z_]+)(\\s*=)", line)
            if not (m == None or m == ""):
                if '{' in line and "BuildingBlocks" in line:
                    if not m.group(1) in dump["BuildingBlocks"]:
                        dump["BuildingBlocks"].append(m.group(1))
                else:
                    if not m.group(1) in dump["ScriptVars"]:
                        dump["ScriptVars"].append(m.group(1))
        count = count + line.count('{') - line.count('}')
    f.close()

def readDir(name, output , startfilter = ""):
    dump = {}
    dump["BuildingBlocks"] = []
    dump["ScriptVars"] = []
    for root, dirs, files in os.walk(name):
        for file in files:
            if file.endswith(".lua") and (startfilter == "" or file.startswith(startfilter)):
                readFile(os.path.join(root, file), dump)
    of = open(output, "w+")
    of.write(json.dumps(dump, sort_keys=True, indent=4))
    of.close()


readDir("DATA/Characters", "dox/Characters.json", "CharScript")
readDir("DATA/Items", "dox/Items.json")
readDir("DATA/Spells", "dox/Spells.json")
readDir("DATA/Talents", "dox/Talents.json")

