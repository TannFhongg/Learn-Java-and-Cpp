// da hinh tai thoi diem chay run-time

class Animal {
    public void sound() {
        System.out.println("Animal make sound");
    }
}

class Dog extends Animal {
    public void sound() {
        System.out.println("Dog make sound gou gou!");
    }
}

// da hinh tai thoi diem bien dich compile-time

class TinhTong {
    int add(int a, int b) {
        return a + b;
    }

    double add(double a, double b) {
        return a + b;
    }
}

interface Shape {
    void drawing(); // public abstract

}

// da hinh voi interface
class Cirlce implements Shape {
    public void drawing() { // khi override lai phuong thuc bat buoc dung "public"
        System.out.println("Drawing the circle");
    }

}

class Square implements Shape {
    public void drawing() {
        System.out.println("Drawing the square");
    }
}

class OOP_Polymorphism {
    public static void main(String args[]) {
        Animal a = new Dog();
        a.sound();
        TinhTong x = new TinhTong();
        System.out.println(x.add(1.2, 3.2));

        Shape s, s1;
        s = new Cirlce();
        s1 = new Square();
        s1.drawing();
        s.drawing();
    }
}