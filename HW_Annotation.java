import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.lang.annotation.Target;
import java.lang.reflect.Method;
import java.lang.annotation.ElementType;
/*
 * Annotation: là một cơ chế để thêm thông tin vào mã nguồn.
 * la chu thich sieu du lieu duoc gan vao class, method, field, ...
 * Annotation được sử dụng để:
 * - Thêm thông tin vào mã nguồn.
 * | Annotation             | Ý nghĩa                                   |
| ---------------------- | ----------------------------------------- |
| `@Override`            | Ghi đè phương thức từ lớp cha             |
| `@Deprecated`          | Đánh dấu là không nên dùng nữa            |
| `@SuppressWarnings`    | Bỏ qua cảnh báo                           |
| `@FunctionalInterface` | Interface chỉ có 1 phương thức trừu tượng |

    */ 
class Cat {
    String name;
    int age;

    Cat(String name) {
        this.name = name;
    }

    void eat() {
        System.out.println("Cat is eating");
    }

    void sleep() {
        System.out.println("Cat is sleeping");
    }

    void run() {
        System.out.println("Cat is running");
    }
}

class Demo { // demo Deprecated
    @Deprecated
    void run() {
        System.out.println("Cat is running");
    }
}

@Retention(RetentionPolicy.RUNTIME)
@Target(ElementType.METHOD)
@interface Info {
    String author() default "Tuan";

    int version() default 1;

}

class Hello {
    @Info(author = "Tuan", version = 2)
    public void sayHello() {
        System.out.println("Hello");
    }
}

public class HW_Annotation {
    public static void main(String[] args) {
        Cat mycat = new Cat("Tom");
        Demo demo = new Demo();
        demo.run();
        Hello hello = new Hello();
        hello.sayHello();

        // Lấy annotation Info trên phương thức sayHello
        try {
            Method m = hello.getClass().getMethod("sayHello");
            Info info = m.getAnnotation(Info.class);
            System.out.println(info.author());
            System.out.println(info.version());
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
