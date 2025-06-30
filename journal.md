day -27 jun
time speant-6.5
created bom, 
sertched for all vaiable items options avbailable in india,
sketched basic musicbox theme idea
got stuck between pcb and perfboard will change depending on what points i apply

next task,  i go for pcb schematic and board, 
creating the schematic, migrated from easyeda pro to std its muc easierr abd i wonk have toi spent 10 hrs designing custom footprint and symbols

![image](https://github.com/user-attachments/assets/4ae99e75-b766-474f-9914-ed2674924622)
the schematic was done wrong entire hour wasted, had to replace battery holde it was parallel needed in series
added new boost conver due to some components requiring 5v whivh woyuld beproblamatic directly
![image](https://github.com/user-attachments/assets/deda32e0-835e-481b-a088-ea43b305c0a9)
finally done with perfect wiring no more issues with esp and dataline connections

![image](https://github.com/user-attachments/assets/cd4a5390-c6b2-4db1-aed6-338fccb376f4) positioning done

man first time its without drc errors ![image](https://github.com/user-attachments/assets/ff063a99-08a4-43e6-b49a-ccdc8716f0c8) just beautiful 6 hrs since morning was useful at last will use copper fill then focus on 3d case will design the one of the most beautiful music boxes over there

day2 28 jun 
total time speant -till now 5 hrs
i forgot yo add a bl module withpoput that i would only work with sd cards so did that, also had to add ther amplifier with inbuilt knob resolving conflicts wkitrh potentiometer potentiomwer will now bw used to change colors intensity or modes.
![image](https://github.com/user-attachments/assets/1cb3b81c-e31d-4852-83f6-a0d939a63169)
so i verified netlist i was verifiynd all manually that was taLKING a lot of time just getting netlust asking ai to vdrify is alot fasdter i can easliy make corresctions


![image](https://github.com/user-attachments/assets/3b5feecf-99f4-49f6-a366-dfcf7d9167c3)
added p[inout for the ble model will use dupint wires for connection, the connection is good, so insted of 3 knobs wel have 4 2 forn psause plsy next prev 1 for vol 1 for light mode
successfuly rewired schemtic needed to use switch chip(CD4053) so had to find proper one  thst lwts switch between ble audio module to df card module had to remove rewire due to problem of paral;lel connection
![image](https://github.com/user-attachments/assets/cb7e11c5-e4a7-47c5-9365-5f7f14cfe388)
finall;y ![image](https://github.com/user-attachments/assets/2f1b1be3-5d57-4e52-a9f5-466bb707f1d0) got there headers and ble model addec rightlu created pcb no errors
 gotta import rest as right models weent available![image](https://github.com/user-attachments/assets/c827c82d-fbdb-4318-a1f5-860beea5debc)

 day 3 29 jun total hrs yet 7.5:
 found out all software the things libraries ill use, the no comprehensive software for me like one that letes me control boith wsdleds and the speaker too, 
 therre are pieces of software for individual like only dfplayer or only wsdled so had to learn hiw to combine both, 
 aded only my stufff to the only dfplayer code like what the rottory encoders shouls do, the pins that handel stuff,
 need to add code to switch audio from n-mh28 and df pl,ayer and indiividual rotatory encoder, while balancing wsdled

 added the right 3d modules fixed some more code
 ![image](https://github.com/user-attachments/assets/f80c052c-6ada-45e9-8666-9efd09a2b1b3) easy std is good no more need of importing 3d models in onshape

 messse up the normal cathoe led header had to change schematic, noe the 3 colors hve own datalines with resistor no risk of short circut changed how the leds are powrred now from 3.3 insted of 5![image](https://github.com/user-attachments/assets/5a255a3b-bb54-409c-aa02-8195bde5a74c)
 added proper 3d models but rotary nd potentiometers habe no righ one noe 3d modelling begains



so easyeda std is good for creating pcb but rendering models its a messs i imported from std to pro and directly imported grabcard models anf the pcb looks great
![image](https://github.com/user-attachments/assets/0c386472-21a9-4287-a20f-05ef78887e1a)

3d render-![image](https://github.com/user-attachments/assets/0f6f8e6a-3652-48af-9c87-2293904eda30)


3d mosels are still messed putting new mosderls from easyeda prov from 4-5 components-![image](https://github.com/user-attachments/assets/61d1ca38-5564-4d1d-93e4-46f10ff3996d)


finally-![image](https://github.com/user-attachments/assets/aa7143d2-31ba-41bc-80a8-78364adf6b65) after so muxh headche
ok pcb rendering is taking too much time jsut stuck shouldnt hape h]from here 5-6 hrs worjt of cad remains,
![image](https://github.com/user-attachments/assets/46f71c69-a958-427d-a692-5a4fe92f3719)

need to add the long femal pins

3d case ![image](https://github.com/user-attachments/assets/073051b6-b9c3-4139-91ea-672ecc99cd8f) finished this much had to rtedi thwe 2nd extrude as drectylu punching holes for usb inpout was infesiable,
![image](https://github.com/user-attachments/assets/6d806ef6-3292-471b-b3a1-76d8a26b6a28) i tried fixing the port for esp tpu and df player

![image](https://github.com/user-attachments/assets/1064010e-3f02-402c-9dc9-cf621541f91b) had to redo stuff
![image](https://github.com/user-attachments/assets/236300c6-b7df-4595-adb3-4502d3259065)still will tske ther whole day have to add accessories
![image](https://github.com/user-attachments/assets/6bb7fd88-3081-4424-a112-1c268526d4bc) finished basic steampunk theamed box what remains is the additions and look enhabncements


![image](https://github.com/user-attachments/assets/fc72a60d-c8c6-48f8-987f-d8554be722b5)

day 4 30june  time 4
speant 45 mins o pcb rendeing of nrw features took so muvh time i am mnow trying to remove pc but if i do the entirre sketcjkh throws errords, trying to replace it with dummy enclosure 
![image](https://github.com/user-attachments/assets/0c220104-5de6-433b-80b8-d8420ac84818)modifying the origninal pcb viaboolereran

finished fake nixietubes![image](https://github.com/user-attachments/assets/6efe1140-8bd3-47cf-ac7f-c1b3b507bd13)
![image](https://github.com/user-attachments/assets/d2cf7f55-f68d-45d7-8fd3-2ff2f021b1cf)
tried the faux tubes fake ones still prblemetic  will habe to try diff one![image](https://github.com/user-attachments/assets/47b9cfab-f4fc-4e66-9cd1-778cb270c545)
![image](https://github.com/user-attachments/assets/8dc2b7ba-f5f6-4c60-863d-58f414b08174)
![image](https://github.com/user-attachments/assets/accf8e62-b069-4c00-bf0a-4b24b7ba9989)





![image](https://github.com/user-attachments/assets/fe13f782-33f2-4fe6-950e-5cf1f8207302)






