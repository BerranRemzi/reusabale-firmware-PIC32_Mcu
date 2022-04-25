/*!
* @file gpio_map.h
* @author D.Chikov
* @date 12/28/2020, 11:37:25
* @brief GPIO MAP
*            GPIO_IN is input
*            GPIO_OUT is output
*            \sa gpio.h
*/



#define GPIO_MAP\
/*1*/   {  GPIO('G',15),  		GPIO_IN 									,0  },\
/*2*/   {  GPIO('A',5),  		GPIO_IN 									,0  },\
/*3*/   {  GPIO('E',5),  		GPIO_IN 								,0  },\
/*4*/   {  GPIO('E',6),  		GPIO_IN 								,0  },\
/*5*/   {  GPIO('E',7),  		GPIO_IN 								,0  },\
/*6*/   {  GPIO('C',1),  		GPIO_IN 								,0  },\
/*7*/   {  GPIO('C',2),  		GPIO_IN									,0  },\
/*8*/   {  GPIO('C',3),  		GPIO_IN									,0  },\
/*9*/   {  GPIO('C',4),  		GPIO_IN									,0  },\
/*10*/  {  GPIO('G',6),  		GPIO_IN									,0  },\
/*11*/  {  GPIO('G',7),  		GPIO_IN									,0  },\
/*12*/  {  GPIO('G',8),  		GPIO_IN									,0  },\
/*13 VSS*/  \
/*14 VDD*/  \
/*15 MCLR*/  \
/*16 LED2*/  {  GPIO('G',9),  		GPIO_OUT 									,1  },\
/*17 LED1*/  {  GPIO('A',0),  		GPIO_OUT 									,1  },\
/*18*/  {  GPIO('E',8),  		GPIO_IN                                     ,0  },\
/*19*/  {  GPIO('E',9),  		GPIO_IN 									,0  },\
/*20*/  {  GPIO('B',5),  		GPIO_IN 									,0  },\
/*21 KEY1*/  {  GPIO('B',4),  		GPIO_IN 									,0  },\
/*22*/  {  GPIO('B',3),  		GPIO_IN                                     ,0  },\
/*23 KEY2*/  {  GPIO('B',2),  		GPIO_IN 									,0  },\
/*24*/  {  GPIO('B',1),  		GPIO_IN 									,0  },\
/*25*/  {  GPIO('B',0),  		GPIO_IN 									,0  },\
/*26*/  {  GPIO('B',6),  		GPIO_IN                                     ,0  },\
/*27*/  {  GPIO('B',7),  		GPIO_IN 									,0  },\
/*28 VREF-*/  {  GPIO('A',9),  		GPIO_IN 									,0  },\
/*29 VREF+*/  {  GPIO('A',10),  		GPIO_IN 									,0  },\
/*30 AVDD*/  \
/*31 AVSS*/  \
/*32*/  {  GPIO('B',8),  		GPIO_ANALOG                                 ,0  },\
/*33*/  {  GPIO('B',9),  		GPIO_ANALOG                                 ,0  },\
/*34*/  {  GPIO('B',10),  		GPIO_ANALOG 								,0  },\
/*35*/  {  GPIO('B',11),  		GPIO_ANALOG 								,0  },\
/*36 VSS*/ \
/*37 VDD*/ \
/*38*/  {  GPIO('A',1),  		GPIO_IN 									,0  },\
/*39*/  {  GPIO('F',13),  		GPIO_IN                                     ,0  },\
/*40*/  {  GPIO('F',12),  		GPIO_IN 									,0  },\
/*41*/  {  GPIO('B',12),  		GPIO_IN 									,0  },\
/*42*/  {  GPIO('B',13),  		GPIO_OUT 									,0  },\
/*43*/  {  GPIO('B',14),  		GPIO_OUT 									,0  },\
/*44*/  {  GPIO('B',15),  		GPIO_OUT									,0  },\
/*45 VSS*/      \
/*46 VDD*/      \
/*47*/  {  GPIO('D',14),  		GPIO_IN 									,0  },\
/*48*/  {  GPIO('D',15),  		GPIO_OUT 									,0  },\
/*49*/  {  GPIO('C',12),  		GPIO_IN 									,0  },\
/*50*/  {  GPIO('C',15),  		GPIO_IN 									,0  },\
/*51 VBUS*/         \
/*52 VUSB3V3*/      \
/*53 VSS*/          \
/*54 USB D-*/       \
/*55 USB D+*/       \
/*56*/  {  GPIO('F',3),  		GPIO_IN 									,0  },\
/*57*/  {  GPIO('F',2),  		GPIO_IN                                     ,0  },\
/*58*/  {  GPIO('F',8),  		GPIO_IN                                     ,0  },\
/*59*/  {  GPIO('A',2),  		GPIO_IN 									,0  },\
/*60*/  {  GPIO('A',3),  		GPIO_IN 									,0  },\
/*61*/  {  GPIO('A',4),  		GPIO_IN                                     ,0  },\
/*62 VDD*/          \
/*63 VSS*/          \
/*64*/  {  GPIO('F',4),  		GPIO_IN                                     ,0  },\
/*65*/  {  GPIO('F',5),  		GPIO_IN                                     ,0  },\
/*66*/  {  GPIO('A',14),  		GPIO_IN                                     ,0  },\
/*67*/  {  GPIO('A',15),  		GPIO_IN                                     ,0  },\
/*68*/  {  GPIO('D',9),  		GPIO_IN                                     ,0  },\
/*69*/  {  GPIO('D',10),  		GPIO_IN										,0  },\
/*70*/  {  GPIO('D',11),  		GPIO_IN										,0  },\
/*71*/  {  GPIO('D',0),  		GPIO_IN										,0  },\
/*72*/  {  GPIO('C',13),  		GPIO_IN                                     ,0  },\
/*73*/  {  GPIO('C',14),  		GPIO_IN                                     ,0  },\
/*74 VDD*/          \
/*75 VSS*/          \
/*76*/  {  GPIO('D',1),  		GPIO_IN										,0  },\
/*77*/  {  GPIO('D',2),  		GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_C1TX)		,0  },\
/*78*/  {  GPIO('D',3),  		GPIO_CUSTOM_INPUT(INPUT_FUNC_C1RX)		    ,0  },\
/*79*/  {  GPIO('D',12),  		GPIO_IN		    							,0  },\
/*80*/  {  GPIO('D',13),  		GPIO_IN		    							,0  },\
/*81*/  {  GPIO('D',4),  		GPIO_IN		    							,0  },\
/*82*/  {  GPIO('D',5),  		GPIO_IN                                     ,0  },\
/*83 VDD*/          \
/*84 VSS*/          \
/*85*/  {  GPIO('F',0),  		GPIO_IN                                     ,0  },\
/*86*/  {  GPIO('F',1),  		GPIO_IN                                     ,0  },\
/*87*/  {  GPIO('G',1),        GPIO_CUSTOM_OUTPUT(OUTPUT_FUNC_U3TX)|GPIO_IN ,0  },\
/*88*/  {  GPIO('G',0),        GPIO_CUSTOM_INPUT(INPUT_FUNC_U3RX)|GPIO_IN	,0  },\
/*89*/  {  GPIO('A',6),  		GPIO_IN                                     ,0  },\
/*90*/ {  GPIO('A',7),  		GPIO_IN                                     ,0  },\
/*91*/ {  GPIO('E',0),  		GPIO_IN                                     ,0  },\
/*92 VSS*/          \
/*93 VDD*/          \
/*94*/ {  GPIO('E',1),  		GPIO_IN										,0  },\
/*95*/ {  GPIO('G',14),  		GPIO_IN                                     ,0  },\
/*96*/ {  GPIO('G',12),  		GPIO_IN										,0  },\
/*97*/ {  GPIO('G',13),  		GPIO_IN										,0  },\
/*98*/ {  GPIO('E',2),  		GPIO_IN                                     ,0  },\
/*99*/ {  GPIO('E',3),  		GPIO_IN                                     ,0  },\
/*100*/ {  GPIO('E',4),  		GPIO_IN										,0  },\
 { 0,0}


