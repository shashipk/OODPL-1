public class InheritanceDemo {
    public static void main(String[] args) {
        Animal cat = new Cat();
        cat.setAge(4);
        cat.setColor("White");
        cat.setHeight(2);

        System.out.println(cat.getAge());

        Dog dog = new Dog();
        dog.setAge(2);

        Bike bike = new Bike();
        bike.setCompanyName("Yamaha");
        bike.setCc(125);
    }
}
