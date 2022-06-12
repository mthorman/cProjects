#Michael Thorman
#CSCI 24000
#11/26/2017
#makefile for assignment#6 BlackBelt

Driver: Driver.class BubbleSort.class InsertionSort.class Sort.class 

Driver.class: Driver.java
	javac Driver.java
BubbleSort.class: BubbleSort.java
	javac BubbleSort.java
InsertionSort.class: InsertionSort.java
	javac InsertionSort.java
Sort.class: Sort.java
	javac Sort.java

clean: 
	rm*.class


