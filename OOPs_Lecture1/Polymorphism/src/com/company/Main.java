package com.company;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Adder adder = new Adder();

        System.out.println(adder.add(4,5));
        System.out.println(adder.add(2,4,7));
        System.out.println(adder.add("Hello", "Geeks"));
    }
}
