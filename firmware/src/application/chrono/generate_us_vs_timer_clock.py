import os

START_US=0
STOP_US=200000
FREQ=250000000.0
DIVIDER = 4





def Generate():
  f= open('_table%d.h'%DIVIDER,'w')
  f.write('static const uint32_t TBL%d[]={'%DIVIDER)
  ticks =0.0
  tmp1=""
  tmp2=""
  i=START_US
  while True:
    ticks = round((float(i)/1000000)/(1/(FREQ/DIVIDER/2)),0)
    tmp1 +="%dus\t"%i   
    tmp2 += "%d,\t"%ticks
    if i%10 ==0 :
      f.write('//%s\n %s\n'%(tmp1,tmp2))
      tmp1=""
      tmp2=""
    i+=1
    if  i>STOP_US: break   
  f.write('};')
  f.close


Generate()