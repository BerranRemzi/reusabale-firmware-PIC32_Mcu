import sys
import re
from datetime import datetime


tmp = None

#opening file
f = open("version.h","rb")
if f != None:
  tmp = f.read()
f.close()

#parsing text
version = int( re.search("\\#define \\VERSION\\s0x(.*)",tmp).group(1),16 )
version_date = datetime.strptime( re.search("\\#define VERSION_DATE\\s\"(.*)\"",tmp).group(1) , '%d.%m.%Y')

#
if len(sys.argv) == 1:
  print "Version:%d"%version
  print "Version date:%s"%datetime.now().date().strftime("%d.%m.%Y")

else:
  cmd = sys.argv[1].replace("\"","")
  if cmd == "increment" or cmd == "inc":
    f = open("version.h","wb+")
    if f != None:
      f.write("#ifndef VERSION_H\n")
      f.write("#define VERSION_H\n")
      f.write("\t#define VERSION 0x%06x\n"%(version+1) )
      f.write("\t#define VERSION_DATE \"%s\"\n"%datetime.now().date().strftime("%d.%m.%Y"))
      f.write("#endif // VERSION_H\n")
    f.close()






