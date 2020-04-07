public class EncapsulationDemo {

    public static void main(String[] args) {

        Person person1 = new Person();
        // person1.age = -10;
        person1.setAge(25);
        person1.setName("Shashi");
        person1.setAge(-20);

        System.out.println(person1.getName()+ " "+ person1.getAge());
        person1.speak();
    }
}
