#Michael Thorman
#CSCI 24000
#9/25/2017
#makefile for assignment#3

Driver: Driver.class Player.class

Driver.class: Driver.java
	javac Driver.java

Player.class: Player.java
	javac Player.java
clean: 
	rm*.class


