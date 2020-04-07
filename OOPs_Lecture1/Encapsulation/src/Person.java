
// Data Bindings
// Data hiding
\*
        int sum(a,b)
        int sum(a,b,c)


*/
public class Person {
    private String name;
    private int age;
    void speak(){
        System.out.println("My name is: "+ name);
    }
    public void setName(String inputName) {
        name = inputName;
    }
    public String getName(){
        return name;
    }

    public void setAge(int age) {
        if(age<0){
            this.age = 0;
        }else {
            this.age = age;
        }
    }

    public int getAge() {
        return age;
    }
}
