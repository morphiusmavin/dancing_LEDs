<h1>Dancing LEDs</h1>
1) run do1.sh to generate test.txt 
2) edit out all the comments in test.txt
3) cut and paste test.txt to what's in between 
	the curly brackets of buf[] = {...}
	in main.c
4) then compile main.c with AVR compiler
	and load to the ProMini

topview pinout for ProMini with reset switch
at bottom

#PD1		RAW
#PD0		GND
 PC6		PC6
 GND		VCC
#PD2		PC3
#PD3		PC2
#PD4		PC1
#PD5		PC0
#PD6		PB5
#PD7		PB4
 PB0		PB3
 PB1		PCB2

LEDs are connected to PORTD (marked as '#')


test.cx:

1) fill from right
2) clear from left
3) fill from left
4) clear from right
5) fill from right
6) clear from right
7) fill from left
8) clear from left
single digit from right
single digit from left
single digit from left
single digit from right
single digit from left (3x)
single digit from right (3x)

test2.cx:

fill from right
single digit from left (reverse)
single digit from right (reverse)
single digit from right (reverse)
single digit from left (reverse)
single digit from left (reverse 3x)
single digit from right (reverse 3x)
clear from left

test3.cx:

stack from left
stack from right
stack from left (reverse)
stack from right (reverse)

sym pattern
single digit from right w/ opp moving bit
single digit from left w/ opp moving bit

