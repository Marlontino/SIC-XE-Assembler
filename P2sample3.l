0000	COPY      START   0                    
0000	FIRST     STL     RETADR          		17202D
0003	          LDB    #LENGTH          		69202D
0006	          BASE    LENGTH     
0006	CLOOP    +JSUB    RDREC		4B101036
000A	          LDA     LENGTH    		032026
000D	          COMP   #0 		290000
0010	          JEQ     ENDFIL      		332007
0013	         +JSUB    WRREC       		4B101062
0017	          J       CLOOP      		3F2FEB
001A	ENDFIL    LDA     EOF               		032010
001D	          STA     BUFFER		0F2016
0020	          LDA    #3		010003
0023	          STA     LENGTH		0F200D
0026	         +JSUB    WRREC		4B101062
002A	          J     @RETADR		3E2003
		454F46
0030	RETADR    RESW    1
0033	LENGTH    RESW    1
0036	BUFFER    RESB    4096  
1036	RDREC     CLEAR   X		B74FCC
1039	          CLEAR   A		B74FCC
103C	          CLEAR   S		B74FCC
103F	         +LDT    #4096		75104096
1043	RLOOP     TD      INPUT		E3201B
1046	          JEQ     RLOOP		332FF9
1049	          RD      INPUT		DB2015
104C	          COMPR   A,S		A34FCC
104F	          JEQ     EXIT		332009
1052	          STCH    BUFFER,X		57C003
1055	          TIXR    T 		BB4FCC
1058	          JLT     RLOOP		3B2FE7
105B	EXIT      STX     LENGTH		134000
105E	          RSUB 		4F0000
		F1
1062	WRREC     CLEAR   X		B74FCC
1065	          LDT     LENGTH		774000
1068	WLOOP     TD      OUTPUT		E32012
106B	          JEQ     WLOOP		332FF9
106E	          LDCH    BUFFER,X		53C003
1071	          WD      OUTPUT		DF2009
1074	          TIXR    TABLE		BB4FCC
1077	          JLT     WLOOP		3B2FED
107A	          RSUB		4F0000
		05
107E	          END     FIRST
