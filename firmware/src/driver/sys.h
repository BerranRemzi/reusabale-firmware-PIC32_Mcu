#ifndef SYS_H
#define SYS_H

/*!
* 	 gpio_unlockChanges()
* 
* 	...tbd...
*/
#define sys_unlock() \
do{	                     \
	SYSKEY = 0x00000000; \
	SYSKEY = 0xAA996655; \
	SYSKEY = 0x556699AA; \
}while(0)



/*!
* 	 gpio_lockChanges(  )
* 
* 	...tbd...
*/
#define sys_lock()  \
do{                         \
	SYSKEY = 0x33333333;\
}while(0)
#endif