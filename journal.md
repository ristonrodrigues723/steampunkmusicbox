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

 day 3 29 jun total hrs yet 2.5:
 found out all software the things libraries ill use, the no comprehensive software for me like one that letes me control boith wsdleds and the speaker too, 
 therre are pieces of software for individual like only dfplayer or only wsdled so had to learn hiw to combine both, 
 aded only my stufff to the only dfplayer code like what the rottory encoders shouls do, the pins that handel stuff,
 need to add code to switch audio from n-mh28 and df pl,ayer and indiividual rotatory encoder, while balancing wsdled

 added the right 3d modules fixed some more code
 ![image](https://github.com/user-attachments/assets/f80c052c-6ada-45e9-8666-9efd09a2b1b3) easy std is good no more need of importing 3d models in onshape







