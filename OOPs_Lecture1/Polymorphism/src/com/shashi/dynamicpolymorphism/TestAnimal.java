package com.shashi.dynamicpolymorphism;

public class TestAnimal {

    public static void main(String[] args) {
        Lion lion1 = new Lion();
        lion1.sound();

        Cat cat1 = new Cat();
        cat1.sound();
        // Animal an1 = new cat(); // new Dog();

        AnimalManager animalManager = new AnimalManager();
        animalManager.makeAnimalSound(cat1);
        animalManager.makeAnimalSound(lion1);

    }
}

// person1