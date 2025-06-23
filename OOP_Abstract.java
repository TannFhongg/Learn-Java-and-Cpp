//abstract class la 1 lop truu tuong 
// -> khong the tao doi tuong truc tiep tu no

// abstract method chi co khai bao,khong co than ham
//dung khi can tao 1 lop cha co khai niem cu the chung
// -> nhung khong du cu the de tao doi tuong

//abstract khi bat buoc 1 so lop con thuc hien hanh vi 

abstract class PC {
    String name;

    PC(String name) {
        this.name = name;
    }

    abstract void Ram();

    abstract void Rom();
}

abstract class DaiLyBanLe extends PC {
    DaiLyBanLe(String name) {
        super(name);
    }

    abstract double giaTien();
}

class MyPC extends DaiLyBanLe {
    MyPC(String name) {
        super(name);
    }

    @Override
    double giaTien() {
        System.out.print(name + " Co gia tien la: ");
        return 1000;
    }

    @Override
    void Ram() {
        System.out.println(name + " Co 16GB RAM");
    }

    @Override
    void Rom() {
        System.out.println(name + " Co 512GB ROM");
    }
}

abstract class Vehicle {
    String brand;

    Vehicle(String brand) {
        this.brand = brand;
    }

    abstract void move();
}

class Car extends Vehicle {
    Car(String brand) {
        super(brand);
    }

    @Override
    void move() {
        System.out.println(brand + " is driving in the road");
    }
}

class Boat extends Vehicle {
    Boat(String brand) {
        super(brand);
    }

    @Override
    void move() {
        System.out.println(brand + " is driving on the water");
    }
}

public class OOP_Abstract {
    public static void main(String args[]) {

        MyPC p = new MyPC("Asus");

        p.Rom();
        p.Ram();
        System.out.println(p.giaTien());

        Boat b = new Boat("Boat"); 
        Car c = new Car("Toyota"); 
        b.move(); 
        c.move(); 
    }
}
