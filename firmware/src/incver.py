import sys
import re
from datetime import datetime


def read_current_file(filename):
    tmp = None
    #opening file
    f = open(filename,"rb")
    if f != None:
        tmp = f.read()
    else: return None
    f.close()
    build={}
    s = re.search("BUILD\\s+0x([0-9A-Za-z]+)",tmp)
    #parsing text
    build["version"] = int( s.group(1), 16 )
    s = re.search("\\#define BUILD_DATE\\s+\"(.*)\"",tmp)
    build["date"] = datetime.strptime( s.group(1) , '%d.%m.%Y')
    s = re.search("\\#define PROJECT\\s+\"(.*)\"",tmp)
    build["project"] = s.group(1)
    return build


def write_build_info(filename,build):
    f = open(filename, "wb+")
    if f != None:
        f.write("#ifndef BUILD_H\n")
        f.write("#define BUILD_H\n")
        f.write("#define BUILD 0x%06x\n"%build["version"] )
        new_date = datetime.now().date().strftime("%d.%m.%Y")
        f.write("#define BUILD_DATE \"%s\"\n"%new_date)
        f.write("#define PROJECT \"%s\"\n"%build["project"])
        f.write("#endif \n")
    f.close()


build = read_current_file("./build.h")
if  build != None:
    if len(sys.argv)>1 and (sys.argv[1] == "inc" or sys.argv[1] == "new"):
        build["version"] = build["version"]+1
    write_build_info("./build.h", build)







