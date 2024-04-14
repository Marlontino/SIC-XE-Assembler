0000	COPY      START   0                    
0000	FIRST     CLEAR   X		B72FFC
0003	          LDA    #0		010000
0006	         +LDB    #TOTAL		6910178C
000A	          BASE    TOTAL
000A	LOOP      ADD     TABLE,X		1BA00F
000D	          TIX     COUNT		2F2009
0010	          JLT     LOOP		3B2FF6
0013	          STA     TOTAL   		0F4000
0016	          RSUB 		4F0000
0019	COUNT     RESW    1
001C	TABLE     RESW    2000
178C	TOTAL     RESW    1                        
178F	          END     FIRST
